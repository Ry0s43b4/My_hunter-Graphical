/*
** EPITECH PROJECT, 2024
** My strcmp
** File description:
** Function that will compare 2 strings given
*/

#include "../include/my.h"

int my_strcmp(char const *str1, char const *str2)
{
    if (my_strlen(str1) != my_strlen(str2))
        return 2;
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != str2[i])
            return 1;
    }
    return 0;
}
