/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:28:17 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/14 16:25:23 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx.h"
#include <fcntl.h>

typedef struct map
{
	char	**array_map;
	char	*line;
	int		fd_map;
	int		width;
	int		height;
}	t_map;

typedef	struct player
{
	char	*image;
	int		p_counter;
}	t_player;

typedef	struct collectibles
{
	char	*image;
	int		c_counter;
}	t_collectibles;

typedef struct exits
{
	char	*image01;
	char	*image02;
	int		e_counter;
}	t_exits;

typedef struct game
{
	t_player 		*player;
	t_collectibles 	*collectibles;
	t_exits			*exits;	
	t_map			*map;
}   t_game;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}	t_vars;


size_t	ft_strlen_2d(char **s);
void	ft_error(char *s);
int		counter(t_game *game, char c);
void	line_checker(t_game *game);
char	*get_line_no_nl(int fd);
void	ft_realloc(t_game *game);
void	check_walls(t_game *game);
void	map_checker(t_game *game);
t_map	*map_initializer(char *path);
t_game  *game_initializer(char *path);

#endif
