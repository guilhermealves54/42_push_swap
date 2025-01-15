#include "push_swap.h"

void	sa(t_node *stack)
{
	int 	temp;
	int		i;

	i = firstelem (stack);
	if (stack[i + 1].filled == 1)
	{
		temp = stack[i].nbr;
		stack[i].nbr = stack[i + 1].nbr;
		stack[i + 1].nbr = temp;
		write (1, "sa\n", 3);
	}
}

void	rra(t_node *stack)
{
	int		temp;
	int 	i;
	int 	min;

	min = firstelem (stack);
	i = lastelem (stack);
	temp = stack[i].nbr;
    while (i > min)
    {
        stack[i].nbr = stack[i - 1].nbr;
        i--;
    }
    stack[firstelem (stack)].nbr = temp;
	write (1, "rra\n", 4);
}

void	ra(t_node *stack)
{
	int		temp;
	int 	i;
	int 	max;

	max = lastelem (stack);
	i = firstelem (stack);
	temp = stack[i].nbr;
    while (i < max)
    {
        stack[i].nbr = stack[i + 1].nbr;
        i++;
    }
    stack[max].nbr = temp;
	write (1, "ra\n", 3);
}

void	rrb(t_node *stack)
{
	int		temp;
	int 	i;
	int 	min;

	min = firstelem (stack);
	i = lastelem (stack);
	temp = stack[i].nbr;
    while (i > min)
    {
        stack[i].nbr = stack[i - 1].nbr;
        i--;
    }
    stack[min].nbr = temp;
	write (1, "rrb\n", 4);
}
void	rb(t_node *stack)
{
	int		temp;
	int 	i;
	int 	max;

	max = lastelem (stack);
	i = firstelem (stack);
	temp = stack[i].nbr;
    while (i < max)
    {
        stack[i].nbr = stack[i + 1].nbr;
        i++;
    }
    stack[max].nbr = temp;
	write (1, "rb\n", 3);
}

void 	pb (t_node *stack_a, t_node *stack_b)
{
	int	i;

	i = 0;
	if (emptystack (stack_b))
	{
		stack_b[i].nbr = stack_a[firstelem (stack_a)].nbr;
		stack_b[i].filled = stack_a[firstelem (stack_a)].filled;
		stack_a[firstelem (stack_a)].nbr = 0;
		stack_a[firstelem (stack_a)].filled = 0;
	}
	else
	{
		i = lastelem (stack_b);
		while (stack_b[i].index >= stack_b[firstelem (stack_b)].index)
		{
			stack_b[i + 1].nbr = stack_b[i].nbr;
			stack_b[i + 1].filled = stack_b[i].filled;
			i--;
		}
		i = firstelem (stack_b) - 1;
		stack_b[i].nbr = stack_a[firstelem (stack_a)].nbr;
		stack_b[i].filled = 1;
		stack_a[firstelem (stack_a)].nbr = 0;
		stack_a[firstelem (stack_a)].filled = 0;
	}
	write(1, "pb\n", 3);
}

void 	pa (t_node *stack_a, t_node *stack_b)
{
	int	a;
	int	i;

	a = firstelem (stack_a);
	i = 0;
	if (stack_a[i].filled == 0)
	{
		while (stack_a[a].index != -1)
		{
			stack_a[i].nbr = stack_a[a].nbr;
			stack_a[i].filled = stack_a[a].filled;
			stack_a[a].filled = 0;
			stack_a[a].nbr = 0;
			a++;
			i++;
		}
	}
	i = lastelem (stack_a);
	while (stack_a[i].index >= stack_a[firstelem (stack_a)].index)
	{
		stack_a[i + 1].nbr = stack_a[i].nbr;
		stack_a[i + 1].filled = stack_a[i].filled;
		i--;
	}
	i = 0;
	stack_a[i].filled = 1;
	stack_a[0].nbr = stack_b[firstelem (stack_b)].nbr;
	stack_b[firstelem (stack_b)].nbr = 0;
	stack_b[firstelem (stack_b)].filled = 0;
	write(1, "pa\n", 3);
}

void	rr(t_node *stack_a, t_node *stack_b)
{
	int		temp;
	int 	i;
	int 	max;

	max = lastelem (stack_a);
	i = firstelem (stack_a);
	temp = stack_a[i].nbr;
    while (i < max)
    {
        stack_a[i].nbr = stack_a[i + 1].nbr;
        i++;
    }
    stack_a[max].nbr = temp;
	max = lastelem (stack_b);
	i = firstelem (stack_b);
	temp = stack_b[i].nbr;
    while (i < max)
    {
        stack_b[i].nbr = stack_b[i + 1].nbr;
        i++;
    }
    stack_b[max].nbr = temp;
	write (1, "rr\n", 3);
}

void	rrr(t_node *stack_a, t_node *stack_b)
{
	int		temp;
	int 	i;
	int 	min;

	min = firstelem (stack_a);
	i = lastelem (stack_a);
	temp = stack_a[i].nbr;
    while (i > min)
    {
        stack_a[i].nbr = stack_a[i - 1].nbr;
        i--;
    }
    stack_a[min].nbr = temp;

	min = firstelem (stack_b);
	i = lastelem (stack_b);
	temp = stack_b[i].nbr;
    while (i > min)
    {
        stack_b[i].nbr = stack_b[i - 1].nbr;
        i--;
    }
    stack_b[min].nbr = temp;
	write (1, "rrr\n", 4);
}