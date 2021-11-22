/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 21:43:24 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/23 03:10:17 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


// void	push_a_from_min(t_struct *data, int i)
// {
// 	while (data->b.size != 0)
// 	{
// 		if (data->b.stack[data->b.size - 1] == data->s.stack[i])
// 			ft_reverse_rotate(data, 'b', TRUE);
// 		if (data->b.stack[0] == data->s.stack[i])
// 		{
// 			ft_push(data, 'a');
// 			ft_rotate(data, 'a', TRUE);
// 			i++;
// 		}
// 		else
// 			ft_rotate(data, 'b', TRUE);
// 	}
// }

void	get_b_mini_index(t_struct *data, int b_min)
{
	int i;

	i = 0;
	while (i < data->b.size)
	{
		if (data->b.stack[i] == data->s.stack[b_min])
		{
			data->b.min_index = i;
			break ;
		}
		i++;
	}

}

t_bool	is_rr(t_struct *data)
{
	if (data->a.stack[1] > data->b.stack[0] && data->b.size != 0)
		return (FALSE);
	ft_ss_rr_rrr(data, "rr");
	return (TRUE);
}
void	is_rr_from_a(t_struct *data)
{
	if (data->b.stack[0] < data->s.stack[data->quarter_index])
	{
		if (!(data->a.stack[0] < data->q3_4_index))
		{
			ft_ss_rr_rrr(data, "rr");
		}
		else
			ft_rotate(data, 'b', TRUE);
	}
}

void	push_a_from_min(t_struct *data, int i)
{
	int	a_top;

	a_top = data->a.stack[0];
	get_b_mini_index(data, i);
	while (data->b.size >= data->quarter_index || a_top != data->a.stack[0])
	{
		if (data->b.stack[0] == data->s.stack[i])
		{
			ft_push(data, 'a');
			if (is_rr(data) == FALSE)
				ft_rotate(data, 'a', TRUE);
			i++;
		}
		if (data->a.stack[0] == data->s.stack[i])
		{
			if (is_rr(data) == FALSE)
				ft_rotate(data, 'a', TRUE);
			i++;
		}
		if (data->a.stack[0] > data->b.stack[0] && data->b.size >= data->quarter_index)
		{
			ft_push(data, 'a');
		}
		else if (data->a.stack[1] > data->b.stack[0] && data->b.size >= data->quarter_index)
		{
			// printf("1\n");
			ft_push(data, 'a');
			ft_swap(data, 'a', TRUE);
		}
		else if (data->a.stack[0] > data->b.stack[data->b.size - 1] && data->b.size >= data->quarter_index)
		{
			ft_reverse_rotate(data, 'b', TRUE);
			ft_push(data, 'a');
		}
		else if (data->b.stack[0] < data->b.stack[data->quarter_index])
			ft_rotate(data, 'b', TRUE);
		else
			ft_reverse_rotate(data, 'b', TRUE);

	}
}

void	put_best2(t_struct *data, int *count)
{
	while (data->a.stack[data->a.size - 1] > data->b.stack[0] && *count > 0)
	{
		ft_reverse_rotate(data, 'a', TRUE); 
		*count-= 1;
	}
	while (data->a.stack[1] < data->b.stack[0] && data->a.stack[1] > data->s.stack[2])
	{
		ft_rotate(data, 'a', TRUE);
		*count+= 1;
	}
	ft_push(data, 'a');
	if (data->a.stack[1] < data->a.stack[0] && data->a.stack[1] != data->s.stack[0])
		ft_swap(data, 'a', TRUE);
	while (data->a.stack[0] == data->s.stack[data->sorted_index])
	{
		ft_rotate(data, 'a', TRUE);
		// if (is_rr(data) == FALSE)
		// 	ft_rotate(data, 'a', TRUE);
		data->sorted_index++;
	}
}
 
void	put_best(t_struct *data, int *count)
{
	while (data->a.stack[data->a.size - 1] > data->b.stack[0] && *count > 0)
	{
		ft_reverse_rotate(data, 'a', TRUE); 
		*count-= 1;
	}
	while (data->a.stack[1] < data->b.stack[0])
	{
		ft_rotate(data, 'a', TRUE);
		*count+= 1;
	}
	ft_push(data, 'a');
	if (data->a.stack[1] < data->a.stack[0])
		ft_swap(data, 'a', TRUE);
	while (data->a.stack[0] == data->s.stack[data->sorted_index])
	{
		ft_rotate(data, 'a', TRUE);
		// if (is_rr(data) == FALSE)
		// 	ft_rotate(data, 'a', TRUE);
		data->sorted_index++;
	}
}

void	push_a_from_min4(t_struct *data)
{
	int	count;

	count = 0;
	while (data->b.stack[0] < data->s.stack[data->quarter_index])
	{
		if (data->b.stack[0] > data->s.stack[data->quarter_index / 2])
		{
			ft_rotate(data, 'b', TRUE);
		}
		else
			put_best(data, &count);
	}
	while (data->b.size > 0)
	{
		put_best(data, &count);
	}
}

void	push_a_from_min3(t_struct *data)
{
	while (data->b.stack[0] >= data->s.stack[data->quarter_index])
	{
		if (data->b.stack[0] >= data->middle_num)
		{
			ft_push(data, 'a');
		}
		else if (data->b.stack[0] >= data->s.stack[data->quarter_index])
		{
			ft_rotate(data, 'b', TRUE);
		}
	}
}
void	push_a_from_min2(t_struct *data)
{
	// while (data->b.size != 0)
	// {
		push_a_from_min3(data);
		push_a_from_min4(data); 
		
	// }
}
void	push_quater_to_b2(t_struct *data)
{
	if (data->a.stack[0] == data->s.stack[data->sorted_index])
		{
			ft_rotate(data, 'a', TRUE);
			data->sorted_index++;
		}
		else
			ft_push(data, 'b');
}


void	push_quater_to_b(t_struct *data)
{
	int	count;

	count = 0;
	while (data->a.stack[0] < data->s.stack[data->q3_4_index])
	{
		push_quater_to_b2(data);
	}
	while (data->b.size > 0)
	{
		put_best(data, &count);
	}
	while (data->a.stack[0] != data->s.stack[0])
		push_quater_to_b2(data);
	while (data->b.size > 0)
	{
		put_best2(data, &count);
	}
}