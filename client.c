/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:17:34 by aappleto          #+#    #+#             */
/*   Updated: 2022/06/17 01:17:36 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int		i;
	char	signal;

	signal = 0;
	i = 8;
	if (!c)
		c = 10;
	while (--i > -1)
	{	
		signal = (c >> i) & 1;
		if (signal == 0)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else if (signal == 1)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

void	error(void)
{
	write(1, "Wrong number of arguments!\n", 28);
	write(1, "usage: ./client [server-pid] [message]\n", 40);
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc != 3)
		error();
	else
	{
		i = -1;
		while (argv[2][++i])
			send_char(argv[2][i], ft_atoi(argv[1]));
		send_char(argv[2][i], ft_atoi(argv[1]));
	}
	return (0);
}
