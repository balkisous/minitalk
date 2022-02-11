/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:02:08 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/15 17:12:50 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	n;
	int	sign;
	int	k;

	n = 0;
	k = 0;
	sign = 1;
	i = ft_check(nptr);
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -sign;
		k++;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - 48);
		i++;
	}
	if (k > 1)
		return (0);
	return (n * sign);
}

void	ft_convert_char_to_sig(char c, int pid)
{
	int	a;

	a = 7;
	while (a >= 0)
	{
		if (c >> a & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		a--;
	}
}
	//if (c >> a & 1) -> ca veut dire que le bit est de 1 
	//else sinon le bit est de 0

int	main(int argc, char **argv)
{
	 pid_t	pid;
	 int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
			ft_convert_char_to_sig(argv[2][i++], pid);
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(1, "error check : ./client [pid server][string]\n", 44);
		exit(EXIT_FAILURE);
	}
	return (0);
}
