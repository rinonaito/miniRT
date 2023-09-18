NAME		=	miniRT
MLX_NAME	=	libmlx.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MLX_CFLAGS	=	-L/usr/X11R6/lib -lX11 -lXext -lm
MLX_MAKE_OP	=	-f Makefile.gen all

SRC_DIR		=	./src
OBJ_DIR		=	./obj
LIBFT_DIR	=	./libft
MLX_DIR		=	./minilibx-linux
INCLUDE		=	-Iinclude -Ilibft -Iminilibx-linux

# (
#   find src -type f -name "*.c" | sort | sed 's/^src\//\${SRC_DIR}\//;s/$/ \\/'
#   find libft -type f -name "*.c" | sort | sed 's/^libft\//\${LIBFT_DIR}\//;s/$/ \\/'
# ) | pbcopy
SRCS	=	\
			main.c \

OBJS	=	${addprefix ${OBJ_DIR}/, ${SRCS:.c=.o}}
DEPS	=	${OBJS:.o=.d}
RM		=	rm -rf
MKDIR	=	mkdir -p

.DEFAULT_GOAL = all
all		:	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${MLX_DIR}/${MLX_NAME} ${MLX_CFLAGS} -o $@ ${OBJS}

${OBJ_DIR}/%.o : %.c
	-$(MAKE) -C ${MLX_DIR}
	${MKDIR} $(@D)
	${CC} ${CFLAGS} ${INCLUDE} -MMD -MP -o $@ -c $<

clean	:
	$(MAKE) clean -C ${MLX_DIR}
	${RM} ${OBJ_DIR}

fclean	:	clean
	${RM} ${NAME}

re		:	fclean all

# Test rule
test: CFLAGS += -fsanitize=address
test: re

-include ${DEPS}

.PHONY: all clean fclean re

# xquartzのインストール方法
# 	brew install --cask xquartz
# 以下のコマンドでDISPLAY環境変数が設定されているか確認する
# 	echo $DISPLAY
