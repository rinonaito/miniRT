/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_is_inside_of_object.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:25:41 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/17 21:26:27 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "types.h"
#include "vector.h"

bool	camera_is_inside_of_object(
		t_vector3d normal_vector,
		t_vector3d ray_direction)
{
	return (dot_vector3d(normal_vector, ray_direction) > 0.0);
}
