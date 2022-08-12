/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:21:57 by amaarouf          #+#    #+#             */
/*   Updated: 2021/12/11 16:06:36 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*holder_char;
	size_t	len;

	holder_char = (char *)s;
	len = ft_strlen(holder_char);
	while (len && *holder_char && holder_char[len] != (char) c)
		len--;
	if (holder_char[len] == (char)c)
		return (&holder_char[len]);
	return (NULL);
}
