/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:48:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/23 18:19:53 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "types.h"

t_object	create_object(
				const void *object,
				double (*fp_hit_object)(const t_ray, const void *),
				t_vector3d (*fp_get_normal_vector_for_object)(
					const t_ray, const t_vector3d, const void *),
				int (*fp_get_pixel_color_for_object)(
					const void *, const t_ray, const t_vector3d));

void		set_ambient(t_scene *scene, const char *const line);

void		set_camera(t_scene *scene, const char *const line);

t_circle	*set_circle(
				const t_vector3d center,
				const double diameter,
				const t_vector3d direction_vec,
				const t_rgb rgb);

void		set_cone_side(t_scene *scene, const char *const line);

void		set_cone(t_scene *scene, const char *const line);

void		set_cylinder(t_scene *scene, const char *const line);

void		set_light(t_scene *scene, const char *const line);

void		set_plane(t_scene *scene, const char *const line);

void		set_sphere(t_scene *scene, const char *const line);

void		set_tube(t_scene *scene, const char *const line);

void		set_vector3d(
				t_vector3d *coordinate,
				double x,
				double y,
				double z);

void		set_vector2d(
				t_vector2d *coordinate,
				double x,
				double y);

void		set_ray(
				t_ray *ray,
				const t_vector3d origin,
				const t_vector3d xyz,
				const t_ambient_lighting ambient);

void		resize_objects_array(t_object **objects, const size_t objects_num);

#endif
