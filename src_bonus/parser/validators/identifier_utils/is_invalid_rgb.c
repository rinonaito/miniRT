/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:22:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/28 21:49:53 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "config.h"
#include <stdbool.h>

bool	is_invalid_rgb(const t_rgb rgb)
{
	return (is_invalid_int(rgb.red, MAX_COLOR_RANGE, MIN_COLOR_RANGE)
		|| is_invalid_int(rgb.green, MAX_COLOR_RANGE, MIN_COLOR_RANGE)
		|| is_invalid_int(rgb.blue, MAX_COLOR_RANGE, MIN_COLOR_RANGE));
}
