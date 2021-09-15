/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:34:49 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/15 08:26:47 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
		ft_putchar(str[i++]);
}

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
	/*
	struct s_octet	s;

	s.n = 0;
	s.bit = 0;
	*/
	static	int	n;
	static	int	bit;
	//Decaler vers la gauche
	if (sig == SIGUSR1)
		bit += 1 << (7 - n);	
//	printf("n vaut %d\n", s.n);
	n++;
//	printf("n vaut %d\n", s.n);
	if (n == 8)
	{
	//	printf("la2\n");
		putchar(bit);
	//	printf("\n");
	//	printf("la2\n");
	//	printf("%c\n", bit);
		n = 0;
		bit = 0;
	}
	//Quand j ai les 8 bits, je l affichage et je remet a 0;
}

int	main(int argc, char	**argv)
{
	pid_t	id;

	(void)argv;
	if (argc == 1)
	{
		id = getpid();
		ft_putstr("le c'est ");
		ft_putnbr(id);
		ft_putchar('\n');
		signal(SIGUSR1, translate_message);
		signal(SIGUSR2, translate_message);
		while (21)
			pause();
	}
	return (0);
}
