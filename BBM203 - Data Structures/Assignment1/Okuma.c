#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *map_file=fopen("Map.txt","r");
    char map_char;
    int map_number;
    int map_i,map_j;
    int map[18][18];

    FILE *key_file=fopen("Key.txt","r");
    char key_char;
    int key_number;
    int key_i,key_j;
    int key[3][3];

    for(map_i=0; map_i<18; map_i++) {
        for(map_j=0; map_j<18; map_j++) {
            fscanf(map_file,"%d",&map[map_i][map_j]);
        }
    }
    fclose(map_file);

    for(key_i=0; key_i<9; key_i++) {
        for(key_j=0; key_j<9; key_j++) {
            fscanf(key_file,"%d",&key[key_i][key_j]);
        }
    }
    fclose(key_file);

    printf("%d %d",map[1][1],key[1][1]);
    return 0;

}




