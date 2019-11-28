#include <stdio.h>
#include <stdlib.h>

int N=0;    //N: Size of the square matrix.
int startX=0,startY=0,endX=0,endY=0; //These variables hold the start and end points.

int main()
{
    char character1,character2;            //Characters also used for reading files.
    int count=0,a;             //count: The variable that holds the total number of characters in the file.

    FILE *maze_file1 = fopen("maze1.txt","r");   //First opening
    while ((character1 = getc(maze_file1)) != EOF)
        count++;

    fclose(maze_file1); //Don't forget to close the file.

    double d_count=1;        // The value that holds the dimension of the matrix we will construct.
    for(a=0; a<count; a++)           //The algorithm I use instead of the "sqrt" function. In other words, SquareRoot.
        d_count=((count/d_count)+d_count)/2;

    N+=(int)d_count;

    int maze_matris[(int)d_count][(int)d_count];
    int i,j;
    FILE *maze_file2;

    if((maze_file2 = fopen("maze1.txt","r"))!=NULL)  //The second opening
    {                                                   //The next steps are write the data to matrix from the file.
        for (i=0; i<(int)d_count; i++)
        {
            for(j=0; j<(int)d_count; j++)
            {
                character2=fgetc(maze_file2);
                if (character2==49)
                    maze_matris[i][j]=1;
                else
                {
                    if(character2==83)   //Determining the start point.
                    {
                        startX+=i;
                        startY+=j;
                    }
                    if(character2==69)   //Determining the end point.
                    {
                        endX+=i;
                        endY+=j;
                    }
                    if(character2==10){j-=1;} //Skip line when end of line.
                    else
                        maze_matris[i][j]=0;
                }
            }
        }
    }

    fclose(maze_file2); //Don't forget to close the file.
    find_path(maze_matris, startX, startY);

    return 0;
}

int find_path(int matris[N][N], int x, int y) //Path finding function
{
    FILE *output_file;
    output_file = fopen("path.txt","w");
    fputs("Start ",output_file);

    matris[x][y]==2;
    if(x==endX && y==endY){}
    else
    {
        /*
        if(matris[x][y+1]==0)   //Control of rigth move.
        {
            fputs("E ",output_file);
            find_path(matris,x,y+1);
        }*/
        if(matris[x][y-1]==0)   //Control of left move.
        {
            fputs("W ",output_file);
            find_path(matris,x,y-1);
        }
        if(matris[x+1][y]==0)   //Control of down move.
        {
            fputs("S ",output_file);
            find_path(matris,x+1,y);
        }/*
        if(matris[x-1][y]==0)   //Control of up move.
        {
            fputs("N ",output_file);
            find_path(matris,x,y-1);
        }*/
    }
    fputs("Exit", output_file);
    fclose(output_file);        //Don't forget to close the file.

    return 0;
}




