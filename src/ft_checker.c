/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:53:09 by tshigena          #+#    #+#             */
/*   Updated: 2021/12/07 11:00:14 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	main(int argc, char **argv)
{
	t_struct	data;
	char		*order;

	if (argc < 2)
		return (0);
	data.total_size = argc - 1;
	data.a.size = data.total_size;
	agrv_to_a_stack(&data, argv);
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
	return (0);
}
