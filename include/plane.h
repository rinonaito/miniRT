/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:20:19 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/03 22:02:38 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "types.h"

double		hit_plane(const t_ray ray, const void *object);

t_vector3d	get_normal_vector_for_plane(
				const t_ray ray,
				const double hit_distance,
				const void *object);

int			get_pixel_color_for_plane(
				const void *object,
				const t_ray ray,
				const double ambient_lighting_ratio);

#endif