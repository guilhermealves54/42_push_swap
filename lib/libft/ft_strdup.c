/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:47:22 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:47:24 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

strdup faz uma copia de uma string.

1. criar str temp e alocar memoria suficiente (malloc e ft_strlen)
2. loop para copiar byte a byte
3. null terminator
4. retornar string criada.

*/

char	*ft_strdup(const char *s1)
{
	char	*tmp_str;
	size_t	i;

	i = 0;
	tmp_str = (char *) malloc ((ft_strlen (s1) + 1) * sizeof(char));
	if (tmp_str == NULL)
	{
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		tmp_str[i] = s1[i];
		i++;
	}
	tmp_str[i] = '\0';
	return (tmp_str);
}
/*
#include<stdio.h>
int main(void)
{
	char    s1[] = "Hello World!";
	char    *strcopy;

	printf ("s1: %s\n", s1);
	strcopy = strdup(s1);
	printf ("strdup: %s\n", strcopy);
	free(strcopy);
}*/
