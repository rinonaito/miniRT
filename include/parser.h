/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimoma <yshimoma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:18:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/10/25 21:53:26 by yshimoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include <stdbool.h>
# include <stdlib.h>

int					file_parser(t_scene *scene, int argc, char **argv);

bool				is_invalid_line(
						const char *const line,
						const t_parser *parser,
						t_scene *scene);

//validators
bool				is_invalid_ambient(const char *const line);
bool				is_invalid_argc(const int argc);
bool				is_invalid_camera(const char *const line);
bool				is_invalid_cone(const char *const line);
bool				is_invalid_coordinates_ratio(
						const double x,
						const double y,
						const double z);
bool				is_invalid_cylinder(const char *const line);
bool				is_invalid_double_ratio(
						const double value,
						const double max,
						const double min);
bool				is_invalid_file_extension(const char *const file_name);
bool				is_invalid_fov_ratio(const int fov);
bool				is_invalid_int_ratio(
						const int value,
						const int max,
						const int min);
bool				is_invalid_light(const char *const line);
bool				is_invalid_lighting_ratio(const double a);
bool				is_invalid_normalized_vector_ratio(
						const double x,
						const double y,
						const double z);
bool				is_invalid_plane(const char *const line);
bool				is_invalid_rgb_ratio(const int r, const int g, const int b);
bool				is_invalid_sphere(const char *const line);
bool				is_string_match(const char *s1, const char *s2);

//utils/conversion
int				convert_csv_to_rgb(t_rgb *rgb, char *str);
int				convert_csv_to_vector3d(t_vector3d *vector3d, char *str);
int					convert_string_to_double(
						double *conversion_num,
						const char *str,
						const double max_num);
int					convert_string_to_int(int *num, const char *str);

//utils/gnl
char				*get_next_line_no_nl(int fd);
char				*get_next_line(int fd);

//utils/string_management
char				*get_first_word_by_comma(
						const char *const str, size_t *index);
char				*get_first_word_by_space(
						const char *const str, size_t *index);
t_identifier_type	get_identifier_type(
						const char *const line,
						size_t *index,
						const t_parser *parser);
void				skip_comma(size_t *index, const char *const str);
void				skip_next_comma(size_t *index, const char *const str);
void				skip_next_space(size_t *index, const char *const str);
void				skip_spaces(size_t *index, const char *const str);
void				set_str_in_double(
						double *num,
						const char *line,
						size_t *index);
void				set_str_in_rgb(
						t_rgb *rgb,
						const char *line,
						size_t *index);
void				set_str_in_vector3d(
						t_vector3d *vector3d,
						const char *line,
						size_t *index);

#endif
