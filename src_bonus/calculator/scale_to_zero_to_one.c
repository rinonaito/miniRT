/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_to_zero_to_one.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:34:45 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/27 20:23:10 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

/**
 * -1.0 ~ 1.0 → 0.0 ~ 1.0にする関数
*/
double	scale_to_zero_to_one(double value)
{
	return (0.5 * (value + SCENE_OFFSET));
}