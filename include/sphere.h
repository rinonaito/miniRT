/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:41:51 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/03 22:02:54 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include <stdbool.h>
# include <stdlib.h>
# include "types.h"

double		hit_sphere(const t_ray ray, const void *object);

t_vector3d	get_normal_vector_for_sphere(
				const t_ray ray,
				const double hit_distance,
				const void *object);

int			get_pixel_color_for_sphere(
				const void *object,
				const t_ray ray,
				const double ambient_lighting_ratio);

#endif