/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:49:03 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:49:04 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

Igual a strchr mas o ponteiro aponta para o ult char encontrado.
assim que encontra um char igual, last é atualizado para o end desse char

*/

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			n;
	char			*last;

	i = 0;
	n = (char) c;
	last = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == n)
		{
			last = (char *) &s[i];
		}
		i++;
	}
	if (s[i] == n)
		return ((char *) &s[i]);
	return (last);
}
/*
#include<stdio.h>
int main(void)
{
	char  c[] = "Hello World World!";
	char    *ptr = ft_strrchr(c, 'W');
	printf ("%s", ptr);
}*/
