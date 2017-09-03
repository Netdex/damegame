
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


int main(const int argc, const char *argv[]){
	for(int i = 0; i < 256; i++){
		printf("/* 0x%02X */	{\"\",		\"\", 	NULL,		0},\n", i);
	}
}
