/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gribeiro <gribeiro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 00:40:57 by gribeiro          #+#    #+#             */
/*   Updated: 2025/01/09 02:54:17 by gribeiro         ###   ########.fr       */
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

int		ft_atoi(const char *str);
char	**ft_split(const char *s, char c);
void	*ft_calloc(size_t count, size_t size);


#endif