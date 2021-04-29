/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:44:15 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/29 21:50:17 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		can_be_move(t_stack *stack, int nbr)
{
	if (stack->data[stack->size - 1] == nbr)
		return (1);
	if (stack->data[stack->size - 2] == nbr)
		return (2);
	if (stack->data[0] == nbr)
		return (3);
	return (0);
}

int			find_min_pos(t_stack *stack)
{
	int		min;
	int		i;

	min = find_min(stack);
	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i] == min)
			break;
		i++;
	}
	return (i);
}

int			find_max_pos(t_stack *stack)
{
	int		max;
	int		i;

	max = find_max(stack);
	i = 0;
	while (i < stack->size)
	{
		if (stack->data[i] == max)
			break;
		i++;
	}
	return (i);
}