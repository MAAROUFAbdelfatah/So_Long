/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:17:14 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 15:34:31 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*temp;

	i = 0;
	if (!len)
		return (b);
	temp = b;
	while (len)
	{
		temp[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}
