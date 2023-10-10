/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:33:47 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/17 22:20:15 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

//スクリーン情報
# define VIEW_PORT_HEIGHT	360.0
# define VIEW_PORT_WIDTH	640.0
# define NORMALIZED_WIDTH	2.0
# define TITLE				"miniRT"

//mlx情報
# define ESC				53
# define ESC_OS_TPYE_M1		49
# define ON_KEYDOWN			2
# define ON_DESTROY			17

//定数
# define DBL_MAX			1.797693e+308

//raytracing情報
# define SCENE_SCALE		2.0
# define SCENE_OFFSET		1.0
# define HALF_ANGLE_DIVISOR	2.0
# define MAX_FOV			179
# define MIN_FOV			1
# define MIN_COLOR			0
# define MAX_COLOR			255
# define HIT_DISTANCE_MIN	0.0
# define NO_LIGHT_STRENGTH	0.0
# define HALF_FULL_DEGREE	180.0
# define HALF_FACTOR		2.0
# define RED_SHIFT			16
# define GREEN_SHIFT		8
# define SECOND_COEFFICIENT	2.0
# define NOT_HIT			-1.0
# define BLACK				0
# define VERTICAL			0.0
# define REFLECT_STRENGTH	32

#endif
