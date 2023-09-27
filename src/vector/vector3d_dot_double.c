/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3d_dot_double.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:29:05 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/27 22:03:18 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_vector3d	vector3d_dot_double(t_vector3d vec, double t)
{
	t_vector3d	result;

	result.x = t * vec.x;
	result.y = t * vec.y;
	result.z = t * vec.z;
	return (result);
}
