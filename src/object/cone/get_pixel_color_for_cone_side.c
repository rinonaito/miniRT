/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_cone_side.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:14:10 by rnaito            #+#    #+#             */
/*   Updated: 2023/11/03 13:06:06 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "color.h"
#include "object.h"

int	get_pixel_color_for_cone_side(
	const void *object,
	const t_ray ray)
{
	t_cone	*cone;

	cone = (t_cone *)object;
	return (get_pixel_color_for_object(cone->color,
			ray.rgb,
			ray.lighting_ratio));
}
