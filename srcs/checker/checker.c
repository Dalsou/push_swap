/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 22:42:37 by afoulqui          #+#    #+#             */
/*   Updated: 2021/05/04 20:23:34 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		checker(t_stack *a, t_stack *b)
{
	char	*cmd;
	int 	ret; 

	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(0, &cmd);
		if (exec_cmd(cmd, a, b) == -1 && cmd[0])
		{
			ft_strdel(&cmd);
			return (-1);
		}
		ft_strdel(&cmd);
	}
	return (0);
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
			init_stack_b(&b, argc - 1) == -1 ||
				checker(a, b) == -1)
	{
		free_allstacks(&a, &b);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	// display(a, b);
	if (is_sorted(a, b) == FALSE)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	free_allstacks(&a, &b);
	return (0);
}