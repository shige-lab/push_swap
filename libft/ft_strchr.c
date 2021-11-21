/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:40:44 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/07 23:39:08 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ss;

	ss = (char *)s;
	i = 0;
	while (ss[i])
	{
		if (ss[i] == (char)c)
			return (&ss[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&ss[i]);
	else
		return (NULL);
}
