/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:33:47 by rnaito            #+#    #+#             */
/*   Updated: 2023/10/23 15:11:39 by yshimoma         ###   ########.fr       */
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
# define CHECKER_SIZE		1

//parser
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# define AMBIENT				"A"
# define CAMERA					"C"
# define LIGHT					"L"
# define SPHERE					"sp"
# define PLANE					"pl"
# define CYLINDER				"cy"
# define CONE					"co"
# define IDENTIFIER_NUM			7
# define FILE_NAME_NUM			1
# define INVALID_ARGC_NUM		2
# define MAX_FOV				180
# define MIN_FOV				0
# define MAX_LIGHTING_RATIO		1.0
# define MIN_LIGHTING_RATIO		0.0
# define MAX_VECTOR_RATIO		1.0
# define MIN_VECTOR_RATIO		-1.0
# define MAX_COLOR_RANGE		0
# define MIN_COLOR_RANGE		255
# define ERROR_MSG			"Error"
# define INVALID_ARGC		"Invalid argument count. \
Usage: ./miniRT [file_name]"
# define INVALID_FILE		"Invalid file name. \
Please provide a .rt file as an argument."
# define INVALID_IDENTIFIER	"Invalid identifier detected. \
Accepted identifiers are: \
A (AMBIENT), C (CAMERA), L (LIGHT), \
sp (SPHERE), pl (PLANE), cy (CYLINDER)."
# define FILE_NOT_FOUND      "File not found. \
Please ensure the provided file path is correct and try again."

#endif
