/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:28:07 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/18 15:43:50 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*ptr_result;
	size_t		len_s1;
	size_t		len_s2;
	int			i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr_result = ft_alloc(len_s1 + len_s2 + 1);
	if (!ptr_result)
		return (NULL);
	while (*s1)
		ptr_result[i++] = *s1++;
	while (*s2)
		ptr_result[i++] = *s2++;
	ptr_result[i] = '\0';
	return (ptr_result);
}
