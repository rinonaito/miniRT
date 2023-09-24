/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_vector3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:45:31 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/24 20:36:11 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

double	dot_vector3d(const t_vector3d a, const t_vector3d b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
