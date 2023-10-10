/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:14:35 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/10 17:44:34 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

void	make_image(t_mlx_data *mlx_data, t_scene *sphere);

void	set_closest_point_info_in_ray(
			t_ray *ray,
			const t_scene scene);

#endif
