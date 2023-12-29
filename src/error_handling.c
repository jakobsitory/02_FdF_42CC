/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:00:31 by jschott           #+#    #+#             */
/*   Updated: 2023/09/27 14:40:40 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

t_vector	*fdf_errors(int code)
{
	write (2, "ERROR:\n", 7);
	if (code == 0)
		write(2, "no file or directory specified", 30);
	if (code == 1)
		write(2, "file is not of type .fdf", 24);
	if (code == 2)
		write(2, "error when opening the file", 27);
	if (code == 3)
		write(2, "error while reading the file", 28);
	if (code == 4)
		write(2, "too many arguments", 18);
	write (2, "\n", 1);
	return (NULL);
}
