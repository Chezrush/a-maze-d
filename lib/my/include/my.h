/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdint.h>

int my_atoi(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_isneg(int nb);
void *my_memcpy(void *dest, const void *src, size_t n);
int my_put_nbr(int nb);
void my_putchar(char c);
int my_putstr(char const *str);
void *my_realloc(void *ptr, size_t size);
char *my_revstr(char *str);
void my_showmem(const void *ptr, size_t size);
int my_showstr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
char **my_str_to_word_array(char const *str, char const sep);
char *my_str_upper(char *str);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(const char *s1, const char *s2, size_t n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
bool check_ismax(long int nb);
int check_i(char const *str, int i);
int check_isneg(char const *str, int i);
void swap_numb(int *nb1, int *nb2);
void print_res(void);
char *my_strstr(char *str, char const *to_find);
#endif /* MY_H_ */
