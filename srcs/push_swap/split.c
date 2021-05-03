/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:29:35 by afoulqui          #+#    #+#             */
/*   Updated: 2021/05/03 17:44:02 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		push_max_on_a(t_stack *a, t_stack *b)
{
	if (B_TOP == find_max(b))
		ft_pa(a, b, 1);
	else
	{
		if (B_TOP == find_min(b) && B_TOP < find_min_limit(a, find_min_pos(a)))
		{
			ft_pa(a, b, 1);
			ft_ra(a, b, 1);
		}
		else
			smallest_rot_b(a, b);
	}
}

void			split_on_a(t_stack *a, t_stack *b, int median)
{
	int		i;

	i = 0;
	while (i++ < b->size)
	{
		if (b->size < 13)
			push_max_on_a(a, b);
		else
		{
			if (B_TOP >= median)
				ft_pa(a, b, 1);
			else
			{
				if (B_TOP == find_min(b))
				{
					ft_pa(a, b, 1);
					ft_ra(a, b, 1);
				}
				else
					ft_rb(a, b, 1);
			}
		}
	}
}

void			split_on_b(t_stack *a, t_stack *b, int median)
{
	int		size;
	int		i;

	size = a->size;
	i = 0;
	while (i < size)
	{
		if (A_TOP < median)
			ft_pb(a, b, 1);
		else
			ft_ra(a, b, 1);
		i++;
	}
}