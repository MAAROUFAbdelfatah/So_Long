/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:44:48 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/12 18:13:45 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_type(const char c, t_args *arg)
{
	if (c == 'c')
		ft_putchar(va_arg(arg->ptr_args, int), arg);
	else if (c == 's')
		ft_putstr(va_arg(arg->ptr_args, char *), arg);
	else if (c == 'p')
		ft_putp(va_arg(arg->ptr_args, unsigned long), arg);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg->ptr_args, int), arg);
	else if (c == 'u')
		ft_putnbr_un(va_arg(arg->ptr_args, unsigned int), arg);
	else if (c == 'x')
		ft_putx(va_arg(arg->ptr_args, unsigned int), arg, 0);
	else if (c == 'X')
		ft_putx(va_arg(arg->ptr_args, unsigned int), arg, 1);
	else if (c == '%')
		ft_putchar('%', arg);
}
