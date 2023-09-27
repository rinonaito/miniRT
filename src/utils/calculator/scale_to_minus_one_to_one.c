/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_to_minus_one_to_one.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:34:42 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/27 20:24:22 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/**
 * 0.0 ~ 1.0 → -1.0 ~ 1.0にする関数
*/
double	scale_to_minus_one_to_one(double value)
{
	return (SCENE_SCALE * value - SCENE_OFFSET);
}
