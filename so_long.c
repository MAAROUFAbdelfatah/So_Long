/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:31:29 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/18 12:37:49 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_error(char *s)
{
    ft_printf("Error\n %s", s);
    exit(0);
}

size_t  ft_strlen_2d(char **s)
{
	size_t	i;

	i = 0;
	while (*s)
    {
        i++;
        s++;
    }
	return (i);
}

int    counter(t_game *game, char c)
{
    if (c == 'P')
    {
        game->player->p_counter++;
        return (1);
    }
    else if (c == 'C')
    {
        game->collectibles->c_counter++;
        return (1);
    }
    else if (c == 'E')
    {
        game->exits->e_counter++;  
        return (1);
    }
    return (0);
}

void    line_checker(t_game *game)
{
    int     i;
    char    *s;

    s = game->map->line;  
    i = 0;
    while (s[i] && s[i] != '\n')
    {
        if(s[i] == '1' || s[i] == '0' || counter(game, s[i]))
            i++;
        else
        {
            free_all(game, NULL, "check the map, 0, 1, C, P or E");
        }
    }
}

char	*get_line_no_nl(int fd)
{
	char	*line;
	
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	if(line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	return (line);
}

void	ft_realloc(t_game *game)
{
	char	**holder;
	int		i;

    holder = game->map->array_map; 
	game->map->array_map = (char**) malloc((sizeof(char*) * (game->map->height + 2)));
	
    i = 0;
	while(holder[i])
	{
		game->map->array_map[i] = holder[i];
		i++;
	}
    free(holder);
	game->map->array_map[i] = game->map->line;
    game->map->array_map[i+1] = NULL;
}

void free_all(t_game *game, t_window *window, char *error)
{
    
    ft_free_tab(game->map->array_map);
    free(game->collectibles);
    free(game->exits);
    free(game->player);
    free(game->map);
    free(game);
    if (window)
    {
        free(window->win);
	    free(window->mlx);
	    free(window);
        exit(0);
    }
    if (error)
        ft_error(error);
}

void    check_walls(t_game *game)
{
    int     i;
	int		j;

    i = 0;
    while (game->map->array_map[i])
    {
		j = 0;
		if(i == 0 || i == game->map->height - 1)
		{
			while (game->map->array_map[i][j])
			{
				if (game->map->array_map[i][j] != '1')
                    free_all(game, NULL, "check the map, wall");
				j++;
			}
		}
		else
			if (game->map->array_map[i][game->map->width - 1] != '1' || game->map->array_map[i][0] != '1')
                free_all(game, NULL, "check the map, wall");
		i++;
    }
}

void	map_checker(t_game *game)
{
    int		len_holder;
	
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
			break;
		ft_realloc(game);
    }
	if (game->player->p_counter != 1 || game->exits->e_counter != 1 || game->collectibles->c_counter < 1)
        free_all(game, NULL, "check the map, P, C or E");
	check_walls(game);
}

t_map   *map_initializer(char *path)
{ 
    t_map   *map;
    
    map = (t_map*) malloc(sizeof(t_map));
	map->array_map = (char**) malloc(sizeof(char*)*2);
    map->fd_map = open(path, O_RDONLY);
    map->height = 0;
    map->width = 0;
    map->counter_x = 0;
    map->counter_x = 0;
    return (map);
}

t_player	*player_initializer()
{
	t_player	*player;
	
	player = (t_player*) malloc(sizeof(t_player));
	player->p_counter = 0;
	player->image = "images/rabbit.xpm"; 
    player->moves_counter = 0;
	return (player);
}

t_collectibles	*collectibles_initializer()
{
	t_collectibles	*collectibles;

	collectibles = (t_collectibles*) malloc(sizeof(t_collectibles));
	collectibles->c_counter = 0;
	collectibles->image = "images/carrot.xpm";
	return	(collectibles);
}

t_exits	*exits_initializer()
{
	t_exits	*exits;

	exits = (t_exits*) malloc(sizeof(t_exits));
	exits->e_counter = 0;
	exits->image01 = "images/close_door.xpm";
	exits->image02 = "images/open_door.xpm";
	return (exits);
}

t_game  *game_initializer(char *path)
{
    t_game			*game;
	
    game = (t_game*) malloc(sizeof(t_game));
   
	game->collectibles = collectibles_initializer();
	game->exits = exits_initializer();
	game->player = player_initializer();
    game->map = map_initializer(path);
	game->img_ground = "images/ground.xpm";
	game->img_wall = "images/wall.xpm";
    return (game);
}

t_window	*window_initializer(t_game *game)
{
	t_window	*window;

	window = (t_window*) malloc(sizeof(t_window));
	window->mlx = mlx_init();
	window->win_width = game->map->width * IMAGE_SIZE;
	window->win_height = game->map->height * IMAGE_SIZE;
	window->win_name = WIN_NAME;
	window->win = mlx_new_window(window->mlx, window->win_width, window->win_height, window->win_name);
    window->game = game;
	return (window);
	
}

int main(int argc, char **argv)
{
    char		**path;
    char		*extension;
    t_game		*game;

    if (argc != 2)
        ft_error("check the number of args");
    path = ft_split(argv[1], '.');
    extension = path[(ft_strlen_2d(path) - 1)];
    if (ft_strncmp(extension, "ber", 3))
    {
        free(path);
        free(extension);
        ft_error("check file extension");
    }
    game = game_initializer(argv[1]);
    map_checker(game);
    generate_map(game);
    return (0);
}