#include "push_swap.h"

int		firstelem (t_node *stack)
{
	int 	i;

	i = 0;
	while (stack[i].index != -1)
	{
		if (stack[i].filled == 1)
			return (i);
		i++;
	}
	if (stack[i].index == -1)
		i--;
	return (i);
}

int		lastelem (t_node *stack)
{
	int 	i;

	i = 0;
	while (stack[i].index != -1)
		i++;
	while (stack[i].filled != 1)
		i--;
	return (i);
}

int		minelem (t_node *stack)
{
	int 	i;
	int		min;
	int		minindex;

	i = 0;
	min = stack[i].nbr;
	minindex = i;
	while (stack[i].index != -1)
	{
		if (stack[i].nbr < min)
		{
			min = stack[i].nbr;
			minindex = i;
		}
		i++;
	}
	return (minindex);
}

int		maxelem (t_node *stack)
{
	int 	i;
	int		max;
	int		maxindex;

	i = 0;
	max = stack[i].nbr;
	maxindex = i;
	while (stack[i].index != -1)
	{
		if (stack[i].nbr > max)
		{
			max = stack[i].nbr;
			maxindex = i;
		}
		i++;
	}
	return (maxindex);
}