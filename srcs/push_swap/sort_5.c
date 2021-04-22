/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:12:49 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/22 11:07:07 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack *a, t_stack *b)
{
	int		i;

	if (a->size == 2)
		
	i = a->size - 3;
	while (i > 0 && i <= a->size - 3)
	{
		ft_pb(a, b);
		ft_printf("pb\n");
		i--;
	}
	if (b_is_sorted(b) == -1)
	{
		ft_sb(a, b);
		ft_printf("sb\n");
	}
	i = b->size;
	while (i > 0 && i <= b->size)
	{
		ft_pa(a, b);
		ft_printf("pa\n");
		i--;
	}
	if (is_sorted(a, b))
		return;
}