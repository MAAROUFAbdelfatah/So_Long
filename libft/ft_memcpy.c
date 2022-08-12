/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:17:56 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 02:17:58 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	int				i;

	if (dst == NULL && src == NULL)
		return (0);
	if (dst == src)
		return (dst);
	i = 0;
	pdest = (unsigned char *)dst;
	psrc = (unsigned char *)src;
	while (n)
	{
		pdest[i] = psrc[i];
		i++;
		n--;
	}
	return (dst);
}
