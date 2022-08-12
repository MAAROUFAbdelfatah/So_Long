/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:18:32 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 02:18:34 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			i;

	if (dst == src)
		return (dst);
	pdest = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	i = 0;
	if (psrc > pdest)
	{
		while (i < len)
		{
			pdest[i] = psrc[i];
			i++;
		}
		return (dst);
	}
	else
	{
		while (len--)
			pdest[len] = psrc[len];
		return (dst);
	}
}
