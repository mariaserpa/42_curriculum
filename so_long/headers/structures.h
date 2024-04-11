/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabelo- <mrabelo-@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:47:27 by mrabelo-          #+#    #+#             */
/*   Updated: 2024/04/09 15:29:58 by mrabelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_pos
{
	int	pos_x;
	int	pos_y;
}	t_pos;

typedef struct s_count
{
	int	qt_player;
	int	qt_collectibles;
	int	qt_exit;
}	t_count;

typedef struct s_map
{
	char	*map_path;
	char	**map;
	char	**map_copy;
	t_pos	display;
	t_pos	exit;
	int		width;
	int		height;
	int		fd;

}	t_map;

typedef struct s_img
{
	char	*background;
	char	*wall;
	char	*exit;
	char	*exit_open;
	char	*player_up;
	char	*player_down;
	char	*player_right;
	char	*player_left;
	char	*collectibles;
	char	*enemy;
}	t_img;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_img		img;
	t_count		counts;
	t_pos		player;
	int			qt_moves;
	int			qt_collected;
	int			available_collectibles;
	int			viable_exit;
	int			victory;
	int			end_game;
}	t_vars;

#endif
