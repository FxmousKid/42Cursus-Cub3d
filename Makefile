# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:32:50 by inazaria          #+#    #+#              #
#    Updated: 2025/03/14 23:58:38 by ptheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<><><><><><><> Files <><><><><><><><><><><><><><><><><><><>
SRC_DIR 	= ./src/

BUILD_DIR 	= ./build/

INC_DIR 	= ./includes/

DEBUG_FILE_PATH = ./src/error_manager/debugging_functions
DEBUG_BUILD_PATH = ./build/error_manager/debugging_functions

# .c files for source code
SRC_FILES_NAMES_BONUS = main.c

# ACTION
SRC_FILES_NAMES_BONUS += action/exit.c
SRC_FILES_NAMES_BONUS += action/keyhandler.c
SRC_FILES_NAMES_BONUS += action/mousehandler.c
SRC_FILES_NAMES_BONUS += action/door.c

# SHAPES
SRC_FILES_NAMES_BONUS += shapes/pixel.c
SRC_FILES_NAMES_BONUS += shapes/vector.c
SRC_FILES_NAMES_BONUS += shapes/draw_shapes.c

# PLAYER
SRC_FILES_NAMES_BONUS += player/player.c
SRC_FILES_NAMES_BONUS += player/player_move.c
SRC_FILES_NAMES_BONUS += player/camera_move.c

# RAYCASTING
SRC_FILES_NAMES_BONUS += raycasting/raycasting.c
SRC_FILES_NAMES_BONUS += raycasting/raycasting_utils.c
SRC_FILES_NAMES_BONUS += raycasting/floor_celling.c

# PARSING
SRC_FILES_NAMES_BONUS += parser/parsing.c
SRC_FILES_NAMES_BONUS += parser/parsing_utils.c
SRC_FILES_NAMES_BONUS += parser/check_map.c
SRC_FILES_NAMES_BONUS += parser/check_map_utils.c
SRC_FILES_NAMES_BONUS += parser/check_config_file.c
SRC_FILES_NAMES_BONUS += parser/check_assets.c

# RENDER
SRC_FILES_NAMES_BONUS += render/render.c
SRC_FILES_NAMES_BONUS += render/map.c
SRC_FILES_NAMES_BONUS += render/background.c

# UTILS
SRC_FILES_NAMES_BONUS += utils/utils.c

# TEXTURING
SRC_FILES_NAMES_BONUS += texturing/texture.c
SRC_FILES_NAMES_BONUS += texturing/color_management.c
SRC_FILES_NAMES_BONUS += texturing/flashlight.c

# to add for example src/map/map.c
# SRC_FILES_NAMES += map/map.c


# Full path to .c files
SRC_FILES_BONUS = $(addprefix $(SRC_DIR_BONUS), $(SRC_FILES_NAMES_BONUS))

# .o files for compilation
OBJ_FILES_BONUS = $(patsubst $(SRC_DIR_BONUS)%.c, $(BUILD_DIR)%.o, $(SRC_FILE_BONUSS))

# .d files for header dependency
DEP_FILES_BONUS = $(patsubst $(SRC_DIR_BONUS)%.c, $(BUILD_DIR)%.d, $(SRC_FILES_BONUS))


#<><><><><><><> Variables <><><><><><><><><><><><><><><><><>

NAME := cub3D
NAME_BONUS := cub3D_bonus
CC := clang
CFLAGS := -gdwarf-4 -Wall -Wextra -Werror -I $(INC_DIR) -MMD -MP
LFLAGS := libft/libft.a -Lmlx_linux -lmlx -lXext -lX11 -lm -lz
MLX_DIR := ./mlx_linux/
MKDIR := mkdir -p
RM_RF := rm -rf
ECHO  := echo -e


BLUE	:= \e[34m
BROWN	:= \e[33m
GREEN	:= \e[32m
RED		:= \e[31m
NC		:= \e[0m


#<><><><><><><> Recipes <><><><><><><><><><><><><><><><><><>

# Modifying Implicit conversion rules to build in custom directory
$(BUILD_DIR)%.o : $(SRC_DIR)%.c
	@$(MKDIR) $(dir $@)
	@$(ECHO) "$(BLUE)[CMP] Compiling $<...$(NC)"
	@$(CC) -c $(CFLAGS) $< -o $@ 


# This is to add the .d files as dependencies for linking
-include $(DEP_FILES) $(DEBUG_BUILD_PATH).d


re : clean all

$(NAME) : $(OBJ_FILES)
	@$(ECHO) "$(BROWN)[BLD] Building libft static library...$(NC)"
	@$(MAKE) --no-print-directory -s -C ./libft all
	@$(ECHO) "$(GREEN)[BLD] successfully built libft.$(NC)"	
	@$(ECHO) "$(BROWN)[BLD] Building mlx library...$(NC)"
	@$(MAKE) --no-print-directory -s -C $(MLX_DIR)
	@$(ECHO) "$(GREEN)[BLD] successfully built mlx.$(NC)"
	@$(ECHO) "$(BROWN)[BLD] Building $(NAME) executable...$(NC)"
	@$(MKDIR) ./build/error_manager/
	@$(CC) $(CFLAGS) -c $(DEBUG_FILE_PATH).c -o $(DEBUG_BUILD_PATH).o
	@$(CC) $(CFLAGS) $^ $(DEBUG_BUILD_PATH).o -o $(NAME) $(LFLAGS)
	@$(ECHO) "$(GREEN)[BLD] Executable built successfully.$(NC)"

all : $(NAME) 

debug : $(OBJ_FILES)
	@$(ECHO) "$(RED)[DBG] Making in DEBUG MODE...$(NC)"
	@$(MKDIR) ./build/error_manager/
	@$(CC) $(CFLAGS) -D DEBUG -c $(DEBUG_FILE_PATH).c -o $(DEBUG_BUILD_PATH).o
	@$(ECHO) "$(BROWN)[BLD] Building executable...$(NC)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(DEBUG_BUILD_PATH).o -o $(NAME) $(LFLAGS)
	@$(ECHO) "$(GREEN)[BLD] Executable built successfully.$(NC)"

force : $(OBJ_FILES)
	@$(ECHO) "$(RED)[DBG] Making in FORCED mode...$(NC)"
	@$(ECHO) "$(BROWN)[BLD] Building libft static library...$(NC)"
	@$(MAKE) --no-print-directory -s -C ./libft all
	@$(ECHO) "$(GREEN)[BLD] successfully built libft.$(NC)"	
	@$(ECHO) "$(BROWN)[BLD] Building mlx library...$(NC)"
	@$(MAKE) --no-print-directory -s -C $(MLX_DIR)
	@$(ECHO) "$(GREEN)[BLD] successfully built mlx.$(NC)"
	@$(ECHO) "$(BROWN)[BLD] Building $(NAME) executable...$(NC)"
	@$(MKDIR) ./build/error_manager/
	@$(CC) $(CFLAGS) -c $(DEBUG_FILE_PATH).c -o $(DEBUG_BUILD_PATH).o
	@$(CC) $(CFLAGS) $^ $(DEBUG_BUILD_PATH).o -o $(NAME) $(LFLAGS)
	@$(ECHO) "$(GREEN)[BLD] Executable built in FORCED mode successfully.$(NC)"


clean : 
	@$(ECHO) "$(BROWN)[CLN] Cleaning object and dependency files...$(NC)"
	@$(RM) $(DEP_FILES) $(OBJ_FILES) $(DEBUG_BUILD_PATH).[od]
	@$(MAKE) --no-print-directory -s -C ./libft clean
	@$(MAKE) --no-print-directory -s -C ./mlx_linux clean
	@$(ECHO) "$(GREEN)[CLN] Clean complete.$(NC)"

fclean : 
	@$(ECHO) "$(BROWN)[CLN] Cleaning object, dependency files, and executable...$(NC)"
	@$(RM_RF) $(BUILD_DIR) $(NAME)
	@$(MAKE) --no-print-directory -s -C ./libft fclean
	@$(MAKE) --no-print-directory -s -C ./mlx_linux clean
	@$(ECHO) "$(GREEN)[CLN] Clean complete.$(NC)"


.DEFAULT_GOAL := all
.PHONY : all clean fclean re debug
