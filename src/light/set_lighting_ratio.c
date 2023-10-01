/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_lighting_ratio.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:02:06 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/01 16:03:43 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "light.h"

void	set_lighting_ratio(
	t_ray *ray,
	const t_vector3d point,
	const t_scene scene,
	const t_vector3d normal_vector)
{
	size_t		i;
	double		diffuse;
	double		specular;
	t_vector3d	light_vec;

	ray->lighting_ratio += scene.ambient.lighting_ratio;
	i = 0;

	while (i < scene.lights_num)
	{
		light_vec = subtraction_vector3d(point, scene.lights[i].origin);
		diffuse = calculate_lighting_ratio(
				normalize_vector3d(light_vec),
				normal_vector,
				scene.lights[i].lighting_ratio);
		specular = get_specular_light(scene.lights[i], normal_vector, point,
				scene.camera.origin);
		ray->lighting_ratio += diffuse + specular;
		i++;
	}
}