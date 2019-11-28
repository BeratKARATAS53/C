#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char komut[20];
    char words[128];
    char* word;
    char* komut2;
    printf("Enter Code: ");
    scanf("%s",&komut);
    komut2 = strtok(komut,"-, ");

    if(komut2 = "r")
    {
        FILE *input1 = fopen("d1.txt","r");
        while(fscanf(input1,"%s",words) == 1)
        {
            word = strtok (words," ,'-.(){\}");
            puts(strlwr(word));
        }
    }
    return 0;
}
