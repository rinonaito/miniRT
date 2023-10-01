
#ifndef LIGHT_H
# define LIGHT_H

# include "types.h"

void	set_lighting_ratio(
			t_ray *ray,
			const t_vector3d point,
			const t_scene scene,
			const t_vector3d normal_vector);

double	get_specular_light(
			t_light light,
			t_vector3d normal_vector,
			t_vector3d point,
			t_vector3d camera_origin);

double	calculate_lighting_ratio(
		const t_vector3d ray,
		const t_vector3d normal_vector,
		const double lighting_ratio);

#endif