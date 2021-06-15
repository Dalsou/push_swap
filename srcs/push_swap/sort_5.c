/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:34:17 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 11:23:10 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_one_on_b(t_stack *a, t_stack *b, int min, int max)
{
	if (b->size == 1 && b->data[b->size - 1] == min)
		min = find_min(a);
	if (a->data[a->size - 1] == min || a->data[a->size - 1] == max)
		return (ft_pb(a, b, 1));
	else if (a->data[0] == min || a->data[0] == max)
		ft_rra(a, b, 1);
	else if (a->data[a->size - 2] == min || a->data[a->size - 2] == max)
		ft_sa(a, b, 1);
	else
	{
		ft_ra(a, b, 1);
		ft_ra(a, b, 1);
	}
	ft_pb(a, b, 1);
}

static void	sort_3(t_stack *a, t_stack *b)
{
	if (a->data[a->size - 1] == find_max(a)
		&& a->data[a->size - 2] == find_min(a))
		ft_ra(a, b, 1);
	else
	{
		while (a_is_sorted(a) == FALSE)
		{
			if (a->data[a->size - 2] == find_max(a))
				ft_rra(a, b, 1);
			else
				ft_sa(a, b, 1);
		}
	}
}

void	sort_5_or_less(t_stack *a, t_stack *b)
{
	int	min;
	int	max;

	min = find_min(a);
	max = find_max(a);
	while (a->size > 3)
		push_one_on_b(a, b, min, max);
	if (a_is_sorted(a) == FALSE)
		sort_3(a, b);
	while (b->size > 0)
	{
		ft_pa(a, b, 1);
		if (a->data[a->size - 1] == max)
			ft_ra(a, b, 1);
	}
}
