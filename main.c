
#include "ft_traceroute.h"

void free_params(t_parametrs *parametrs)
{
	freeaddrinfo(parametrs->res);
	close(parametrs->sock_fd);
	parametrs->addr_host;
	free(parametrs);
}

t_parametrs * init()
{
	t_parametrs *tmp;
	tmp = (t_parametrs*)malloc(sizeof(t_parametrs));
	ft_bzero(tmp, sizeof(t_parametrs));
	tmp->pid = getpid();
	tmp->sock_fd = 0;
	tmp->first_stage = 1;
	tmp->nb_stage_max = 30;
	tmp->nb_queries = 3;
	tmp->pack_size = 60;
	tmp->res = NULL;
	return tmp;
}

void get_arguments(int ac, char **av)
{
	if (ft_strcmp(av[1], "-h") == 0)
    {
		ft_printf("Usage: ft_traceroute [-h help] hostname\n");
		exit(1);
    }
}

void create_sock(t_parametrs *parametrs)
{
	struct timeval time_out;
	parametrs->sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (parametrs->sock_fd == -1)
	{
		ft_printf("Error socket!\n");
		exit(1);
	}
	time_out.tv_sec = 1;
	time_out.tv_usec = 0;
	if (setsockopt(parametrs->sock_fd, SOL_SOCKET, SO_RCVTIMEO, &time_out, sizeof(struct timeval)) != 0)
	{
		ft_printf("error setsocket\n");
		free_params(parametrs);
		exit(1);
	}
}

void get_host_name(t_parametrs *parametrs, char *name)
{
	void *addr;
	struct sockaddr_in *sockaddr;

	addr = parametrs->res->ai_addr;
	sockaddr = (struct sockaddr_in*)addr;
	addr = &(sockaddr->sin_addr);
	inet_ntop(parametrs->res->ai_family, addr, name, parametrs->res->ai_addrlen);
}

uint16_t check_sum(uint16_t *buf, size_t size)
{
	uint32_t sum;

	sum = 0;
	while (size > 1)
	{
		sum += *buf;
		buf++;
		size -= 2;
	}
	if (size == 1)
	{
		sum += *(unsigned char *)buf;
	}
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	return ((uint16_t)~sum);
}

void reverse_dns(t_parametrs *parametrs, uint32_t ip)
{
	struct sockaddr_in tmp;
	socklen_t	size;

	tmp.sin_family = AF_INET;
	tmp.sin_addr.s_addr = ip;
	size = sizeof(struct sockaddr_in);
	if (getnameinfo((struct sockaddr *)&tmp, size, parametrs->rev_dns, NI_MAXHOST, NULL, 0, NI_NOFQDN) != 0)
		ft_strcpy(parametrs->rev_dns, parametrs->addr_host);
}

float time_ttl(t_parametrs *parametrs)
{
	return ((parametrs->end.tv_usec - parametrs->start.tv_usec) / 1000.0f +
			(parametrs->end.tv_sec - parametrs->start.tv_sec) * 1000.0f);
}


int check_resp(t_parametrs *parametrs, struct iphdr *iphdr, struct icmphdr *icmphdr)
{
	struct icmphdr *tmp;
	char   addr_host[INET_ADDRSTRLEN];
	char	*buf;

	buf = (char *)icmphdr;
	tmp = (struct icmphdr *)(buf + sizeof(struct icmphdr) + sizeof(struct iphdr));
	if (tmp->un.echo.id == parametrs->pid)
	{
		inet_ntop(AF_INET, &iphdr->saddr, addr_host, INET_ADDRSTRLEN);
		if (ft_strcmp(addr_host, parametrs->addr_host) != 0)
		{
			inet_ntop(AF_INET, &iphdr->saddr, parametrs->addr_host, INET_ADDRSTRLEN);
			reverse_dns(parametrs, iphdr->saddr);
			ft_printf(" %s (%s)", parametrs->rev_dns, parametrs->addr_host);
		}
		ft_printf("  %.3fms", time_ttl(parametrs));
		if (icmphdr->type == ICMP_DEST_UNREACH)
		{
			ft_printf("some error\n");
		}
		return (0);
	}
	return (-1);
}

int get_responce(t_parametrs *parametrs)
{
	ssize_t ret;
	struct iphdr *iphdr;
	struct icmphdr *icmphdr;
	char buf[128];
	char host_addr[INET_ADDRSTRLEN];

	ret = recvfrom(parametrs->sock_fd, buf, 128, 0, NULL, NULL);
	if (ret > 0)
	{
		gettimeofday(&parametrs->end, NULL);
		iphdr = (struct iphdr *)buf;
		icmphdr = (struct icmphdr *)(buf + sizeof(struct iphdr));
		if (icmphdr->un.echo.id != parametrs->pid)
		{
			inet_ntop(AF_INET, &iphdr->saddr, host_addr, INET_ADDRSTRLEN);
			if (ft_strcmp(host_addr, parametrs->addr_host) != 0)
			{
				inet_ntop(AF_INET, &iphdr->saddr, parametrs->addr_host, INET_ADDRSTRLEN);
				reverse_dns(parametrs, iphdr->saddr);
				ft_printf(" %s (%s)", parametrs->rev_dns, parametrs->addr_host);
			}
			ft_printf("  %.3fms", time_ttl(parametrs));
			if (ft_strcmp(host_addr, parametrs->addr_host_canonik) == 0)
				return (-1);
			return (1);
		}
		else
		{
			ret = check_resp(parametrs, iphdr, icmphdr);
			if (ret == -1)
				return (get_responce(parametrs));
			return ((int)ret);
		}
	}
	else
	{
		ft_printf(" *");
		return (0);
	}
}

int ping_stages(t_parametrs *parametrs)
{
	char *pack;
	ssize_t ret;
	size_t i;
	struct icmphdr *icmphdr;

	i = 0;
	while (i < parametrs->nb_queries)
	{
		pack = ft_memalloc(parametrs->pack_size);
		icmphdr = (struct icmphdr *)pack;
		icmphdr->type = ICMP_ECHO;
		icmphdr->un.echo.id = parametrs->pid;
		icmphdr->un.echo.sequence = htons(1);
		icmphdr->checksum = check_sum((uint16_t *)pack, parametrs->pack_size);
		gettimeofday(&parametrs->start, NULL);
		ret = sendto(parametrs->sock_fd, pack, parametrs->pack_size, 0, parametrs->res->ai_addr, sizeof(struct sockaddr_in));
		free(pack);
		if (ret < 1)
		{
			ft_printf("error sendto\n");
			free_params(parametrs);
			exit(1);
		}
		ret = get_responce(parametrs);
		i++;
	}
	ft_printf("\n");
	return ((int)ret);
}

int traceroute(t_parametrs *parametrs)
{
	size_t ttl;
	int ping;

	ttl = parametrs->first_stage;
	create_sock(parametrs);
	get_host_name(parametrs, parametrs->addr_host);
	ft_strcpy(parametrs->addr_host_canonik, parametrs->addr_host);
	ft_printf("traceroute to %s (%s), %d hops max, %d byte packets\n", parametrs->host_name, parametrs->addr_host, parametrs->nb_stage_max, parametrs->pack_size);
	if (parametrs->first_stage > parametrs->nb_stage_max)
	{
		ft_printf("error hops!\n");
		exit(1);
	}
	while (ttl <= parametrs->nb_stage_max) {
		if (setsockopt(parametrs->sock_fd, SOL_IP, IP_TTL, &ttl, sizeof(&ttl)) != 0) {
			ft_printf("error setsock!\n");
			exit(1);
		}
		ft_printf("%2u ", ttl);
		ping = ping_stages(parametrs);
		if (ping < 0 || parametrs->some_errors == 1) {
			break;
		}
		ttl++;
	}
	free_params(parametrs);
	return 0;
}

int main(int ac, char **av)
{
	t_parametrs *parametrs;
	struct addrinfo hints;

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

	get_arguments(ac, av);
	parametrs->host_name = av[1];
	ft_bzero(&hints, sizeof(struct addrinfo));
	hints.ai_flags = AI_CANONNAME;
	hints.ai_family = AF_INET;
	if (getaddrinfo(av[1], NULL, &hints, &parametrs->res) == -1)
		ft_printf("error getaddrinfo\n");
	else if (parametrs->res != NULL)
		return traceroute(parametrs);
	else
		ft_printf("no host exist\n");
	free_params(parametrs);
	return (1);
}
