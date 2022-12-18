#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"
#include <ncurses.h>

void palette() {
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLUE);
    init_pair(5, COLOR_RED, COLOR_RED);
    init_pair(6, COLOR_GREEN, COLOR_GREEN);
}

int main(){
    int ch, posY, posX, sY, sX;

    setlocale(LC_ALL, "");
    ncurses_init();
    ncurses_colors();
    ncurses_init_mouse();
    palette();

    posX = COLS/2;
    posY = LINES/2;

    attron(COLOR_PAIR(4));
    mvaddch(1, 1, ' ');
    attroff(COLOR_PAIR(4));

    attron(COLOR_PAIR(5));
    mvaddch(1, 2, ' ');
    attroff(COLOR_PAIR(5));

    attron(COLOR_PAIR(6));
    mvaddch(1, 3, ' ');
    attroff(COLOR_PAIR(6));

    mvprintw(posY, posX, "Bonjour");
    while((ch = getch()) != KEY_F(2)){
        switch (ch) {
            case KEY_MOUSE:
                if (mouse_getpos(&sX, &sY) == OK) {
                    move(LINES - 1, 2);
                    if (sY == 1 && sX == 1) {
                        attron(COLOR_PAIR(1));
                        mvprintw(posY, posX, "Bonjour");
                        attroff(COLOR_PAIR(1));
                    } else if (sY == 1 && sX == 2) {
                        attron(COLOR_PAIR(2));
                        mvprintw(posY, posX, "Bonjour");
                        attroff(COLOR_PAIR(2));
                    } else if(sY == 1 && sX == 3){
                        attron(COLOR_PAIR(3));
                        mvprintw(posY, posX, "Bonjour");
                        attroff(COLOR_PAIR(3));
                    }
                }
                break;
        }
    }
    ncurses_stop();
    return EXIT_SUCCESS;
}
