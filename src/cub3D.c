/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:43:11 by sguzman           #+#    #+#             */
/*   Updated: 2024/06/19 22:15:35 by sguzman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	terminate(t_game game)
{
	mlx_terminate(game.mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.map = load_map(argc, argv);
	rendering_setup(game);
	terminate(game);
	return (EXIT_SUCCESS);
}
