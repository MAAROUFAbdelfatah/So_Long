/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:42:07 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/18 18:40:01 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_initializer(t_game *game, char *path)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	map->fd_map = open(path, O_RDONLY);
	if (map->fd_map < 0)
	{
		free(map);
		free(game);
		ft_printf("check the file path.");
		exit(0);
	}
	map->array_map = (char **) malloc(sizeof(char *) * 2);
	map->height = 0;
	map->width = 0;
	map->counter_x = 0;
	map->counter_x = 0;
	return (map);
}

t_player	*player_initializer(void)
{
	t_player	*player;

	player = (t_player *) malloc(sizeof(t_player));
	player->p_counter = 0;
	player->image = "images/rabbit.xpm";
	player->moves_counter = 0;
	return (player);
}

t_collectibles	*collectibles_initializer(void)
{
	t_collectibles	*collectibles;

	collectibles = (t_collectibles *) malloc(sizeof(t_collectibles));
	collectibles->c_counter = 0;
	collectibles->image = "images/carrot.xpm";
	return (collectibles);
}

t_exits	*exits_initializer(void)
{
	t_exits	*exits;

	exits = (t_exits *) malloc(sizeof(t_exits));
	exits->e_counter = 0;
	exits->image01 = "images/close_door.xpm";
	exits->image02 = "images/open_door.xpm";
	return (exits);
}

t_game	*game_initializer(char *path)
{
	t_game	*game;

	game = (t_game *) malloc(sizeof(t_game));
	game->map = map_initializer(game, path);
	game->col = collectibles_initializer();
	game->exits = exits_initializer();
	game->player = player_initializer();
	game->img_ground = "images/ground.xpm";
	game->img_wall = "images/wall.xpm";
	return (game);
}
