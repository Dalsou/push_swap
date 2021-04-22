/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:11:38 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/22 10:45:43 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		b_is_sorted(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int		a_is_sorted(t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[i] < stack->data[i + 1])
			return (-1);
		i++;
	}
	return (0);
}

int		is_sorted(t_stack *a, t_stack *b)
{
	int		i;

	if (b->size != 0)
		return (-1);
	i = 0;
	while (i < a->size - 1)
	{
		if (a->data[i] < a->data[i + 1])
			return (-1);
		i++;
	}
	return (0);
}