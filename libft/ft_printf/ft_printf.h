/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshigena <tshigena@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:29:58 by tshigena          #+#    #+#             */
/*   Updated: 2021/11/12 22:22:27 by tshigena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdarg.h"
# include "stdlib.h"
# include <unistd.h>
# include <limits.h>

size_t	print_c(int c);
size_t	print_s(char *s);
size_t	print_d(int d);
size_t	print_u(unsigned int u);
size_t	print_p(unsigned long long p);
size_t	print_x(int x, unsigned int u);
size_t	put_num_dx(unsigned long long n, int base, int x);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *format, ...);

#endif