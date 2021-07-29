
#include "ft_traceroute.h"


void rtt_info(t_parametrs *parametrs)
{
	long double	rtt;

	if (gettimeofday(&parametrs->time.r, NULL) < 0)
	{
		ft_putstr_fd("Error: timeofday\n", 2);
		exit(2);
	}
	parametrs->received++;
	rtt = (parametrs->time.r.tv_usec - parametrs->time.s.tv_usec) / 1000000.0;
	rtt += (parametrs->time.r.tv_sec - parametrs->time.s.tv_sec);
	rtt *= 1000.0;
	parametrs->time.rtt = rtt;
	if (rtt > parametrs->time.max)
		parametrs->time.max = rtt;
	if (parametrs->time.min == 0.0)
		parametrs->time.min = rtt;
	else if (parametrs->time.min > rtt)
		parametrs->time.min = rtt;
	parametrs->time.avg += rtt;
	parametrs->time.sum_sqrt += rtt * rtt;
}

void init_receive_param(t_parametrs *parametrs)
{
	t_response *response;

	response = &parametrs->response;
	ft_bzero((void *)parametrs->pack.buff, 84);
	ft_bzero(response, sizeof(t_response));
	response->iovec->iov_base = (void *)parametrs->pack.buff;
	response->iovec->iov_len = sizeof(parametrs->pack.buff);
	response->msghdr.msg_iov = response->iovec;
	response->msghdr.msg_name = NULL;
	response->msghdr.msg_iovlen = 1;
	response->msghdr.msg_namelen = 0;
	response->msghdr.msg_flags = MSG_DONTWAIT;
}

void receive_from_host(t_parametrs *parametrs)
{
	int 	rec;
	struct ip *ip;

	init_receive_param(parametrs);
	while (!parametrs->sig.sin_end)
	{
		rec = recvmsg(parametrs->sock_fd, &parametrs->response.msghdr, MSG_DONTWAIT);
		if (rec > 0)
		{
			parametrs->byte_received = rec;
			ip = (struct  ip*) parametrs->response.iovec->iov_base;
			if (parametrs->pack.icmp->type == ICMP_ECHOREPLY)
			{
				rtt_info(parametrs);
				if (parametrs->host_name != parametrs->addr_str)
					printf("%d bytes from %s (%s): icmp_seq=%d ttl=%d time=%.2Lf ms\n", parametrs->byte_received - (int) sizeof(struct iphdr), parametrs->host_name,
						   parametrs->addr_str, parametrs->pack.icmp->un.echo.sequence, ip->ip_ttl, parametrs->time.rtt);
				else
					printf("%d bytes from %s: icmp_seq=%d ttl=%d time=%.2Lf ms\n", parametrs->byte_received - (int) sizeof(struct iphdr),
						   parametrs->addr_str, parametrs->pack.icmp->un.echo.sequence, ip->ip_ttl, parametrs->time.rtt);
			}
			else if (parametrs->flag_v)
			{
				char str[50];

				printf("%d bytes from %s: type=%d code=%d\n", parametrs->byte_received - (int) sizeof(struct iphdr),
					   inet_ntop(AF_INET, (void *)&parametrs->pack.ip->saddr, str, 100),
					   parametrs->pack.icmp->type, parametrs->pack.icmp->code);
			}
			return;
		}
	}
}

unsigned short checksum(unsigned short *icmp, int len_struct)
{
	unsigned long	res;

	res = 0;
	while (len_struct > 1)
	{
		res = res + *icmp++;
		len_struct = len_struct - sizeof(unsigned short);
	}
	if (len_struct)
	{
		res = res + *(unsigned char *)icmp;
	}
	res = (res >> 16) + (res & 0xffff);
	res = res + (res >> 16);
	return (unsigned short)(~res);
}

void send_to_host(t_parametrs *parametrs)
{
	ft_bzero((void *)parametrs->pack.buff, 84);
	parametrs->pack.ip->version = 4;
	parametrs->pack.ip->protocol = IPPROTO_ICMP;
	parametrs->pack.ip->ttl = parametrs->ttl;
	parametrs->pack.ip->ihl = sizeof(*parametrs->pack.ip) >> 2;
	inet_pton(AF_INET, parametrs->addr_str, &parametrs->pack.ip->daddr);
	parametrs->pack.icmp->code = 0;
	parametrs->pack.icmp->type = ICMP_ECHO;
	parametrs->pack.icmp->un.echo.id = parametrs->pid;
	parametrs->pack.icmp->un.echo.sequence = parametrs->seq++;
	parametrs->pack.icmp->checksum = checksum((unsigned short *)parametrs->pack.icmp, sizeof(struct icmphdr));
	if (sendto(parametrs->sock_fd, (void *)&parametrs->pack, 84, 0, (void *)parametrs->sock, sizeof(struct sockaddr_in)) < 0)
	{
		ft_putstr_fd("Error: sendto\n", 2);
		exit(2);
	}
	if (gettimeofday(&parametrs->time.s, NULL) < 0)
	{
		ft_putstr_fd("Error: gettimeofday\n", 2);
		exit(2);
	}
	parametrs->send > 1 ? gettimeofday(&parametrs->time.start, NULL) : 0;
	parametrs->send++;
	parametrs->sig.sin_send = 0;
}

void get_socket_fd(t_parametrs *parametrs)
{
	int opt_val;

	opt_val = 1;
	parametrs->sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (parametrs->sock_fd == -1)
	{
		ft_putstr_fd("Socket file descriptor not received!\n", 2);
		exit(2);
	}
	if (setsockopt(parametrs->sock_fd, IPPROTO_IP, IP_HDRINCL, &opt_val, sizeof(int)) < 0)
	{
		ft_putstr_fd("Error: setsockopt\n", 2);
		exit(2);
	}
}

void ft_ping(t_parametrs *parametrs)
{
	get_socket_fd(parametrs);
	parametrs->sock->sin_port = htons(33434);
	printf("traceroute to %s (%s), %d hops max, %d byte packets\n", parametrs->host_name, parametrs->addr_str, 30, 60);
//	while (!parametrs->sig.sin_end)
//	{
//		send_to_host(parametrs);
//		alarm(10);
//		receive_from_host(parametrs);
//		usleep(1000000);
//	}
}

void get_stat(t_parametrs *parametrs)
{
	struct timeval start;
	struct timeval end;
	long double time;
	long double mdev;
	double loss;

	gettimeofday(&parametrs->time.end, NULL);
	start = parametrs->time.start;
	end = parametrs->time.end;
	loss = (parametrs->send - parametrs->received) / parametrs->send * 100.0;
	time = (end.tv_usec - start.tv_usec) / 1000000.0;
	time += (end.tv_sec - start.tv_sec);
	time *= 1000.0;

	parametrs->time.avg /= parametrs->send;
	mdev = (parametrs->time.sum_sqrt / parametrs->send) - parametrs->time.avg * parametrs->time.avg;
	mdev = sqrt(mdev);
	ft_printf("\n--- %s ping statistics ---\n", parametrs->host_name);
	ft_printf("%d packets transmitted, %d received, ", parametrs->send, parametrs->received);
	printf("%.0f%% packet loss, time %.0Lfms\n", loss, time);
	if (parametrs->time.rtt > 0.0)
		printf("rtt min/avg/max/mdev = %.3Lf/%.3Lf/%.3Lf/%.3Lf ms\n", parametrs->time.min, parametrs->time.avg, parametrs->time.max, mdev);
}

//void sig_handler(int dummy)
//{
//	if (dummy == SIGINT)
//	{
//		parametrs->sig.sin_end = 1;
//		get_stat();
//	}
//	if (dummy == SIGALRM)
//		parametrs->sig.sin_send = 1;
//}

void free_params(t_parametrs *parametrs)
{
	freeaddrinfo(parametrs->res);
	free(parametrs);
}

t_parametrs *init()
{
	t_parametrs *tmp;
	tmp = (t_parametrs*)malloc(sizeof(t_parametrs));
	ft_bzero(tmp, sizeof(t_parametrs));
	tmp->sock_fd = 0;
	tmp->sig.sin_send = 0;
	tmp->sig.sin_end = 0;
	tmp->pack.ip = (struct iphdr *)tmp->pack.buff;
	tmp->pack.icmp = (struct icmphdr *)(tmp->pack.ip + 1);
	tmp->ttl = 17;
	tmp->pid = getpid();
	tmp->seq = 1;
	tmp->time.min = 0.0;
	tmp->time.max = 0.0;
	tmp->time.sum_sqrt = 0;
	tmp->received = 0;
	return tmp;
}

int get_host_info(t_parametrs *parametrs)
{
	struct addrinfo start;
	struct addrinfo *res;

	ft_bzero(&start, sizeof(start));
	start.ai_family = AF_INET;
	start.ai_socktype = SOCK_RAW;
	start.ai_protocol = IPPROTO_ICMP;
	if (getaddrinfo(parametrs->host_name, NULL, &start, &parametrs->res) != 0)
		return (1);
	parametrs->sock = (struct sockaddr_in *)parametrs->res->ai_addr;
	return (0);
}

void get_arguments(int ac, char **av, t_parametrs *parametrs)
{
    int i;
	int count;
	int stop;

	stop = 0;
	count = 1;
    i = 1;
        if (ft_strcmp(av[1], "-h") == 0)
        {
			ft_printf("Usage: ft_traceroute [-h help] hostname\n");
			exit(1);
        }
        else
		{
			parametrs->host_name = av[i];
        	if (get_host_info(parametrs))
			{
				ft_putstr_fd("ft_traceroute: ", 2);
				ft_putstr_fd(parametrs->host_name, 2);
				ft_putstr_fd(": ", 2);
				ft_putstr_fd(" Name or service not known!!\n", 2);
				exit(1);
			}
        	inet_ntop(AF_INET, (void *)&parametrs->sock->sin_addr, parametrs->addr_str, INET_ADDRSTRLEN);
		}
}

int set_ttl_by_new_fd(int fd, int ttl)
{
	const int count = ttl;

	if (setsockopt(fd, IPPROTO_IP, IP_TTL, &count, sizeof(count)) != 0)
	{
		printf("%s\n", "error setsock");
		exit(1);
	}
	return (0);
}

int init_new_fd_send()
{
	int fd;

	if ((fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
	{
		ft_printf("error socket create\n");
		exit(1);
	}
	return (fd);
}

int check_addr(struct sockaddr_in rem_addr[], int i)
{
	int tmp;
	int res;

	res = 0;
	tmp = 0;
	while (tmp < i)
	{
		if (rem_addr[i].sin_addr.s_addr == rem_addr[tmp].sin_addr.s_addr)
			res++;
		tmp++;
	}
	return (res);
}

int output_display(char *buf, struct sockaddr_in *rem_addr, struct timeval *time_rec, struct timeval *time_start, int is_outputed_addr)
{
	struct icmphdr *tmp;
	double time_output;

	tmp = (struct icmphdr *)((void *)buf + sizeof(struct ip));
	if (!is_outputed_addr)
		ft_printf(" %s", inet_ntoa(rem_addr->sin_addr));

	time_output = ((1000000 * time_rec->tv_sec + time_rec->tv_usec) - (1000000 * time_start->tv_sec + time_start->tv_usec));
	ft_printf("  %0.003f ms", time_output / 1000);

	return (0);
}

int output_stage(char buf[3][1024], struct sockaddr_in *rem_addr, struct timeval *time_rec, struct timeval *time_start)
{
	int i;

	i = 0;
	while (i < 3)
	{
		output_display(buf[i], &rem_addr[i], &time_rec[i], time_start, check_addr(rem_addr, i));
		i++;
	}
	ft_printf("\n");
	return (0);
}

int responce(int fd)
{
	struct sockaddr_in remonte_addr[3];
	int len_recv;
	socklen_t addr_len = sizeof(remonte_addr);
	char buf[3][1024];
	struct timeval time_start;
	struct timeval time_now;
	struct timeval time_rec[3];
	struct icmphdr *icmphdr;
	int end = 0;
	int rec_packets = 0;
	int size_pack_min = sizeof(struct icmphdr) + sizeof(struct ip);

	gettimeofday(&time_start, NULL);
	ft_bzero(buf, 1024 * 3);
	ft_bzero(time_rec, sizeof(struct timeval) * 3);
	ft_bzero(remonte_addr, sizeof(struct sockaddr_in) * 3);
	while (1)
	{
		gettimeofday(&time_now, NULL);
		if (time_now.tv_sec >= time_start.tv_sec + 1 && !end)
		{
			ft_printf(" %s\n", "* * *");
			return (1);
		}
		len_recv = (int)recvfrom(fd, buf[rec_packets], 1024, MSG_DONTWAIT, (struct sockaddr *)&remonte_addr[rec_packets], &addr_len);
		if (len_recv > size_pack_min)
		{
			gettimeofday(&time_rec[rec_packets], NULL);
			buf[rec_packets][len_recv] = 0;
			icmphdr = (struct icmphdr *)((void *)buf[rec_packets] + sizeof(struct ip));
			if (icmphdr->type == ICMP_DEST_UNREACH && icmphdr->code == ICMP_PORT_UNREACH)
			{
				end++;
				rec_packets++;
			}
			else if (icmphdr->type == ICMP_TIME_EXCEEDED && icmphdr->code == ICMP_EXC_TTL)
			{
				rec_packets++;
			}
		}
		if (rec_packets >= 3)
		{
			output_stage(buf, remonte_addr, time_rec, &time_start);
			if (end)
				exit(1);
			return (0);
		}
	}
	return (0);
}

int loop(int sock_fd, struct sockaddr_in *serv_addr)
{
	int send;
	int sended_pbh;
	int	sended_p;
	char buf[1024];
	int new_fd;
	int ttl;

	sended_pbh = 0;
	ttl = 1;
	while (ttl <= 30)
	{
		sended_p = 0;
		while (sended_p < 3)
		{
			if (sended_pbh == 3)
			{
				sended_pbh = 0;
				ttl++;
			}
			while (sended_pbh < 3 && sended_p < 3)
			{
				ft_bzero(buf, 60);
				new_fd = init_new_fd_send();
				set_ttl_by_new_fd(new_fd, ttl);
				if ((send = sendto(new_fd, buf, 60, 0, (struct sockaddr *)serv_addr, sizeof(struct sockaddr))) < 0)
				{
					ft_printf("sendto fail\n");
					exit(1);
				}
				close(new_fd);
				sended_pbh++;
				sended_p++;
			}
		}
		ft_printf(" %s%d ", ((ttl < 10) ? " " : ""), ttl);
		responce(sock_fd);
	}
	return (1);
}

int main(int ac, char **av)
{
	t_parametrs *parametrs;
	if (getuid() != 0)
	{
		ft_printf(":smile_8 ft_traceroute: need root (sudo -s)!\n");
		exit(1);
	}
	if (ac != 2)
	{
		ft_printf("Usage: ft_traceroute [-h help] hostname\n");
		exit(1);
	}
	parametrs = init();

	get_arguments(ac, av, parametrs);
//	signal(SIGALRM, sig_handler);
//	signal(SIGINT, sig_handler);
	ft_ping(parametrs);
	loop(parametrs->sock_fd, parametrs->sock);
	free_params(parametrs);
	return 0;
}
