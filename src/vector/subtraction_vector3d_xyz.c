/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction_vector3d_xyz.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:02:46 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 16:02:51 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"

t_vector3d	subtraction_vector3d_xyz(
		const t_vector3d a,
		const double x,
		const double y,
		const double z)
{
	t_vector3d result;

	result.x = a.x - x; 
	result.y = a.y - y; 
	result.z = a.z - z; 
	return (result);
}
