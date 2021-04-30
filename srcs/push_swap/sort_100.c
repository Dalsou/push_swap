/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:21:04 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/30 16:42:13 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		find_smallest_rot(t_stack *a, t_stack *b)
{
	int		max_pos;
	int		min_pos;

	min_pos = find_min_pos(b);
	if (min_pos > b->size / 2)
		min_pos = b->size - min_pos;
	max_pos = find_max_pos(b);
	if (max_pos > b->size / 2)
		max_pos = b->size - min_pos;
	if (max_pos > min_pos)
	{
		if (find_min_pos(b) > b->size / 2)
			ft_rb(a, b, 1);
		else
			ft_rrb(a, b, 1); 
	}
	else
	{
		if (find_max_pos(b) > b->size / 2)
			ft_rb(a, b, 1);  
		else
			ft_rrb(a, b, 1); 
	}
}

static void		split_again(t_stack *a, t_stack *b)
{
	int		median;
	int		i;
	int		size;

	median = find_median(b);
	i = 0;
	size = b->size;
	while (i < size)
	{
		if (B_TOP > median)
		{
			ft_pa(a, b, 1);
		}
		else
			ft_rb(a, b, 1);
		i++;
	}
}

void		sort_back(t_stack *a, t_stack *b, int limit)
{
	int		pos;
	int		count;
	int		count_rot;

	pos = 0;
	count = 0;
	count_rot = 0;
	while (b->size > 20)
		split_again(a, b);
	while (b->size > 0)
	{
		if ((pos = can_be_move(b, find_min(b))) > 0)
		{
			if (pos == 2)
				ft_sb(a, b, 1);
			if (pos == 3)
				ft_rrb(a, b, 1);			
			ft_pa(a, b, 1);
			ft_ra(a, b, 1);
		}
		else if ((pos = can_be_move(b, find_max(b))) > 0)
		{
			if (pos == 2)
				ft_sb(a, b, 1);
			if (pos == 3)
				ft_rrb(a, b, 1);			
			ft_pa(a, b, 1);
			count_rot++;
		}
		else 
			find_smallest_rot(a, b);
	}
	while (count_rot > 0)
	{
		ft_ra(a, b, 1);
		count_rot--;
	}
	if (limit == find_min(a))
		while (A_TOP != limit)
			ft_pb(a, b, 1);
	else
		while (A_TOP <= limit)
			ft_pb(a, b, 1);
	if (b->size > 0)
		sort_back(a, b, limit);
}

void			sort_100_or_less(t_stack *a, t_stack *b)
{
	int		median;
	int		first_quart;
	int		last_quart;

	median = find_median(a);
	first_quart = find_fisrt_quart(a);
	split_median_on_b(a, b, find_median(a), first_quart);
	last_quart = find_median(a);
	while (B_TOP > first_quart)
		ft_pa(a, b, 1);
	sort_back(a, b, first_quart);
	while (A_TOP < median)
		ft_pb(a, b, 1);
	sort_back(a, b, median);
	// // half sorted
	split_median_on_b_2(a, b, last_quart, find_min(a));
	sort_back(a, b, last_quart);
	while (A_TOP != find_min(a))
		ft_pb(a, b, 1);
	sort_back(a, b, find_min(a));
	// while (A_TOP != find_min(a))
	// 	ft_ra(a, b, 1);
}

