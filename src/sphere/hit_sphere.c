/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:42:36 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/24 17:02:13 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <vector.h>

#include <stdio.h>
bool	hit_sphere(t_ray ray, t_vector3d center, double radius)
{		
	t_vector3d diff_oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	diff_oc = subtraction_vector3d(ray.origin, center);
	a = dot_vector3d(ray.direction_vec, ray.direction_vec);
	b = 2.0 * dot_vector3d(diff_oc, ray.direction_vec);
	c = dot_vector3d(diff_oc, diff_oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	printf("IN HIT_SPHERE\n");
	printf("center[%lf][%lf][[%lf]\n", center.x, center.y, center.z);
	printf("ray[%lf][%lf][[%lf]\n", ray.direction_vec.x, ray.direction_vec.y, ray.direction_vec.z);
	printf("diff_oc[%lf][%lf][[%lf]\n", diff_oc.x, diff_oc.y, diff_oc.z);
	printf("discriminant = %lf\n", discriminant);
	return (discriminant > 0);
}