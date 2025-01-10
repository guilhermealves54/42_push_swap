#include "push_swap.h"

static int	sort3(t_node *stack)
{
	if (stack[firstelem (stack)].nbr == stack[maxelem (stack)].nbr)
	{
		if (stack[lastelem (stack)].nbr == stack[minelem (stack)].nbr)
		{
			sa (stack);
			return (rra (stack), 0);
		}
		return (ra (stack), 0);
	}
	else if (stack[firstelem (stack)].nbr == stack[minelem (stack)].nbr)
	{
		rra (stack);
		return (sa (stack), 0);
	}
	else
	{
		if (stack[lastelem (stack)].nbr == stack[minelem (stack)].nbr)
			return (rra (stack), 0);
		return (sa (stack), 0);
	}
}

void 	pb (t_node *stack_a, t_node *stack_b)
{
	int		i;
	int		n;
	int		last;

	i = firstelem (stack_a);
	n = firstelem (stack_b);
	last = lastelem (stack_b);
	if (stack_a[i].filled == 1)
	{
		if (n > 0)
		{
			stack_b[n - 1].nbr = stack_a[i].nbr;
			stack_b[n - 1].filled = 1;
			stack_a[i].nbr = 0;
			stack_a[i].filled = 0;
		}
		else
		{
			stack_b[last + 1].filled = 1;
			while (last > n)
			{
				stack_b[last + 1].nbr = stack_b[last].nbr;
				last--;
			}
			stack_b[last].nbr = stack_a[i].nbr;
			stack_a[i].filled = 0;
			stack_a[i].nbr = 0;
		}
		write (1, "pb\n", 3);
	}
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

int		calc_btarget (t_node *stack_a, t_node *stack_b, int i)
{
	int		n;
	int		pos_max;
	int		pos_min;

	// se i for maior que o maximo numero tem de ficar por cima.
	// se i for menor que o minimo numero tem de ficar por baixo.
	if (stack_a[i].nbr > stack_b[maxelem (stack_b)].nbr)
		return (maxelem (stack_b));
	else if (stack_a[i].nbr < stack_b[minelem (stack_b)].nbr)
		return (maxelem (stack_b));
	//se i for um valor intermedio tem de ficar no meio
	//encontrar menor valor do stack b que esta mais proximo do valor ref.
	n = 0;
	pos_min = minelem (stack_b);
	while (stack_b[n].index != -1)
	{
		if (stack_b[n].nbr < stack_a[i].nbr)
		{
			if (stack_b[n].nbr > stack_b[pos_min].nbr)
				pos_min = n;
		}
		n++;
	}
	//o target e o valor maior mais proximo. o index podera ser colocado por cima.
}

int		cost(t_node *stack_a, t_node *stack_b, int i)
{
	int		mov_a;
	int		mov_b;
	int		b_target;
	int		direction;

	direction = 0;
	if (i > (stacksize (stack_a) / 2))
		mov_a = stacksize (stack_a) - i;
	else
		mov_a = i;
	b_target = calc_btarget (stack_a, stack_b, i);
	if (b_target > (stacksize (stack_b) / 2))
		mov_b = stacksize (stack_b) - b_target;
	else
		mov_b = b_target;
	// falta calcular direcao movimento para calcular movimentos conjuntos
	return (mov_a + mov_b);
}

static int 	biggersort (t_node *stack_a, t_node *stack_b)
{
	int		min_cost;
	int		min_i;
	int		i;

	pb (stack_a, stack_b);
	pb (stack_a, stack_b);
	while (stacksize(stack_a) > 0)
	{
		min_i = 0;
		i = 0;
		min_cost = cost (stack_a, stack_b, i);
		while (i < (stacksize(stack_a) / 2))
		{
			if (cost (stack_a, stack_b, i) < min_cost)
			{
				min_cost = cost (stack_a, stack_b, i);
				min_i = i;
			}
			i++;
		}
		push_element (stack_a, stack_b, min_i);
	}
	return (0);
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