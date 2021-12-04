/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_for_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 20:56:43 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/05 00:51:33 by tshigena         ###   ########.fr       */
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

int	diff(t_struct data, int index)
{
	int	i;

	i = 0;
	while (i < data.total_size)
	{
		if (data.a.stack[index + i] != data.s.stack[i])
		{
			if (i == 0)
				return (-1);
			return (i);
		}
		i++;
	}
	return (0);
}

void	ft_free_stacks(t_struct data)
{
	free(data.a.stack);
	free(data.b.stack);
	free(data.s.stack);
}

void	put_argv_to_a(t_struct *data, char **argv)
{
	int	i;

	data->a.stack = (int *)ft_calloc(data->total_size + 1, sizeof(int));
	data->b.stack = (int *)ft_calloc(data->total_size + 1, sizeof(int));
	data->s.stack = (int *)ft_calloc(data->total_size + 1, sizeof(int));
	if (data->a.stack == NULL || data->b.stack == NULL || data->s.stack == NULL)
		error_exit_with_free(data, "failed malloc");
	data->a.size = data->total_size;
	i = 0;
	while (i + 1 <= data->total_size)
	{
		data->a.stack[i] = ft_atoi_simple(argv[i + 1]);
		if ((data->a.stack[i] == 0 && ft_strncmp(argv[i + 1], "0", 2))
			|| sort_s_stock(data, data->a.stack[i], i) == FALSE)
			error_exit_with_free(data, "invalid figure");
		i++;
	}
	get_standard_value(data);
}
