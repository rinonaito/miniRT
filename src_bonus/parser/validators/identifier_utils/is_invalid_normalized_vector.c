/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_normalized_vector.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:22:11 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 21:49:46 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "vector.h"
#include <stdbool.h>

bool	is_invalid_normalized_vector(const t_vector3d direction_vec)
{
	t_vector3d	normalized;

	normalized = normalize_vector3d(direction_vec);
	return (normalized.x != direction_vec.x
		|| normalized.y != direction_vec.y
		|| normalized.z != direction_vec.z);
}
