/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:28:07 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 02:28:08 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr_result;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ptr_result = (char *)malloc(len_s1 + len_s2 + 1);
	if (!ptr_result)
		return (NULL);
	ft_strlcpy(ptr_result, s1, len_s1 + 1);
	ft_strlcat(ptr_result, s2, len_s1 + len_s2 + 1);
	return (ptr_result);
}
