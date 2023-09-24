/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:07:52 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 16:17:04 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

void	set_color_in_image(t_ray ray, t_vector2d xy, t_mlx_data *mlx_data, t_scene scene);
void	my_mlx_pixel_put(
		t_mlx_data *mlx_data,
		int x,
		int y,
		int color);

#endif
