/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subtraction_vector3d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:13:28 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 15:46:00 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_vector3d	subtraction_vector3d(const t_vector3d a, const t_vector3d b)
{
	t_vector3d result;

	result.x = a.x - b.x; 
	result.y = a.y - b.y; 
	result.z = a.z - b.z; 
	return (result);
}
