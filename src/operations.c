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
    stack[min].nbr = temp;
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