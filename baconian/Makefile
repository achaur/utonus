NAME = baconian

INC_DIR = inc/
OBJ_DIR = obj/
SRC_DIR = src/
CC = clang 
FLAGS = -std=c11 $(addprefix -W, all extra error pedantic)
RM = rm -rf
PRINT = printf
MKDIR = mkdir -p
AR = ar
AR_FLAGS = rcs

INC_FILES = $(wildcard $(INC_DIR)*.h)
SRC_FILES = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(CC) $(FLAGS) -o $@ $^
	@$(PRINT) "\033[0;32m$@\033[0m\tcreated\n"

#adding order-only prerequisite so the OBJ_DIR will not be rebuild if any of the OBJ_FILES was changed
$(OBJ_FILES): | $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_FILES)
	@$(CC) $(FLAGS) -c $< -o $@ -I$(INC_DIR)
	@$(PRINT) "\033[0;32m$<\033[0m\tcompiled\n"

$(OBJ_DIR):
	@$(MKDIR) $@

clean: 
	@$(RM) $(OBJ_DIR)
	@printf "\033[31;1m$(OBJ_DIR)\033[0m\n in $(NAME)\t deleted"

reinstall: uninstall all
		   
uninstall: 
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@$(PRINT) "\033[0;31m$(NAME)\033[0m\tuninstalled\n"

.PHONY: all clean reinstall uninstall
