/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:48:54 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:48:56 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

Funciona como o strchr mas procura toda uma substring em n bytes.
se needle for uma str vazia retorna haystack.
se needle não ocorrer em haystack retorna NULL.
se encontrar needle em haystack retorna um pointer para o primeiro char.

*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while ((haystack[i + n] == needle[n]) && haystack[i + n] != '\0'
			&& i + n < len)
		{
			n++;
			if (needle[n] == '\0')
				return ((char *) haystack + i);
		}
		i++;
		n = 0;
	}
	return (0);
}
/*
#include<stdio.h>
int main(void)
{
	char    haystack[] = "42 Porto";
	char    needle[] = "Porto";

	printf ("%s", strnstr (haystack, needle, 8));
}*/
