/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:20:29 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/12 18:12:22 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_un(unsigned int n, t_args *arg)
{
	unsigned long	nb;

	nb = n;
	if (nb > 9)
	{
		ft_putnbr_un(nb / 10, arg);
		ft_putnbr_un(nb % 10, arg);
	}
	else
		ft_putchar(nb + '0', arg);
}
