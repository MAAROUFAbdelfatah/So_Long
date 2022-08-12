/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:30:28 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 02:30:30 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptrs;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	ptrs = (char *)malloc(len + 1);
	if (!ptrs)
		return (NULL);
	while (i < len)
	{
		ptrs[i] = f(i, s[i]);
		i++;
	}
	ptrs[i] = 0;
	return (ptrs);
}
