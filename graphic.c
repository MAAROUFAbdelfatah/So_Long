/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:59:57 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/15 19:33:12 by amaarouf         ###   ########.fr       */
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
		ft_printf("position: (%d, %d)\n", game->player->x_position, game->player->y_position);
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
    while (game->map->array_map[i])
    {
        ft_printf("%s\n", game->map->array_map[i]);
        i++;
    }
	
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

int	envirenment_checker(t_game	*game, int n_x_position, int n_y_position)
{
	if (game->map->array_map[n_y_position / IMAGE_SIZE][n_x_position / IMAGE_SIZE] == '0')
	{
		game->map->array_map[n_y_position / IMAGE_SIZE][n_x_position / IMAGE_SIZE] = 'P';
		game->map->array_map[game->player->y_position / IMAGE_SIZE][game->player->x_position / IMAGE_SIZE] = '0';
		ft_printf("\nplayer position: (%d, %d\n)",game->player->x_position, game->player->y_position );
		return (1);
	}
	else if (game->map->array_map[n_y_position / IMAGE_SIZE][n_x_position / IMAGE_SIZE] == 'C')
	{
		game->map->array_map[n_y_position / IMAGE_SIZE][n_x_position / IMAGE_SIZE] = 'P';
		game->map->array_map[game->player->y_position / IMAGE_SIZE][game->player->x_position / IMAGE_SIZE] = '0';
		game->collectibles->c_counter--;
		return (1);
	}
	else if (game->map->array_map[n_y_position / IMAGE_SIZE][n_x_position / IMAGE_SIZE] == 'E')
	{
		game->map->array_map[n_y_position / IMAGE_SIZE][n_x_position / IMAGE_SIZE] = 'P';
		game->map->array_map[game->player->y_position / IMAGE_SIZE][game->player->x_position / IMAGE_SIZE] = '0';
		exit (0);
	}
	return (0);
}

int	action(int keycode,t_window *window)
{
	int x;
	int y;
	
	if (keycode == KEY_A)
    {
		x = window->game->player->x_position - IMAGE_SIZE;
		if(envirenment_checker(window->game, x, window->game->player->y_position))
		{
			mlx_clear_window(window->mlx, window->win);
			window_render(*window, window->game);
			ft_printf("\nplayer position: (%d, %d)\n",window->game->player->x_position, window->game->player->y_position );
		}
    }
	else if (keycode == KEY_S)
	{
		y = window->game->player->y_position + IMAGE_SIZE;
		if(envirenment_checker(window->game, window->game->player->x_position, y))
		{
			mlx_clear_window(window->mlx, window->win);
			window_render(*window, window->game);
			ft_printf("\nplayer position: (%d, %d)\n",window->game->player->x_position, window->game->player->y_position );
		}
    }   
    else if (keycode == KEY_D)
    {
		x = window->game->player->x_position + IMAGE_SIZE;
		if(envirenment_checker(window->game, x, window->game->player->y_position))
		{
			mlx_clear_window(window->mlx, window->win);
			window_render(*window, window->game);
			ft_printf("\nplayer position: (%d, %d)\n",window->game->player->x_position, window->game->player->y_position );
		}
    }
    else if (keycode == KEY_W)
    {
		
		y = window->game->player->y_position - IMAGE_SIZE;
		if(envirenment_checker(window->game, window->game->player->x_position, y))
		{
			mlx_clear_window(window->mlx, window->win);
			window_render(*window, window->game);
			ft_printf("\nplayer position: (%d, %d)\n",window->game->player->x_position, window->game->player->y_position );
		}
    }
    return (0);
}



void    generate_map(t_game *game)
{
	t_window	*window;

	window = window_initializer(game);
	window_render(*window, game);
	mlx_hook(window->win, 2, 1L<<0, action, window);
	mlx_loop(window->mlx);  
}