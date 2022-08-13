/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 18:31:29 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/13 21:38:37 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_error(char *s)
{
    ft_printf("Error: %s", s);
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
        game->p_counter++;
        return (1);
    }
    else if (c == 'C')
    {
        game->c_counter++;
        return (1);
    }
    else if (c == 'E')
    {
        game->e_counter++;  
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
            free(s);
            free(game->map);
            free(game);
            ft_error("check the map, 0, 1, C, P or E");
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
	int		j;

	i = 0;
	j = 0;
	holder = game->map->map; 
	game->map->map = (char**) malloc(sizeof(char*) * game->map->nbr_lines);
	
	while(holder[i])
	{
		game->map->map[i] = holder[i];
		i++;
	}
	game->map->map[i] = ;
	ft_printf("|amaarouf|");
	// i = 0;
	// while(game->map->map[i])
	// {
	// 	ft_printf("map: %s", *game->map->map[i]);
	// 	i++;	
	// }
	
}

void	map_checker(t_game *game)
{
    int		len_holder;
	
	game->map->line = get_line_no_nl(game->map->fd_map);
	len_holder = ft_strlen(game->map->line);
    while (game->map->line)
    {	
		game->map->nbr_lines++;
		ft_realloc(game);
        game->map->width = ft_strlen(game->map->line);
        if (len_holder != game->map->width)
            ft_error("check the map, rectangular");
        line_checker(game);
    	game->map->line = get_line_no_nl(game->map->fd_map);
		if (!game->map->line)
			break;
    }
	if (game->p_counter != 1 || game->e_counter < 1 || game->c_counter < 1)
			ft_error("check the map, P, C or E");
}

t_map   *map_initializer(char *path)
{ 
    t_map   *map;
    
    map = (t_map*) malloc(sizeof(t_map));
	map->map = (char**) malloc(sizeof(char*)*1);
    map->fd_map = open(path, O_RDONLY);
    map->height = 0;
    map->width = 0;
	map->nbr_lines = 1;
    return (map);
}

t_game  *game_initializer(t_map *map)
{
    t_game  *game;
    
    game = (t_game*) malloc(sizeof(t_game));
    game->c_counter = 0;
    game->e_counter = 0;
    game->p_counter = 0;
    game->map = map;
    return game;
}

int main(int argc, char **argv)
{
    char    **path;
    char    *extension;
    t_game  *game;
    t_map   *map;

    if (argc != 2)
        ft_error("check the number of args");
    path = ft_split(argv[1], '.');
    extension = path[(ft_strlen_2d(path) - 1)];
    if (ft_strncmp(extension, "ber", 3))
        ft_error("check file extension");
    map = map_initializer(argv[1]);
    game = game_initializer(map);
    map_checker(game);
    return (0);
}