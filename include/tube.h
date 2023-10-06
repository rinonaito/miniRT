/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:00:46 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/06 16:19:39 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUBE_H
# define TUBE_H

# include "types.h"

double		hit_tube(const t_ray ray, const void *object);

t_vector3d	get_normal_vector_for_2d(
				const t_ray ray,
				const double hit_distance,
				const t_vector3d object_center,
				const t_vector3d object_direction);

t_vector3d	get_normal_vector_for_3d(
				const t_ray ray,
				const double hit_distance,
				const t_vector3d object_center,
				const t_vector3d object_direction);

t_vector3d	get_normal_vector_for_tube(
				const t_ray ray,
				const double hit_distance,
				const void *object);

int			get_pixel_color_for_tube(
				const void *object,
				const t_ray ray,
				const double ambient_lighting_ratio);

#endif