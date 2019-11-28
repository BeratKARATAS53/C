#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *clientData = fopen("clients.dat","r");

    char cli[100];

    fgets(cli, 100, (FILE*)clientData);
    int len = atoi(cli),i,j,a,b,c;

    char **map;
    map=(char **)malloc(len);
    for(a=0; a<len; a++) {
        map[a]=(char *)malloc(30);
    }
    for(i=0; i<len; i++) {
        for(j=0; j<3; j++) {
            fscanf(clientData,"%s",&map[i][j]);
        }
    }
    fclose(clientData);

    printf("%s",map[0]);
    /*
    for(b=0; b<len; b++) {
        for(c=0; c<3; c++) {
            printf("%s",map[b][c]);
        }
    }*/
    return 0;

}
