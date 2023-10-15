/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color_for_circle.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:25:48 by naitorino         #+#    #+#             */
/*   Updated: 2023/10/15 16:27:42 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"
#include "object.h"

int	get_pixel_color_for_circle(
	const void *object,
	const t_ray ray)
{
	t_circle	*circle;

	circle = (t_circle *)object;
	return (get_pixel_color_for_object(
			circle->color,
			ray.rgb,
			ray.lighting_ratio)
	);
}
