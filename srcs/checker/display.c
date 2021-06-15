/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 14:44:28 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 11:07:30 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display(t_stack *a, t_stack *b)
{
	int	i;

	ft_printf("\n\n");
	if (a->size > b->size)
		i = a->size - 1;
	else
		i = b->size - 1;
	while (i >= 0)
	{
		if (i > a->size - 1)
			ft_printf("\t|  %s  |\t|  %d  |\n", " ", b->data[i]);
		else if (i > b->size - 1)
			ft_printf("\t|  %d  |\t|  %s  |\n", a->data[i], " ");
		else
			ft_printf("\t|  %d  |\t|  %d  |\n", a->data[i], b->data[i]);
		i--;
	}
	ft_printf("\n\t%4s\t%4s\n\n", "a", "b");
}
