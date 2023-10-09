/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:18:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/09 18:04:50 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include <stdbool.h>
# include <stdlib.h>

# define AMBIENT			"A"
# define CAMERA				"C"
# define LIGHT				"L"
# define SPHERE				"sp"
# define PLANE				"pl"
# define CYLINDER			"cy"
# define FILE_NAME_NUM		1
# define INVALID_ARGC_NUM	2

typedef enum e_identifier
{
	A,
	C,
	L,
	sp,
	pl,
	cy,
	UNDEFINED,
}	t_identifier;

typedef struct s_parser
{
	bool	(*fp_is_invalid_identifier)(char *, t_scene *, size_t);
	void	(*fp_set_identifier)(t_scene *, char *);
}	t_parser;

int				file_parser(t_scene *scene, int argc, char **argv);
bool			is_invalid_line(const char *const line, t_scene *scene);

//identifier
bool			is_invalid_ambient(const char *const line, t_scene *scene, const size_t index);
bool			is_invalid_camera(const char *const line, t_scene *scene, const size_t index);
bool			is_invalid_cylinder(const char *const line, t_scene *scene, const size_t index);
bool			is_invalid_light(const char *const line, t_scene *scene, const size_t index);
bool			is_invalid_plane(const char *const line, t_scene *scene, const size_t index);
bool			is_invalid_sphere(const char *const line, t_scene *scene, const size_t index);
void			set_ambient(t_scene *scene, const char *const line);
void			set_camera(t_scene *scene, const char *const line);
void			set_cylinder(t_scene *scene, const char *const line);
void			set_light(t_scene *scene, const char *const line);
void			set_plane(t_scene *scene, const char *const line);
void			set_sphere(t_scene *scene, const char *const line);

//ratio
bool			is_invalid_double_ratio(const double a);
bool			is_invalid_int_ratio(const int a);
bool			is_invalid_coordinates_ratio(const double x, const double y, const double z);
bool			is_invalid_fov_ratio(const int fov);
bool			is_invalid_lighting_ratio(const double a);
bool			is_invalid_normalized_vector_ratio(const double x, const double y, const double z);
bool			is_invalid_rgb_ratio(const int r, const int g, const int b);

//utils
bool			is_invalid_argc(const int argc);
bool			is_invalid_file_extension(const char *const file_name);
void			skip_spaces(size_t *index, char *str);
t_identifier	get_identifier_type(const char *const line, size_t *index);

#endif
