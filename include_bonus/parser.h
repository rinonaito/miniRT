/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnaito <rnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:18:59 by yshimoma          #+#    #+#             */
/*   Updated: 2023/11/03 16:17:01 by rnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "types.h"
# include <stdbool.h>
# include <stdlib.h>

int					file_parser(t_scene *scene, int argc, char **argv);

int					rt_parser(
						const char *filename,
						t_scene *scene,
						bool *have_bump_texture);

int					set_line_info_in_scene(
						const char *const line,
						t_parser *parser,
						t_scene *scene,
						bool *have_bump_texture);

int					ppm_parser(
						const char *filename,
						t_scene *scene);

int					set_normal_bump_in_bump_map(
						const char *const line,
						t_bumpmap *bump_map,
						const int max_color,
						int count_map_height);
//validators
bool				is_invalid_argc(const int argc);
bool				is_invalid_coordinate(const t_vector3d cordinate);
bool				is_invalid_double(
						const double value,
						const double max,
						const double min);
bool				is_invalid_file_extension(const char *const file_name);
bool				is_invalid_fov(const int fov);
bool				is_invalid_int(
						const int value,
						const int max,
						const int min);
bool				is_invalid_lighting_ratio(const double a);
bool				is_invalid_normalized_vector(
						const t_vector3d direction_vec);
bool				is_invalid_rgb(const t_rgb rgb);
bool				is_string_match(const char *s1, const char *s2);

//utils/conversion
int					convert_csv_to_rgb(t_rgb *rgb, char *str);
int					convert_csv_to_vector3d(t_vector3d *vector3d, char *str);
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
int					set_str_in_double(
						double *num,
						const char *line,
						size_t *index);
int					set_str_in_rgb(
						t_rgb *rgb,
						const char *line,
						size_t *index);
int					set_str_in_vector3d(
						t_vector3d *vector3d,
						const char *line,
						size_t *index);
size_t				get_num_of_token(const char *line);
size_t				get_num_of_element_in_token(const char *token);

#endif
