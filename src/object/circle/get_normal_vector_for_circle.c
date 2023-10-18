/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_circle.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:33:48 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/18 21:46:24 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "object.h"

t_vector3d	get_normal_vector_for_circle(
	const t_ray ray,
	const t_vector3d point,
	const void *object)
{
	t_circle	*circle;

	(void)point;
	circle = (t_circle *)object;
	return (get_normal_vector_for_2d(ray, circle->direction_vec));
}
