/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:34:49 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/15 14:15:30 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
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
	static int	n;
	static int	bit;

	if (sig == SIGUSR1)
		bit += 1 << (7 - n);
	n++;
	if (n == 8)
	{
		ft_putchar(bit);
		n = 0;
		bit = 0;
	}
}
	// (1 << (7 - n)) -> Decaler les bits vers la gauche
	//Quand j ai les 8 bits, je l'affiche
	//et je remet a 0 n pour recommencer a l'octet suivant

int	main(int argc, char	**argv)
{
	pid_t	id;

	(void)argv;
	if (argc == 1)
	{
		id = getpid();
		ft_putstr("le pid est ");
		ft_putnbr(id);
		ft_putchar('\n');
		signal(SIGUSR1, translate_message);
		signal(SIGUSR2, translate_message);
		while (21)
			pause();
	}
	return (0);
}
