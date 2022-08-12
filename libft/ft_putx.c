/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:17:16 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/12 18:13:00 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putx(unsigned long x, t_args *arg, int up)
{
	char	*lower;
	char	*upper;

	lower = "0123456789abcdef";
	upper = "0123456789ABCDEF";
	if (x >= 16)
	{
		ft_putx(x / 16, arg, up);
		ft_putx(x % 16, arg, up);
	}
	else
	{
		if (up)
			ft_putchar(upper[x % 16], arg);
		else
			ft_putchar(lower[x % 16], arg);
	}	
}
