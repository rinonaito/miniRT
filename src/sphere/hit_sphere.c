/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:42:36 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/24 20:35:57 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <vector.h>

//TODO:以下のコードを理解する
bool	hit_sphere(t_ray ray, t_vector3d center, double radius)
{		
	t_vector3d	diff_oc;
	double		a;
	double		b;
	double		c;
	double		discriminant;

	diff_oc = subtraction_vector3d(ray.origin, center);
	a = dot_vector3d(ray.direction_vec, ray.direction_vec);
	b = 2.0 * dot_vector3d(diff_oc, ray.direction_vec);
	c = dot_vector3d(diff_oc, diff_oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}
