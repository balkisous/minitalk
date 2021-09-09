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

void	translate_message(int sig)
{
	int c;

	c = 0;
	if (sig == SIGUSR1)
	{
		c = sig;
		printf("%c", c >> 2);
	}
}

int	main(void)
{
	pid_t	id;

	if (42)
	{
		id = getpid();
		printf("le id c'est %d\n", id);
		signal(SIGUSR1, translate_message);
		signal(SIGUSR2, translate_message);
		pause();

	}
	return (0);
}
