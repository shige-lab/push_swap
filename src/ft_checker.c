/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 21:53:09 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/30 19:14:45 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
