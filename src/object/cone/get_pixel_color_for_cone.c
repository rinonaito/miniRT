/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_cone.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:14:10 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/17 11:14:49 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "vector.h"
#include "color.h"
#include "object.h"

int	get_pixel_color_for_cone(
	const void *object,
	const t_ray ray)
{
	t_cone	*cone;

	cone = (t_cone *)object;
	return (get_pixel_color_for_object(cone->color,
			ray.rgb,
			ray.lighting_ratio));
}
