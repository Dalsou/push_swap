/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:42:42 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/21 11:47:05 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, t_stack *b)
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
}

void	ft_rb(t_stack *a, t_stack *b)
{
	int		i;
	int		tmp;

	(void)a;
	tmp = b->data[0];
	i = 0;
	while (i < b->size)
	{
		b->data[i - 1] = b->data[i];
		i++;
	}
	b->data[b->size - 1] = tmp;
}

void	ft_rr(t_stack *a, t_stack *b)
{
	ft_ra(a, b);
	ft_rb(a, b);
}
