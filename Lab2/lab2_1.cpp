// THIS CODE DOES NOT WORK!!!
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_draw.h>

void drawsmth(SDL_Surface * screen){
/* Отображение графика функции отрезками */
/* screen – инициализированная поверхность для рисования
640 на 480 пикселей, */
    const Sint16 width=640, heght=480;
    double xmin=-32.0, xmax=32.0, ymin, ymax;
    double mx=10.0, my=10.0, dx=0.1, x1, y1, x2, y2;
    Sint16 x0scr, y0scr, xscr1, yscr1, xscr2, yscr2;
    x0scr=floor(-1*xmin*mx);
/* ymin – неизвестно, так нельзя:
y0scr=floor(height+ymin*my);
Используем соглашение о середине экрана: */
    y0scr=screen->h/2; /*целочисленное деление */
    for(x1=xmin, x2=xmin+dx;x1<xmax;x1=x2, x2+=dx){
        if((fabs(x1)-1e-4)>0 && (fabs(x2)-1e-4)>0){
/*исключение нуля с учетом погрешности */
            y1=log(fabs(x1)); /*можно исключить повтор вычислений*/
            y2=log(fabs(x2));
            xscr1=x0scr+floor(x1*mx);
            yscr1=y0scr-floor(y1*my);
            xscr2=x0scr+floor(x2*mx);
            yscr2=y0scr-floor(y2*my);
/*Отрезок синим цветом: */
            Draw_Line(screen,xscr1,yscr1,
                      xscr2,yscr2,0x0000FF);
        }
    }
}
int main(int argc, char *argv[]) {
    SDL_Surface *screen;
    SDL_Event event;
    int flag = 0;
    if (SDL_Init(SDL_INIT_VIDEO)) /* инициализация SDL */
    { /* При ошибке формируем сообщение и выходим */
        fprintf(stderr, "Ошибка в SDL_Init: %s\n", SDL_GetError());
        return 1;
    }
/* После инициализации собственно SDL
и установки atexit(SDL_Quit): */
    screen = SDL_SetVideoMode(1280, 720, 32, SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "SDL mode failed: %s\n", SDL_GetError());
        return 1;
    }
    drawsmth(screen);
}