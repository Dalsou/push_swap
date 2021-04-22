/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:26:02 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/20 15:37:42 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			init_stack_a(char **args, t_stack **a, int size)
{
	int		i;
	int		nbr;

	i = size - 1;
	while (i >= 0)
	{
		nbr = ft_atoi(args[i]);
		if (nbr < INT_MAX && nbr > INT_MIN)
			(*a)->data[size - 1 - i] = nbr;
		else
			return (-1);
		i--;
	}
	(*a)->size = size;
	return (0);
}

bool			check_args(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if ((arg[0] != '-') && (!(ft_isdigit(arg[0]))))
			return (FALSE);
		if (i != 0 && !(ft_isdigit(arg[i])))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			parse_args(char **args, t_stack **a, int size)
{
	int i;
	int	j;

	if (!(*a = (t_stack*)malloc(sizeof(t_stack))))
		return (-1);
	if (!((*a)->data = (int*)malloc(sizeof(int) * (size))))
		return (-1);
	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[j])
		{
			if (i != j && ft_strncmp(args[i], args[j], 12) == 0)
				return (-1);
			j++;
		}
		if (check_args(args[i]) == FALSE)
			return (-1);
		i++;
	}
	if (init_stack_a(args, a, size) == -1)
		return (-1);
	return (0);
}