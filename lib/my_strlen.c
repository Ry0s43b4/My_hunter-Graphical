/*
** EPITECH PROJECT, 2024
** My strlen
** File description:
** Function that will counts and returns the number of characters in a string
*/

int my_strlen(char const *str)
{
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++)
        x++;
    return x;
}
