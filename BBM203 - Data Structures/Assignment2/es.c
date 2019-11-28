#include <stdio.h>
#include <stdlib.h>

void square(char *argv) {
    printf("%s",argv);
}
int main(int argc, char *argv[])
{
    square(argv[1]);
}
