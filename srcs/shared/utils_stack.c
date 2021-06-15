/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:04:08 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 11:45:08 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack_b(t_stack **b, int size)
{
	*b = (t_stack *)malloc(sizeof(t_stack));
	(*b)->data = (int *)malloc(sizeof(int) * (size));
	if (!(*b) || !((*b)->data))
		return (-1);
	(*b)->size = 0;
	return (0);
}

void	free_allstacks(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

void	free_stack(t_stack **stack)
{
	if (*stack != NULL)
	{
		free((*stack)->data);
		free(*stack);
		*stack = NULL;
	}
}

void	free_exit(t_stack **a, t_stack **b, int *nbrs)
{
	if (nbrs != NULL)
		free(nbrs);
	free_allstacks(a, b);
	exit(-1);
}
