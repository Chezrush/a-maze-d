/*
** EPITECH PROJECT, 2025
** my_showmem.c
** File description:
** my_showmem
*/

#include "my.h"

void my_puthex(uint8_t byte)
{
    char hex[3] = "00";

    hex[0] = "0123456789abcdef"[byte / 16];
    hex[1] = "0123456789abcdef"[byte % 16];
    write(1, hex, 2);
}

void display(size_t i, char *addr)
{
    for (size_t j = 0; j < 8; ++j) {
        addr[7 - j] = "0123456789abcdef"[(i >> (j * 4)) & 0xF];
    }
}

void my_showmem(const void *ptr, size_t size)
{
    uint8_t const *bytes = {};
    char addr[9] = "00000000";

    if (ptr == NULL) {
        my_putstr("NULL pointer provided\n");
        return;
    }
    bytes = (const uint8_t *)ptr;
    for (size_t i = 0; i < size; ++i) {
        if (i % 16 == 0) {
            display(i, addr);
            write(1, addr, 8);
            my_putstr(": ");
        }
        my_puthex(bytes[i]);
        my_putstr(" ");
        if ((i + 1) % 16 == 0 || i == size - 1) {
            my_putstr("\n");
        }
    }
}
