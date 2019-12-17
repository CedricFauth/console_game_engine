
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "input.h"

volatile char ch = ' ';

void listen(){
    printf("listener thread started.\r\n");
    while ((ch = getchar()) != 'q') ;
    printf("Terminated.\n\r");
}
