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
    WINDOW *level, *tools, *infos;
    WINDOW *sublevel, *subtools, *subinfos;
    int ch;
    setlocale(LC_ALL, "");
    ncurses_init();
    ncurses_colors();
    palette();

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

    attron(COLOR_PAIR(2));
    mvwprintw(subtools, 0, 2, "Delete");
    mvwprintw(subtools, 1, 2, "Block");
    mvwprintw(subtools, 2, 2, "Ladder");
    mvwprintw(subtools, 3, 2, "Trap");
    mvwprintw(subtools, 4, 2, "Gate");
    mvwprintw(subtools, 5, 2, "Key");
    mvwprintw(subtools, 6, 2, "Door");
    mvwprintw(subtools, 7, 2, "Exit");
    mvwprintw(subtools, 8, 2, "Start");
    mvwprintw(subtools, 9, 2, "Robot");
    mvwprintw(subtools, 10, 2, "Probe");
    mvwprintw(subtools, 11, 2, "Life");
    mvwprintw(subtools, 12, 2, "Bomb");
    mvwprintw(subtools, 18, 3, "DELETE");
    mvwprintw(subinfos, 0, 0, "Press 'F2' to quit...");
    attroff(COLOR_PAIR(2));

    mvwprintw(subtools, 14, 0, "Current level");
    mvwprintw(subtools, 16, 3, "< 001 >");

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