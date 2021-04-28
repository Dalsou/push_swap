/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:12:49 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/28 10:19:11 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_order(t_stack *a, t_stack *b, int min, int max)
{
	int		top;
	
	top = a->size - 1;
	if (a_is_sorted(a) == 0)
		return;
	else if (a->data[top] > a->data[top - 1])
		ft_sa(a, b , 1);
	else if (b->size == 1 && b->data[0] < max)
		ft_pa(a, b, 1);
	else
		return;	
	return (check_order(a, b, min, max));
}

void	sort_lastnbr(t_stack *a, t_stack *b, int min, int max)
{
	int 	i;
	int		top;

	if (b->size > 0)
		ft_pa(a, b, 1);
	top = a->size - 1;
	if (a->data[top] > a->data[top - 1] && a->data[top] < a->data[top - 2])
		ft_sa(a, b, 1);
	else if (a->data[top] > a->data[0])
		ft_ra(a, b, 1);
	if (b->size > 0 && a_is_sorted(a) == 0)
		return (sort_lastnbr(a, b, min, max)); 
	else if (is_sorted(a, b) != 0)
	{
		ft_rra(a, b, 1);
		check_order(a, b, min, max);
		i = a->size;
		while (i > 0 && a->data[i - 1] > min)
			i--;
		while (i-- >= 0)
			ft_ra(a, b, 1);
		if (b->size > 0 && a_is_sorted(a) == 0)
			return (sort_lastnbr(a, b, min, max));
	}                                                                                                                                                                                                                                                                                                                                                                 
}

void	sort_3(t_stack *a, t_stack *b)
{
	int		i_min;
	int		i_max;

	i_min = 0;
	i_max = 0;
	find_min_max(a, &i_min, &i_max);
	if ((i_min == 1 && i_max == 0) || (i_min == 0 && i_max == 2) ||
		(i_min == 2 && i_max == 1))
	{
		if (b->size == 2 && b_is_sorted(b) == -1 &&
				b->data[0] < a->data[1] && b->data[1] < a->data[1])
			ft_ss(a, b, 1);
		else if (b->size == 2 && a_is_sorted(b) == -1)
			ft_ss(a, b, 1);
		else
			ft_sa(a, b, 1);
	}
	else if (i_min == 1 && i_max == 2)
		ft_ra(a, b, 1);
	else if (i_min == 0 && i_max == 1)
		ft_rra(a, b, 1);	
	if (a_is_sorted(a) == -1)
		return (sort_3(a, b));
}

void	sort_5(t_stack *a, t_stack *b)
{
	int		i;
	int		min;
	int		max;
	
	if (a->size == 2 && is_sorted(a, b) == -1)
	{
		ft_sa(a, b , 1);
		return;
	}
	i = a->size - 3;
	while (i > 0 && i <= a->size - 3)
	{
		ft_pb(a, b, 1);
		i--;
	}
	min = find_min(a);
	max = find_max(a);
	sort_3(a, b);
	if (b->size == 2 && b_is_sorted(b) == -1 &&
			b->data[0] < a->data[1] && b->data[1] < a->data[1])
		ft_sb(a, b, 1);
	else if (b->size == 2 && a_is_sorted(b) == -1)
		ft_sb(a, b, 1);
	if (b->size > 0)
		sort_lastnbr(a, b, min, max);
}