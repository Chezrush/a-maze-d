##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC					?=	gcc

UTILS_PATH			=	utils/

PARSER_PATH			=	parser/

SRC					=	$(addprefix src/,									\
						main.c												\
						amazed.c											\
						$(PARSER_PATH)parsing.c                             \
						$(PARSER_PATH)my_strchr.c                           \
						$(UTILS_PATH)open_file.c							\
                	    )
SRC_TU				=	$(addprefix src/,									\
						amazed.c											\
						$(UTILS_PATH)open_file.c							\
                	    )

SRC_TEST			=	$(addprefix tests/,									 \
						test_minishell.c									 \
						)

NAME    			=	amazed

NAME_TEST   		=	unit_tests

CFLAGS  			=	-Wall -Wextra -Werror -std=gnu2x

LDFLAGS				=	-L./lib/my -lmy -L./lib/lib_vectors -lvectors

CPPFLAGS			=	-iquote./include/

OBJ					=	$(SRC:.c=.o)

OBJ_TU				=	$(SRC_TU:.c=.o)

UT_OBJ				=	*.gcno *.gcda

all:		$(NAME)

lib_build:
		make -C ./lib

$(NAME):	$(OBJ) lib_build
		$(CC) $(OBJ) $(LIB_PATH) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ)

clean_test:
		$(RM) $(UT_OBJ)
		$(RM) $(NAME_TEST)

fclean:		clean clean_test
		make fclean -C ./lib
		$(RM) $(NAME) $(NAME_TEST)

coding-style:	fclean
		coding-style . .
		clear
		cat coding-style-reports.log

re:		fclean all

debug: 		CFLAGS 	+= -g3 -ggdb3
debug: 		all

asan: 		CFLAGS 	+= -fsanitize=address -g3 -ggdb3
asan:		LDFLAGS += -fsanitize=address
asan: 		all

unit_tests: 	lib_build
		$(CC) $(CPPFLAGS) -o $(NAME_TEST) $(SRC_TEST) $(SRC_TU) $(LIB_PATH) \
		--coverage -lcriterion

tests_run:	fclean clean_test unit_tests
		./$(NAME_TEST)

.PHONY: all clean fclean coding-style re debug asan unit-tests tests_run
