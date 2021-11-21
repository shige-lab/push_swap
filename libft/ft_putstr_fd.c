/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:40:36 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/07 23:38:53 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	len;
	size_t	i;

	if (!s)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (len > INT_MAX)
	{
		write(fd, &s[i], INT_MAX);
		len -= INT_MAX;
		i += INT_MAX;
	}
	write(fd, &s[i], len);
}
