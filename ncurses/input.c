#include <curses.h>

int main(){
    initscr();			
    raw();				
    keypad(stdscr, TRUE);		
    noecho();			
  
    for (;;) {
        printw("Pressione alguma tecla (F1 para sair).\n");
        int ch = getch();			
        if(ch == KEY_F(1)){		
            break;
        } else{
            printw("A tecla que você pressionou foi: ");
            attron(A_BOLD);
            printw("%i\n", ch);
            attroff(A_BOLD);
        }
        refresh();			
    }
    endwin();			

    return 0;
}