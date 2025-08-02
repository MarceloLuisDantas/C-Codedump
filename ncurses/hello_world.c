#include <ncurses.h>

int main(){	
  initscr(); // Inicializa terminal no modo do curses (stdscr)			
  
  // desativa o buffer de linha, sem ele é preciso difigar \n para que 
  // a linha esteja disponivel. Porem assim não, porem cuidado, se vc 
  // tentar sair com CTRL + C n vai da certo, pois ele desativa comandos
  raw(); 

  // Para de imprimir oq o usuario digita na tela
  noecho();

  // Faz com que oq o usuario digite seja imprimido na tela
  // echo();

  for (int i = 0; i < 10; i++) {
    printw("Hello World !!!"); // escreve no stdscr invẽs do stdio 
    refresh(); // Atualiza stdscr			
    getch(); // input pra dar delay			
  }
  endwin();	// Finaliza o stdscr
  
  return 0;
}
