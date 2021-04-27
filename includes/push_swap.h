/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:16:21 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/22 16:25:09 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# include "libft.h"

typedef struct	s_stack
{
	int			*data;
	int 		size;
}				t_stack;

typedef struct s_cmds
{
	char		*cmd;
	void		(*fct)(t_stack *a, t_stack *b, int print);
}				t_cmds;

/*
**	CHECKER
*/

int			parse_args(char **args, t_stack **stack_a, int size);
void		display(t_stack *a, t_stack *b);
int			exec_cmd(char *arg_cmd, t_stack *a, t_stack *b);

/*
**	PUSH_SWAP
*/

void		push_swap(t_stack *a, t_stack *b);
void		sort_5(t_stack *a, t_stack *b);
void		op_and_print(char *cmd, t_stack *a, t_stack *b);
void		init_cmds(t_cmds cmds[11]);
int			check_cmds(char *arg_cmd, t_cmds cmds[11]);
void		find_min_max(t_stack *stack, int *min_i, int *max_i);
int			find_index(t_stack *stack, int nbr);
void		sort_3(t_stack *a, t_stack *b);
void		sort_lastnbr(t_stack *a, t_stack *b);
void		check_order(t_stack *a, t_stack *b);

/*
**	SHARED
*/

bool		check_args(char *arg);
int			init_stack_a(char **args, t_stack **a, int size);
int			init_stack_b(t_stack **b, int size);
int			checker(t_stack *a, t_stack *b);
int			is_sorted(t_stack *a, t_stack *b);
int			b_is_sorted(t_stack *stack);
int			a_is_sorted(t_stack *stack);
void		free_stack(t_stack **stack);
void		free_allstacks(t_stack **a, t_stack **b);

/*
**	OPERATIONS
*/

void		ft_sa(t_stack *a, t_stack *b, int print);
void		ft_sb(t_stack *a, t_stack *b, int print);
void		ft_ss(t_stack *a, t_stack *b, int print);
void		ft_pa(t_stack *a, t_stack *b, int print);
void		ft_pb(t_stack *a, t_stack *b, int print);
void		ft_ra(t_stack *a, t_stack *b, int print);
void		ft_rb(t_stack *a, t_stack *b, int print);
void		ft_rr(t_stack *a, t_stack *b, int print);
void		ft_rra(t_stack *a, t_stack *b, int print);
void		ft_rrb(t_stack *a, t_stack *b, int print);
void		ft_rrr(t_stack *a, t_stack *b, int print);

#endif