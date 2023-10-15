/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:18:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/14 17:15:47 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include <stdbool.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define AMBIENT				"A"
# define CAMERA					"C"
# define LIGHT					"L"
# define SPHERE					"sp"
# define PLANE					"pl"
# define CYLINDER				"cy"
# define IDENTIFIER_NUM			6
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

//message
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

typedef enum e_identifier_type
{
	A = 0,
	C = 1,
	L = 2,
	sp = 3,
	pl = 4,
	cy = 5,
	UNDEFINED = 99,
}	t_identifier_type;

typedef struct s_parser
{
	bool	(*fp_is_invalid_identifier)(char *, t_scene *, size_t);
	void	(*fp_set_identifier)(t_scene *, char *);
	char	*identifier_type_str;
}	t_parser;

int					file_parser(t_scene *scene, int argc, char **argv);
bool				is_invalid_line(
						const char *const line,
						const t_parser *parser,
						t_scene *scene);

//identifier
bool				is_invalid_ambient(const char *const line, t_scene *scene, const size_t index);
bool				is_invalid_camera(const char *const line, t_scene *scene, const size_t index);
bool				is_invalid_cylinder(const char *const line, t_scene *scene, const size_t index);
bool				is_invalid_light(const char *const line, t_scene *scene, const size_t index);
bool				is_invalid_plane(const char *const line, t_scene *scene, const size_t index);
bool				is_invalid_sphere(const char *const line, t_scene *scene, const size_t index);
void				set_ambient(t_scene *scene, const char *const line);
void				set_camera(t_scene *scene, const char *const line);
void				set_cylinder(t_scene *scene, const char *const line);
void				set_light(t_scene *scene, const char *const line);
void				set_plane(t_scene *scene, const char *const line);
void				set_sphere(t_scene *scene, const char *const line);

//ratio
bool				is_invalid_double_ratio(
						const double value,
						const double min,
						const double max);
bool				is_invalid_int_ratio(
						const int value,
						const int min,
						const int max);
bool				is_invalid_coordinates_ratio(const double x, const double y, const double z);
bool				is_invalid_fov_ratio(const int fov);
bool				is_invalid_lighting_ratio(const double a);
bool				is_invalid_normalized_vector_ratio(const double x, const double y, const double z);
bool				is_invalid_rgb_ratio(const int r, const int g, const int b);

//utils
bool				is_invalid_argc(const int argc);
bool				is_invalid_file_extension(const char *const file_name);
void				skip_spaces(size_t *index, char *str);
void				skip_next_space(size_t *index, const char *const str);
t_identifier_type	get_identifier_type(
						const char *const line,
						size_t *index,
						const t_parser parser);
void				skip_spaces(size_t *index, const char *const str);
void				skip_next_space(size_t *index, const char *const str);
void				skip_comma(size_t *index, const char *const str);
void				skip_next_comma(size_t *index, const char *const str);

#endif
