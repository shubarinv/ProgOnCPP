//
// Created by vhundef on 21.02.19.
//

#include <cstdio>
#include <SDL/SDL.h>
#include <SDL/SDL_draw.h>

void drawShip(SDL_Surface *where_to_draw, SDL_Rect *shp, SDL_Rect *cleaner, SDL_Rect *ship_tower, SDL_Rect *flag) {
    Sint32 base_color = 0xFFB533; // Основной цвет (желтый)

    SDL_FillRect(where_to_draw, cleaner, 0x0d34f6); // Очищаем экран

    Draw_Line(where_to_draw, shp->x, shp->y, shp->x - 40, shp->y, 0xFFB533);
    Draw_Line(where_to_draw, shp->x, shp->y + shp->h - 1, shp->x - 40, shp->y + shp->h - 30, 0xFFB533);
    SDL_FillRect(where_to_draw, shp, base_color);
    SDL_FillRect(where_to_draw, ship_tower, base_color);
    Draw_Line(where_to_draw, shp->x + 100, shp->y, shp->x + 140, shp->y, 0xFFB533);
    Draw_Line(where_to_draw, shp->x + 100, shp->y + shp->h - 1, shp->x + 140, shp->y + shp->h - 30, 0xFFB533);
    SDL_FillRect(where_to_draw, flag, 0xff7878);
    Draw_Line(where_to_draw, shp->x + 30, shp->y - 20, shp->x + 30, shp->y - 80, 0xFFB533);
    Draw_Line(where_to_draw, shp->x + 125, shp->y, shp->x + 125, shp->y - 50, 0xFFB533);

}

void moveShip(SDL_Rect *shipParts[], int leftright, int speed) {
    int ship_towerOffsetX = 0, ship_towerOffsetY = -20, flag_OffsetX = -20, flag_OffsetY = -50;
    //Ship Tower
    shipParts[1]->x = shipParts[0]->x + ship_towerOffsetX;
    shipParts[1]->y = shipParts[0]->y + ship_towerOffsetY;
    //Flag

    if (speed == 0) {
        shipParts[2]->x = shipParts[0]->x + flag_OffsetX + 150;
        shipParts[2]->y = shipParts[0]->y + flag_OffsetY;
    } else {
        if (leftright == 1) {
            shipParts[2]->x = shipParts[0]->x + flag_OffsetX + 5;
            shipParts[2]->y = shipParts[0]->y + flag_OffsetY - 30;
        } else if (leftright == -1) {
            shipParts[2]->x = shipParts[0]->x + flag_OffsetX + 50;
            shipParts[2]->y = shipParts[0]->y + flag_OffsetY - 30;
        }
    }
}

int main(int argc, char *argv[]) {
    SDL_Surface *screen; /* объявление указателя на поверхность: */
    SDL_Event event;
    SDL_Rect r; /* сам прямоугольник*/
    SDL_Rect r_new; /* новое положение прямоугольника*/
    SDL_Rect cleaner;
    SDL_Rect ship_tower;
    SDL_Rect flag;
    SDL_Rect bg;
    Sint16 leftright = 1; /* слева направо = 1, справа налево =-1 */
    Sint16 max_x, max_y;
    int nextstep = 1; /* для цикла обработки сообщений */
    double movementSpeed = 0;
    max_x = 1280;
    max_y = 720;
    screen = SDL_SetVideoMode(max_x, max_y, 32,
                              SDL_ANYFORMAT);    /* инициализация библиотеки и установка видеорежима */
    if (!screen) {
        fprintf(stderr, "SDL mode failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1; /* Выход с одним кодом ошибки */
    }
    // Задаём размер и координаты основной части корабля
    r.x = max_x / 2 - 50;
    r.y = max_y / 2 - 15;
    r.w = 100;
    r.h = 30;
    bg.w=max_x;
    bg.h=max_y;
    bg.x=0;
    bg.y=0;
    SDL_FillRect(screen,&bg,0x0d34f6);
    // Задаём размер и координаты прямоугольника стирающего корабль(нужен для удаления следов при движении)
    cleaner.x = 0;
    cleaner.y = max_y / 2 - 100;
    cleaner.h = 150;
    cleaner.w = max_x;
    // Задаём размер и координаты башни
    ship_tower.x = max_x / 2;
    ship_tower.y = max_y / 2;
    ship_tower.w = 55;
    ship_tower.h = 20;
    // Задаём размер флага
    flag.w = 45;
    flag.h = 25;
    r_new = r;
    while (nextstep) // цикл перерисовки и обработки событий
    {
        if (SDL_PollEvent(&event)) // проверяем нажатие клавиш на клавиатуре
        {
            if (event.type == SDL_QUIT ||
                (event.type == SDL_KEYDOWN &&
                 event.key.keysym.sym == SDLK_ESCAPE))
                nextstep = 0;
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_DOWN) {
                movementSpeed = 0; // останавливаем корабль
            }
            if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_DOWN) {
                movementSpeed = 1;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_LEFT) {
                leftright = -1; // поворот налево
                movementSpeed = 1;
            }
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RIGHT) {
                leftright = 1; // поворот направо
                movementSpeed = 1;
            }
        }
        // расчет перемещения по горизонтали
        r_new.x = r.x + leftright * movementSpeed; // скорость перемещения и направление движения
        // (на сколько пикселей смещаться за один шаг цикла)

        if (r_new.x < 50 || r_new.x + r.w > max_x - 75) { // остановка при приближении к краям окна
            movementSpeed = 0;
            if (r_new.x + r.w > max_x - 75) {
                r_new.x = max_x - 75 - r.w;
            }
        }
        r = r_new; // обоновляем координаты
        SDL_Rect *shipParts[]{&r, &ship_tower, &flag}; // Здесь содержатся части корабля
        moveShip(shipParts, leftright, movementSpeed); // Обновляем координаты частей корабля
        // собственно перерисовка:
        SDL_LockSurface(screen);
        drawShip(screen, &r, &cleaner, &ship_tower, &flag); //Рисуем корабль
        SDL_UnlockSurface(screen);
        SDL_UpdateRect(screen, 0, 0, max_x, max_y);
        SDL_Delay(movementSpeed * 10); // нужно для замедления движения корабля
    }
    SDL_Quit();
    return 0; /* Нормальное завершение */
}