/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:33:47 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/01 13:35:00 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

//スクリーン情報
# define SCREEN_HEIGHT		(180)
# define SCREEN_WIDTH		(320)
# define TITLE				("miniRT")

//mlx情報
# define ESC				(53)
# define ESC_OS_TPYE_M1		(49)
# define ON_KEYDOWN			(2)
# define ON_DESTROY			(17)

//raytracing情報
# define SCENE_SCALE		(2.0)
# define SCENE_OFFSET		(1.0)
# define HALF_ANGLE_DIVISOR	(2.0)
# define MAX_FOV			(179)
# define MIN_FOV			(1)
# define MIN_COLOR			(0)
# define MAX_COLOR			(255)
# define HIT_DISTANCE_MIN	(0.0)
# define NO_LIGHT_STRENGTH	(0.0)
# define HALF_FULL_DEGREE	(180.0)
# define HALF_FACTOR		(2.0)
# define RED_SHIFT			(16)
# define GREEN_SHIFT		(8)
# define SECOND_COEFFICIENT	(2.0)
# define NOT_HIT			(-1)

#endif
