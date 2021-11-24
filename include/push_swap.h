/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:39:44 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/24 20:33:40 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_stack
{
	int	*stack;
	int	size;
}	t_stack;

typedef struct s_struct
{
	t_stack	a;
	t_stack	b;
	t_stack	s;
	int		total_size;
	int		middle_num;
	int		max_num;
	int		min_num;
	int		middle_index;
	int		index_1_4;
	int		index_3_4;
	int		index_1_8;
	int		sorted_index;
}	t_struct;

// !修正必須
void	is_rr_from_a(t_struct *data);
void	error_exit(char *message);
void	error_exit_with_free(t_struct *data, char *message);
void	get_standard_value(t_struct *data);
void	get_standard_value_3(t_stack *stack);
t_bool	is_same_number(t_struct data, int number, int number_location);
t_bool	sort_s(t_struct *data, int number, int number_location);
void	push_a_from_min(t_struct *data, int i);
void	push_a_from_min2(t_struct *data);
void	push_quater_to_b(t_struct *data);
void	push_a_from_min_dx(t_struct *data, int base);
void	ft_push_front(int *data, int data_size, int insert);
void	ft_pop_front(int *data, int data_size); 
t_bool	sort_is_correct(t_struct *data);
// 不要
void	ft_reverse(int *data, int data_size);
void	ft_rotate_front_to_end(int *data, int data_size);
void	ft_rotate_end_to_front(int *data, int data_size);
void	ft_swap(t_struct *data, char a_b, t_bool put_message);
void	ft_push(t_struct *data, char a_b);
void	ft_rotate(t_struct *data, char a_b, t_bool put_message);
void	ft_reverse_rotate(t_struct *data, char a_b, t_bool put_message);
void	ft_ss_rr_rrr(t_struct *data, char *ss_rr_rrr);
void	sort_a_front(t_struct *data);
void	push_swap(t_struct *data);

void	split_to_4block_by_size(t_struct *data);
void	push_small_2block_to_bottom_of_a(t_struct *data);
void	push_small_1block_to_bottom_of_a(t_struct *data, int base);
void	ra_minimum_numbers(t_struct *data);
void	pb_and_sort_from_small(t_struct *data, int *count, int flag);

#endif