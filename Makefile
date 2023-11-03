NAME			=	miniRT
NAME_BONUS		=	miniRT_bonus
MLX_NAME		=	libmlx.a
LIBFT_NAME		=	libft.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
# CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address
MLX_CFLAGS		=	-L/usr/X11R6/lib -lX11 -lXext -lm

SRC_DIR			=	./src
SRC_BONUS_DIR	=	./src_bonus
OBJ_DIR			=	./obj
OBJ_BONUS_DIR	=	./obj_bonus
MLX_DIR			=	./minilibx-linux
LIBFT_DIR		=	./libft
INCLUDE			=	-Iinclude -I${MLX_DIR} -I${LIBFT_DIR}
INCLUDE_BONUS	=	-Iinclude_bonus -I${MLX_DIR} -I${LIBFT_DIR}

# find src -type f -name "*.c" | sort | sed 's/^src\//\${SRC_DIR}\//;s/$/ \\/' | pbcopy
SRCS			=	\
				main.c \
${SRC_DIR}/calculator/get_closer_hit_distance.c \
${SRC_DIR}/calculator/scale_to_minus_one_to_one.c \
${SRC_DIR}/calculator/scale_to_zero_to_one.c \
${SRC_DIR}/color/convert_rgb_in_int.c \
${SRC_DIR}/color/reflect_lighting_ratio_in_color.c \
${SRC_DIR}/get_pixel_color.c \
${SRC_DIR}/init/create_object.c \
${SRC_DIR}/init/resize_objects_array.c \
${SRC_DIR}/init/set_ambient.c \
${SRC_DIR}/init/set_camera.c \
${SRC_DIR}/init/set_circle.c \
${SRC_DIR}/init/set_cone.c \
${SRC_DIR}/init/set_cone_side.c \
${SRC_DIR}/init/set_cylinder.c \
${SRC_DIR}/init/set_light.c \
${SRC_DIR}/init/set_plane.c \
${SRC_DIR}/init/set_ray.c \
${SRC_DIR}/init/set_sphere.c \
${SRC_DIR}/init/set_tube.c \
${SRC_DIR}/init/set_vector2d.c \
${SRC_DIR}/init/set_vector3d.c \
${SRC_DIR}/light/calculate_lighting_ratio.c \
${SRC_DIR}/light/get_specular_lighting_ratio.c \
${SRC_DIR}/light/is_hit_by_spot_light.c \
${SRC_DIR}/light/set_lighting_ratio.c \
${SRC_DIR}/make_image.c \
${SRC_DIR}/object/circle/get_normal_vector_for_circle.c \
${SRC_DIR}/object/circle/get_pixel_color_for_circle.c \
${SRC_DIR}/object/circle/hit_circle.c \
${SRC_DIR}/object/common/camera_is_inside_of_object.c \
${SRC_DIR}/object/common/get_circle_center.c \
${SRC_DIR}/object/common/get_normal_vector_for_2d.c \
${SRC_DIR}/object/common/get_pixel_color_for_object.c \
${SRC_DIR}/object/cone/get_normal_vector_for_cone_side.c \
${SRC_DIR}/object/cone/get_pixel_color_for_cone_side.c \
${SRC_DIR}/object/cone/hit_cone_side.c \
${SRC_DIR}/object/plane/convert_3d_coordinate_on_plane_in_2d.c \
${SRC_DIR}/object/plane/get_normal_vector_for_plane.c \
${SRC_DIR}/object/plane/get_pixel_color_for_plane.c \
${SRC_DIR}/object/plane/hit_plane.c \
${SRC_DIR}/object/sphere/get_normal_vector_for_sphere.c \
${SRC_DIR}/object/sphere/get_pixel_color_for_sphere.c \
${SRC_DIR}/object/sphere/hit_sphere.c \
${SRC_DIR}/object/tube/get_normal_vector_for_tube.c \
${SRC_DIR}/object/tube/get_pixel_color_for_tube.c \
${SRC_DIR}/object/tube/hit_tube.c \
${SRC_DIR}/parser/file_parser.c \
${SRC_DIR}/parser/rt_parser.c \
${SRC_DIR}/parser/set_line_info_in_scene.c \
${SRC_DIR}/parser/utils/conversion/convert_csv_to_rgb.c \
${SRC_DIR}/parser/utils/conversion/convert_csv_to_vector3d.c \
${SRC_DIR}/parser/utils/conversion/convert_string_to_double.c \
${SRC_DIR}/parser/utils/conversion/convert_string_to_int.c \
${SRC_DIR}/parser/utils/gnl/get_next_line.c \
${SRC_DIR}/parser/utils/gnl/get_next_line_no_nl.c \
${SRC_DIR}/parser/utils/string_management/get_first_word_by_comma.c \
${SRC_DIR}/parser/utils/string_management/get_first_word_by_space.c \
${SRC_DIR}/parser/utils/string_management/get_identifier_type.c \
${SRC_DIR}/parser/utils/string_management/get_num_of_element_in_token.c \
${SRC_DIR}/parser/utils/string_management/get_num_of_token.c \
${SRC_DIR}/parser/utils/string_management/set_str_in_double.c \
${SRC_DIR}/parser/utils/string_management/set_str_in_rgb.c \
${SRC_DIR}/parser/utils/string_management/set_str_in_vector3d.c \
${SRC_DIR}/parser/utils/string_management/skip_comma.c \
${SRC_DIR}/parser/utils/string_management/skip_next_comma.c \
${SRC_DIR}/parser/utils/string_management/skip_next_space.c \
${SRC_DIR}/parser/utils/string_management/skip_spaces.c \
${SRC_DIR}/parser/validators/general/is_invalid_argc.c \
${SRC_DIR}/parser/validators/general/is_invalid_file_extension.c \
${SRC_DIR}/parser/validators/general/is_string_match.c \
${SRC_DIR}/parser/validators/identifier_utils/is_invalid_coordinate.c \
${SRC_DIR}/parser/validators/identifier_utils/is_invalid_double.c \
${SRC_DIR}/parser/validators/identifier_utils/is_invalid_fov.c \
${SRC_DIR}/parser/validators/identifier_utils/is_invalid_int.c \
${SRC_DIR}/parser/validators/identifier_utils/is_invalid_lighting_ratio.c \
${SRC_DIR}/parser/validators/identifier_utils/is_invalid_normalized_vector.c \
${SRC_DIR}/parser/validators/identifier_utils/is_invalid_rgb.c \
${SRC_DIR}/set_closest_point_info_in_ray.c \
${SRC_DIR}/utils/common/free_scene.c \
${SRC_DIR}/utils/common/malloc_2dimensional_array.c \
${SRC_DIR}/utils/error_utils/exit_with_errno.c \
${SRC_DIR}/utils/error_utils/print_error_msg.c \
${SRC_DIR}/utils/mlx_utils/handle_key_press.c \
${SRC_DIR}/utils/mlx_utils/handle_window_close.c \
${SRC_DIR}/utils/mlx_utils/my_mlx_pixel_put.c \
${SRC_DIR}/utils/x_wrapper/ft_xcalloc.c \
${SRC_DIR}/utils/x_wrapper/ft_xputendl_fd.c \
${SRC_DIR}/utils/x_wrapper/ft_xputstr_fd.c \
${SRC_DIR}/utils/x_wrapper/ft_xsubstr.c \
${SRC_DIR}/vector/addition_vector3d.c \
${SRC_DIR}/vector/cross_vector3d.c \
${SRC_DIR}/vector/dot_vector3d.c \
${SRC_DIR}/vector/get_len_of_vector3d.c \
${SRC_DIR}/vector/get_projection_vector.c \
${SRC_DIR}/vector/normalize_vector3d.c \
${SRC_DIR}/vector/subtraction_vector3d.c \
${SRC_DIR}/vector/subtraction_vector3d_xyz.c \
${SRC_DIR}/vector/vector3d_dot_double.c \


# find src_bonus -type f -name "*.c" | sort | sed 's/^src_bonus\//\${SRC_BONUS_DIR}\//;s/$/ \\/' | pbcopy
SRCS_BONUS		=	\
				main.c \
				${SRC_BONUS_DIR}/calculator/get_closer_hit_distance.c \
				${SRC_BONUS_DIR}/calculator/scale_to_minus_one_to_one.c \
				${SRC_BONUS_DIR}/calculator/scale_to_zero_to_one.c \
				${SRC_BONUS_DIR}/color/convert_rgb_in_int.c \
				${SRC_BONUS_DIR}/color/reflect_lighting_ratio_in_color.c \
				${SRC_BONUS_DIR}/get_pixel_color.c \
				${SRC_BONUS_DIR}/init/create_object.c \
				${SRC_BONUS_DIR}/init/resize_objects_array.c \
				${SRC_BONUS_DIR}/init/set_ambient.c \
				${SRC_BONUS_DIR}/init/set_camera.c \
				${SRC_BONUS_DIR}/init/set_circle.c \
				${SRC_BONUS_DIR}/init/set_cone.c \
				${SRC_BONUS_DIR}/init/set_cone_side.c \
				${SRC_BONUS_DIR}/init/set_cylinder.c \
				${SRC_BONUS_DIR}/init/set_light.c \
				${SRC_BONUS_DIR}/init/set_plane.c \
				${SRC_BONUS_DIR}/init/set_ray.c \
				${SRC_BONUS_DIR}/init/set_sphere.c \
				${SRC_BONUS_DIR}/init/set_tube.c \
				${SRC_BONUS_DIR}/init/set_vector2d.c \
				${SRC_BONUS_DIR}/init/set_vector3d.c \
				${SRC_BONUS_DIR}/light/calculate_lighting_ratio.c \
				${SRC_BONUS_DIR}/light/get_specular_lighting_ratio.c \
				${SRC_BONUS_DIR}/light/is_hit_by_spot_light.c \
				${SRC_BONUS_DIR}/light/set_lighting_ratio.c \
				${SRC_BONUS_DIR}/make_image.c \
				${SRC_BONUS_DIR}/object/circle/get_normal_vector_for_circle.c \
				${SRC_BONUS_DIR}/object/circle/get_pixel_color_for_circle.c \
				${SRC_BONUS_DIR}/object/circle/hit_circle.c \
				${SRC_BONUS_DIR}/object/common/camera_is_inside_of_object.c \
				${SRC_BONUS_DIR}/object/common/get_circle_center.c \
				${SRC_BONUS_DIR}/object/common/get_normal_vector_for_2d.c \
				${SRC_BONUS_DIR}/object/common/get_pixel_color_for_object.c \
				${SRC_BONUS_DIR}/object/cone/get_normal_vector_for_cone_side.c \
				${SRC_BONUS_DIR}/object/cone/get_pixel_color_for_cone_side.c \
				${SRC_BONUS_DIR}/object/cone/hit_cone_side.c \
				${SRC_BONUS_DIR}/object/plane/convert_3d_coordinate_on_plane_in_2d.c \
				${SRC_BONUS_DIR}/object/plane/get_normal_vector_for_plane.c \
				${SRC_BONUS_DIR}/object/plane/get_normal_vector_with_bump.c \
				${SRC_BONUS_DIR}/object/plane/get_pixel_color_for_plane.c \
				${SRC_BONUS_DIR}/object/plane/hit_plane.c \
				${SRC_BONUS_DIR}/object/sphere/get_normal_vector_for_sphere.c \
				${SRC_BONUS_DIR}/object/sphere/get_pixel_color_for_sphere.c \
				${SRC_BONUS_DIR}/object/sphere/hit_sphere.c \
				${SRC_BONUS_DIR}/object/tube/get_normal_vector_for_tube.c \
				${SRC_BONUS_DIR}/object/tube/get_pixel_color_for_tube.c \
				${SRC_BONUS_DIR}/object/tube/hit_tube.c \
				${SRC_BONUS_DIR}/parser/file_parser.c \
				${SRC_BONUS_DIR}/parser/ppm_parser.c \
				${SRC_BONUS_DIR}/parser/rt_parser.c \
				${SRC_BONUS_DIR}/parser/set_line_info_in_scene.c \
				${SRC_BONUS_DIR}/parser/set_normal_bump_in_bump_map.c \
				${SRC_BONUS_DIR}/parser/utils/conversion/convert_csv_to_rgb.c \
				${SRC_BONUS_DIR}/parser/utils/conversion/convert_csv_to_vector3d.c \
				${SRC_BONUS_DIR}/parser/utils/conversion/convert_string_to_double.c \
				${SRC_BONUS_DIR}/parser/utils/conversion/convert_string_to_int.c \
				${SRC_BONUS_DIR}/parser/utils/gnl/get_next_line.c \
				${SRC_BONUS_DIR}/parser/utils/gnl/get_next_line_no_nl.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/get_first_word_by_comma.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/get_first_word_by_space.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/get_identifier_type.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/get_num_of_element_in_token.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/get_num_of_token.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/set_str_in_double.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/set_str_in_rgb.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/set_str_in_vector3d.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/skip_comma.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/skip_next_comma.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/skip_next_space.c \
				${SRC_BONUS_DIR}/parser/utils/string_management/skip_spaces.c \
				${SRC_BONUS_DIR}/parser/validators/general/is_invalid_argc.c \
				${SRC_BONUS_DIR}/parser/validators/general/is_invalid_file_extension.c \
				${SRC_BONUS_DIR}/parser/validators/general/is_string_match.c \
				${SRC_BONUS_DIR}/parser/validators/identifier_utils/is_invalid_coordinate.c \
				${SRC_BONUS_DIR}/parser/validators/identifier_utils/is_invalid_double.c \
				${SRC_BONUS_DIR}/parser/validators/identifier_utils/is_invalid_fov.c \
				${SRC_BONUS_DIR}/parser/validators/identifier_utils/is_invalid_int.c \
				${SRC_BONUS_DIR}/parser/validators/identifier_utils/is_invalid_lighting_ratio.c \
				${SRC_BONUS_DIR}/parser/validators/identifier_utils/is_invalid_normalized_vector.c \
				${SRC_BONUS_DIR}/parser/validators/identifier_utils/is_invalid_rgb.c \
				${SRC_BONUS_DIR}/set_closest_point_info_in_ray.c \
				${SRC_BONUS_DIR}/utils/common/free_scene.c \
				${SRC_BONUS_DIR}/utils/common/malloc_2dimensional_array.c \
				${SRC_BONUS_DIR}/utils/error_utils/exit_with_errno.c \
				${SRC_BONUS_DIR}/utils/error_utils/print_error_msg.c \
				${SRC_BONUS_DIR}/utils/mlx_utils/handle_key_press.c \
				${SRC_BONUS_DIR}/utils/mlx_utils/handle_window_close.c \
				${SRC_BONUS_DIR}/utils/mlx_utils/my_mlx_pixel_put.c \
				${SRC_BONUS_DIR}/utils/x_wrapper/ft_xcalloc.c \
				${SRC_BONUS_DIR}/utils/x_wrapper/ft_xputendl_fd.c \
				${SRC_BONUS_DIR}/utils/x_wrapper/ft_xputstr_fd.c \
				${SRC_BONUS_DIR}/utils/x_wrapper/ft_xsubstr.c \
				${SRC_BONUS_DIR}/vector/addition_vector3d.c \
				${SRC_BONUS_DIR}/vector/cross_vector3d.c \
				${SRC_BONUS_DIR}/vector/dot_vector3d.c \
				${SRC_BONUS_DIR}/vector/get_len_of_vector3d.c \
				${SRC_BONUS_DIR}/vector/get_projection_vector.c \
				${SRC_BONUS_DIR}/vector/normalize_vector3d.c \
				${SRC_BONUS_DIR}/vector/subtraction_vector3d.c \
				${SRC_BONUS_DIR}/vector/subtraction_vector3d_xyz.c \
				${SRC_BONUS_DIR}/vector/vector3d_dot_double.c \

OBJS			=	${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}
DEPS			=	${OBJS:.o=.d}
OBJS_BONUS		=	${addprefix ${OBJ_BONUS_DIR}/, ${SRCS_BONUS:.c=.o}}
DEPS_BONUS		=	${OBJS_BONUS:.o=.d}
RM				=	rm -rf
MKDIR			=	mkdir -p

.DEFAULT_GOAL = all
all		:	${NAME}

${NAME}: ${OBJS}
	-$(MAKE) -C ${MLX_DIR}
	$(MAKE) -C ${LIBFT_DIR}
	${CC} ${CFLAGS} ${MLX_DIR}/${MLX_NAME} ${MLX_CFLAGS} ${LIBFT_DIR}/${LIBFT_NAME} -o $@ ${OBJS}

${OBJ_DIR}/%.o : %.c
	${MKDIR} $(@D)
	${CC} ${CFLAGS} ${INCLUDE} -MMD -MP -o $@ -c $<

clean	:
	$(MAKE) clean -C ${MLX_DIR}
	$(MAKE) clean -C ${LIBFT_DIR}
	${RM} ${OBJ_DIR} ${OBJ_BONUS_DIR}

fclean	:	clean
	${RM} ${NAME} ${MLX_DIR}/${MLX_NAME} ${LIBFT_DIR}/${LIBFT_NAME} ${NAME_BONUS}

re		:	fclean all

bonus	:	${NAME_BONUS}

${NAME_BONUS}: ${OBJS_BONUS}
	-$(MAKE) -C ${MLX_DIR}
	$(MAKE) -C ${LIBFT_DIR}
	${CC} ${CFLAGS} ${MLX_DIR}/${MLX_NAME} ${MLX_CFLAGS} ${LIBFT_DIR}/${LIBFT_NAME} -o $@ ${OBJS_BONUS}

${OBJ_BONUS_DIR}/%.o : %.c
	${MKDIR} $(@D)
	${CC} ${CFLAGS} ${INCLUDE_BONUS} -MMD -MP -o $@ -c $<

norm	:
	norminette main.c ${SRC_DIR} include include_bonus ${LIBFT_DIR}

test	:
	./map/tester.sh

-include ${DEPS}

.PHONY: all clean fclean re bonus norm test

# m1, m2チップのmacでコンパイルする方法
# xquartzのインストール方法
# 	brew install --cask xquartz
# 以下のコマンドでDISPLAY環境変数が設定されているか確認する
# 	echo $DISPLAY
# 出力されない場合は、macから再ログインすれば表示される
