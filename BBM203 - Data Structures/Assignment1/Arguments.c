#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* recursive; the main function on the map where we will find out where to proceed.
* map; map matrix, key; key matrix, mod; The mode value to be found for the product.
* mapRow, mapColumn; map matrix's row and column,
* key_size; key matrix's size,
* output_file; the result of which we will print the file.
*/
int recursive(int **map, int **key, int mod, int point_i, int point_j, int mapRow, int mapColumn, int key_size, FILE *output_file);

int main(int argc,char* argv[])
{
    // argv[0]; first argument, file name
    int mapRow = atoi(strtok(argv[1],"x")); // argv[1] Because it is the size of the map matrix, we had to smash it. The first part is row..
    int mapColumn = atoi(strtok(NULL,"x")); // ..and the second part is column.

    int key_size = atoi(argv[2]); // argv[2] Because it is the size of the key matrix, it is enough to take it directly.

    FILE *map_file=fopen(argv[3],"r"); // Map File will open for read.
    FILE *key_file=fopen(argv[4],"r"); // Key File will open for read.
    FILE *output_file=fopen(argv[5],"w"); // Output File will create for write.

    // a, map_i, map_j; values for creating map matrix with malloc.
    int a, map_i, map_j;
    int **map;
    map=(int **)malloc(mapRow*sizeof(int*));
    for(a=0; a<mapRow; a++){
        map[a]=(int *)malloc(mapColumn*sizeof(int));}

    // b, key_i, key_j; values for creating map matrix with malloc.
    int b, key_i, key_j;
    int **key;
    key=(int **)malloc(key_size*sizeof(int*));
    for(b=0; b<key_size; b++){
        key[b]=(int *)malloc(key_size*sizeof(int));}

    int map_row=0, map_column=0;
    // Transfer data from file to map matrix
    for(map_i=0; map_i<mapRow; map_i++) {
        for(map_j=0; map_j<mapColumn; map_j++) {
            fscanf(map_file,"%d",&map[map_i][map_j]);
            map_column++;
        }
        map_row++;
    }
    map_column=map_column/map_row;
    fclose(map_file); // Need to close!

    int keySize=0;
    // Transfer data from file to key matrix
    for(key_i=0; key_i<key_size; key_i++) {
        for(key_j=0; key_j<key_size; key_j++) {
            fscanf(key_file,"%d",&key[key_i][key_j]);
        }
        keySize++;
    }
    fclose(key_file); // Need to close!

    if((keySize != key_size) || ((map_row != mapRow) && (map_column != mapColumn)))
        return 0;
    /**
    * The mode was initially set to -1 so that it did not specify any direction when it entered the function.
    * point_i and point_j, coordinate of the first element of the received sub matrix.
    */
    int mod=-1, point_i=0, point_j=0;
    recursive(map,key,mod,point_i,point_j,mapRow,mapColumn,key_size,output_file);
    free(map); // It is imperative to release memory when done!
    free(key); // It is imperative to release memory when done!
    return 0;
}

int recursive(int **map, int **key, int mod, int point_i, int point_j, int mapRow, int mapColumn, int key_size, FILE *output_file) {
    int c,d,e,f,g; // Required values for cycles.

    // A space allocation step in a sub-matrix that plays a role in each product.
    int **subArray;
    subArray=(int **)malloc(key_size*sizeof(int*));
    for(c=0; c<key_size; c++) {
        subArray[c]=(int *)malloc(key_size*sizeof(int));}

    // Assign the values from the map matrix to the sub matrix in which memory is allocated.
    int second = point_i;
    for(d=0; d<key_size; d++) {
        int first = point_j;
        for(e=0; e<key_size; e++) {
            subArray[d][e]=map[point_i][point_j];
            point_j++;
        }
        point_j=first;
        point_i++;
    }
    point_i=second;

    int sum=0; // With the fork below, we multiply the matrix with the sub matrix and add the result to sum.
    for(f=0; f<key_size; f++) {
        for(g=0; g<key_size; g++) {
            int mult=(subArray[f][g]*key[f][g]);
            sum=(sum+mult);
        }
    }
    mod=(sum%5); // Calculation of the mode value that determines the direction.
    if(mod<0) {mod = mod+5;}
    fprintf(output_file,"%d,%d:%d\n",(point_i+(key_size/2)),(point_j+(key_size/2)),sum); // Write center cell address of sub-matrix and sum.

    if(mod==0) { // If the mode is set to "0", the treasure has been found. The function is exited and the process is finished.
        free(subArray);
        return 0;
    }
    else if(mod==1) { // If the mode "1" appears, you need to "move up".
        if((point_i-key_size)<0) // "Move down" if you cannot go up.
            return recursive(map,key,mod,(point_i+key_size),point_j,mapRow,mapColumn,key_size,output_file);
        else
            return recursive(map,key,mod,(point_i-key_size),point_j,mapRow,mapColumn,key_size,output_file);
    }
    else if(mod==2) { // If the mode "2" appears, you need to "move down".
        if((point_i+key_size)>=mapRow) // "Move up" if you cannot go down.
            return recursive(map,key,mod,(point_i-key_size),point_j,mapRow,mapColumn,key_size,output_file);
        else
            return recursive(map,key,mod,(point_i+key_size),point_j,mapRow,mapColumn,key_size,output_file);
    }
    else if(mod==3) { // If the mode "3" appears, you need to "move right".
        if((point_j+key_size)>=mapColumn) // "Move left" if you cannot go right.
            return recursive(map,key,mod,point_i,(point_j-key_size),mapRow,mapColumn,key_size,output_file);
        else
            return recursive(map,key,mod,point_i,(point_j+key_size),mapRow,mapColumn,key_size,output_file);
    }
    else if(mod==4) { // If the mode "4" appears, you need to "move left".
        if((point_j-key_size)<0) // "Move right" if you cannot go left.
            return recursive(map,key,mod,point_i,(point_j+key_size),mapRow,mapColumn,key_size,output_file);
        else
            return recursive(map,key,mod,point_i,(point_j-key_size),mapRow,mapColumn,key_size,output_file);
    }
}


