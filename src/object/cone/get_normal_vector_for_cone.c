/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_cone.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:03:40 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/18 21:47:47 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "object.h"

t_vector3d	get_normal_vector_for_cone(
	const t_ray ray,
	const t_vector3d point,
	const void *object)
{
	t_cone	*cone;

	(void)point;
	cone = (t_cone *)object;
	return (get_normal_vector_for_3d(ray, cone->top));
}
