/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition_vector3d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:00:32 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 18:01:13 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_vector3d	addition_vector3d(const t_vector3d a, const t_vector3d b)
{
	t_vector3d result;

	result.x = a.x + b.x; 
	result.y = a.y + b.y; 
	result.z = a.z + b.z; 
	return (result);
}
