/*
** EPITECH PROJECT, 2024
** B-MUL-100-PAR-1-1-myhunter-nicky.truong
** File description:
** clock.c
*/

#include "../include/my.h"

sfIntRect set_rect(void)
{
    sfIntRect rect;

    rect.left = 0;
    rect.top = 0;
    rect.width = 110;
    rect.height = 110;
    return rect;
}

static void anim_duck(sfIntRect *rect, int offset, int max_offset,
    game_t *game)
{
    rect->left += offset;
    rect->left %= max_offset;
    sfSprite_setTextureRect(game->sprite, *rect);
}

void move_sprite(game_t *game)
{
    game->pos.x += 15;
    sfSprite_setPosition(game->sprite, game->pos);
    if (game->pos.x > 1920) {
        game->pos.x = -120;
        game->pos.y = rand() % 1080;
        sfSprite_setPosition(game->sprite, game->pos);
    }
}

int initclock(sfIntRect *rect, game_t *game)
{
    sfClock *clock;
    sfTime time;
    float sec;

    clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    sec = time.microseconds / 80000.0;
    while (sec < 1) {
        time = sfClock_getElapsedTime(clock);
        sec = time.microseconds / 80000.0;
        if (sec > 1.0)
            return initclock(rect, game);
    }
    sfClock_destroy(clock);
    anim_duck(rect, 110, 330, game);
    return 0;
}
