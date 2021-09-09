/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 09:31:31 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/09 10:55:33 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main (void)
{
	int a = 75;
	int b = a << 2;
	
	printf("a = %c\n", a);
	printf("a decallage %d\n", a << 2); //fichier client

	printf("b sans decallage = %d\n", b);
	printf("b = %c\n", b >> 2); //fichier server
	return (0);
}
