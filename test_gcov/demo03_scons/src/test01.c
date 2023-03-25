#include <stdlib.h>
#include <stdio.h>

#include "math/math.h"
void test01(){
    printf("test01\n");
}

void test02(){
    printf("test add, %d\n", add(1,1));
}

int main(int argc, char *argv[]){
    printf("main\n");

    test01();
    test02();
    return 0;
}