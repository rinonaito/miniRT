/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_cone.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:03:40 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/17 11:04:49 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "object.h"

t_vector3d	get_normal_vector_for_cone(
	const t_ray ray,
	const void *object)
{
	t_cone	*cone;

	cone = (t_cone *)object;
	return (get_normal_vector_for_3d(ray, cone->top));
}
