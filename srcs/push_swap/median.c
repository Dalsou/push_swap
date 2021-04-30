/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:46:37 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/30 16:43:12 by afoulqui         ###   ########.fr       */
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

int			find_fisrt_quart(t_stack *stack)
{
	int		*sorted;
	int		quart;
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
	quart = sorted[stack->size / 4];
	free(sorted);
	return (quart);
}

void		split_median_on_b(t_stack *a, t_stack *b, int median, int quart)
{
	int		i;
	int		size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if (A_TOP < median)
		{
			ft_pb(a, b, 1);
			if (B_TOP <= quart)
				ft_rb(a, b, 1);
		}
		else
			ft_ra(a, b, 1);
		i++;
	}
}

void		split_median_on_b_2(t_stack *a, t_stack *b, int quart, int stop)
{
	while (A_TOP > stop)
	{
		if (A_TOP < quart)
		{
			ft_pb(a, b, 1);
			if (B_TOP == find_min(b))
				ft_rb(a, b, 1);
		}
		else
			ft_ra(a, b, 1);	
	}
	while (A_LAST >= quart)
		ft_rra(a, b, 1);
}