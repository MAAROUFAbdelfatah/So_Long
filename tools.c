/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarouf <amaarouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:11:34 by amaarouf          #+#    #+#             */
/*   Updated: 2022/08/18 18:32:38 by amaarouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_all(t_game *game, t_window *window, char *error)
{
	if (game)
	{
		ft_free_tab(game->map->array_map);
		free(game->col);
		free(game->exits);
		free(game->player);
		free(game->map);
		free(game);
	}
	if (window)
	{
		free(window->win);
		free(window->mlx);
		free(window);
		exit(0);
	}
	if (error)
	{
		ft_printf("Error\n %s", error);
		exit(0);
	}
}

size_t	ft_strlen_2d(char **s)
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

int	close_win(void)
{
	exit(EXIT_SUCCESS);
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
