/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bben-yaa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:53:09 by bben-yaa          #+#    #+#             */
/*   Updated: 2021/09/09 08:31:33 by bben-yaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void    ft_putstr(char  *str);
void    ft_putchar(char c);
void    ft_putnbr(int n);
void    translate_message(int sig);
void    ft_convert_char_to_sig(char c, pid_t    pid);
int     atoi(const char *nptr);
int     ft_check(const char *nptr);

#endif
