/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:00:43 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/04 13:23:28 by yshimoma         ###   ########.fr       */
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

double	calculate_lighting_ratio(
			const t_vector3d ray,
			const t_vector3d normal_vector,
			const double lighting_ratio);

bool	is_hit_by_spot_light(
			t_ray spot_light_ray,
			const t_scene scene,
			t_vector3d original_point,
			const t_light light);

#endif
