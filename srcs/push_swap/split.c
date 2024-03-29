/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:29:35 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 11:36:52 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_on_a_little(t_stack *a, t_stack *b)
{
	if (b->data[b->size - 1] == find_max(b))
		ft_pa(a, b, 1);
	else if (b->data[b->size - 1] == find_min(b)
		&& b->data[b->size - 1] < find_min_limit(a))
	{
		ft_pa(a, b, 1);
		ft_ra(a, b, 1);
	}
	else
		smallest_rot_b(a, b);
}

void	split_on_a(t_stack *a, t_stack *b)
{
	int	i;
	int	size;
	int	median;

	i = 0;
	size = b->size;
	median = find_median(b, a);
	while (i++ < size)
	{
		if (size < 20)
			split_on_a_little(a, b);
		else
		{
			if (b->data[b->size - 1] >= median)
				ft_pa(a, b, 1);
			else if (b->data[b->size - 1] == find_min(b))
			{
				ft_pa(a, b, 1);
				ft_ra(a, b, 1);
			}
			else
				ft_rb(a, b, 1);
		}
	}
}

void	split_on_b(t_stack *a, t_stack *b)
{
	int	median;
	int	size;
	int	i;

	median = find_median(a, b);
	size = a->size;
	i = 0;
	while (i < size)
	{
		if (a->data[a->size - 1] < median)
			ft_pb(a, b, 1);
		else
			ft_ra(a, b, 1);
		i++;
	}
}
