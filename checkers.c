/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:45:45 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/18 16:28:54 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	line_checker(t_game *game)
{
	int		i;
	char	*s;

	s = game->map->line;
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (s[i] == '1' || s[i] == '0' || counter(game, s[i]))
			i++;
		else
			free_all(game, NULL, "check the map, 0, 1, C, P or E");
	}
}

void	map_checker(t_game *game)
{
	int	len_holder;

	game->map->line = get_line_no_nl(game->map->fd_map);
	len_holder = ft_strlen(game->map->line);
	game->map->array_map[0] = game->map->line;
	game->map->array_map[1] = NULL;
	while (game->map->line)
	{
		game->map->height++;
		game->map->width = ft_strlen(game->map->line);
		if (len_holder != game->map->width)
			free_all(game, NULL, "check the map, rectangular");
		line_checker(game);
		game->map->line = get_line_no_nl(game->map->fd_map);
		if (!game->map->line)
			break ;
		ft_realloc(game);
	}
	if (game->player->p_counter != 1 || game->exits->e_counter != 1
		|| game->col->c_counter < 1)
		free_all(game, NULL, "check the map, P, C or E");
	check_walls(game);
}

void	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map->array_map[i])
	{
		j = 0;
		if (i == 0 || i == game->map->height - 1)
		{
			while (game->map->array_map[i][j])
			{
				if (game->map->array_map[i][j] != '1')
					free_all(game, NULL, "check the map, wall");
				j++;
			}
		}
		else
			if (game->map->array_map[i][game->map->width - 1] != '1'
				|| game->map->array_map[i][0] != '1')
				free_all(game, NULL, "check the map, wall");
		i++;
	}
}

int	envirenment_checker(t_window *window, int x, int y)
{
	if (window->game->map->array_map[y / IMAGE_SIZE][x / IMAGE_SIZE] == '0')
	{
		replacement(window->game, y / IMAGE_SIZE, x / IMAGE_SIZE);
		return (1);
	}
	else if (window->game->map->array_map
		[y / IMAGE_SIZE][x / IMAGE_SIZE] == 'C')
	{
		replacement(window->game, y / IMAGE_SIZE, x / IMAGE_SIZE);
		window->game->col->c_counter--;
		return (1);
	}
	else if (window->game->map->array_map
		[y / IMAGE_SIZE][x / IMAGE_SIZE] == 'E')
	{
		if (window->game->col->c_counter == 0)
		{
			replacement(window->game, y / IMAGE_SIZE, x / IMAGE_SIZE);
			free_all(window->game, window, NULL);
		}
	}
	return (0);
}

void	char_checker(t_window w, t_game *g, char c)
{
	if (c == 'P')
	{
		put_image(w, g->player->image, g->map->counter_x, g->map->counter_y);
		g->player->x_position = g->map->counter_x;
		g->player->y_position = g->map->counter_y;
	}
	else if (c == 'E')
	{
		if (g->col->c_counter)
			put_image(w, g->exits->image01,
				g->map->counter_x, g->map->counter_y);
		else
			put_image(w, g->exits->image02,
				g->map->counter_x, g->map->counter_y);
	}
	else if (c == 'C')
		put_image(w, g->col->image, g->map->counter_x, g->map->counter_y);
	else if (c == '1')
		put_image(w, g->img_wall, g->map->counter_x, g->map->counter_y);
	else
		put_image(w, g->img_ground, g->map->counter_x, g->map->counter_y);
}
