
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

struct {
	int :4;
	int a:1;
	int b:1;
	int c:1;
	int d:1;
} test;
int main(const int argc, const char *argv[]){
	test.a = 3;
    printf("%d\n", test.a);

}
