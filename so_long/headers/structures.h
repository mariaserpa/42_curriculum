/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:47:27 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/03/20 15:18:10 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_pos
{
	size_t	pos_x;
	size_t	pos_y;
}	t_pos;

typedef struct s_tile
{
	char	type;
	int		check;
}	t_tile;

typedef struct s_player
{
	t_pos	pos;
	t_pos	start_pos;
}	t_player;

typedef struct s_sprite
{
	int		pos_w;
	int		pos_h;
	void	*sprite_img;
}	t_sprite;

typedef struct s_map
{
	char		*path;
	char		**grid;
	t_tile		**tile;
	size_t		grid_height;
	size_t		grid_width;
	int			fd;
	BOOL		exit; //verificar nome
	int			collectibles; //verificar nome
}	t_map;


typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	t_map		map;
	t_player	player;
	int			qt_moves;
	int			qt_collected;
	int			collectibles;
	int			start;
	int			exit;
	int			bpp;
	int			line_length;
	int			endian;
	t_sprite	sprite_wall;
	t_sprite	sprite_collectible;
	t_sprite	sprite_start;
	t_sprite	sprite_exit;
	t_sprite	sprite_background;
	t_sprite	sprite_player;
	t_sprite	sprite_win;
	t_sprite	*qt_display;
	BOOL		victory;
	BOOL		end_game;
}	t_vars;


#endif