/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:00:43 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/14 17:51:01 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "types.h"
# include <stdbool.h>

void	set_lighting_ratio(
			t_ray *ray,
			const t_vector3d point,
			const t_scene scene,
			const t_vector3d normal_vector);

double	get_specular_lighting_ratio(
			t_light light,
			t_vector3d normal_vector,
			t_vector3d point,
			t_vector3d camera_origin);

double	calculate_lighting_ratio(
			const t_vector3d ray,
			const t_vector3d normal_vector,
			const double lighting_ratio);

bool	is_hit_by_spot_light(
			const t_scene scene,
			const t_vector3d point,
			const t_light light);

#endif