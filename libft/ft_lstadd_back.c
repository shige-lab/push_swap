/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:38:58 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/07 23:37:09 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		lst_last = ft_lstlast(*lst);
		lst_last->next = new;
	}
	else
		*lst = new;
}
