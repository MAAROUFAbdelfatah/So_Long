/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:28:24 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 02:28:26 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_there(char const *set, int c)
{	
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	size_t	len_s1;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	while (s1[i] && is_there(set, s1[i]))
		i++;
	while (s1[i] && is_there(set, s1[len_s1 - 1]))
		len_s1--;
	return (ft_substr(s1, (unsigned int)i, len_s1 - i));
}
