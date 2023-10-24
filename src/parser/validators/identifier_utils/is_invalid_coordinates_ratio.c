/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_coordinates_ratio.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:35:18 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/10 22:19:58 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdbool.h>

/**
 * x, y, zの座標が正しい範囲か判定する
*/
//TODO:上限値をどうするか相談する
bool	is_invalid_coordinates_ratio(
	const double x,
	const double y,
	const double z)
{
	return (is_invalid_double_ratio(x, 1000, -1000)
		&& is_invalid_double_ratio(y, 1000, -1000)
		&& is_invalid_double_ratio(z, 1000, -1000));
}
