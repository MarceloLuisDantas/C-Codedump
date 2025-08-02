#include <ncurses.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

int max_distance = 0;
int WIDTH  = 0;
int HEIGHT = 0;

typedef struct Point {
    long double x;
    long double y;
} Point;

Point *new_point(int64_t x, int64_t y) {
    Point *p = malloc(sizeof(Point));
    p->x = (long double)x;
    p->y = (long double)y;
    return p;
}

long double distance_from_zero(Point *p) {
    long double a_square = powl(p->x, 2);
    long double b_square = powl(p->y, 2);
    return sqrtl(a_square + b_square);
}

long double distance(Point *from, Point *to) {
    long double a_square = powl(abs(to->x - from->x), 2);
    long double b_square = powl(abs((to->y * 2.2) - (from->y * 2.2)), 2);
    return sqrtl(a_square + b_square);
}

void init_grayscale_colors() {
    if(!can_change_color()) {
        endwin();
        printf("Seu terminal não suporta cores customizadas!\n");
        exit(1);
    }
    
    for(int i = 0; i <= 9; i++) {
        int intensity = i * 1000 / 9;
        init_color(i + 100, intensity, intensity, intensity);
        init_pair(i + 1, i + 100, COLOR_BLACK);
    }
}

int get_grayscale_pair(float value, float max_value) {
    float normalized = fabs(value) / max_value;
    int level = (int)(normalized * 9);
    if (level < 0)   return 1;
    if ((level > 9)) return 10;
    return level + 1;
}

void update(Point *center) {
    for (size_t x = 0; x < WIDTH; x++) {
        for (size_t y = 0; y < HEIGHT; y++) {
            Point *p = new_point(x, y);
            long double dist = distance(center, p);
            free(p);

            int pair = get_grayscale_pair(dist, max_distance);
            attron(COLOR_PAIR(pair));
            mvprintw(y, x, "#");
        }
    }
    refresh();
}

int main() {
    initscr();
    noecho();
    start_color();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    init_grayscale_colors();

    
    getmaxyx(stdscr, HEIGHT, WIDTH);
    if (HEIGHT % 2 == 0) HEIGHT -= 1;
    if (WIDTH % 2 == 0) WIDTH -= 1;
    max_distance = (WIDTH / 2);

    Point *center = new_point((WIDTH / 2) + 1, (HEIGHT / 2) + 1);
    
    int ch;
    while (true) {
        ch = getch();
        switch (ch) {
            case 'q':
                goto end;  // Sai do loop
                
            case KEY_UP:
                if (center->y > 1) center->y--;
                break;
                
            case KEY_DOWN:
                if (center->y < HEIGHT) center->y++;
                break;
                
            case KEY_LEFT:
                if (center->x > 1) center->x--;
                break;
                
            case KEY_RIGHT:
                if (center->x < WIDTH) center->x++;
                break;
                
            default:
                // Opcional: tratamento para outras teclas
                break;
        }

        update(center);
    }
end:

    endwin();			
    return 0;
}
