/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:49:19 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:49:21 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	substr retorna uma sub string da string s1. a começar no byte start
	e a terminar ao fim de len bytes.

	1. verf. se s1 é uma string vazia
	2. verf. se start é maior que o tam da s1
	3. cond. para garantir que len nunca é maior que s1 + start, para n
		criar mais bytes do que o necessário.

*/

char	*ft_substr(const char *s1, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	if (start > ft_strlen(s1))
		return (ft_strdup(""));
	if (ft_strlen(s1) < start + len)
		len = ft_strlen(s1) - start;
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
/*
#include<stdio.h>
int main(void)
{
	char    s1[13] = "Hello World!";
	char    *s2;

	s2 = ft_substr (s1, 6, 6);
	printf ("s1: %s\n", s1);
	printf ("s2: %s\n", s2);
	free(s2);
}*/
