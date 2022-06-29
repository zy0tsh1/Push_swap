/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enja <enja@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 03:59:31 by enja              #+#    #+#             */
/*   Updated: 2022/06/29 18:37:56 by enja             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	**stack_push(int **stack1, int **stack2)
{
	t_data2	dt;
	t_data2	*ptr;

	ptr = &dt;
	ptr->ndx = 0;
	ptr->idx = 0;
	ptr->size = tdm_arr_len(stack1) + 2;
	ptr->new_stack = malloc(ptr->size * sizeof(int *));
	ptr->new_stack[ptr->size - 1] = NULL;
	ptr->new_stack[ptr->idx] = stack2[ptr->idx];
	if (tdm_arr_len(stack1) == 0)
	{
		free(stack1);
		stack1 = ptr->new_stack;
		return (stack1);
	}
	ptr->idx++;
	while (ptr->idx < ptr->size - 1)
		ptr->new_stack[ptr->idx++] = stack1[ptr->ndx++];
	ptr->new_stack[ptr->idx] = NULL;
	free(stack1);
	stack1 = ptr->new_stack;
	return (stack1);
}

int	**stack_pop(int **stack, int sign)
{
	int	a;
	int	size;
	int	**stack_pop;
	int	m;

	a = 0;
	m = 1;
	size = tdm_arr_len(stack);
	if (size == 0)
	{
		free(stack);
		stack = malloc(1 * sizeof(int *));
		stack[0] = NULL;
		return (stack);
	}
	stack_pop = malloc(size * sizeof(int *));
	while (a < size)
		stack_pop[a++] = stack[m++];
	free(stack);
	stack = stack_pop;
	print_instractions(sign);
	return (stack);
}

void	stack_swap(int **stack, int sign)
{
	int		idx;
	int		*ptr;

	idx = 0;
	ptr = stack[idx];
	stack[idx] = stack[idx + 1];
	stack[idx + 1] = ptr;
	print_instractions(sign);
}

int	**stack_rotate(int **stack, int sign)
{
	int		**handl_stack;
	int		idx;
	int		size;

	idx = 1;
	size = tdm_arr_len(stack) + 1;
	handl_stack = malloc(size * sizeof(int *));
	size = 0;
	while (stack[idx] != NULL)
	{
		handl_stack[size] = stack[idx];
		idx++;
		size++;
	}
	handl_stack[idx] = NULL;
	handl_stack[idx - 1] = stack[0];
	free(stack);
	stack = handl_stack;
	print_instractions(sign);
	return (stack);
}

int	**stack_reverse_rotate(int	**stack, int sign)
{
	int		**handl_stack;
	int		idx;
	int		ndx;
	int		size;

	idx = 1;
	ndx = 0;
	size = tdm_arr_len(stack) + 1;
	handl_stack = malloc(size * sizeof(int *));
	while (idx < size - 1)
	{
		handl_stack[idx] = stack[ndx];
		idx++;
		ndx++;
	}
	handl_stack[idx] = NULL;
	handl_stack[0] = stack[idx - 1];
	free(stack);
	stack = handl_stack;
	print_instractions(sign);
	return (stack);
}
