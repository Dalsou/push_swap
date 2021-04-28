/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:54:48 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/27 11:51:47 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_index(t_stack *stack, int nbr)
{
	int		i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i] == nbr)
			return (i);
		i++;
	}
	return (i);
}

int		find_max(t_stack *stack)
{
	int		max;
	int		i;

	i = 0;
	max = stack->data[0];
	while (i < stack->size - 1)
	{
		if (max < stack->data[i + 1])
			max = stack->data[i + 1];
		i++;
	}
	return (max);
}

int		find_min(t_stack *stack)
{
	int		min;
	int		i;

	i = 0;
	min = stack->data[0];
	while (i < stack->size - 1)
	{
		if (min > stack->data[i + 1])
			min = stack->data[i + 1];
		i++;
	}
	return (min);
}

void	find_min_max(t_stack *stack, int *min_i, int *max_i)
{
	int		min;
	int		max;

	min = find_min(stack);
	max = find_max(stack);
	*min_i = find_index(stack, min);
	*max_i = find_index(stack, max);
}