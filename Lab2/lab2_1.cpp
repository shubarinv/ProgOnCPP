/* Copyright (C) Vladimir Shubarin - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 * Written by Vladimir Shubarin <vhundef@gmail.com>, Feb 2019
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL/SDL.h>
#include <SDL/SDL_draw.h>
#include <SDL/SDL_ttf.h>
#include <iostream>

using namespace std;

void drawText(SDL_Surface *whereToDraw, SDL_Surface *text_surface, SDL_Rect text_rect, TTF_Font *fnt, std::string text,
              int textCoordX, int textCoordY) {
    SDL_Color text_color;
    text_color.r = 0;
    text_color.g = 0;
    text_color.b = 0;
    text_rect.x = textCoordX;
    text_rect.y = textCoordY;
    text_surface = TTF_RenderUTF8_Solid(fnt, text.c_str(), text_color);
    SDL_BlitSurface(text_surface, NULL, whereToDraw, &text_rect);
    SDL_FreeSurface(text_surface);
    text_surface = NULL;
}

void drawsmth(SDL_Surface *screen,double xmin,double xmax) {
/* Отображение графика функции отрезками */
/* screen – инициализированная поверхность для рисования
640 на 480 пикселей, */
    double mx = 90, my = 3500, dx = 0.001, x1, y1, x2, y2;
    Sint16 x0scr, y0scr, xscr1, yscr1, xscr2, yscr2;
    int iter = 0,i=0;

    x0scr = floor(-1 * xmin * mx);//floor(-1 * xmin * mx);
//Используем соглашение о середине экрана:
    y0scr = screen->h / 2; /*целочисленное деление */
    for (x1 = xmin, x2 = xmin + dx; x1 < xmax; x1 = x2, x2 += dx) {
        if(x1==4||x1==5||x2==4||x2==5)
            continue;
        if ((fabs(x1) - 1e-4) > 0 && (fabs(x2) - 1e-4) > 0) {
/*исключение нуля с учетом погрешности */
            y1 = -(pow(M_E, -2) / (5 - x1)); /*можно исключить повтор вычислений*/
            y2 = -(pow(M_E, -2) / (5 - x2));
            std::cout << "=======" << std::endl << "x1: " << x1 << std::endl << "x2: " << x2 << std::endl;
            std::cout << "y1: " << y1 << std::endl << "y2: " << y2 << std::endl << "========" << std::endl;

            xscr1 = x0scr + floor(x1 * mx);
            yscr1 = y0scr - floor(y1 * my);
            xscr2 = x0scr + floor(x2 * mx);
            yscr2 = y0scr - floor(y2 * my);
/*Отрезок синим цветом: */
            Draw_Line(screen, xscr1, yscr1,
                      xscr2, yscr2, 0x0000FF);
            iter++;
        }
    }
    std::cout << "iterations" << iter << std::endl;
}


int main(int argc, char *argv[]) {
    SDL_Surface *screen;
    SDL_Event event;
    SDL_Rect bg;
    SDL_Surface *text_surface = NULL;
    TTF_Font *fnt = NULL;
    SDL_Rect text_rect;
    SDL_Color text_color;
    if (SDL_Init(SDL_INIT_VIDEO)) /* инициализация SDL */
    { /* При ошибке формируем сообщение и выходим */
        fprintf(stderr, "Ошибка в SDL_Init: %s\n", SDL_GetError());
        return 1;
    }
    if (TTF_Init()) {
        return 1;
    }
/* После инициализации собственно SDL
и установки atexit(SDL_Quit): */
    screen = SDL_SetVideoMode(720, 480, 32, SDL_ANYFORMAT);
    if (!screen) {
        fprintf(stderr, "SDL mode failed: %s\n", SDL_GetError());
        return 1;
    }

    if (!(fnt = TTF_OpenFont("Roboto-Regular.ttf", 18))) {
        TTF_Quit();
        SDL_Quit();
        return 3;
    }

    bg.w = 720;
    bg.h = 480;

    text_color.r = 0;
    text_color.g = 0;
    text_color.b = 0;

    text_rect.w = 1;
    text_rect.h = 1;

    SDL_FillRect(screen, &bg, 0xfffffff);

    drawText(screen,text_surface,text_rect,fnt,"-5",0,screen->h / 2);
    drawText(screen,text_surface,text_rect,fnt,"0",screen->w / 2 + 5,screen->h / 2);
    drawText(screen,text_surface,text_rect,fnt,"3",screen->w-10,screen->h / 2);

    SDL_Flip(screen);
    double xmin,xmax;
    cout<<"xmin: ";
    cin>>xmin;
    cout<<endl<<"xmax: ";
    cin>>xmax;
    drawsmth(screen,xmin,xmax);

    Draw_Line(screen, 0, screen->h / 2, screen->w, screen->h / 2, 0x0);
    Draw_Line(screen, screen->w / 2, 0, screen->w / 2, screen->h, 0x0);

    while (true) // цикл перерисовки и обработки событий
    {
        if (SDL_PollEvent(&event)) // проверяем нажатие клавиш на клавиатуре
        {
            if (event.type == SDL_QUIT ||
                (event.type == SDL_KEYDOWN &&
                 event.key.keysym.sym == SDLK_ESCAPE))
                break;
        }
        SDL_UpdateRect(screen, 0, 0, 720, 480);
    }
    TTF_CloseFont(fnt);
    TTF_Quit();
    SDL_Quit();
    return 0;
}