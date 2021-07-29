//
// Created by cxim1 on 05.06.2021.
//

#ifndef FT_PING__FT_PING_H_
#define FT_PING__FT_PING_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <math.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include "ft_printf/includes/printf.h"
#include <netdb.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

typedef struct s_pack
{
	char 		buff[84];
	struct iphdr	*ip;
	struct icmphdr	*icmp;
}				t_pack;

typedef struct s_sig
{
	int 	sin_end;
	int 	sin_send;
}				t_sig;

typedef struct s_time
{
	struct timeval start;
	struct timeval end;
	struct timeval	r;
	struct timeval	s;
	long double		rtt;
	long double		min;
	long double		max;
	long double		avg;
	long double		sum_sqrt;
}				t_time;

typedef struct s_response
{
	struct iovec	iovec[1];
	struct msghdr	msghdr;
}				t_response;

typedef struct s_parametrs
{
	struct addrinfo *res;
    struct sockaddr_in *sock;
    int 	flag_v;
    int     sock_fd;
	t_pack pack;
    char 	*host_name;
    char 	addr_str[INET6_ADDRSTRLEN];
    t_time	time;
    t_sig sig;
    int send;
    int received;
	int ttl;
	pid_t 	pid;
	int 	seq;
	t_response response;
	int 	byte_received;
}               t_parametrs;


#endif
