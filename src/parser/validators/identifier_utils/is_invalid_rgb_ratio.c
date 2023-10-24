/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_rgb_ratio.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:22:50 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 19:44:10 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "config.h"
#include <stdbool.h>

bool	is_invalid_rgb_ratio(const int r, const int g, const int b)
{
	return (is_invalid_int_ratio(r, MAX_COLOR_RANGE, MIN_COLOR_RANGE)
		&& is_invalid_int_ratio(g, MAX_COLOR_RANGE, MIN_COLOR_RANGE)
		&& is_invalid_int_ratio(b, MAX_COLOR_RANGE, MIN_COLOR_RANGE));
}
