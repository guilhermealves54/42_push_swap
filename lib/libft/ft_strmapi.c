/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:48:29 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:48:31 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

strmapi cria uma nova string e aplica a função f a cada char 
da string s.

*/

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
/*
char    test_function(unsigned int i, char c)
{
	if (i % 2 == 0)
	{
		if (c >= 'a' && c <= 'z')
			return (c -= 32);
		if (c >= 'A' && c <= 'Z')
			return (c += 32);
	}
	return (c);
}

#include<stdio.h>
int main(void)
{
	char    str[] = "Hello World!";
	char    *s = ft_strmapi(str, test_function);;
	unsigned int    i = 0;

	printf ("Antes: %s\n", str);
	printf ("Depois: %s\n", s);
	free(s);
}*/
