/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_circle.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:33:48 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/03 19:44:30 by yshimoma         ###   ########.fr       */
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
