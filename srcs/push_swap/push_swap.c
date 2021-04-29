/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 16:16:32 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/29 16:47:28 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	if (is_sorted(a, b) == FALSE)
	{
		if (a->size == 2)
			return (ft_sa(a, b , 1));
		else if (a->size <= 5)
			sort_5_or_less(a, b);
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack 	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if ((parse_args(&argv[1], &a, (argc - 1)) == -1) ||
			init_stack_b(&b, argc - 1) == -1)
	{
		free_allstacks(&a, &b);
		ft_putstr_fd("Error_push_swap\n", 2);
		return (1);
	}
	if (a->size > 1)
		push_swap(a, b);
	free_allstacks(&a, &b);
	return (0);
}