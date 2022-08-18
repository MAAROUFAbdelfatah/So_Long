/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:31:29 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/18 15:09:42 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	counter(t_game *game, char c)
{
	if (c == 'P')
	{
		game->player->p_counter++;
		return (1);
	}
	else if (c == 'C')
	{
		game->col->c_counter++;
		return (1);
	}
	else if (c == 'E')
	{
		game->exits->e_counter++;
		return (1);
	}
	return (0);
}

char	*get_line_no_nl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

void	ft_realloc(t_game *g)
{
	char	**holder;
	int		i;
	int		size;

	i = 0;
	holder = g->map->array_map;
	size = g->map->height + 2;
	g->map->array_map = (char **) malloc((sizeof(char *) * size));
	while (holder[i])
	{
		g->map->array_map[i] = holder[i];
		i++;
	}
	free(holder);
	g->map->array_map[i] = g->map->line;
	g->map->array_map[i + 1] = NULL;
}

t_window	*window_initializer(t_game *game)
{
	t_window	*w;

	w = (t_window *) malloc(sizeof(t_window));
	w->mlx = mlx_init();
	w->win_width = game->map->width * IMAGE_SIZE;
	w->win_height = game->map->height * IMAGE_SIZE;
	w->win_name = WIN_NAME;
	w->win = mlx_new_window(w->mlx, w->win_width, w->win_height, w->win_name);
	w->game = game;
	return (w);
}

int	main(int argc, char **argv)
{
	char		**path;
	char		*extension;
	t_game		*game;

	if (argc != 2)
		free_all(NULL, NULL, "check the number of args");
	path = ft_split(argv[1], '.');
	extension = path[(ft_strlen_2d(path) - 1)];
	if (ft_strncmp(extension, "ber", 3))
	{
		free(path);
		free(extension);
		free_all(NULL, NULL, "check file extension");
	}
	game = game_initializer(argv[1]);
	map_checker(game);
	generate_map(game);
	return (0);
}
