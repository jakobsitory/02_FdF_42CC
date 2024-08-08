/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:00:31 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 10:57:55 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Handles errors by printing specific error messages based on error codes.
 * 
 * - 0: No file or directory specified.
 * - 1: File is not of type .fdf.
 * - 2: Error when opening the file.
 * - 3: Error while reading the file.
 * - 4: Too many arguments.
 * 
 * @param code The error code indicating the type of error encountered.
 * @return Always returns NULL, indicating an error has occurred.
 */
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
