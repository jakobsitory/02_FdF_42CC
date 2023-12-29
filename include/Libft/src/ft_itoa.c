/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:15:14 by jschott           #+#    #+#             */
/*   Updated: 2023/05/24 16:31:53 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(char *tab1, char *tab2)
{
	char	memory;

	memory = *tab1;
	*tab1 = *tab2;
	*tab2 = memory;
}

void	ft_revstr(char *tab, int size)
{
	int	i;

	i = 0;
	while (i <= size / 2 - 1)
	{
		ft_swap(&tab[i], &tab[size - 1 - i]);
		i++;
	}
}

void	ft_iina(char *str, long int n)
{
	if (n < 0)
		n = -n;
	if (n >= 10)
		ft_iina(&str[1], n / 10);
	str[0] = n % 10 + '0';
}

int	ft_itodigs(long int nb)
{
	int			digits;

	digits = 1;
	while (nb >= 10)
	{
		digits++;
		nb = nb / 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			digits;
	long int	nb;
	int			sign;

	nb = (long int) n;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		nb = -(long int)n;
	}
	digits = ft_itodigs(nb);
	str = (char *) malloc (digits + sign + 1);
	if (str == NULL)
		return (NULL);
	if (sign && nb != 0)
		str[0] = '-';
	if (nb == 0)
		str[0] = '0';
	else
		ft_iina(&str[sign], (long int) n);
	ft_revstr(&str[sign], digits);
	str[digits + sign] = '\0';
	return (str);
}
