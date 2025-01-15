#include "push_swap.h"

int		calc_btarget(t_node *stack_a, t_node *stack_b, int target_a)
{
	int		i;
	int		target_b;

	if (emptystack (stack_b) == 1)
		return (0);
	if (stack_a[target_a].nbr > stack_b[maxelem (stack_b)].nbr)
		return (maxelem (stack_b));
	else if (stack_a[target_a].nbr < stack_b[minelem (stack_b)].nbr)
		return (maxelem(stack_b));
	i = 0;
	target_b = minelem(stack_b);
	while (stack_b[i].index != -1)
	{
		if (stack_b[i].filled == 1)
		{
			if ((stack_b[i].nbr < stack_a[target_a].nbr 
				&& stack_b[i].nbr > stack_b[target_b].nbr))
					target_b = i;
		}
		i++;
	}
	return (target_b);
}

int		cost(t_node *stack_a, t_node *stack_b, int target_a, int target_b)
{
	int		median_a;
	int		median_b;
	int		mov_a;
	int		mov_b;

	median_a = ((stack_a[lastelem (stack_a)].index - stack_a[firstelem (stack_a)].index) / 2) + firstelem (stack_a);
	median_b = ((stack_b[lastelem (stack_b)].index - stack_b[firstelem (stack_b)].index) / 2) + firstelem (stack_b);
	if (stack_a[target_a].index <= stack_a[median_a].index)
		mov_a = stack_a[target_a].index - stack_a[firstelem (stack_a)].index;
	if (stack_a[target_a].index > stack_a[median_a].index)
		mov_a = (stack_a[lastelem (stack_a)].index - stack_a[target_a].index) + 1;
	mov_a++;
	if (emptystack (stack_b))
		return (mov_a);
	if (stack_b[target_b].index <= stack_b[median_b].index)
		mov_b = stack_b[target_b].index - stack_b[firstelem (stack_b)].index;
	if (stack_b[target_b].index > stack_b[median_b].index)
		mov_b = (stack_b[lastelem (stack_b)].index - stack_b[target_b].index) + 1;
	if (((stack_a[target_a].index <= stack_a[median_a].index 
			&& stack_b[target_b].index <= stack_b[median_b].index)
			|| (stack_a[target_a].index > stack_a[median_a].index
			&& stack_b[target_b].index > stack_b[median_b].index)) 
			&& stack_a[target_a].index != stack_a[firstelem (stack_a)].index)
	{
		if (mov_a > mov_b)
			return (mov_a + 1);
		else
			return (mov_b + 1);
	}
		return (mov_a + mov_b);
}


int		push_element(t_node *stack_a, t_node *stack_b, int min_a, int target_b)
{
	int		median_a;
	int		median_b;
	int		trgnum_a;
	int		trgnum_b;
	
	trgnum_a = stack_a[min_a].nbr;
	trgnum_b = stack_b[target_b].nbr;
	median_a = ((stack_a[lastelem (stack_a)].index - stack_a[firstelem (stack_a)].index) / 2) + firstelem (stack_a);
	median_b = ((stack_b[lastelem (stack_b)].index - stack_b[firstelem (stack_b)].index) / 2) + firstelem (stack_b);
	
	if ((stack_a[min_a].index <= stack_a[median_a].index
			&& stack_b[target_b].index <= stack_b[median_b].index) 
			&& (stack_a[min_a].nbr != stack_a[firstelem (stack_a)].nbr) 
			&& (stack_b[target_b].nbr != stack_b[firstelem (stack_b)].nbr))
	{
		while (stack_a[firstelem (stack_a)].nbr != trgnum_a && stack_b[firstelem (stack_b)].nbr != trgnum_b)
				rr (stack_a, stack_b);
	}
	if ((stack_a[min_a].index > stack_a[median_a].index
			&& stack_b[target_b].index > stack_b[median_b].index)
			&& (stack_a[min_a].nbr != stack_a[firstelem (stack_a)].nbr) 
			&& (stack_b[target_b].nbr != stack_b[firstelem (stack_b)].nbr))
	{
		while (stack_a[firstelem (stack_a)].nbr != trgnum_a && stack_b[firstelem (stack_b)].nbr != trgnum_b)
				rrr (stack_a, stack_b);
	}
	if (stack_a[min_a].index <= stack_a[median_a].index)
	{
		while (stack_a[firstelem (stack_a)].nbr != trgnum_a)
			ra (stack_a);
	}
	if (stack_a[min_a].index > stack_a[median_a].index)
	{
		while (stack_a[firstelem (stack_a)].nbr != trgnum_a)
			rra (stack_a);
	}	
	if (stack_b[target_b].index <= stack_b[median_b].index)
	{
		while (stack_b[firstelem (stack_b)].nbr != trgnum_b)
			rb (stack_b);
	}
	if (stack_b[target_b].index > stack_b[median_b].index)
	{
		while (stack_b[firstelem (stack_b)].nbr != trgnum_b)
			rrb (stack_b);
	}		
	if (stack_a[firstelem(stack_a)].nbr == trgnum_a && stack_b[firstelem (stack_b)].nbr == trgnum_b)
		pb (stack_a, stack_b);
	return (0);
}

int		calc_atarget (t_node *stack_a, t_node *stack_b, int target_b)
{
	int		i;
	int		target_a;

	if (stack_b[target_b].nbr > stack_a[maxelem (stack_a)].nbr)
		return (minelem (stack_a));
	else if (stack_b[target_b].nbr < stack_a[minelem (stack_a)].nbr)
		return (minelem(stack_a));
	i = 0;
	target_a = maxelem(stack_a);
	while (stack_a[i].index != -1)
	{
		if (stack_a[i].filled == 1)
		{
			if ((stack_a[i].nbr > stack_b[target_b].nbr 
				&& stack_a[i].nbr < stack_a[target_a].nbr))
					target_a = i;
		}
		i++;
	}
	return (target_a);
}

void	push_btoa(t_node *stack_a, t_node *stack_b, int target_a, int target_b)
{
	int		median_a;
	int		median_b;
	int		trgnum_a;
	int		trgnum_b;

	median_a = ((stack_a[lastelem (stack_a)].index - stack_a[firstelem (stack_a)].index) / 2) + firstelem (stack_a);
	median_b = ((stack_b[lastelem (stack_b)].index - stack_b[firstelem (stack_b)].index) / 2) + firstelem (stack_b);
	trgnum_a = stack_a[target_a].nbr;
	trgnum_b = stack_b[target_b].nbr;
	while (stack_a[firstelem (stack_a)].nbr != trgnum_a)
	{
		if (stack_a[target_a].index <= stack_a[median_a].index)
			ra (stack_a);
		else
			rra (stack_a);
	}
	while (stack_b[firstelem (stack_b)].nbr != trgnum_b)
	{
		if (stack_b[target_b].index <= stack_b[median_b].index)
			rb (stack_b);
		else
			rrb (stack_b);
	}	
	pa (stack_a, stack_b);
}

int		org_a (t_node *stack_a)
{
	int		min_a;
	int		min_i;
	int		median_a;

	min_a = stack_a[minelem (stack_a)].nbr;
	min_i = stack_a[minelem (stack_a)].index;
	median_a = ((stack_a[lastelem (stack_a)].index - stack_a[firstelem (stack_a)].index) / 2) + firstelem (stack_a);
	if (stack_a[min_i].index <= stack_a[median_a].index)
	{
		while (stack_a[firstelem (stack_a)].nbr != min_a)
			ra (stack_a);
	}
	else
		while (stack_a[firstelem (stack_a)].nbr != min_a)
			rra (stack_a);
	return (0);
}

int		back_to_a(t_node *stack_a, t_node *stack_b)
{
	int		target_a;
	int		i;

	i = 0;
	while (stack_b[i].index != -1)
	{
		if (stack_b[i].filled == 1)
		{
			target_a = calc_atarget (stack_a, stack_b, i);
			push_btoa (stack_a, stack_b, target_a, i);
		}
		i++;
	}
	org_a (stack_a);
	return (0);
}