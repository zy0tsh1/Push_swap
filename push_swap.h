/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:26:37 by enja              #+#    #+#             */
/*   Updated: 2022/07/01 19:35:18 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_data{
	int	r;
	int	f;
	int	*arr;
	int	m;
}	t_data;

typedef struct t_lmk{
	int	idx;
	int	ndx;
	int	**bloc2;
}t_lmk;

typedef struct t_data2{
	int	**new_stack;
	int	size;
	int	idx;
	int	ndx;
}t_data2;

int		*arguments_scanner(int ac, char **ar);
void	error_msg(void);
int		string_comp_no_digits(char *str);
int		my_atoi(char *str);
int		string_len(char *str);
void	check_for_sorted(int *bloc, int ac);
int		tdm_arr_len(int **arr);
int		**arg_arr(int *bloc, int ac);
int		finished_check(int **stack);
int		**sort_args(int **stack, int ac);
int		**switching_args(int **stack_a, int **srt_stack, int ac);
int		next_check(int **stack, int len);
void	stack_swap(int **stack, int sign);
int		**stack_rotate(int **stack, int sign);
int		**stack_reverse_rotate(int **stack, int sign);
int		**stack_push(int **stack1, int **stack2);
int		**stack_pop(int **stack, int sign);
int		**sort_action_3_num(int **stack);
void	print_instractions(int sign);
int		**sort_action_5_num(int **stack_a, int **stack_b);
int		**sort_actions_for_5(int **stack_a, int **stack_b);
int		**sort_actions_for_4(int **stack_a, int **stack_b);
int		**sort_stack(int **stack_a, int **stack_b, int **stack_hold);
void	update_range(int **stack_a, int *max, int *min, int *mid);
int		**rotate_up(int **stack_a, int i, int sign);
int		**rotate_down(int **stack_a, int i, int sign);
int		**check_stack_b(int **stack_b, int mid);
int		**check_up_or_down(int **stack, int i);
int		smalest(int **stack);
int		smalest2(int **stack);
int		check_min_max(int **stack, int min, int max);
int		**sort_action_all(int **stack_a, int **stack_b);
int		**check_up_or_down_b(int **stack, int i);
int		**first_move_check(int **stack, int min, int max);
int		bigest(int **stack);
int		**stack_push_2(int **stack1, int **stack2);
int		**stack_pop_2(int **stack);
int		**stack_rotate_2(int **stack);
int		**stack_reverse_rotate_2(int **stack);

#endif