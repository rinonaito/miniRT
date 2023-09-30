/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_in_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:59:18 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/30 14:24:29 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "config.h"

int	convert_rgb_in_int(t_rgb rgb)
{
	int	color;

	color = (rgb.red << RED_SHIFT) | (rgb.green << GREEN_SHIFT) | rgb.blue;
	return (color);
}
