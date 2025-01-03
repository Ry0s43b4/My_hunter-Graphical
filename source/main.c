/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myhunter-nicky.truong
** File description:
** main.c
*/

#include <stdlib.h>
#include "../include/my.h"

static int display_info(void)
{
    my_putstr("Helpful sheet :\n");
    my_putstr("My_hunter : Project based on the incredible game named ");
    my_putstr("'Duck hunt' made by Nintendo on april 21st 1984\n");
    my_putstr("The 2 characters of this game will later appeared in ");
    my_putstr("Super Smash Bros Ultimate, also a game made by Nintendo\n");
    my_putstr("The goal of the game ? Shoot ducks with the mouse and ");
    my_putstr("have the highest score.\n");
    my_putstr("Game over condition ? If 3 ducks reach the end of the screen,");
    my_putstr(" You lose !\n");
    return 0;
}

static int check_all_csfml(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfVector2i winposition = {150, 100};

    game->window = sfRenderWindow_create(mode, "My Hunter",
        sfResize | sfClose, NULL);
    if (!game->window)
        return 84;
    sfRenderWindow_setPosition(game->window, winposition);
    game->texture = sfTexture_createFromFile("assets/duck.png", NULL);
    if (!game->texture)
        return 84;
    game->sprite = sfSprite_create();
    sfSprite_setTexture(game->sprite, game->texture, sfTrue);
    game->bgtexture = sfTexture_createFromFile("assets/void.jpg", NULL);
    if (!game->bgtexture)
        return 84;
    return 0;
}

static int initialize_all(game_t *game)
{
    sfVector2f vec = { .x = 1, .y = 1.2 };

    check_all_csfml(game);
    game->background = sfSprite_create();
    sfSprite_setTexture(game->background, game->bgtexture, sfTrue);
    sfSprite_setScale(game->background, vec);
    game->pos.x = 0;
    sfSprite_setPosition(game->background, game->pos);
    game->pos.x = -130;
    sfSprite_setPosition(game->sprite, game->pos);
    display(game);
    return 0;
}

int main(int ac, char **av)
{
    game_t game = {0};

    if (ac != 1 && my_strcmp(av[1], "-h") == 0)
        return display_info();
    return initialize_all(&game);
}
