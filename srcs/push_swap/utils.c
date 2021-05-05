/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:44:15 by afoulqui          #+#    #+#             */
/*   Updated: 2021/05/05 11:16:15 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void		smallest_rot_b(t_stack *a, t_stack *b)
{
	int		max_pos;

	max_pos = find_max_pos(b);
	if (b->size < 3)
		ft_sb(a, b, 1);
	else if (max_pos > b->size / 2)
		ft_rb(a, b, 1);
	else 
		ft_rrb(a, b, 1);
}

int			max_pos_size(t_stack *stack, int max)
{
	int		i;
	int		count;

	if (stack->size == 0)
		return (0);
	count = 0;
	i = stack->size - 1;
	while (stack->data[i] <= max)
	{
		count++;
		i--;
	}
	return (count);
}