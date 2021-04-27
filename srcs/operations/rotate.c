/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 19:15:35 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/22 15:29:12 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack *a, t_stack *b, int print)
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
	if (print == 1)
		ft_printf("ra\n");
}

void	ft_rb(t_stack *a, t_stack *b, int print)
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
	if (print == 1)
		ft_printf("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b, int print)
{
	ft_ra(a, b, 0);
	ft_rb(a, b, 0);
	if (print == 1)
		ft_printf("rr\n");
}
