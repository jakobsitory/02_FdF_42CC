/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:15:49 by jschott           #+#    #+#             */
/*   Updated: 2023/06/27 17:07:28 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_xtodigs(unsigned long int nb)
{
	int			digits;

	digits = 1;
	if (nb < 0)
	{
		digits++;
		nb = -nb;
	}
	while (nb >= 16)
	{
		digits++;
		nb = nb / 16;
	}
	return (digits);
}

void	ft_putnbr_base(unsigned long long int nbr, char *base)
{
	if (nbr / ft_strlen(base) > 0)
	{
		ft_putnbr_base (nbr / ft_strlen(base), base);
		write (1, &base[nbr % ft_strlen(base)], 1);
	}
	else
		write (1, &base[nbr % ft_strlen(base)], 1);
}

int	ft_printx(char c, unsigned long long int h)
{
	if (c == 'x')
		ft_putnbr_base(h, "0123456789abcdef");
	if (c == 'X')
		ft_putnbr_base(h, "0123456789ABCDEF");
	return (ft_xtodigs(h));
}
