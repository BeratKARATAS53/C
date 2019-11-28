#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char *name,*pass;
    struct Node *child[26];
};
struct Node *newNode(char *name)
{
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->name = malloc(strlen(name)+1);
    strcpy(new_node->name,name);
    return new_node;
}

int main()
{
    FILE *input = fopen("input.txt","r");

    char ch; int lines=0;
    int command_A=0, command_S=0, command_Q=0, command_D=0;
    while(!feof(input)) {
        ch=fgetc(input);
        if(ch=='\n') { lines++; }
        if(ch=='-') {
            ch=fgetc(input);
            if(ch=='a') {command_A++;} /** number of -a commands */
            if(ch=='s') {command_S++;} /** number of -s commands */
            if(ch=='q') {command_Q++;} /** number of -q commands */
            if(ch=='d') {command_D++;} /** number of -d commands */
        }
    }

    rewind(input); int x,a=0;
    char operand1[3]="-a",operand2[3]="-s",operand3[3]="-q",operand4[3]="-d",operand5[3]="-l";
    char *names[command_A];
    struct Node *root=newNode("root");
    for(x=0; x<=lines; x++) {
        char word[3];
        fscanf(input,"%s",word);
        if(strcmp(word,operand1)==0) { /** -a command */
            char nameOp1[20], passwordOp1[20];
            fscanf(input,"%s",nameOp1); fscanf(input,"%s",passwordOp1);
            printf("\"%s\" was added.\n",nameOp1);
            root->child[a]=newNode(nameOp1); root->child[a]->child[0]=newNode(passwordOp1);
        }
        else if(strcmp(word,operand2)==0) { /** -s command */
            char nameOp2[20];
            fscanf(input,"%s",nameOp2);
            printf("password %s\n",nameOp2);
        }
        else if(strcmp(word,operand3)==0) { /** -q command */
            char nameOp3[20], passwordOp3[20];
            fscanf(input,"%s",nameOp3); fscanf(input,"%s",passwordOp3);
            printf("%s successful login\n",nameOp3);
        }
        else if(strcmp(word,operand4)==0) { /** -d command */
            char nameOp4[20];
            fscanf(input,"%s",nameOp4);
            printf("%s deletion is successful\n",nameOp4);
        }
        else { /** -l command */
            printf("%s\n",operand5);
        }
    }
}
