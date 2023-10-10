/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:57:36 by naitorino         #+#    #+#             */
/*   Updated: 2023/10/10 14:23:26 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "types.h"

//common.h
t_vector3d	get_normal_vector_for_2d(
				const t_ray ray,
				const t_vector3d object_direction);

t_vector3d	get_normal_vector_for_3d(
				const t_ray ray,
				const t_vector3d object_center);

int			get_pixel_color_for_object(
				t_rgb object_rgb,
				t_rgb ray_rgb,
				double ambient_lighting_ratio,
				double direct_lighting_ratio);

//sphere.h
double		hit_sphere(const t_ray ray, const void *object);

t_vector3d	get_normal_vector_for_sphere(
				const t_ray ray,
				const void *object);

int			get_pixel_color_for_sphere(
				const void *object,
				const t_ray ray,
				const double ambient_lighting_ratio);

//plane.h
double		hit_plane(const t_ray ray, const void *object);

t_vector3d	get_normal_vector_for_plane(
				const t_ray ray,
				const void *object);

int			get_pixel_color_for_plane(
				const void *object,
				const t_ray ray,
				const double ambient_lighting_ratio);

//circle.h
double		hit_circle(const t_ray ray, const void *object);

t_vector3d	get_normal_vector_for_circle(
				const t_ray ray,
				const void *object);

int			get_pixel_color_for_circle(
				const void *object,
				const t_ray ray,
				const double ambient_lighting_ratio);

//tube.h
double		hit_tube(const t_ray ray, const void *object);

t_vector3d	get_normal_vector_for_tube(
				const t_ray ray,
				const void *object);

int			get_pixel_color_for_tube(
				const void *object,
				const t_ray ray,
				const double ambient_lighting_ratio);

#endif
