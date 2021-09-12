/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:34:49 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/10 07:58:00 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdbool.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	char	z;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
		z = n + '0';
		ft_putchar(z);
	}
	else
	{
		ft_putnbr (n / 10);
		ft_putnbr (n % 10);
	}
}

void	translate_message(int sig)
{
	static int	n;
	static int	bit;

	//n = 0;
	//bit = 0;
	//Decaler vers la gauche
	printf("On a recu un signal\n");
	if (sig == SIGUSR1)
		bit += 1 << (7 - n);
	n++;
	if (n == 8)
	{
		printf("%c\n", bit);
		n = 0;
		bit = 0;
	}
	//Quand j ai les 8 bits, je l affichage et je remet a 0;
}

int	main(void)
{
	pid_t	id;

	id = getpid();
	printf("le id c'est %d\n", id);
	signal(SIGUSR1, translate_message);
	signal(SIGUSR2, translate_message);
	while (true)
	{	
		pause();
	}
	return (0);
}
