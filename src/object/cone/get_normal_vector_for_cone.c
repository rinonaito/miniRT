/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_tube.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:02:17 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/10 14:23:22 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "object.h"

t_vector3d	get_normal_vector_for_tube(
	const t_ray ray,
	const void *object)
{
	t_tube	*tube;

	tube = (t_tube *)object;
	return (get_normal_vector_for_3d(ray, tube->center));
}
