/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_lighting_ratio.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:21:23 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 19:43:38 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "config.h"
#include <stdbool.h>

bool	is_invalid_lighting_ratio(const double a)
{
	return (is_invalid_double_ratio(a, MAX_LIGHTING_RATIO, MIN_LIGHTING_RATIO));
}
