/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:28:17 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/13 20:44:26 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx.h"
#include <fcntl.h>

typedef struct map
{
	char	**map;
	char	*line;
	int		fd_map;
	int		width;
	int		height;
	int		nbr_lines;
}	t_map;

typedef struct game
{
    int		p_counter;
    int		e_counter;
    int		c_counter;
	t_map	*map;
}   t_game;

size_t	ft_strlen_2d(char **s);
void    ft_error(char *s);

#endif
