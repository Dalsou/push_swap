/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:33:26 by afoulqui          #+#    #+#             */
/*   Updated: 2021/06/15 14:43:27 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_cmds(char *arg_cmd, t_cmds cmds[11])
{
	int		i;

	i = 0;
	while (i < 11 && arg_cmd)
	{
		if ((!ft_strncmp(arg_cmd, cmds[i].cmd, ft_strlen(arg_cmd)))
			&& ft_strlen(arg_cmd) == ft_strlen(cmds[i].cmd))
			return (i);
		i++;
	}
	return (-1);
}

void	init_cmds(t_cmds cmds[11])
{
	cmds[0].cmd = "sa";
	cmds[0].fct = &ft_sa;
	cmds[1].cmd = "sb";
	cmds[1].fct = &ft_sb;
	cmds[2].cmd = "ss";
	cmds[2].fct = &ft_ss;
	cmds[3].cmd = "pa";
	cmds[3].fct = &ft_pa;
	cmds[4].cmd = "pb";
	cmds[4].fct = &ft_pb;
	cmds[5].cmd = "ra";
	cmds[5].fct = &ft_ra;
	cmds[6].cmd = "rb";
	cmds[6].fct = &ft_rb;
	cmds[7].cmd = "rr";
	cmds[7].fct = &ft_rr;
	cmds[8].cmd = "rra";
	cmds[8].fct = &ft_rra;
	cmds[9].cmd = "rrb";
	cmds[9].fct = &ft_rrb;
	cmds[10].cmd = "rrr";
	cmds[10].fct = &ft_rrr;
}

int	exec_cmd(char *arg_cmd, t_stack *a, t_stack *b)
{
	t_cmds	cmds[11];
	int		i;

	init_cmds(cmds);
	i = check_cmds(arg_cmd, cmds);
	if (i == -1)
		return (-1);
	cmds[i].fct(a, b, 0);
	return (0);
}
