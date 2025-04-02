##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC				?=	gcc

SRC				=	$(addprefix tmp/, 								\
					test_split_word_array.c							\
					)												\
					$(addprefix src/, 								\
					auto_free.c										\
					split_word_array.c								\
                    vector_create.c									\
                    vector_destroy.c								\
                    vector_find.c									\
                    vector_get_at.c									\
                    vector_getlength.c								\
                    vector_insert_at.c								\
                    vector_npushback.c								\
                    vector_pop_at.c									\
                    vector_popback.c								\
                    vector_pushback.c								\
                    vector_pushback_dynamic.c						\
                    )
SRC_TU			=	$(addprefix src/, 								\
                    auto_free.c										\
                    split_word_array.c								\
                    vector_create.c									\
                    vector_destroy.c								\
                    vector_find.c									\
                    vector_get_at.c									\
                    vector_getlength.c								\
                    vector_insert_at.c								\
                    vector_npushback.c								\
                    vector_pop_at.c									\
                    vector_popback.c								\
                    vector_pushback.c								\
                    vector_pushback_dynamic.c						\
                    )

SRC_TEST		=	$(addprefix tests/,								\
					test_vectors.c									\
					)

NAME    		=	libvectors.a

NAME_DEV    	=	test_lib

NAME_TEST   	=	unit_test

CFLAGS  		=	-Wall -Wextra -Werror -std=gnu2x -L../my -lmy -g3 -ggdb3

CPPFLAGS		=	-iquote./include/ -iquote../my/include

OBJ				=	$(SRC:.c=.o)

OBJ_TU			=	$(SRC_TU:.c=.o)

UT_OBJ			=	*.gcno *.gcda

all:    	$(NAME)

$(NAME):	$(OBJ_TU)
		$(AR) rc $(NAME) $(OBJ_TU)
		cp ./include/vectors.h ../../include

dev:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME_DEV) $(LDFLAGS)

clean:
		$(RM) $(OBJ_TU)

clean_test:
		$(RM) $(OBJ)
		$(RM) $(UT_OBJ)
		$(RM) $(NAME_TEST)

fclean:		clean clean_test
		$(RM) $(NAME) $(NAME_TEST)


re:		fclean all

debug: 		CFLAGS 	+= -g3 -ggdb3
debug: 		all

asan: 		CFLAGS 	+= -fsanitize=address -g3 -ggdb3
asan:		LDFLAGS += -fsanitize=address
asan: 		all

unit_tests:
		$(CC) $(CPPFLAGS) -o $(NAME_TEST) $(SRC_TEST) $(SRC_TU) \
		--coverage -lcriterion

tests_run:	fclean clean_test unit_tests
		./$(NAME_TEST)

%.o:	%.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

.PHONY: all clean fclean coding-style re debug asan unit-tests tests_run
