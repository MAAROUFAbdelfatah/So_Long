/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:40:02 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/17 21:20:19 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_alloc(int size)
{
	char	*ptr;

	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (NULL);
	*ptr = '\0';
	return (ptr);
}

int	new_line_exist(char *buffer, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
