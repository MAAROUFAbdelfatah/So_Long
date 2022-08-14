/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 14:59:57 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/14 20:50:37 by amaarouf         ###   ########.fr       */
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

void    generate_map(t_game game)
{
	t_window	*window;
	int		i;
	int		j;
	int		counter_x;
	int		counter_y;
	
	counter_x = 0;
	i = 0;

	window = (t_window*) malloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->win_width = game.map->width * IMAGE_SIZE;
	window->win_height = game.map->height * IMAGE_SIZE;
	window->win_name = WIN_NAME;
	window->win = mlx_new_window(window->mlx, window->win_width, window->win_height, window->win_name);
	while (game.map->array_map[i])
	{
		j = 0;
		counter_y = 0;
		while (game.map->array_map[i][j])
		{
			if (game.map->array_map[i][j] == 'P'){
				
				
				put_image(*window, game.player->image, counter_y, counter_x);
			}
			else if (game.map->array_map[i][j] == 'E')
			{
				if (game.collectibles->c_counter)
					put_image(*window, game.exits->image01, counter_y, counter_x);
				else
					put_image(*window, game.exits->image02, i, j);
			}
			else if (game.map->array_map[i][j] == 'C')
			{
				
				put_image(*window, game.collectibles->image, counter_y, counter_x);
			}
			else if (game.map->array_map[i][j] == '1')
				put_image(*window, game.img_wall, counter_y, counter_x);
			else
				put_image(*window, game.img_ground, counter_y, counter_x);
			
			j++;
			counter_y += IMAGE_SIZE; 
		}
		i++;
		counter_x += IMAGE_SIZE;
	} 
	mlx_loop(window->mlx);  
}