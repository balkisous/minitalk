/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:34:49 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/09 10:59:46 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdbool.h>

void	translate_message(int sig)
{
	int c;
	char letter;

	letter = 0;
	//Decaler vers la gauche
	printf("On a recu un signal\n");
	c = 0;
	if (sig == SIGUSR1)
	{
		printf("J'ai recu un sigusr1\n");
		c = sig;
	}
	if (sig == SIGUSR2)
	{
		printf("J'ai recu un sigusr2\n");
		c = sig;
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
