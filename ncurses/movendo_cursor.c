#include <curses.h>

int main(){
    initscr();			
    raw();				
    keypad(stdscr, TRUE);		
    echo();			
  
    int x = 0, y = 0;

    printw("Pressione alguma tecla (F1 para sair).\n");
    for (;;) {
        int ch = getch();			
        switch (ch) {
            case KEY_F(1):
                goto end;
                break;
            case KEY_UP:
                if (y > 0) y--;
                break;
            case KEY_DOWN:
                if (y < LINES - 1) y++;
                break;
            case KEY_LEFT:
                if (x > 0) x--;
                break;
            case KEY_RIGHT:
                if (x < COLS - 1) x++;
                break;
        }

        move(y, x);
        refresh(); 			
    }
    
end:
    endwin();			

    
    // Configurações iniciais
    // move(y, x);            // Move cursor para posição inicial
    // refresh();             // Atualiza a tela

    // int ch;
    // while ((ch = getch()) != 'q') {  // Sai ao pressionar 'q'

        
    //     clear();           // Limpa a tela
    //     move(y, x);        // Move o cursor para nova posição
    //     refresh();         // Atualiza a tela
    // }

    return 0;
}