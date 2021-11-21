/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:41:35 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/07 23:40:14 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	end;

	end = ft_strlen(s);
	while (end >= 0)
	{
		if (((char *)s)[end] == (char)c)
			return (&((char *)s)[end]);
		if (end == 0)
			break ;
		end--;
	}
	return (NULL);
}
