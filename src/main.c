/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:47:23 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/23 03:10:51 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_free_stacks(t_struct *data)
{
	free(data->a.stack);
	free(data->b.stack);
	free(data->s.stack);
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
		data->a.stack[i] = atoi(argv[i + 1]);
		if ((data->a.stack[i] == 0 && *argv[i + 1] != '0')
		|| sort_s(data, data->a.stack[i], i) == FALSE)
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
	
	// printf("B\n");
	// int j = 0;
	// while (j < data.b.size)
	// {
	// 	printf("%d\n",data.b.stack[j]);
	// 	j++;
	// }
	
	// printf("A\n");
	// int i = 0;
	// while (i < data.a.size)
	// {
	// 	printf("%d\n",data.a.stack[i]);
	// 	i++;
	// }
	
	// printf("S\n");
	// int k = 0;
	// while (k < 13)
	// {
	// 	printf("%d\n",data.s.stack[k]);
	// 	k++;
	// }
	// printf(" a_size = %d\n",data.a.size);
	// printf(" b_size = %d\n",data.b.size);
	// printf(" sorted = %d\n",data.sorted_index);
	ft_free_stacks(&data);
	// system ("leaks push_swap");
	return (0);
}