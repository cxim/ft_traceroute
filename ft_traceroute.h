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


typedef struct s_parametrs
{
	int     sock_fd;
	int		some_errors;
	pid_t 	pid;
	size_t	first_stage;
	size_t	nb_stage_max;
	size_t	nb_queries;
	size_t	pack_size;

	struct addrinfo *res;
	char 	*host_name;
	struct timeval start;
	struct timeval end;
	struct timeval	r;

    char 	addr_host[INET_ADDRSTRLEN];
    char 	addr_host_canonik[INET_ADDRSTRLEN];
	char 	rev_dns[NI_MAXHOST];
}               t_parametrs;


#endif
