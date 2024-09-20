/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: droied <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:29:18 by droied            #+#    #+#             */
/*   Updated: 2024/09/20 08:09:22 by deordone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minimap.h"

typedef enum e_orient
{
	NORTH = 'N',
	EAST = 'E',
	SOUTH = 'S',
	WEST = 'W'
}					t_orient;

typedef struct s_fvec
{
	float			x;
	float			y;
}					t_fvec;

typedef struct s_ivec
{
	int32_t			x;
	int32_t			y;
}					t_ivec;

typedef enum e_cell
{
	SPACE = '0',
	WALL = '1',
	DOOR = 'D'
}					t_cell;

typedef struct s_player
{
	t_fvec			pos;
	t_fvec			plane;
	t_fvec			dir;
	t_orient		spawn_orient;
}					t_player;

typedef struct s_map
{
	t_cell			**cells;
	int32_t			rows;
	int32_t			cols;
}					t_map;

typedef struct s_textures
{
	mlx_texture_t	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*west;
}					t_textures;

typedef struct s_minimap
{
	t_ivec			pos;
	t_ivec			dir;
	t_ivec			player;
	t_fvec			step;
	t_fvec			scale;
	uint32_t		radius;
}					t_minimap;

typedef struct s_scene
{
	t_map			map;
	t_player		player;
	t_textures		textures;
	t_minimap		minimap;
	int8_t			refresh;
	int32_t			floor_color;
	int32_t			ceiling_color;
}					t_scene;

t_scene				create_scene(int, char **);
void				init_scene(t_scene *, mlx_image_t *);
void				minimap(mlx_image_t *image, t_scene scene);

#endif /* SCENE_H */
