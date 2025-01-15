#include "push_swap.h"

static void	sort3(t_node *stack)
{
	while (!sorted (stack))
	{
		if (stack[firstelem (stack)].nbr == stack[maxelem (stack)].nbr)
			ra (stack);
		else if (stack[lastelem (stack)].nbr == stack[maxelem (stack)].nbr)
			sa (stack);
		else
			rra (stack);
	}
}

static int 	biggersort (t_node *stack_a, t_node *stack_b)
{
	int min_a;
	int min_b;
	int target_b;
	int min_cost;
	int temp_cost;
	int i;

	pb (stack_a, stack_b);	
	pb (stack_a, stack_b);
	while (stacksize(stack_a) > 3)
	{
		i = firstelem (stack_a);
		target_b = calc_btarget (stack_a, stack_b, i);
		min_cost = cost (stack_a, stack_b, i, target_b);
		while (stack_a[i].index != -1)
		{
			target_b = calc_btarget (stack_a, stack_b, i);
			temp_cost = cost (stack_a, stack_b, i, target_b);
			if (stack_a[i].filled == 1)
			{
				target_b = calc_btarget (stack_a, stack_b, i);
				temp_cost = cost (stack_a, stack_b, i, target_b);
				if (temp_cost <= min_cost)
				{
					min_cost = temp_cost;
					min_a = i;
					min_b = target_b;
				}
			}
			i++;
		}
		push_element (stack_a, stack_b, min_a, min_b);
	}
	sort3 (stack_a);
	return (back_to_a (stack_a, stack_b));
}

int		sortstack(t_node *stack_a, t_node *stack_b, int argc)
{
	if (argc == 3)
		return (sa (stack_a), 0);
	if (argc == 4)
		return (sort3 (stack_a), 0);
	else
		return (biggersort (stack_a, stack_b));
	return (0);
}

int		sorted(t_node *stack_a)
{
	int		i;

	i = 1;
	while (stack_a[i].index != -1)
	{
		if (stack_a[i].nbr < stack_a[i - 1].nbr)
			return (0);
		i++;
	}
	return (1);
}
