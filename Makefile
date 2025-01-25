# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ptheo <ptheo@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/20 15:32:50 by inazaria          #+#    #+#              #
#    Updated: 2025/01/25 22:22:41 by ptheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#<><><><><><><> Files <><><><><><><><><><><><><><><><><><><>
SRC_DIR 	= ./src/

BUILD_DIR 	= ./build/

INC_DIR 	= ./includes/

DEBUG_FILE_PATH = ./src/error_manager/debugging_functions
DEBUG_BUILD_PATH = ./build/error_manager/debugging_functions

# .c files for source code
SRC_FILES_NAMES  = main.c
SRC_FILES_NAMES += figure.c
SRC_FILES_NAMES += render.c
SRC_FILES_NAMES += parsing.c
SRC_FILES_NAMES += pixel.c

# to add for example src/map/map.c
# SRC_FILES_NAMES += map/map.c


# Full path to .c files
SRC_FILES = $(addprefix $(SRC_DIR), $(SRC_FILES_NAMES))

# .o files for compilation
OBJ_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.o, $(SRC_FILES))

# .d files for header dependency
DEP_FILES = $(patsubst $(SRC_DIR)%.c, $(BUILD_DIR)%.d, $(SRC_FILES))


#<><><><><><><> Variables <><><><><><><><><><><><><><><><><>

NAME := cub3d
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
