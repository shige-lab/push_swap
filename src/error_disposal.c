/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_disposal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:32:15 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/30 19:34:58 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *message)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(message, 1);
	exit (1);
}

void	error_exit_with_free(t_struct *data, char *message)
{
	ft_free_stacks(*data);
	error_exit(message);
}
