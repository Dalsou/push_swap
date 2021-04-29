/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 17:21:04 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/29 22:19:25 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		split_median_on_b(t_stack *a, t_stack *b, int median)
{
	int		i;
	int		size;

	i = 0;
	size = a->size;
	while (i < size)
	{
		if (A_TOP < median)
			ft_pb(a, b, 1);
		else
			ft_ra(a, b, 1);
		i++;
	}
}

static void		split_median_on_a(t_stack *a, t_stack *b, int median)
{
	int		i;
	int		size;

	i = 0;
	size = b->size;
	while (i < size)
	{
		if (B_TOP > median)
			ft_pa(a, b, 1);
		else
			ft_rb(a, b, 1);
		i++;
	}
}

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

static void		sort_back(t_stack *a, t_stack *b)
{
	int		pos;

	pos = 0;
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
		}
		else 
			find_smallest_rot(a, b);
	}
}

void			sort_100_or_less(t_stack *a, t_stack *b)
{
	int		median;
	int		first_quart;
	int		last_quart;

	median = find_median(a);
	split_median_on_b(a, b, find_median(a));
	first_quart = find_median(b);
	last_quart = find_median(a);
	split_median_on_a(a, b, find_median(b));
	sort_back(a, b);
	while (A_TOP < first_quart)
		ft_ra(a, b, 1);
	while (A_TOP < median)
		ft_pb(a, b, 1);
	sort_back(a, b);
	while (A_TOP < median)
		ft_ra(a, b, 1);
	while (A_TOP > find_min(a))
		ft_pb(a, b, 1);
	split_median_on_a(a, b, find_median(b));
	sort_back(a, b);
	while (A_TOP < last_quart)
		ft_ra(a, b, 1);
	while (A_TOP > find_min(a))
		ft_pb(a, b, 1);
	sort_back(a, b);
	while (A_TOP > find_min(a))
		ft_ra(a, b, 1);	
}