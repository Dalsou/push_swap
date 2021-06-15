/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:26:25 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 11:11:23 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *a, t_stack *b, int print)
{
	if (b->size < 1)
		return ;
	a->size++;
	a->data[a->size - 1] = b->data[b->size - 1];
	b->size--;
	if (print == 1)
		ft_printf("pa\n");
}

void	ft_pb(t_stack *a, t_stack *b, int print)
{
	if (a->size < 1)
		return ;
	b->size++;
	b->data[b->size - 1] = a->data[a->size - 1];
	a->size--;
	if (print == 1)
		ft_printf("pb\n");
}
