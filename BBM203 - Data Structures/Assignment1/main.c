#include <stdio.h>
#include <stdlib.h>

int recursive(int **map, int **key, int mod, int point_i, int point_j, FILE *output_file);

int treasure()
{
    FILE *map_file=fopen("Map3.txt","r");
    FILE *key_file=fopen("Key3.txt","r");
    FILE *output_file=fopen("Output.txt","w");

    int a, b, x, y, map_i, map_j, key_i, key_j;

    int **map;
    map=(int **)malloc(18*sizeof(int*));
    for(a=0; a<18; a++) {
        map[a]=(int *)malloc(18*sizeof(int));
    }

    int **key;
    key=(int **)malloc(3*sizeof(int*));
    for(b=0; b<3; b++) {
        key[b]=(int *)malloc(3*sizeof(int));
    }

    for(map_i=0; map_i<18; map_i++) {
        for(map_j=0; map_j<18; map_j++) {
            fscanf(map_file,"%d",&map[map_i][map_j]);
        }
    }
    fclose(map_file);

    for(key_i=0; key_i<3; key_i++) {
        for(key_j=0; key_j<3; key_j++) {
            fscanf(key_file,"%d",&key[key_i][key_j]);
        }
    }
    fclose(key_file);

    int mod=-1, point_i=0, point_j=0;
    int result = recursive(map, key, mod, point_i, point_j,output_file);
    if(result==0) {
        printf("TREASURE FOUND!");
    }

    free(map);
    free(key);
    return 0;
}

int recursive(int **map, int **key, int mod, int point_i, int point_j, FILE *output_file) {
    int c,d,e,f,g,h;
    int subArray[3][3];
    // Assign the values from the map matrix to the sub matrix in which memory is allocated.
    int second = point_i;
    for(d=0; d<3; d++) {
        int first = point_j;
        for(e=0; e<3; e++) {
            subArray[d][e]=map[point_i][point_j];
            point_j++;
        }
        point_j=first;
        point_i++;
    }
    point_i=second;

    int sum=0;
    for(f=0; f<3; f++) {
        for(g=0; g<3; g++) {
            int mult = subArray[f][g]*key[f][g];
            sum = sum + mult;
        }
    }
    mod = sum%5;
    if(mod<0) {
        mod = mod + 5;}
    printf("%d\n",sum);
    fprintf(output_file,"%d,%d:%d\n",(point_i+1),(point_j+1),sum);
    if(mod==0) {
        free(subArray);
        return 0;
    }
    else if(mod==1) {//Up
        if((point_i-3)<0) {
            return recursive(map,key,mod,(point_i+3),point_j,output_file);}
        else {
            return recursive(map,key,mod,(point_i-3),point_j,output_file);}
    }
    else if(mod==2) {//Down
        if((point_i+3)>=18) {
            return recursive(map,key,mod,(point_i-3),point_j,output_file);}
        else {
            return recursive(map,key,mod,(point_i+3),point_j,output_file);}
    }
    else if(mod==3) {//Right
        if((point_j+3)>=18) {
            return recursive(map,key,mod,point_i,(point_j-3),output_file);}
        else {
            return recursive(map,key,mod,point_i,(point_j+3),output_file);}
    }
    else if(mod==4) {//Left
        if((point_j-3)<0) {
            return recursive(map,key,mod,point_i,(point_j+3),output_file);}
        else {
            return recursive(map,key,mod,point_i,(point_j-3),output_file);}
    }
}


