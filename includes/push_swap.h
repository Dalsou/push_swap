/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afoulqui <afoulqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 15:16:21 by afoulqui          #+#    #+#             */
/*   Updated: 2021/04/29 22:42:26 by afoulqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# include "libft.h"

# define A a->data
# define B b->data
# define A_TOP a->data[a->size - 1]
# define B_TOP b->data[b->size - 1]
# define A_SEC a->data[a->size - 2]
# define B_SEC b->data[b->size - 2]
# define A_LAST a->data[0]
# define B_LAST b->data[0]

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

int			checker(t_stack *a, t_stack *b);
int			parse_args(char **args, t_stack **stack_a, int size);
void		display(t_stack *a, t_stack *b);
void		init_cmds(t_cmds cmds[11]);
int			check_cmds(char *arg_cmd, t_cmds cmds[11]);
int			exec_cmd(char *arg_cmd, t_stack *a, t_stack *b);

/*
**	PUSH_SWAP
*/

void		push_swap(t_stack *a, t_stack *b);
int			find_min(t_stack *stack);
int			find_max(t_stack *stack);
int			find_median(t_stack *stack);
int			find_decile(t_stack *stack, int decile);
void		sort_5_or_less(t_stack *a, t_stack *b);
void		sort_100_or_less(t_stack *a, t_stack *b);
int			can_be_move(t_stack *stack, int nbr);
int			find_min_pos(t_stack *stack);
int			find_max_pos(t_stack *stack);

/*
**	SHARED
*/

bool		check_args(char *arg);
int			init_stack_a(char **args, t_stack **a, int size);
int			init_stack_b(t_stack **b, int size);
bool		is_sorted(t_stack *a, t_stack *b);
bool		b_is_sorted(t_stack *stack);
bool		a_is_sorted(t_stack *stack);
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