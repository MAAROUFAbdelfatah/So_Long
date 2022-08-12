/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:24:40 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 16:05:10 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *searched_str, size_t len)
{
	char	*pstr;
	char	*psearched_str;
	size_t	i;
	size_t	j;

	pstr = (char *)str;
	psearched_str = (char *)searched_str;
	i = 0;
	if (psearched_str[i] == 0)
		return (pstr);
	while (i <= len && pstr[i])
	{
		j = 0;
		if (pstr[i] == psearched_str[j])
		{
			while ((pstr[i + j] == psearched_str[j]) && psearched_str[j])
				j++;
			if (!psearched_str[j] && i + j <= len)
				return (&pstr[i]);
		}
		i++;
	}
	return (NULL);
}
