/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:28:17 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/17 21:45:18 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include "libft/libft.h"
#include "mlx.h"
#include <fcntl.h>

#define IMAGE_SIZE 32
#define WIN_NAME "So Long"
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_W 13
#define KEY_ESC 53

typedef struct map
{
	char	**array_map;
	char	*line;
	int		fd_map;
	int		width;
	int		height;
	int		counter_x;
	int		counter_y;
}	t_map;

typedef	struct player
{
	char	*image;
	int		p_counter;
	int		x_position;
	int		y_position;
	int		moves_counter;
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
	char			*img_ground;
	char			*img_wall;
}   t_game;

typedef struct	window {
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	char	*win_name;
	t_game	*game;
}	t_window;

size_t			ft_strlen_2d(char **s);
void			ft_error(char *s);
int				counter(t_game *game, char c);
void			line_checker(t_game *game);
char			*get_line_no_nl(int fd);
void			ft_realloc(t_game *game);
void			check_walls(t_game *game);
void			map_checker(t_game *game);
t_map			*map_initializer(char *path);
t_player		*player_initializer();
t_collectibles	*collectibles_initializer();
t_exits			*exits_initializer();
t_game			*game_initializer(char *path);
t_window		*window_initializer(t_game *game);
void			put_image(t_window window,char *image, int x, int y);
void			generate_map(t_game *game);
void			ft_free_tab(char **tab);
void			free_all(t_game *game);
#endif
