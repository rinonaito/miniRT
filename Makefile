NAME		=	miniRT
MLX_NAME	=	libmlx.a
LIBFT_NAME	=	libft.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MLX_CFLAGS	=	-L/usr/X11R6/lib -lX11 -lXext -lm

SRC_DIR		=	./src
OBJ_DIR		=	./obj
MLX_DIR		=	./minilibx-linux
LIBFT_DIR	=	./libft
INCLUDE		=	-Iinclude -I${MLX_DIR} -I${LIBFT_DIR}

# find src -type f -name "*.c" | sort | sed 's/^src\//\${SRC_DIR}\//;s/$/ \\/' | pbcopy
SRCS	=	\
			init_map.c \
			main.c \
${SRC_DIR}/calculator/get_closer_hit_distance.c \
${SRC_DIR}/calculator/scale_to_minus_one_to_one.c \
${SRC_DIR}/calculator/scale_to_zero_to_one.c \
${SRC_DIR}/color/convert_rgb_in_int.c \
${SRC_DIR}/color/reflect_lighting_ratio_in_color.c \
${SRC_DIR}/get_pixel_color.c \
${SRC_DIR}/init/set_ray.c \
${SRC_DIR}/init/set_vector2d.c \
${SRC_DIR}/init/set_vector3d.c \
${SRC_DIR}/light/calculate_lighting_ratio.c \
${SRC_DIR}/light/get_specular_lighting_ratio.c \
${SRC_DIR}/light/is_not_in_shadow.c \
${SRC_DIR}/light/set_lighting_ratio.c \
${SRC_DIR}/make_image.c \
${SRC_DIR}/object/circle/get_normal_vector_for_circle.c \
${SRC_DIR}/object/circle/get_pixel_color_for_circle.c \
${SRC_DIR}/object/circle/hit_circle.c \
${SRC_DIR}/object/common/get_normal_vector_for_2d.c \
${SRC_DIR}/object/common/get_normal_vector_for_3d.c \
${SRC_DIR}/object/common/get_pixel_color_for_object.c \
${SRC_DIR}/object/plane/get_normal_vector_for_plane.c \
${SRC_DIR}/object/plane/get_pixel_color_for_plane.c \
${SRC_DIR}/object/plane/hit_plane.c \
${SRC_DIR}/object/sphere/get_normal_vector_for_sphere.c \
${SRC_DIR}/object/sphere/get_pixel_color_for_sphere.c \
${SRC_DIR}/object/sphere/hit_sphere.c \
${SRC_DIR}/object/tube/get_normal_vector_for_tube.c \
${SRC_DIR}/object/tube/get_pixel_color_for_tube.c \
${SRC_DIR}/object/tube/hit_tube.c \
${SRC_DIR}/set_closest_point_info_in_ray.c \
${SRC_DIR}/utils/error_utils/exit_with_errno.c \
${SRC_DIR}/utils/mlx_utils/handle_key_press.c \
${SRC_DIR}/utils/mlx_utils/handle_window_close.c \
${SRC_DIR}/utils/mlx_utils/my_mlx_pixel_put.c \
${SRC_DIR}/utils/x_wrapper/ft_xcalloc.c \
${SRC_DIR}/vector/addition_vector3d.c \
${SRC_DIR}/vector/cross_vector3d.c \
${SRC_DIR}/vector/dot_vector3d.c \
${SRC_DIR}/vector/get_len_of_vector3d.c \
${SRC_DIR}/vector/normalize_vector3d.c \
${SRC_DIR}/vector/subtraction_vector3d.c \
${SRC_DIR}/vector/subtraction_vector3d_xyz.c \
${SRC_DIR}/vector/vector3d_dot_double.c \

OBJS	=	${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}
DEPS	=	${OBJS:.o=.d}
RM		=	rm -rf

MKDIR	=	mkdir -p

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
	${RM} ${OBJ_DIR}

fclean	:	clean
	${RM} ${NAME} ${MLX_DIR}/${MLX_NAME} ${LIBFT_DIR}/${LIBFT_NAME}

re		:	fclean all

norm	:
	norminette main.c ${SRC_DIR} include ${LIBFT_DIR}

# Test rule
test: CFLAGS += -fsanitize=address
test: re

-include ${DEPS}

.PHONY: all clean fclean re

# m1, m2チップのmacでコンパイルする方法
# xquartzのインストール方法
# 	brew install --cask xquartz
# 以下のコマンドでDISPLAY環境変数が設定されているか確認する
# 	echo $DISPLAY
# 出力されない場合は、macから再ログインすれば表示される
