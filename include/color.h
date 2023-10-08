/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:34:35 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/06 15:16:48 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "types.h"

int		convert_rgb_in_int(t_rgb rgb);

t_rgb	reflect_lighting_ratio_in_color(
			const t_rgb object_rgb,
			const t_rgb light_rgb,
			const double ambient_lighting_ratio,
			const double direct_lighting_ratio);

#endif
