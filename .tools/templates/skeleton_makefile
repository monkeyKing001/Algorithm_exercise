#input manual cpp
#SRC = main.cpp
CFLAGS =
CDEBUG = -g -fsanitize=address -std=c++11
RM = rm -f
CC = g++
SRC_DIR = .
OBJ_DIR = .
BIN_DIR = .
NAME = $(BIN_DIR)/$(BIN)
PRINTF = LC_NUMERIC="en_US.UTF-8" printf
TEST_DIR = ./test
t = 1
BIN = a.out

#################################################
##########    JAVA COMPILE OPTION      ##########
#################################################
JFLAGS = -g
JAVA_SRC = Main.java
JAVAC  = javac
JAVA_CLASS = Main.class
JAVA_BIN = Main


# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SHELL=/bin/bash
UNAME = $(shell uname -s)

# Progress vars
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | grep ".cpp" | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

#compile and test!
all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(CDEBUG) $(OBJ) -o $@
	@$(PRINTF) "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"
	@make clean

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) $(CDEBUG) -c $< -o $@

clean:
	@$(PRINTF) "$(CYAN)Cleaning up object files in $(BIN)...$(DEFAULT)\n"
	@$(RM) $(OBJ) $(JAVA_CLASS)

fclean: clean
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"
	@$(RM) $(OBJ)
	@$(RM) $(BIN)
	@$(RM) $(JAVA_CLASS)

run :
	@${BIN_DIR}/${BIN}

re: fclean
	@make all

test:
	make re
	@${BIN_DIR}/${BIN} < ${TEST_DIR}/$t.txt

java : ${JAVA_SRC}
	$(JAVAC) $(JFLAGS) ${JAVA_SRC}
	@$(PRINTF) "\r%100s\r$(GREEN)${JAVA_CLASS} has been made!$(DEFAULT)\n"

javarun :
	@make java
	@java ${JAVA_BIN}

javatest :
	@make java
	@java ${JAVA_BIN} < ${TEST_DIR}/$t.txt

git:
	git add .
	git commit
	git push

.PHONY: make clean fclean re test
