/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:44:26 by gribeiro          #+#    #+#             */
/*   Updated: 2024/11/11 17:26:19 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

Qd malloc atribui um bloco de memória nao alt o conteudo desses bytes.
A ideia da func calloc é atribuir x bytes com malloc e dps apagar
o conteudo desses bytes, atribuindo-lhes 0.

1. definir um pointer temporário.
2. atribuit memoria com malloc.
3. se malloc falhar a função retorna NULL.
4. loop que percorre o bloco de mem byte a byte e atribui 0 a cada um.
5. retorna o ponteiro para o inicio do bloco de memória atribuido.

*/

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
/*
#include<stdio.h>
int main(void)
{
    void    *ptrcalloc;
    void    *ptrmalloc;
    size_t  i;

    i = 0;
    ptrcalloc = ft_calloc (2, 4);
    ptrmalloc = malloc (2 * 4);
    printf ("Resultado ft_calloc: ");
    while (i < 8)
    {
        printf ("%c ", ((char *)ptrcalloc)[i] + 48);
        i++;
    }
    printf ("\nResultado malloc: ");
    while (i < 8)
    {
        printf ("%c ", ((char *)ptrmalloc)[i] + 48);
        i++;
    }
    free(ptrcalloc);
    free(ptrmalloc);
}*/
