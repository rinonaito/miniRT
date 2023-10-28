/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_coordinate.c         		            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:35:18 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 18:16:11 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "config.h"
#include "types.h"
#include <stdbool.h>

/**
 * x, y, zの座標が正しい範囲か判定する
*/
//TODO:上限値をどうするか相談する
bool	is_invalid_coordinate(const t_vector3d cordinate)
{
	return (is_invalid_double(cordinate.x, MAX_COORDINATE, MIN_COORDINATE)
		|| is_invalid_double(cordinate.y, MAX_COORDINATE, MIN_COORDINATE)
		|| is_invalid_double(cordinate.z, MAX_COORDINATE, MIN_COORDINATE)
	);
}
