/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:49:18 by jschott           #+#    #+#             */
/*   Updated: 2023/08/24 13:26:58 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int				ft_printf(const char *form, ...);
int				ft_printc(int c);
int				ft_prints(void *str);
int				ft_printi(int i);
int				ft_printu(long int i);
int				ft_printp(void *ptr);
int				ft_printx(char c, unsigned long long int h);

#endif
