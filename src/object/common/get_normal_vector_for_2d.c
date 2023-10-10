/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal_vector_for_2d.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:53:32 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/10 15:52:31 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

t_vector3d	get_normal_vector_for_2d(
	const t_ray ray,
	const t_vector3d object_direction)
{
	(void)ray;
	return (normalize_vector3d(object_direction));
}
