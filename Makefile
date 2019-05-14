# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 14:57:58 by pchadeni          #+#    #+#              #
#    Updated: 2019/05/13 16:03:02 by pchadeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------Name of the project------#

NAME = libfts.a

#------Compilation's flags------#

AR = ar rc
CC = gcc
NASM = nasm

# flags
C_FLAGS = -Wall -Wextra
NASM_FLAGS = -f macho64

ifneq ($(NOERR),yes)
C_FLAGS += -Werror
endif

ifeq ($(DEV),yes)
FLAGS += -g
endif

ifeq ($(SAN),yes)
FLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

NUMBER_FILES = $(words $(LIB_FILES))
INDEX = 1

#------All sources------#
#------Library------#

INCLUDES = ./inc/
INC += -I$(INCLUDES)
INC += -I $(LIB_PATH)
HEAD = ''

#### FILES FROM LIB ####
LIB_FILES = ft_bzero.s		\
			ft_isalpha.s	\
			ft_isdigit.s	\
			ft_isalnum.s	\
			ft_isascii.s	\
			ft_isprint.s	\
			ft_tolower.s	\
			ft_toupper.s	\
			ft_strlen.s		\
			ft_puts.s

MAIN = $(addprefix $(SRCS_PATH)/, main.c)
#------Path------#

SRCS_PATH = srcs
OBJ_PATH  = obj
LIB_PATH  = libft
SRCS_LIB    += $(addprefix $(SRCS_PATH)/, $(LIB_FILES))

SRCS += $(addprefix $(SRCS_PATH)/, $(SRCS_LIB))

#OBJP += $(addprefix ./$(OBJ_PATH)/, $(LIB_PATH))
OBJP += ./$(OBJ_PATH)/)

OBJ += $(addprefix ./$(OBJ_PATH)/, $(LIB_FILES:.s=.o))

#------Main rules------#

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ)
	@$(eval PROGRESS:=$(shell echo $$(($(PROGRESS)+1))))
	@printf "\r⸨`printf '▓%.s' {0..$(PROGRESS)}`⸩"
	@printf " Objects created $(BOLD_GREEN)✓$(EOC)\n"
	@printf "Start making $(NAME)...\n"
	@$(AR) $(NAME) $^
	@ranlib $(NAME)
	@printf "$(BOLD_GREEN)⤖     $(NAME)$(EOC) created $(BOLD_GREEN)✓$(EOC)\n"

$(OBJ_PATH):
	@echo "Generating $(NAME)"
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRCS_PATH)/%.s
	@$(eval PROGRESS=$(shell echo $$(($(INDEX)*30/$(NUMBER_FILES)))))
	@$(eval NOT_DONE=$(shell echo $$((30-$(INDEX)*30/$(NUMBER_FILES) - 1))))
	@$(NASM) $(NASM_FLAGS) -o $@ $<
	@$(eval INDEX:=$(shell echo $$(($(INDEX)+1))))
	@$(eval PERCENT=$(shell echo $$((($(INDEX))*100/$(NUMBER_FILES)))))
	@printf "\r⸨`printf '▓%.s' {0..$(PROGRESS)}``printf '░%.s' {0..$(NOT_DONE)}`⸩"
	@printf " | %3d%% - [$(INDEX)/$(NUMBER_FILES)]" $(PERCENT)

test: $(NAME)
	$(CC) $(C_FLAGS) $(MAIN) $^ -o output_test

clean:
	@if [ -d $(OBJ_PATH) ]; \
	then \
		rm -Rf $(OBJ_PATH); \
		echo "$(BOLD_GREEN)clean ✓$(EOC)"; \
	fi;

fclean: clean
	@if [ -e $(NAME) ]; \
	then \
		rm -Rf $(NAME); \
		echo "$(BOLD_GREEN)fclean ✓$(EOC)"; \
	fi;

re: fclean all

#------Define colors------#

BOLD_GREEN = \033[01;32m
COL_GREEN = \033[0;32m
COL_YELLOW = \033[0;33m
EOC = \033[0m
