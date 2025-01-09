/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:48:47 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:48:49 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

compara duas strings ate ao max de n caracteres.
se houver diferenças:

se o caractere em s2[i] for maior que o s1[i] o res é neg.
se o caractere em s1[i] for maior que s2[i] o res é pos.

se as strings forem iguais retorna 0.

*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if ((unsigned char) s1[i] != (unsigned char) s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		i++;
	}
	return (0);
}
/*
#include<stdio.h>
int main(void)
{
	char    s1[] = "Hello World!";
	char    s2[] = "Hello";
	int n = 0;

	n = ft_strncmp (s1, s2, 13);
	printf ("%d", n);
}*/
