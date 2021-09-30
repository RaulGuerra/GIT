#include <stdio.h>
#include "header.h"
#include "add.c"

void main(void)
{
    int num1 = 10;
    int num2 = 20;

    printf("The result of %d + %d = %d\n", num1, num2, add(num1,num2));
    
}