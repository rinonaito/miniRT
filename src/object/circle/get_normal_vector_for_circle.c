/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_circle.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:33:48 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/06 19:34:44 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "object.h"

t_vector3d	get_normal_vector_for_circle(
	const t_ray ray,
	const double hit_distance,
	const void *object)
{
	t_circle	*circle;

	circle = (t_circle *)object;
	return (get_normal_vector_for_2d(ray, hit_distance, circle->direction_vec));
}
