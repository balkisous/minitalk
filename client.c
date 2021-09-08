/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:02:08 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/08 12:36:26 by bben-yaa         ###   ########.fr       */
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
	//le probleme est la wsh
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
	printf ("le int %d\n", n);
	return (n * sign);
}

void	client(pid_t id, char *str)
{
	int	i;
	int a;

	i = 0;
	a = 0;
	printf("j'ai recu %d\n", id);
	printf("la string: %s\n", str);
	while (str[i])
	{
		printf("lettre %c\n", str[i]);
		a = ft_atoi(&str[i]);
		printf("le carctere vaut %d\n", a);
		printf("le carctere vaut %d\n", ft_atoi(&str[i]));
		i++;
	}
}
int main(int argc, char **argv)
{
	int id;

	id = (int)argv[1];
	client(id, argv[2]);
	return (0);
}
