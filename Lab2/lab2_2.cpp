//
// Created by vhundef on 21.02.19.
//

#include <cstdio>
#include <SDL/SDL.h>
#include <SDL/SDL_draw.h>
#include <iostream>

void drawShip(SDL_Surface * where_to_draw,SDL_Rect *shp, int left){ //if not left(-1),then right(1)
    Sint32 base_color=0xFFB533;

    if(left==-1){
        Draw_FillCircle(where_to_draw,shp->x+shp->w,shp->y+30,40,0x000);
        SDL_FillRect(where_to_draw, shp, base_color);
        Draw_FillCircle(where_to_draw,shp->x+shp->w,shp->y+30,30,0xFFB533);
        Draw_Line(where_to_draw,shp->x,shp->y,shp->x-50,shp->y+30,0x00000FF);
        Draw_Line(where_to_draw,shp->x,shp->y+shp->h-2,shp->x-50,shp->y+30,0x00000FF);
    }
    else{
        Draw_FillCircle(where_to_draw,shp->x-10,shp->y+30,40,0x000);
        SDL_FillRect(where_to_draw, shp, base_color);
        Draw_FillCircle(where_to_draw,shp->x,shp->y+30,30,0xFFB533);
        Draw_Line(where_to_draw,shp->x+99,shp->y,shp->x+140,shp->y+30,0x00000FF);
        Draw_Line(where_to_draw,shp->x+99,shp->y+shp->h-2,shp->x+140,shp->y+30,0x00000FF);
    }

}

int main(int argc, char *argv[]) {
    SDL_Surface *screen; /* объявление указателя на поверхность: */
    SDL_Event event;
    SDL_Rect r; /* сам прямоугольник*/
    SDL_Rect r_new; /* новое положение прямоугольника*/
    Sint16 leftright = 1; /* слева направо = 1, справа налево =-1 */
    Sint16 max_x, max_y;
    int nextstep = 1; /* для цикла обработки сообщений */
    double movementSpeed=0;
    max_x = 1280;
    max_y = 720;
    screen = SDL_SetVideoMode(max_x, max_y, 32,
                              SDL_ANYFORMAT);    /* инициализация библиотеки и установка видеорежима */
    if (!screen) {
        fprintf(stderr, "SDL mode failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1; /* Выход с одним кодом ошибки */
    }
/* В объявленных ранее переменных Sint16 max_x и Sint16 max_y записаны фактическая ширина и вы-
сота области, в которой перемещается квадратик после установки видеорежима – фрагмент опущен*/
/* Первоначальное рисование по центру экрана синего прямоугольника с шириной 40 и высотой 20
пикселей */
    r.x = max_x / 2 - 50;
    r.y = max_y / 2 - 30;
    r.w = 100;
    r.h = 60;
    r_new = r;
    while (nextstep) /* цикл перерисовки и обработки событий */
    {
        if (SDL_PollEvent(&event)) /*если наступило событие*/
        {
            if (event.type == SDL_QUIT ||
                (event.type == SDL_KEYDOWN &&
                 event.key.keysym.sym == SDLK_ESCAPE))
                nextstep = 0; /* Выход */
            if(event.type==SDL_KEYDOWN&&event.key.keysym.sym==SDLK_DOWN){
                movementSpeed=0;
            }
            if(event.type==SDL_KEYUP&&event.key.keysym.sym==SDLK_DOWN){
                movementSpeed=1;
            }
            if(event.type==SDL_KEYDOWN&&event.key.keysym.sym==SDLK_LEFT){
                leftright=-1;
                movementSpeed=1;
            }
            if(event.type==SDL_KEYDOWN&&event.key.keysym.sym==SDLK_RIGHT){
                leftright=1;
                movementSpeed=1;
            }
        }
/* расчет перемещения по горизонтали */
        r_new.x = r.x + 1 * leftright*movementSpeed; /* 1 – скорость перемещения
(на сколько пикселей смещаться за один шаг цикла)*/
        if (r_new.x < 50 || r_new.x + r.w > max_x-50) { /* отскок от стенки */
            movementSpeed=0;
        }
        r = r_new; /* используем новые координаты */
/* собственно перерисовка: */
        SDL_LockSurface(screen);
        drawShip(screen,&r,leftright);
        SDL_UnlockSurface(screen);
        SDL_UpdateRect(screen, 0, 0, max_x, max_y);
/* Задержка на опрос событий составляет около 10 мс или более, в зависимости от производительности
компьютера. При необходимости возможна дополнительная задержка */
    }
    SDL_Quit();
    return 0; /* Нормальное завершение */
}