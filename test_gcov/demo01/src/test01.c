#include <stdlib.h>
#include <stdio.h>

void test01(){
    printf("test01\n");
}

int main(int argc, char *argv[]){
    printf("main\n");

    test01();
    return 0;
}