/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:46:37 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/29 22:41:34 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_nbr(int *nbr, int len)
{
	int		i;
	int		tmp;

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

int				find_median(t_stack *stack)
{
	int		*sorted;
	int		median;
	int		i;

	sorted = (int*)malloc(sizeof(int) * (stack->size + 1));
	if (!sorted)
		return (-1);
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

int			find_decile(t_stack *stack, int decile)
{
	int		*sorted;
	int		res;
	int		i;
	sorted = (int*)malloc(sizeof(int) * (stack->size + 1));
	if (!sorted)
		return (-1);
	i = 0;
	while (i < stack->size)
	{
		sorted[i] = stack->data[i];
		i++;
	}
	sort_nbr(sorted, stack->size);
	res = sorted[(stack->size / 10) * decile];
	free(sorted); 
}