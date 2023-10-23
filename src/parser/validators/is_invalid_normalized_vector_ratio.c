/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_invalid_normalized_vector_ratio.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 19:22:11 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/22 19:43:56 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "config.h"
#include <stdbool.h>

bool	is_invalid_normalized_vector_ratio(
	const double x,
	const double y,
	const double z)
{
	return (is_invalid_double_ratio(x, MAX_VECTOR_RATIO, MIN_VECTOR_RATIO)
		&& is_invalid_double_ratio(y, MAX_VECTOR_RATIO, MIN_VECTOR_RATIO)
		&& is_invalid_double_ratio(z, MAX_VECTOR_RATIO, MIN_VECTOR_RATIO));
}
