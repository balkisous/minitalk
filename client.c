/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:02:08 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/14 17:11:38 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check(const char *nptr)
{
	int i;

	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
	|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	return (i);
}

int			ft_atoi(const char *nptr)
{
	int i;
	int n;
	int sign;
	int k;

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

void	ft_convert_char_to_sig(char	c, pid_t	pid)
{
	int	a;

	a = 8;
	while (a > 0)
	{
		if (c >> a & 1) //le bit est de 1
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2); //le signal est de 0
		usleep(500);
		a--;
	}
}

int main(int argc, char **argv)
{
	 pid_t	pid;
	 int	i;

	i = 0;
	if (argc != 3)
	{
		printf("error check : ./client [pid server][string]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (argc == 3)
	{
		while(argv[2][i])
			ft_convert_char_to_sig(argv[2][i++], pid);
	//	usleep(500);
	}
	return (0);
}
