/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sguzman <sguzman@student.42barcelona.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:43:11 by sguzman           #+#    #+#             */
/*   Updated: 2024/07/06 18:44:58 by droied           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	begin_window(t_core *core, int32_t width, int32_t height)
{
	mlx_t		*mlx;
	mlx_image_t	*image;

	mlx = mlx_init(width, height, PROGRAM, 0);
	if (mlx == 0)
		libx_error("mlx error");
	mlx_get_monitor_size(0, &width, &height);
	mlx_set_window_size(mlx, width, height);
	mlx_set_window_pos(mlx, 0, 0);
	image = mlx_new_image(mlx, width, height);
	if (image == 0 || (mlx_image_to_window(mlx, image, 0, 0)) < 0)
		libx_error("mlx error");
	core->mlx = mlx;
	core->img = image;
}

int	main(int argc, char **argv)
{
	t_core	core;

	/* setup argc and argc to scene */
	core.scene = create_scene(argc, argv);
	/* setup MLX; create window; setup width, heitht, image */
	begin_window(&core, 1280, 960);
	/* rasterize in image */
	start_renderer(core);
	// rendering(core.image, core.scene);
	// separation of concerns
	mlx_terminate(core.mlx);
	return (EXIT_SUCCESS);
}
