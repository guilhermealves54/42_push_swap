/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 00:40:57 by gribeiro          #+#    #+#             */
/*   Updated: 2025/03/20 17:01:52 by gribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Libs

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// Structs

typedef struct s_node
{
	int				nbr;
	int				idx;
	int				filled;
}	t_node;

// Checking functions 

int		ft_checkerrors(char **list);
int		sorted(t_node *st_a);

//	Operations

int		sortstack(t_node *st_a, t_node *st_b, int argc);
void	sa(t_node *stack);
void	rra(t_node *stack);
void	ra(t_node *stack);
void	pb(t_node *st_a, t_node *st_b);
void	pa(t_node *st_a, t_node *st_b);
void	rrr(t_node *st_a, t_node *st_b);
void	rr(t_node *st_a, t_node *st_b);
void	rb(t_node *stack);
void	rrb(t_node *stack);

// stack processing

int		calc_btarget(t_node *st_a, t_node *st_b, int target_a);
int		cost(t_node *st_a, t_node *st_b, int target_a, int target_b);
void	push_element(t_node *st_a, t_node *st_b, int min_a, int target_b);
int		calc_atarget(t_node *st_a, t_node *st_b, int target_b);
void	push_btoa(t_node *st_a, t_node *st_b, int target_a, int target_b);
int		org_a(t_node *st_a);
int		back_to_a(t_node *st_a, t_node *st_b);
void	push_up(t_node *st);

//	check elements in stack

int		fs_e(t_node *stack);
int		ls_e(t_node *stack);
int		minelem(t_node *stack);
int		maxelem(t_node *stack);
int		emptystack(t_node *stack);
int		stacksize(t_node *st_a);
int		sorted(t_node *st_a);

// lib functions

int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int n);

#endif