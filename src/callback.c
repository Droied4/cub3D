/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droied <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:47:13 by droied            #+#    #+#             */
/*   Updated: 2024/08/07 19:21:09 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	event_listener(mlx_t *mlx, t_scene *scene)
{
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		scene->refresh = 1;
		scene->player.cor.y -= 10;
		printf("UP\n");
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		scene->refresh = 1;
		scene->player.cor.y += 10;
		printf("DOWN\n");
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		scene->refresh = 1;
		scene->player.cor.x -= 10;
		printf("LEFT\n");
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		scene->refresh = 1;
		scene->player.cor.x += 10;
		printf("RIGHT\n");
	}
}
