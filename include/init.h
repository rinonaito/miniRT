/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:48:58 by yshimoma          #+#    #+#             */
/*   Updated: 2023/09/23 22:29:01 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "types.h"

void	set_vector3d(
			t_vector3d *coordinate,
			double x,
			double y,
			double z);

void	set_vector2d(
			t_vector2d *coordinate,
			double x,
			double y);

void	set_ray(
			t_ray *ray,
			t_vector3d origin,
			t_vector2d uv,
			double focal_len);
#endif
