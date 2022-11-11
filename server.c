/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aappleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 01:17:44 by aappleto          #+#    #+#             */
/*   Updated: 2022/06/17 01:17:45 by aappleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	binary[8] = {128, 64, 32, 16, 8, 4, 2, 1};
	static int	i = 0;
	static char	sum = 0;

	if (signal == SIGUSR1)
		i++;
	if (signal == SIGUSR2)
	{
		sum = sum + binary[i];
		i++;
	}
	if (i >= 8)
	{
		write(1, &sum, 1);
		i = 0;
		sum = 0;
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
