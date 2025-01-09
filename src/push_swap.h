/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 00:40:57 by gribeiro          #+#    #+#             */
/*   Updated: 2025/01/09 18:10:35 by gribeiro         ###   ########.fr       */
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
	int				order;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

// Functions

long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int n);
int		ft_checkerrors(char **list, int argc);

#endif