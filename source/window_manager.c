/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myhunter-nicky.truong
** File description:
** window_manager.c
*/

#include "../include/my.h"
#include <time.h>

static void destroy(game_t *game)
{
    sfSprite_destroy(game->sprite);
    sfTexture_destroy(game->texture);
    sfRenderWindow_destroy(game->window);
}

static void check_mouse_position(game_t *game, sfIntRect *rect)
{
    sfVector2f pos_duck = sfSprite_getPosition(game->sprite);
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mouse_pos.x >= pos_duck.x && mouse_pos.x <= pos_duck.x +
            rect->width && mouse_pos.y >= pos_duck.y && mouse_pos.y <=
            pos_duck.y + rect->height) {
                sfSprite_setPosition(game->sprite, game->pos);
                game->pos.x = -130;
                game->pos.y = rand() % 1080;
            }
    }
    return;
}

static void analyse_events(game_t *game, sfEvent event, sfIntRect *rect)
{
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (event.type == sfEvtMouseButtonPressed) {
            check_mouse_position(game, rect);
        }
    }
}

void display(game_t *game)
{
    sfIntRect rect = set_rect();
    sfEvent event;

    while (sfRenderWindow_isOpen(game->window)) {
        initclock(&rect, game);
        analyse_events(game, event, &rect);
        move_sprite(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, game->background, NULL);
        sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
        sfRenderWindow_display(game->window);
    }
    destroy(game);
}
