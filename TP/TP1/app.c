#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"
#include <ncurses.h>

int main(){
    WINDOW *w1, *w2;
    int ch, sY, sX;
    setlocale(LC_ALL, "");
    ncurses_init();
    ncurses_init_mouse();

    w1 = newwin(10, COLS, 1, 1);
    w2 = newwin(10, 10, 12, 1);
    box(w1, 0, 0);
    box(w2, 0, 10);
    while((ch = getch()) != KEY_F(2)){
        switch (ch) {
            case KEY_MOUSE:
                if (mouse_getpos(&sX, &sY) == OK) {
                    if(sY <= 22 && sY >= 12 && sX <= 11 && sX >= 1){
                        mvwaddch(w2, sY - 12, sX - 1, 'X');
                        wprintw(w1, "Y = %d, X = %d \n", sY, sX);
                        wrefresh(w1);
                        wrefresh(w2);
                    }
                }
                break;
        }
    }

    delwin(w1);
    delwin(w2);
    ncurses_stop();
    return EXIT_SUCCESS;
}