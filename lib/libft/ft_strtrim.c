/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:49:11 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 16:49:13 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

strtrim remove parte do inicio e fim da string s1 com chars de set.
1. strlen de s1 para difinir n como o ultimo byte da string.
2. loop que verifica o inicio da string com apoio da função trim.
	que verifica cada char de s1 e ret 1 se enc esse char.
	quando nao encontrar um char retorna 0 e o loop acaba, ficando i
	no inicio da string final.
3. o mesmo acontece no final da string, trim verifica cada char do ultimo
	para o primeiro. ficando n apontoda para o fim da string final.
4. malloc com o tamanho da string final n - i + 1.
5. copiar de i ate n e adicionar null terminator.

*/

static int	trim(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	n;
	size_t	a;
	char	*str;

	i = 0;
	n = ft_strlen (s1);
	if (s1 == NULL)
		return (NULL);
	while (s1[i] != '\0' && trim (s1[i], set) == 1)
		i++;
	while (n > i && trim (s1[n - 1], set) == 1)
		n--;
	str = malloc(n - i + 1);
	if (str == NULL)
		return (NULL);
	a = 0;
	while (i < n)
	{
		str[a] = s1[i];
		a++;
		i++;
	}
	str[a] = '\0';
	return (str);
}
/*
#include<stdio.h>
int main(void)
{
	char    s1[26] = "sasdleHello World!asasdel";
	char    set[6] = "sadle";
	char    *str;

	printf ("s1: %s\nset: %s\n", s1, set);
	str = ft_strtrim(s1, set);
	printf ("ft_strtrim: %s\n", str);
	free(str);
}*/
