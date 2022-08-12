/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:57:25 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 15:57:28 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*holder_char;

	holder_char = (char *)s;
	while (*holder_char != (char)c && *holder_char)
	{
		holder_char++;
	}
	if (*holder_char == (char)c)
		return (holder_char);
	return (NULL);
}
