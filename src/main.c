
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>
#include <time.h>

char ch;

void *listen(){
    printf("Second Thread started.\n");
    system("stty raw");
    while ((ch = getchar()) != 'q') {
        
        //printf("%c\n", ch);
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
        
    }
    system("stty cooked");
    printf("Terminated.\n\r");
    return NULL;
}

int msleep(long msec)
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

int main(void){
    printf("\e[?25l");
    pthread_t th[1];
    pthread_create (th  , NULL, listen, NULL);
    while(ch != 'q'){
        printf("Main Program\n\r");
        msleep(400);
    }
    printf("\e[?25h");
    exit(EXIT_SUCCESS);
}
