/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:15:49 by jschott           #+#    #+#             */
/*   Updated: 2023/06/27 17:07:32 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsigned_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putunsigned_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

int	ft_printu(long int i)
{
	ft_putunsigned_fd(i, 1);
	return (ft_itodigs((long int) i));
}
