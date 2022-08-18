/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:59:57 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/18 12:38:00 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_window window,char *image, int x, int y)
{
	void    *img;
	int     img_width;
    int     img_height;
	
	img = mlx_xpm_file_to_image(window.mlx, image, &img_width, &img_height);
	mlx_put_image_to_window(window.mlx, window.win, img, x, y);
}

void	char_checker(t_window window, t_game *game, char c)
{
	if (c == 'P')
	{
		put_image(window, game->player->image, game->map->counter_x, game->map->counter_y);
		game->player->x_position = game->map->counter_x;
		game->player->y_position = game->map->counter_y;
	}
	else if (c == 'E')
	{
		if (game->collectibles->c_counter)
			put_image(window, game->exits->image01, game->map->counter_x, game->map->counter_y);
		else
			put_image(window, game->exits->image02, game->map->counter_x, game->map->counter_y);
	}
	else if (c == 'C')
		put_image(window, game->collectibles->image, game->map->counter_x, game->map->counter_y);
	else if (c == '1')
		put_image(window, game->img_wall, game->map->counter_x, game->map->counter_y);
	else
		put_image(window, game->img_ground, game->map->counter_x, game->map->counter_y);			
}

void	window_render(t_window window, t_game *game)
{
	int		i;
	int		j;
	
	i = 0;
	game->map->counter_y = 0;
	while (game->map->array_map[i])
	{
		j = 0;
		game->map->counter_x = 0;
		while (game->map->array_map[i][j])
		{
			char_checker(window, game, game->map->array_map[i][j]);
			j++;
			game->map->counter_x += IMAGE_SIZE;
		}
		i++;
		game->map->counter_y += IMAGE_SIZE;
	}
}

void	replacement(t_game *game, int x, int y)
{
	int	py;
	int	px;
	
	py = game->player->y_position / IMAGE_SIZE;
	px = game->player->x_position / IMAGE_SIZE;	 
	game->map->array_map[x][y] = 'P';
	game->map->array_map[py][px] = '0';
	game->player->moves_counter++;
	ft_printf("counter: %d\n", game->player->moves_counter);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	envirenment_checker(t_window *window, int n_x_position, int n_y_position)
{
	if (window->game->map->array_map[n_y_position / IMAGE_SIZE][n_x_position / IMAGE_SIZE] == '0')
	{
		replacement(window->game,n_y_position / IMAGE_SIZE , n_x_position / IMAGE_SIZE);
		return (1);
	}
	else if (window->game->map->array_map[n_y_position / IMAGE_SIZE][n_x_position / IMAGE_SIZE] == 'C')
	{
		replacement(window->game,n_y_position / IMAGE_SIZE , n_x_position / IMAGE_SIZE);
		window->game->collectibles->c_counter--;
		return (1);
	}
	else if (window->game->map->array_map[n_y_position / IMAGE_SIZE][n_x_position / IMAGE_SIZE] == 'E')
	{
		if (window->game->collectibles->c_counter == 0)
		{
			replacement(window->game,n_y_position / IMAGE_SIZE , n_x_position / IMAGE_SIZE);
			free_all(window->game, window, NULL);
		}
	}
	return (0);
}

void	clear_and_render(t_window *window, int x, int y)
{
	if(envirenment_checker(window, x, y))
	{
		mlx_clear_window(window->mlx, window->win);
		window_render(*window, window->game);
	}
}

int	action(int keycode,t_window *window)
{	
	if (keycode == KEY_ESC)
		free_all(window->game, window, NULL);
	else if (keycode == KEY_A)
		clear_and_render(window, window->game->player->x_position - IMAGE_SIZE, window->game->player->y_position);	
	else if (keycode == KEY_S)
		clear_and_render(window, window->game->player->x_position, window->game->player->y_position + IMAGE_SIZE); 
	else if (keycode == KEY_D)
		clear_and_render(window, window->game->player->x_position + IMAGE_SIZE, window->game->player->y_position);
	else if (keycode == KEY_W)
		clear_and_render(window, window->game->player->x_position, window->game->player->y_position - IMAGE_SIZE);
	return (0);
}

int close_win()
{
	exit(EXIT_SUCCESS);
}

void    generate_map(t_game *game)
{
	t_window	*window;

	window = window_initializer(game);
	window_render(*window, game);
	mlx_hook(window->win, 2, 1L<<0, action, window);
	mlx_hook(window->win, 17, 0, close_win, window);
	mlx_loop(window->mlx);  
}