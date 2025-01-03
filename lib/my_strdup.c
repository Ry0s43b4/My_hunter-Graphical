/*
** EPITECH PROJECT, 2024
** My str dup
** File description:
** Function that will duplicate a string into another string allocated
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(sizeof(char) * my_strlen(src));
    int i = 0;

    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
