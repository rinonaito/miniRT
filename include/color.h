/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 21:34:35 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/27 22:18:13 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "types.h"

int		convert_rgb_in_int(t_rgb rgb);
t_rgb	get_pixel_color(t_rgb	original_color, t_vector3d N);

#endif
