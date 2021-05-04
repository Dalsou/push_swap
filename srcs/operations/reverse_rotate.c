/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:42:42 by afoulqui          #+#    #+#             */
/*   Updated: 2021/05/04 20:26:22 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a, t_stack *b, int print)
{
	int		i;
	int		tmp;

	(void)b;
	tmp = a->data[0];
	i = 0;
	while (i < a->size)
	{
		a->data[i] = a->data[i + 1];
		i++;
	}
	a->data[a->size - 1] = tmp;
	if (print == 1)
		ft_printf("rra\n");
}

void	ft_rrb(t_stack *a, t_stack *b, int print)
{
	int		i;
	int		tmp;

	(void)a;
	tmp = b->data[0];
	i = 0;
	while (i < b->size)
	{
		b->data[i] = b->data[i + 1];
		i++;
	}
	b->data[b->size - 1] = tmp;
	if (print == 1)
		ft_printf("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b, int print)
{
	ft_rra(a, b, 0);
	ft_rrb(a, b, 0);
	if (print == 1)
		ft_printf("rrr\n");
}
