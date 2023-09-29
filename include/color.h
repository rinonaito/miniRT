/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:34:35 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/29 19:27:54 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "types.h"

int		convert_rgb_in_int(t_rgb rgb);

t_rgb	get_pixel_color(
			t_rgb original_color,
			t_vector3d nomal_vector,
			double lighting_ratio);

#endif
