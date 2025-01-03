/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myhunter-nicky.truong
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <stdlib.h>

typedef struct game_s {
    sfRenderWindow *window;
    sfTexture *texture;
    sfTexture *bgtexture;
    sfSprite *sprite;
    sfSprite *background;
    sfVector2f pos;
} game_t;

void display(game_t *game);
int initclock(sfIntRect *rect, game_t *game);
sfIntRect set_rect(void);
int my_strcmp(char const *str1, char const *str2);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
int my_put_nbr(int nb);
char *my_revstr(char *str);
void my_putchar(char c);
void move_sprite(game_t *game);

#endif /* MY_H */
