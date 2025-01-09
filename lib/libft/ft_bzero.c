/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:42:08 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:42:19 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	char	*temp_s;

	temp_s = (char *)s;
	while (n > 0)
	{
		*temp_s = 0;
		temp_s++;
		n--;
	}
	return (s);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
    char    str[] = "Hello!";

    printf ("String original: %s\n", str);
    ft_bzero (str, 5);
    printf ("String ft_bzero: %s\n", str);
    bzero (str, 5);
    printf ("String bzero: %s\n", str);
}*/