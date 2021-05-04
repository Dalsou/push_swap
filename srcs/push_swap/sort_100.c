/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:21:04 by afoulqui          #+#    #+#             */
/*   Updated: 2021/05/04 12:55:26 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		backtrack(t_stack *a, t_stack *b, int limit)
{
	while (A_TOP <= limit && A_TOP != find_min(a))
	{
		if (A_TOP == find_min_limit(a, find_min_pos(a))
				&& (A_TOP < find_min(b) || b->size == 0))
			ft_ra(a, b, 1);
		else
			ft_pb(a, b, 1);
	}
	if (find_min(b) < find_min_limit(a, find_min_pos(a)))
		sort_on_a(a, b);
}

static void		backtrack_split(t_stack *a, t_stack *b, int limit)
{
	int		median;
	int		count;
	int		i;

	count = 0;
	median = find_median_limit(a, b, find_min_pos(a));
	while (A_TOP <= limit && A_TOP != find_min(a))
	{
		if (A_TOP >= median)
		{
			ft_ra(a, b, 1);
			count++;
		}
		else
			ft_pb(a, b, 1);	
	}
	i = 0;
	while (i++ < count)
		if (B_TOP != find_max(b))
			ft_rrr(a, b, 1);
		else
			ft_rra(a, b, 1);
	if (find_min(b) < find_min_limit(a, find_min_pos(a)))
		sort_on_a(a, b);
}

void			sort_on_a(t_stack *a, t_stack *b)
{
	int		max;
	int		median;

	if (b->size == 0)
		return;
	max = find_max(b);
	median = find_median(b, a);
	split_on_a(a, b, median);
	while (A_TOP == find_min_limit(a, find_min_pos(a))
			&& (A_TOP < find_min(b) || b->size == 0))
		ft_ra(a, b, 1);
	sort_on_a(a, b);
	if (get_size(a, max) >= 20)
		backtrack_split(a, b, max);
	backtrack(a, b, max);
}

void			sort_500_or_less(t_stack *a, t_stack *b)
{
	int		max;
	
	split_on_b(a, b, find_median(a, b));
	sort_on_a(a, b);
	max = find_max(a);
	// if (get_size(a, max) >= 20)
	// {
	// 	backtrack_split(a, b, max);
	// 	backtrack_split(a, b, max);
	// }
	// backtrack(a, b, max);
}