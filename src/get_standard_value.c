/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_standard_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:56:43 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/24 18:01:14 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_standard_value(t_struct *data)
{
	data->max_num = data->s.stack[data->total_size - 1];
	data->min_num = data->s.stack[0];
	// data->middle_index = data->total_size / 2;
	data->middle_index = data->total_size -  data->total_size / 2;
	// data->middle_index2 = data->total_size / 2;
	data->index_1_4 = data->middle_index - data->middle_index / 2;
	data->index_3_4 = data->total_size - data->index_1_4;
	data->index_1_8 = data->index_1_4 - data->index_1_4 / 2;
	data->middle_num = data->s.stack[data->middle_index];
	data->sorted_index = 0;
	// printf("m = %d\n", data->middle_num);
	// printf("mi = %d\n", data->middle_index);

}

// void	get_standard_value_3(t_stack *stack)
// {
// 	int	i;

// 	i = 0;
// 	stack->max_num = stack->stack[0];
// 	stack->min_num = stack->stack[0];
// 	while (++i < stack->size)
// 	{
// 		if (stack->stack[i] > stack->max_num)
// 			stack->max_num = stack->stack[i];
// 		if (stack->stack[i] < stack->min_num)
// 			stack->min_num = stack->stack[i];
// 	}
// }