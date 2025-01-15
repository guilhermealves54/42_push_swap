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
		i = 0;
	return (i);
}

int		lastelem (t_node *stack)
{
	int 	i;

	i = 0;
	while (stack[i].index != -1)
		i++;
	while (stack[i].filled != 1 && i >= 0)
		i--;
	return (i);
}

int		minelem (t_node *stack)
{
	int 	i;
	int		min;
	int		minindex;

	i = firstelem (stack);
	min = stack[i].nbr;
	minindex = i;
	while (stack[i].index != -1)
	{
		if (stack[i].nbr < min && stack[i].filled == 1)
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

	i = firstelem (stack);
	max = stack[i].nbr;
	maxindex = i;
	while (stack[i].index != -1)
	{
		if (stack[i].nbr > max && stack[i].filled == 1)
		{
			max = stack[i].nbr;
			maxindex = i;
		}
		i++;
	}
	return (maxindex);
}

int		emptystack (t_node *stack)
{
	int i;

	i = 0;
	while (stack[i].index != -1)
	{
		if (stack[i].filled == 1)
			return (0);
		i++;
	}
	return (1);
}

int		stacksize(t_node *stack_a)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	while (stack_a[i].index != -1)
	{
		if (stack_a[i].filled == 1)
			res++;
		i++;
	}
	return (res);
}