/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_circle_center.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 19:36:56 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 19:37:43 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parser.h"
#include "types.h"

t_vector3d	get_circle_center(
	t_vector3d base_point,
	t_vector3d direction_vec,
	double distance)
{
	t_vector3d	center;

	center.x = base_point.x + direction_vec.x * distance;
	center.y = base_point.y + direction_vec.y * distance;
	center.z = base_point.z + direction_vec.z * distance;
	return (center);
}