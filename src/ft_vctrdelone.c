/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vctrdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:19:24 by jschott           #+#    #+#             */
/*   Updated: 2024/08/08 11:05:06 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../FdF.h"

/**
 * Frees a single vector and its associated data.
 * 
 * Note: This function does not free the `lst` pointer itself; it only uses the `del` function to free associated
 * data. The caller is responsible for freeing the `lst` pointer if necessary.
 * 
 * @param lst Pointer to the vector to be freed.
 * @param del Function pointer to the function used to free the vector's associated data.
 */
void	ft_vctrdelone(t_vector *lst, void (*del)(void*))
{
	del(lst);
}
