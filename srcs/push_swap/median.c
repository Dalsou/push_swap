/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:46:37 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 11:17:44 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_nbr(int *nbr, int len)
{
	int	i;
	int	tmp;

	tmp = nbr[0];
	i = 0;
	while (i < len - 1)
	{
		if (nbr[i] <= nbr[i + 1])
			i++;
		else
		{
			tmp = nbr[i];
			nbr[i] = nbr[i + 1];
			nbr[i + 1] = tmp;
			i = 0;
		}
	}
}

int	find_median(t_stack *stack, t_stack *stack2)
{
	int	*sorted;
	int	median;
	int	i;

	sorted = (int *)malloc(sizeof(int) * (stack->size + 1));
	if (!sorted)
		free_exit(&stack, &stack2, sorted);
	i = 0;
	while (i < stack->size)
	{
		sorted[i] = stack->data[i];
		i++;
	}
	sort_nbr(sorted, stack->size);
	median = sorted[stack->size / 2];
	free(sorted);
	return (median);
}

int	find_median_limit(t_stack *stack, t_stack *stack2)
{
	int	*sorted;
	int	median;
	int	size;
	int	i;
	int	j;

	i = stack->size - 1;
	size = 0;
	while (i > find_min_pos(stack) && i >= 0)
	{
		size++;
		i--;
	}
	sorted = (int *)malloc(sizeof(int) * (size + 1));
	if (!sorted)
		free_exit(&stack, &stack2, sorted);
	i = stack->size - 1;
	j = 0;
	while (i > find_min_pos(stack) && i >= 0)
		sorted[j++] = stack->data[i--];
	sort_nbr(sorted, size);
	median = sorted[size / 2];
	free(sorted);
	return (median);
}
