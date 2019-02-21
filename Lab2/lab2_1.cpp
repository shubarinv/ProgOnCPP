//
// Created by vhundef on 21.02.19.
//
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_draw.h>
#include "iostream"
#include <cmath>

using namespace std;

int getcoordY(int x) {
    double y;
    y = ((pow(M_E, -2) / (x - 5))*1000);

    return y;
}

int main(int argc, char *argv[]) {
    SDL_Surface *screen;
    SDL_Event event;
    SDL_Rect r; /* сам прямоугольник*/
    Sint16 max_x, max_y;
    double nextstep = -5; /* для цикла обработки сообщений */
    int prevX, prevY;
/* инициализация библиотеки и установка видеорежима */
    max_x = 1280;
    max_y = 720;
    screen=SDL_SetVideoMode(max_x,max_y,32,SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "SDL mode failed: %s\n", SDL_GetError());
        SDL_Quit();
        return 1; /* Выход с одним кодом ошибки */
    }

    r.x = 0;
    r.y = 0;
    r.w = max_x;
    r.h = max_y;
    SDL_FillRect(screen, &r, 0xFFFFFFFF); /* ярко-синий */
    prevX = max_x/2;
    prevY = max_y/2;
/* цикл перерисовки и обработки событий */
    while (nextstep <3) {
        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT ||
                (event.type == SDL_KEYDOWN &&
                 event.key.keysym.sym == SDLK_ESCAPE))
                nextstep = 0; /* Выход */

        }
        Draw_Line(screen, prevX, prevY, prevX + nextstep, prevY + getcoordY(nextstep), 0x0000000FF);

        prevX += nextstep;
        prevY += getcoordY(nextstep);

        nextstep+=1;
        /* собственно перерисовка: */
        SDL_LockSurface(screen);
        //SDL_FillRect(screen, &r, 0xFFFFFFFF); /* ярко-синий */
        SDL_UnlockSurface(screen);
        SDL_UpdateRect(screen, 0, 0, max_x, max_y);
        /* Задержка на опрос событий составляет около 10 мс или более, в зависимости от
       производительности компьютера. При необходимости возможна дополнительная задержка */
    }
    while(SDL_WaitEvent(&event)){
        if(event.type == SDL_QUIT ||
           (event.type == SDL_KEYDOWN &&
            event.key.keysym.sym == SDLK_ESCAPE)){
            SDL_Quit();
            return 0;
        }
    }
    SDL_Quit();
    return 0; /* Нормальное завершение */
}