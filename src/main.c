/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:47:23 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/24 20:36:18 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	diff(t_struct data, int j)
{
	int	i;

	i = 0;
	while (i < data.total_size)
	{
		if (data.a.stack[j + i] != data.s.stack[i])
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
	if (data->a.stack == NULL || data->b.stack == NULL|| data->s.stack == NULL)
		error_exit_with_free(data, "failed malloc");
	data->a.size = data->total_size;
	i = 0;
	while (i + 1 <= data->total_size)
	{
		data->a.stack[i] = ft_atoi(argv[i + 1]);
		if ((data->a.stack[i] == 0 && ft_memcmp(argv[i + 1], "0", 1)) || sort_s(data, data->a.stack[i], i) == FALSE)
			error_exit_with_free(data, "invalid figure");
		i++;
	}
	get_standard_value(data);
}

int	main(int argc, char **argv)
{
	t_struct	data;

	if (argc < 3)
		return (0);
	data = (t_struct){0};
	data.total_size = argc - 1;
	data.a.size = data.total_size;
	put_argv_to_a(&data, argv);
	push_swap(&data);

	
	// fprintf(stderr, "B\n");
	// int j = 0;
	// while (j < data.b.size)
	// {
	// 	fprintf(stderr"%d\n",data.b.stack[j]);
	// 	j++;
	// }
	
	// fprintf(stderr, "A\n");
	// int i = 0;
	// while (i < data.a.size)
	// {
	// 	fprintf(stderr, "%d\n",data.a.stack[i]);
	// 	i++;
	// }
	
	// fprintf(stderr, "S\n");
	// int k = 0;
	// while (k < data.middle_index)
	// {
	// 	fprintf(stderr, "%d\n",data.s.stack[k]);
	// 	k++;
	// }
	// fprintf(stderr, "a_size = %d\n",data.a.size);
	// fprintf(stderr, "b_size = %d\n",data.b.size);
	// fprintf(stderr, " sorted = %d\n",data.sorted_index);
	// fprintf(stderr, " last_s = %d\n",data.s.stack[data.sorted_index]);
	// fprintf(stderr, " s = %d\n",data.index_1_8;
	// fprintf(stderr, " b = %d\n",data.index_1_4 - (data.index_1_4/ 2));
	// fprintf(stderr, " 1_4 - 1_8 = %d\n",data.index_1_4 - data.index_1_8);
	// fprintf(stderr, " 1_4 + _1_4/2 = %d\n",data.index_1_4 + data.index_1_4 / 2);
	// fprintf(stderr, " 1_4 = %d\n",data.index_1_4);
	// fprintf(stderr, " 3_4 = %d\n",data.index_3_4);
	// fprintf(stderr, " middle = %d\n",data.middle_index);
	// fprintf(stderr, "%d\n", diff(data, 0));
	ft_free_stacks(data);
	// system ("leaks push_swap");
	return (0);
}