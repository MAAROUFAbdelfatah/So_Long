/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:58:02 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/12 18:11:53 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	t_args	arg;
	int		i;

	arg.len = 0;
	i = 0;
	va_start(arg.ptr_args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_type(format[i + 1], &arg);
			i++;
		}
		else
			ft_putchar(format[i], &arg);
		i++;
	}
	va_end(arg.ptr_args);
	return (arg.len);
}
