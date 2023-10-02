/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:08:45 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/03 22:03:24 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include <math.h>

double	hit_plane(const t_ray ray, const void *object)
{
	t_plane		*plane;
	double		denom;
	double		t;
	t_vector3d	oc;

	plane = (t_plane *)object;
	denom = dot_vector3d(ray.direction_vec, plane->direction_vec);
	if (fabs(denom) > 0.0)
	{
		oc = subtraction_vector3d(ray.origin, plane->coordinate);
		t = dot_vector3d(oc, plane->direction_vec) / denom;
		if (t >= 0)
			return (t);
	}
	return (INFINITY);
}
