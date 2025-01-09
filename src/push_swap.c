/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 00:50:30 by gribeiro          #+#    #+#             */
/*   Updated: 2025/01/09 03:32:29 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*fillfromstring(int argc, char **argv, t_node *stack_a, t_node *stack_b);
static t_node	*fillstack(int argc, char **argv, t_node *stack_a, t_node *stack_b);
static int		checkerrors(t_node *stack_a);
/*

	Verificações iniciais:
		ERRO se for passado apenas 1 argumento
		ERRO se forem 2 argumentos com string vazia
	
*/
int		main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	
	// caso não sejam atribuidos args ou atrib string vazia.
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	// se os valor forem dados com string
	if (argc == 2)
		fillfromstring (argc, argv, stack_a, stack_b);
	// se os valor forem dados com varios args
	if (argc > 2)
		fillstack (argc, argv, stack_a, stack_b);
	// verificar erros
	if (checkerrors (stack_a) != 0)
		return (1); // libertar lista
	return (0);
}

static t_node	*fillstack(int argc, char **argv, t_node *stack_a, t_node *stack_b)
{
	stack_a = ft_calloc (argc, sizeof(t_node));
	if (stack_a == NULL)
		return (NULL);
	stack_b = ft_calloc (argc, sizeof(t_node));
	if (stack_b == NULL)
		return (NULL);
	while (argc > 1)
	{
		
	}
	return (stack_a);
}
static t_node	*fillfromstring(int argc, char **argv, t_node *stack_a, t_node *stack_b)
{
	
}

static int	checkerrors(t_node *stack_a)
{
	return (0);
}