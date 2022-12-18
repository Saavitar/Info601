#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"
#include <ncurses.h>

int main(){
    WINDOW *level, *tools, *infos;
    WINDOW *sublevel, *subtools, *subinfos;
    int ch;
    setlocale(LC_ALL, "");
    ncurses_init();

    level = newwin(22, 62, 0, 0);
    tools = newwin(22, 15, 0, 62);
    infos = newwin(5, 77, 22, 0);

    sublevel = newwin(20, 60, 1, 1);
    subtools = newwin(20, 13, 1, 63);
    subinfos = newwin(3, 75, 23, 1);

    box(level, 0, 0);
    mvwprintw(level, 0, 1, "Level");
    box(tools, 0, 0);
    mvwprintw(tools, 0, 1, "Tools");
    box(infos, 0, 0);
    mvwprintw(infos, 0, 1, "Informations");

    wrefresh(level);
    wrefresh(sublevel);
    wrefresh(tools);
    wrefresh(subtools);
    wrefresh(infos);
    wrefresh(subinfos);
    while((ch = getch()) != KEY_F(2)){

    }

    delwin(level);
    delwin(sublevel);
    delwin(tools);
    delwin(subtools);
    delwin(infos);
    delwin(subinfos);
    ncurses_stop();
    return EXIT_SUCCESS;
}