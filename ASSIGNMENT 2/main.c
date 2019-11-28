#include <stdio.h>
#include <stdlib.h>

void funcA(FILE *file, char a)
{
    fprintf(file, "%c ", a);
}

void funcI(FILE *file, char a)
{
    fprintf(file, "%c ", a);
}

void funcS(FILE *file, char a)
{
    fprintf(file, "%c ", a);
}

void funcO(FILE *file, char a)
{
    fprintf(file, "%c ", a);
}

int main()
{
    int numberOfRow=-1,i,j;
    int character1, character2;
    FILE *input1a = fopen("I1.txt","r");
    while ((character1 = getc(input1a)) != EOF)
    {
        if (character1==10)
            numberOfRow++;
    }
    //printf("%d",numberOfRow);
    fclose(input1a);

    int sizeList[numberOfRow][2];

    //FILE *input1b = fopen("I1.txt","r");
    /*if((input1b = fopen("I1.txt","r"))!=NULL)  //The second opening
    {                                                   //The next steps are write the data to matrix from the file.
        for (i=0; i<numberOfRow; i++)
        {
            for(j=0; j<3; j++)
            {
                character2=fgetc(input1b);
                if(character2==10)
                    j++;
                else
                {
                    if(character2!=32)
                    {
                        if(character2!=10)
                            sizeList[i][j]=character2;
                        else
                            j++;
                    }
                }
            }
        }
    }*/
    FILE *input1b = fopen("I1.txt","r");

    char word[10];
    fseek(input1b,3,0);
    while( fscanf(input1b, "%s", word) != EOF )
    {
        printf("%s ", &word);
    }
    fclose(input1b);
    FILE *output = fopen("output.txt","w");
    FILE *input2 = fopen("I2.txt","r");
    printf("\n");
    char word2[10];
    fseek(input2,3,0);
    while( fscanf(input2, "%s", word2) != EOF )
    {
        printf("%s ", &word2);
        if (&word2=="A")
        {
            fputc(&word2,output);
            printf("%s ", &word2);
            //funcA(output,word2);
        }
    }
    fclose(output);
    fclose(input1b);
}
