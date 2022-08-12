/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:31:29 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/12 20:28:59 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

void    ft_error(char *s)
{
    ft_printf("Error: %s", s);
    exit(0);
}

size_t  ft_strlen_2d(char **s)
{
	size_t	i;

	i = 0;
	while (*s)
    {
        i++;
        s++;
    }
	return (i);
}

int main(int argc, char **argv)
{
    char **path;
    char *extension;
    
    if (argc != 2)
        ft_error("check the number of args");
        
    path = ft_split(argv[1], '.');
    extension = path[(ft_strlen_2d(path) - 1)];
    if (ft_strncmp(extension, "ber", 3))
        ft_error("check file extension");

    ft_printf("valide");
    return (0);
}