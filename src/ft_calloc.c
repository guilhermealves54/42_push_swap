/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:44:26 by gribeiro          #+#    #+#             */
/*   Updated: 2025/01/15 14:50:48 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp_ptr;
	size_t			i;

	i = 0;
	tmp_ptr = malloc (count * size);
	if (tmp_ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		tmp_ptr[i] = 0;
		i++;
	}
	return (tmp_ptr);
}
