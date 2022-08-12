/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 02:31:40 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/12 18:13:18 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	len_s;
	size_t	i;

	i = 0;
	if (!s || !f)
		return ;
	len_s = ft_strlen(s);
	while (i < len_s)
	{
		(*f)(i, s + i);
		i++;
	}
}
