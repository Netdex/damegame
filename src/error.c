//
// Created by netdex on 9/7/2017.
//

#include <windef.h>
#include <stdio.h>
#include <stdlib.h>
#include "error.h"

void error(){
    error_msg(NULL);
}

void error_msg(const char* msg){
    printf("FATAL ERROR: ");
    if(msg){
        printf("%s\n", msg);
    } else {
        printf("unspecified error\n");
    }
    getchar();
    exit(1);
}