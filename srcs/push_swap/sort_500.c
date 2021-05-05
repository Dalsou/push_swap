/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:21:04 by afoulqui          #+#    #+#             */
/*   Updated: 2021/05/05 11:38:29 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		sort_last_nbrs(t_stack *a, t_stack *b, int max)
{
	while (A_TOP <= max && A_TOP != find_min(a))
	{
		if (A_TOP == find_min_limit(a) && (A_TOP < find_min(b) || b->size == 0))
			ft_ra(a, b, 1);
		else
			ft_pb(a, b, 1);
	}
	if (find_min(b) < find_min_limit(a))
		sort_on_a(a, b);
}

static void		split_again(t_stack *a, t_stack *b, int max)
{
	int		median;
	int		count;
	int		i;

	count = 0;
	median = find_median_limit(a, b);
	while (A_TOP <= max && A_TOP != find_min(a))
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
	if (find_min(b) < find_min_limit(a))
		sort_on_a(a, b);
}

void			sort_on_a(t_stack *a, t_stack *b)
{
	int		max; 

	if (b->size == 0)
		return;
	max = find_max(b);
	split_on_a(a, b);
	while (A_TOP == find_min_limit(a) && b->size == 0)
		ft_ra(a, b, 1);
	sort_on_a(a, b);
	if (max_pos_size(a, max) > 20)
		split_again(a, b, max);
	sort_last_nbrs(a, b, max);
}

void			sort_500_or_less(t_stack *a, t_stack *b)
{
	int		max;
	
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