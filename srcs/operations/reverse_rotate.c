/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:15:35 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/21 11:46:56 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, t_stack *b)
{
	int		i;
	int		tmp;

	(void)b;
	tmp = a->data[a->size - 1];
	i = a->size - 1;
	while (i > 0)
	{
		a->data[i] = a->data[i - 1];
		i--;
	}
	a->data[0] = tmp;
}

void	ft_rrb(t_stack *a, t_stack *b)
{
	int		i;
	int		tmp;

	(void)a;
	tmp = b->data[b->size - 1];
	i = b->size - 1;
	while (i > 0)
	{
		b->data[i] = b->data[i - 1];
		i--;
	}
	b->data[0] = tmp;
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	ft_rra(a, b);
	ft_rrb(a, b);
}
