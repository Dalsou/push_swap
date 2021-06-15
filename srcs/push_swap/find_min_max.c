/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 11:54:48 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 11:15:13 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *stack)
{
	int	max;
	int	i;

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

int	find_min(t_stack *stack)
{
	int	min;
	int	i;

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

int	find_min_limit(t_stack *stack)
{
	int	limit;
	int	min;
	int	i;

	limit = find_min_pos(stack);
	i = limit + 1;
	min = stack->data[limit + 1];
	while (i < stack->size - 1)
	{
		if (min > stack->data[i + 1])
			min = stack->data[i + 1];
		i++;
	}
	return (min);
}
