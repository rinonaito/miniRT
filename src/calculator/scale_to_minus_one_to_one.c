/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_to_minus_one_to_one.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:34:42 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/02 18:14:00 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"
#include <stdbool.h>

/**
 * 0.0 ~ 1.0 → -1.0 ~ 1.0にする関数
*/
double	scale_to_minus_one_to_one(double value, bool invert)
{
	if (invert)
		return (SCENE_OFFSET - SCENE_SCALE * value);
	return (SCENE_SCALE * value - SCENE_OFFSET);
}
