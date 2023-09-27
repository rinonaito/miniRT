/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:58:03 by rnaito            #+#    #+#             */
/*   Updated: 2023/09/27 22:18:07 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "types.h"

int	convert_rgb_in_int(t_rgb rgb)
{
	int	color;

	color = (rgb.red << 16) | (rgb.green << 8) | rgb.blue;
	return (color);
}
