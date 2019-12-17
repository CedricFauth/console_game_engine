#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "input.h"
#include "engine.h"

extern char ch;

static int msleep(long msec)
{
    struct timespec ts;
    int res;

    if (msec < 0)
    {
        return -1;
    }

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;

    do {
        res = nanosleep(&ts, &ts);
    } while (res);

    return res;
}


void start_game(){
    system("stty raw");
    printf("\e[?25l");
        pthread_t tid[1];
        pthread_create (&tid[0]  , NULL, (void*) listen, NULL);
        while(ch != 'q'){
            printf("\e[2J\e[;f");
            printf("Main Program\r\n");
            switch (ch)
            {
                case 'w':
                    printf("UP\n\r");
                    break;
                case 's':
                    printf("DOWN\n\r");
                    break;
                case 'a':
                    printf("LEFT\n\r");
                    break;
                case 'd':
                    printf("RIGHT\n\r");
                    break;
                default:
                    break;
            }

            msleep(100);
        }

        pthread_join(tid[0], NULL);

        printf("\e[?25h");
    system("stty cooked");
}        
