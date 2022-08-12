/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:25:18 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 14:56:15 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	skipper;
	int	sign;
	int	result;

	sign = 1;
	skipper = 0;
	result = 0;
	while (str[skipper] && ((str[skipper] >= 9 \
	&& str[skipper] <= 13) || str[skipper] == 32))
		skipper++;
	if (str[skipper] == '-' || str[skipper] == '+')
	{
		if (str[skipper] == '-')
			sign = -1;
		skipper++;
	}
	while (str[skipper] && ft_isdigit(str[skipper]))
	{
		result = result * 10 + str[skipper] - 48;
		skipper++;
	}
	return (result * sign);
}
