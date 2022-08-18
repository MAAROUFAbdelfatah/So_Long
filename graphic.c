/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:59:57 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/18 16:30:20 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_window window, char *image, int x, int y)
{
	void	*img;
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(window.mlx, image, &img_width, &img_height);
	mlx_put_image_to_window(window.mlx, window.win, img, x, y);
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

void	clear_and_render(t_window *window, int x, int y)
{
	if (envirenment_checker(window, x, y))
	{
		mlx_clear_window(window->mlx, window->win);
		window_render(*window, window->game);
	}
}

int	action(int keycode, t_window *window)
{	
	if (keycode == KEY_ESC)
		free_all(window->game, window, NULL);
	else if (keycode == KEY_A)
		clear_and_render(window, window->game->player->x_position - IMAGE_SIZE,
			window->game->player->y_position);
	else if (keycode == KEY_S)
		clear_and_render(window, window->game->player->x_position,
			window->game->player->y_position + IMAGE_SIZE);
	else if (keycode == KEY_D)
		clear_and_render(window, window->game->player->x_position + IMAGE_SIZE,
			window->game->player->y_position);
	else if (keycode == KEY_W)
		clear_and_render(window, window->game->player->x_position,
			window->game->player->y_position - IMAGE_SIZE);
	return (0);
}

void	generate_map(t_game *game)
{
	t_window	*window;

	window = window_initializer(game);
	window_render(*window, game);
	mlx_hook(window->win, 2, 1L << 0, action, window);
	mlx_hook(window->win, 17, 0, close_win, window);
	mlx_loop(window->mlx);
}
