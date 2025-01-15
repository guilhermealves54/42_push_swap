#include "push_swap.h"

static int ft_checkduplicates (char **list);

int	ft_checkerrors(char **list)
{
	int		i;
	int		n;

	i = 0;
	while (list[i])
	{
        n = 0;
        if (list[i][n] == '-' || list[i][n] == '+')
            n++;
        while (list[i][n])
        {
            if (ft_isdigit (list[i][n]) == 0)
                return (1);
            n++;
        }
        if (ft_atol (list[i]) > INT_MAX || ft_atol (list[i]) < INT_MIN)
            return (1);
        i++;
    }
    if (ft_checkduplicates (list))
        return (1);
    return (0);
}

static int ft_checkduplicates (char **list)
{
    int     i;
    int     n;

    i = 0;
    while (list[i])
    {
        n = 0;
        while (list[n])
        {
            if (n != i && (atol (list[i]) == atol (list[n])))
                return (1);
            n++;
        }
        i++;
    }
    return (0);
}
