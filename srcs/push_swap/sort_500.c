/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:21:04 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 11:34:02 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_last_nbrs(t_stack *a, t_stack *b, int max)
{
	while (a->data[a->size - 1] <= max && a->data[a->size - 1] != find_min(a))
	{
		if (a->data[a->size - 1] == find_min_limit(a)
			&& (a->data[a->size - 1] < find_min(b) || b->size == 0))
			ft_ra(a, b, 1);
		else
			ft_pb(a, b, 1);
	}
	if (find_min(b) < find_min_limit(a))
		sort_on_a(a, b);
}

static void	split_again(t_stack *a, t_stack *b, int max)
{
	int	median;
	int	count;

	count = 0;
	median = find_median_limit(a, b);
	while (a->data[a->size - 1] <= max && a->data[a->size - 1] != find_min(a))
	{
		if (a->data[a->size - 1] >= median)
		{
			ft_ra(a, b, 1);
			count++;
		}
		else
			ft_pb(a, b, 1);
	}
	while (count-- > 0)
	{
		if (b->data[b->size - 1] != find_max(b))
			ft_rrr(a, b, 1);
		else
			ft_rra(a, b, 1);
	}
	if (find_min(b) < find_min_limit(a))
		sort_on_a(a, b);
}

void	sort_on_a(t_stack *a, t_stack *b)
{
	int	max;

	if (b->size == 0)
		return ;
	max = find_max(b);
	split_on_a(a, b);
	while (a->data[a->size - 1] == find_min_limit(a) && b->size == 0)
		ft_ra(a, b, 1);
	sort_on_a(a, b);
	if (max_pos_size(a, max) > 20)
		split_again(a, b, max);
	sort_last_nbrs(a, b, max);
}

void	sort_500_or_less(t_stack *a, t_stack *b)
{
	int	max;

	split_on_b(a, b);
	sort_on_a(a, b);
	max = find_max(a);
	if (max_pos_size(a, max) > 20)
	{
		split_again(a, b, max);
		split_again(a, b, max);
	}
	sort_last_nbrs(a, b, max);
}
