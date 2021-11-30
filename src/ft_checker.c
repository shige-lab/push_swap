/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:53:09 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/30 14:03:44 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	error_exit2(t_struct *data)
// {
// 	free(data->s.stack);
// 	ft_putendl_fd("Error", 1);
// 	exit (1);
// }

void	ft_free_stacks(t_struct data)
{
	free(data.a.stack);
	free(data.b.stack);
	free(data.s.stack);
}

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

void	sort_by_order(t_struct *data, char *order)
{
	if (ft_memcmp(order, "sa\n", 3) == 0)
		ft_swap(data, 'a', FALSE);
	else if (ft_memcmp(order, "sb\n", 3) == 0)
		ft_swap(data, 'b', FALSE);
	else if (ft_memcmp(order, "ss\n", 3) == 0)
		ft_ss_rr_rrr(data, "ss", FALSE);
	else if (ft_memcmp(order, "pa\n", 3) == 0)
		ft_push(data, 'a', FALSE);
	else if (ft_memcmp(order, "pb\n", 3) == 0)
		ft_push(data, 'b', FALSE);
	else if (ft_memcmp(order, "ra\n", 3) == 0)
		ft_rotate(data, 'a', FALSE);
	else if (ft_memcmp(order, "rb\n", 3) == 0)
		ft_rotate(data, 'b', FALSE);
	else if (ft_memcmp(order, "rr\n", 3) == 0)
		ft_ss_rr_rrr(data, "rr", FALSE);
	else if (ft_memcmp(order, "rra\n", 4) == 0)
		ft_reverse_rotate(data, 'a', FALSE);
	else if (ft_memcmp(order, "rrb\n", 4) == 0)
		ft_reverse_rotate(data, 'b', FALSE);
	else if (ft_memcmp(order, "rrr\n", 4) == 0)
		ft_ss_rr_rrr(data, "rrr", FALSE);
	else
		error_exit_with_free(data, "invalid order");
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
		data->a.stack[i] = ft_atoi(argv[i + 1]);
		if ((data->a.stack[i] == 0 && ft_memcmp(argv[i + 1], "0", 1))
			|| sort_s(data, data->a.stack[i], i) == FALSE)
			error_exit_with_free(data, "invalid figure");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_struct	data;
	char		*order;

	if (argc < 2)
		return (0);
	data.total_size = argc - 1;
	put_argv_to_a(&data, argv);
	while (1)
	{
		order = get_next_line(0);
		if (order == NULL)
			break ;
		sort_by_order(&data, order);
		free(order);
	}
	if (diff(data, 0) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_free_stacks(data);
	// system("leaks ft_checker");
	return (0);
}
