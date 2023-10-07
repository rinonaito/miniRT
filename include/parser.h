/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:18:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/07 19:24:21 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include <stdbool.h>
# include <stdlib.h>

# define AMBIENT	"A"
# define CAMERA		"C"
# define LIGHT		"L"
# define SPHERE		"sp"
# define PLANE		"pl"
# define CYLINDER	"cy"

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

int		file_parser(t_scene *scene, int argc, char **argv);
bool	is_invalid_line(char *line, t_scene *scene);

//identifier
bool	is_invalid_ambient(char *line, t_scene *scene, size_t index);
bool	is_invalid_camera(char *line, t_scene *scene, size_t index);
bool	is_invalid_cylinder(char *line, t_scene *scene, size_t index);
bool	is_invalid_light(char *line, t_scene *scene, size_t index);
bool	is_invalid_plane(char *line, t_scene *scene, size_t index);
bool	is_invalid_sphere(char *line, t_scene *scene, size_t index);
void	set_ambient(t_scene *scene, char *line);
void	set_camera(t_scene *scene, char *line);
void	set_cylinder(t_scene *scene, char *line);
void	set_light(t_scene *scene, char *line);
void	set_plane(t_scene *scene, char *line);
void	set_sphere(t_scene *scene, char *line);

//ratio
bool	is_invalid_double_ratio(double a);
bool	is_invalid_int_ratio(int a);
bool	is_invalid_coordinates_ratio(double x, double y, double z);
bool	is_invalid_fov_ratio(int fov);
bool	is_invalid_lighting_ratio(double a);
bool	is_invalid_normalized_vector_ratio(double x, double y, double z);
bool	is_invalid_rgb_ratio(int r, int g, int b);

//utils
bool	is_invalid_argc(int argc);
bool	is_invalid_file_extension(char *file_name);
void	skip_spaces(size_t *index, char *str);

#endif
