/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:12:27 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/22 11:23:21 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a, t_stack *b, int print)
{
	int		tmp;

	(void)b;
	if (a->size < 2)
		return;
	tmp = a->data[a->size - 1];
	a->data[a->size - 1] = a->data[a->size - 2];
	a->data[a->size - 2] = tmp;
	if (print == 1)
		ft_printf("sa\n");
}

void	ft_sb(t_stack *a, t_stack *b, int print)
{
	int		tmp;

	(void)a;
	if (b->size < 2)
		return;
	tmp = b->data[b->size - 1];
	b->data[b->size - 1] = b->data[b->size - 2];
	b->data[b->size - 2] = tmp;
	if (print == 1)
		ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b, int print)
{
	ft_sa(a, b, 0);
	ft_sb(a, b, 0);
	if (print == 1)
		ft_printf("ss\n");
}