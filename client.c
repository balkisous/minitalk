/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:02:08 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/09 11:19:15 by bben-yaa         ###   ########.fr       */
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

void	ft_convert_char_to_sig(char	*str,pid_t	pid)
{
	int	i;
	int a;

	i = 0;
	a = 8;
	while (str[i])
	{
		while (a > 0)
		{
			printf("%d\n", str[i] << (7 - a));
			if (str[i] == 0)
				kill(pid, SIGUSR1);
			//else if (str[i] == 1)
				kill(pid, SIGUSR2);
			a--;
		}
		i++;
		//printf("je suis dans le cas 2\n");
		//printf("le char %c\n", str[i]);
		//printf("le int dcaller vers la gauche %d\n", str[i] << 2);
		//on print avant le char pour voir s'il corespond au ascii
		//Si je sais que c'est un 0
		//kill(pid, SIGUSR1);
		
		//Si je sais que c'est un 1
		//kill(pid,SIGUSR2);
		//printf("le n decaller vers la gauche %d\n", n);
		//on va printer n en deccaller vers la gauche
		//apres on envoie le signal
		//traduction des char reussit manque plus qu'a envoyer a server et print
		//kill(pid, SIGUSR1);
		//pause(5);
	}
}
/*
void signal_handler(int sig)
{
	char s1[] = "SIGUSR1\n";
	char s2[] = "SIGUSR2\n";
	if (sig == SIGUSR1)
		printf("SIGUSR1 recu");
	else if (sig == SIGUSR2)
		printf("SIGUSRS2 recu");
	signal(sig, signal_handler);
}
*/
int main(int argc, char **argv)
{
	 pid_t	pid;

	pid = ft_atoi(argv[1]);
	printf("l'id est %d\n", pid);
	ft_convert_char_to_sig(argv[2], pid);
//	kill(pid, SIGUSR1);
//	client(pid, argv[2]);
	return (0);
}
