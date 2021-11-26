/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_standard_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:56:43 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/26 20:59:38 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_standard_value(t_struct *data)
{
	data->max_num = data->s.stack[data->total_size - 1];
	data->min_num = data->s.stack[0];
	data->middle_index = data->total_size - data->total_size / 2;
	data->index_1_4 = data->middle_index - data->middle_index / 2;
	data->index_3_4 = data->total_size - data->index_1_4;
	data->index_1_8 = data->index_1_4 - data->index_1_4 / 2;
	data->middle_num = data->s.stack[data->middle_index];
	data->sorted_index = 0;
}
