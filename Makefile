NAME = solong

CC = clang
CFLAGS = -Wall -Wextra

INTERNAL_LIBS = -lmlx -lft 
EXTERNAL_LIBS = -lm -lXext -lX11

LIBFT = libft.a
LIBFT_PATH = $(LIBS_PATH)/libft
LIBFT_ARCHIVE = $(ARCHIVES_PATH)/$(LIBFT)

MLX = libmlx.a
MLX_PATH = $(LIBS_PATH)/mlx_linux
MLX_ARCHIVE = $(ARCHIVES_PATH)/$(MLX)

MAKE_EXTERNAL = make -C
SAFE_MAKRDIR = mkdir -p

COPY = cp -p

REMOVE = rm -rf

OBJECTS_PATH = ./objects
SOURCES_PATH = ./sources
INCLUDES_PATH = ./includes
LIBS_PATH = ./libs
ARCHIVES_PATH = ./archives

HEADER_FILE = solong.h
HEADER = $(addprefix $(INCLUDES_PATH)/,$(HEADER_FILE))

SOURCE_FILES =	main.c \
				print_error.c \
				valid_game.c \
				gnl.c \
				gnl_utils.c \
				check_args.c \
				check_map.c \
				get_elements.c \
				init_structs.c \
				find_player.c \
				start_game.c \
				movements.c \
				init_sprites.c \
				load_map.c \

SOURCES = $(addprefix $(SOURCES_PATH)/,$(SOURCE_FILES))

OBJECTS = $(addprefix $(OBJECTS_PATH)/,$(subst .c,.o,$(SOURCE_FILES)))

all: $(NAME)

$(NAME): build_libft build_libmlx $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) -w -g $(OBJECTS) -o $(NAME) -L $(ARCHIVES_PATH) -I $(INCLUDES_PATH) $(EXTERNAL_LIBS) $(INTERNAL_LIBS)

$(OBJECTS_PATH)/%.o: $(SOURCES_PATH)/%.c $(HEADER)
	$(SAFE_MAKRDIR) $(OBJECTS_PATH)
	$(CC) $(CFLAGS) -g -I $(INCLUDES_PATH) -o $@ -c $< $(EXTERNAL_LIBS)

build_libft:
	$(MAKE_EXTERNAL) $(LIBFT_PATH)
	$(SAFE_MAKRDIR) $(ARCHIVES_PATH)
	$(COPY) $(LIBFT_PATH)/$(LIBFT) $(ARCHIVES_PATH)

build_libmlx:
	$(MAKE_EXTERNAL) $(MLX_PATH)
	$(SAFE_MAKRDIR) $(ARCHIVES_PATH)
	$(COPY) $(MLX_PATH)/$(MLX) $(ARCHIVES_PATH)

libft_clean:
	$(MAKE_EXTERNAL) $(LIBFT_PATH) fclean 
	$(REMOVE) $(LIBFT_ARCHIVE)

libmlx_clean:
	$(MAKE_EXTERNAL) $(MLX_PATH) clean
	$(REMOVE) $(MLX_ARCHIVE)

re:	fclean all

archives_clean: 
	$(REMOVE) $(ARCHIVES_PATH)

clean:
	$(REMOVE) $(OBJECTS_PATH)

fclean: clean archives_clean libft_clean libmlx_clean
	$(REMOVE) $(NAME)
