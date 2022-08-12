/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:24:03 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 02:24:05 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptrs1;
	unsigned char	*ptrs2;

	ptrs1 = (unsigned char *)s1;
	ptrs2 = (unsigned char *)s2;
	while (n && (*ptrs1 == *ptrs2) && ptrs1 && ptrs2)
	{
		ptrs1++;
		ptrs2++;
		n--;
	}
	if (!n || !ptrs1 || !ptrs2)
		return (0);
	return (*ptrs1 - *ptrs2);
}
