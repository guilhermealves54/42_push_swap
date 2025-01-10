/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 00:40:57 by gribeiro          #+#    #+#             */
/*   Updated: 2025/01/10 02:05:01 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libs

# include<stdlib.h>
# include<unistd.h>
# include<limits.h>
# include<stdio.h> //apagar

// Structs

typedef struct s_node
{
	int				nbr;
	int				index;
	int				filled;
}	t_node;

// Checking functions 

int		ft_checkerrors(char **list, int argc);
int		sorted (t_node *stack_a);

//	Sorting and operation functions

int		sortstack (t_node *stack_a, t_node *stack_b, int argc);
void	sa(t_node *stack);
void 	rra(t_node *stack);
void	ra(t_node *stack);

//	Functions to check elements in a stack

int		firstelem (t_node *stack);
int		lastelem (t_node *stack);
int		minelem (t_node *stack);
int		maxelem (t_node *stack);

// lib functions

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int n);

#endif