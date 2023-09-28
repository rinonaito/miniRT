/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:07:52 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/28 21:47:42 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include "types.h"

void	set_color_in_image(
			t_ray *ray,
			t_vector3d xyz,
			t_vector2d uv,
			t_mlx_data *mlx_data,
			t_scene scene);

void	my_mlx_pixel_put(
			t_mlx_data *mlx_data,
			int x,
			int y,
			int color);

int		handle_key_press(int keycode, void *value);

int		handle_window_close(void *value);

#endif
