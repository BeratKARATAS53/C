#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Stack
{
    int top;
    unsigned capacity;
    char *array;
};
// Function to create a stack of given capacity. It initializes size of stack as 0
struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity);
    return stack;
}
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, char *item)
{
    stack->array[++stack->top] = *item;
}
// Function to remove an item from stack.  It decreases top by 1
char pop(struct Stack* stack)
{
    return stack->array[stack->top--];
}
// A structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    char *array;
};
// Function to create a queue of given capacity. It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important, see the enqueue
    queue->array = (char*)malloc(queue->capacity);
    return queue;
}
// Function to add an item to the queue. It changes rear and size
void enqueue(struct Queue* queue, char item)
{
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
// Function to remove an item from queue. It changes front and size
char dequeue(struct Queue* queue)
{
    char item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
}
// Function to get front of queue
int front(struct Queue* queue)
{
    return queue->array[queue->front];
}
// Function to get rear of queue
int rear(struct Queue* queue)
{
    return queue->array[queue->rear];
}
/**
* Find A Client Address
*/
char *clientAdress(char ch[2])
{
    FILE *clientData = fopen("clients.dat","r");
    int c_i, c_len;
    char c[1];
    fscanf(clientData,"%c",c);
    c_len = atoi(c);
    char *address = (char *)malloc(10);

    for(c_i=0; c_i<(c_len)*3; c_i++) {
        char str[20];
        fscanf(clientData,"%s",str);
        if(strcmp(str,ch) == 0) {
            char str2[20];
            fscanf(clientData,"%s",str2);
            strcpy(address,str2);
            break;
        }
    }
    fclose(clientData);
    return address;
    free(address);
}
/**
* Find A Client Mac Address
*/
char *clientMacAdress(char ch[2])
{
    FILE *clientData = fopen("clients.dat","r");
    int c_i, c_len;
    char c[1];
    fscanf(clientData,"%c",c);
    c_len = atoi(c);
    char *macAddress = (char *)malloc(10);

    for(c_i=0; c_i<(c_len)*3; c_i++) {
        char str[20];
        fscanf(clientData,"%s",str);
        if(strcmp(str,ch) == 0) {
            char str2[20], str3[20];
            fscanf(clientData,"%s",str2);
            fscanf(clientData,"%s",str3);
            strcpy(macAddress,str3);
            break;
        }
    }
    fclose(clientData);
    return macAddress;
    free(macAddress);
}
/**
* This function finds out which way we should send the message.
*/
/*void *findPath(char firstClient[2], char secondClient[2]){
    FILE *routeData = fopen("routing.dat","r");
    char rou;
    int i = 0;
    while((rou = fgetc(routeData)) != EOF)
        i++;
    rewind(routeData);
    i=i/2;

    int j = 0;
    while(i>0) {
        char str[2];
        fscanf(routeData,"%s",str);
        if(strcmp(str,"-\0")==0)
            break;
        i--;
        j++;
    }
    rewind(routeData);

    char character[2] = "-\0";
    int c1Index = clientIndex(firstClient);
    int a, b, c=0;
    for(a=0; a<=i; a++) {
        if(c1Index==c) {
            for(b=0; b<j/2; b++) {
                char cli1[2], cli2[2];
                fscanf(routeData,"%s",cli1);
                fscanf(routeData,"%s",cli2);
                if(strcmp(cli1,secondClient)==0){
                    strcpy(firstClient,cli2);
                }
            }
            break;
        }
        char ch1[2];
        fscanf(routeData,"%s",ch1);
        if(strcmp(ch1,character)==0){
            c++;
        }
    }
}*/
int main(int argc, char *argv[])
{
    FILE *commandsData = fopen("commands.dat","r");
    FILE *outputText = fopen("output.txt","w");

    int com_i,com_len;
    char com[1];
    fscanf(commandsData,"%c",com);
    com_len = atoi(com);

    int hop = 20;
    char msg[500];
    char First_Client[2], Second_Client[2];
    for(com_i=0; com_i<com_len; com_i++) {
        char str[20];
        struct Stack* stack = createStack(1000); // Create Stack.
        struct Queue* queue = createQueue(1000); // Create Queue.
        fscanf(commandsData,"%s",str);
        if(strcmp(str,"MESSAGE")==0) { // MESSAGE COMMAND
            char *sendPort = "1", *recPort = "2"; // Send Port, Receive Port
            int clientInt1;
            char* address1 = (char *)malloc(10); char* macAddress1 = (char *)malloc(10); // Info of First Client
            int clientInt2;
            char* address2 = (char *)malloc(10); char* macAddress2 = (char *)malloc(10); // Info of Second Client

            char str2[2], str2_2[2];
            fscanf(commandsData,"%s",str2);
            strcpy(str2_2,str2);
            strcpy(First_Client,str2);

            FILE *clientData = fopen("clients.dat","r");
            int c_i, c_len;
            char c[1];
            fscanf(clientData,"%c",c);
            c_len = atoi(c);

            for(c_i=0; c_i<(c_len)*3; c_i++) {
                char str10[20];
                fscanf(clientData,"%s",str10);
                if(strcmp(str10,str2) == 0) {
                    clientInt1 = c_i/3;
                    break;
                }
            }
            rewind(clientData);

            char c2[1];
            fscanf(clientData,"%c",c2);
            for(c_i=0; c_i<(c_len)*3; c_i++) {
                char str12[20];
                fscanf(clientData,"%s",str);
                if(strcmp(str12,str2) == 0) {
                    char str22[20];
                    fscanf(clientData,"%s",str2);
                    strcpy(address1,str22);
                    break;
                }
            }
            rewind(clientData);

            macAddress1 = clientMacAdress(str2);

            char str3[2], str3_2[2];
            fscanf(commandsData,"%s",str3);
            strcpy(str3_2,str3);
            strcpy(Second_Client,str3);
            //findPath(str2_2,str3_2);
            //Information is written to the values with the help of functions.
            macAddress2 = clientMacAdress(str2_2);

            char c3[1];
            fscanf(clientData,"%c",c3);
            for(c_i=0; c_i<(c_len)*3; c_i++) {
                char str11[20];
                fscanf(clientData,"%s",str11);
                if(strcmp(str11,str3) == 0) {
                    clientInt2 = c_i/3;
                    break;
                }
            }
            rewind(clientData);

            char c4[1];
            fscanf(clientData,"%c",c4);
            for(c_i=0; c_i<(c_len)*3; c_i++) {
                char str12[20];
                fscanf(clientData,"%s",str);
                if(strcmp(str12,str2) == 0) {
                    char str22[20];
                    fscanf(clientData,"%s",str2);
                    strcpy(address2,str22);
                    break;
                }
            }

            int hopLen = 20;
            char *messageFrame = malloc(500);
            fgets(messageFrame,500,commandsData); // Read a message from file.
            strcpy(msg,messageFrame);

            fprintf(outputText,"---------------------------------------------------------------------------------------");
            fprintf(outputText,"\nCommand: MESSAGE %s %s%s",str2,str3,messageFrame);
            fprintf(outputText,"---------------------------------------------------------------------------------------");
            fprintf(outputText,"\nMessage to be sent: ");
            int len = strlen(messageFrame);
            char word[len];
            strcpy(word,messageFrame);
            int i=2;
            while(i<len-2){
                fprintf(outputText,"%c",word[i]);
                i++;
            }
            fprintf(outputText,"\n");
            int numberHop = (len/hop)+1;
            int a, b;
            for(a=0; a<numberHop; a++){
                int len2 = a*hop;
                push(stack,macAddress1); push(stack,macAddress2);
                fprintf(outputText,"\nFrame #%d\nSender MAC address: %s, Receiver MAC address: %s\n",a+1,macAddress1,macAddress2);
                push(stack,address1); push(stack,address2);
                fprintf(outputText,"Sender IP address: %s, Receiver IP address: %s\n",address1,address2);
                push(stack,sendPort); push(stack,recPort);
                fprintf(outputText,"Sender port number: %s, Receiver port number: %s\n",sendPort,recPort);
                push(stack,str2); push(stack,str3);
                fprintf(outputText,"Sender ID: %s, Receiver ID: %s\n",str2,str3);
                fprintf(outputText,"Message chunk carried: ");
                for(b=len2; b<(len2+hop); b++) {
                    if(b>=len-4)
                        break;
                    fprintf(outputText,"%c",word[b+2]);
                }
                fprintf(outputText,"\n--------");
            }
            fprintf(outputText,"\n--------");
            free(address1); free(address2); free(macAddress1); free(macAddress2);

        }
        else if (strcmp(str,"SHOW_FRAME_INFO")==0) {
            char *clientName = malloc(1);
            fscanf(commandsData,"%s",clientName);
            char str2[5]; fscanf(commandsData,"%s",str2);
            char str3[5]; fscanf(commandsData,"%s",str3);
            fprintf(outputText,"---------------------------------\n");
            fprintf(outputText,"Command: SHOW_FRAME_INFO %s %s %s\n",clientName,str2,str3);
            fprintf(outputText,"---------------------------------\n");
        }
        else if (strcmp(str,"SHOW_Q_INFO")==0) {
            char *clientName = malloc(1);
            fscanf(commandsData,"%s",clientName);
            char str2[5]; fscanf(commandsData,"%s",str2);
            int msgLen = strlen(msg);
            int numberOfFrame = (msgLen/hop)+1;
            fprintf(outputText,"---------------------------------\n");
            fprintf(outputText,"Command: SHOW_Q_INFO %s %s\n",clientName,str2);
            fprintf(outputText,"---------------------------------\n");
            if(strcmp(str2,"out")==0)
                fprintf(outputText,"Client %s Outgoing Queue Status\nCurrent total number of frames: %d\n",clientName,numberOfFrame);
            else if(strcmp(str2,"in")==0)
                fprintf(outputText,"Client %s Incoming Queue Status\nCurrent total number of frames: %d\n",clientName,numberOfFrame);
        }
        else if (strcmp(str,"SEND")==0) { // SEND COMMAND
            char clientId[2];
            fscanf(commandsData,"%s",clientId);
            int msgLen = strlen(msg);
            int numberHops = (msgLen/hop)+1;
            fprintf(outputText,"---------------------------------\n");
            fprintf(outputText,"Command: SEND %s\n",clientId);
            fprintf(outputText,"---------------------------------\n");
            int g=0, f;
            char c1[2];
            strcpy(c1,First_Client);
            while(g<3) {
                //findPath(First_Client,Second_Client);
                if(strcmp(First_Client,Second_Client)==0) {
                    fprintf(outputText,"A message received by client %s from client %s after a total of %d hops.\n",Second_Client,c1,(numberHops-1));
                    fprintf(outputText,"Message: ");
                    int len = strlen(msg);
                    char word[len];
                    strcpy(word,msg);
                    int i=2;
                    while(i<len-2){
                        fprintf(outputText,"%c",word[i]);
                        i++;
                    }
                    fprintf(outputText,"\n");
                    break;
                }
                fprintf(outputText,"A message received by client %s, but intended for client %s. Forwarding...\n",First_Client,Second_Client);
                enqueue(queue,pop(stack)); enqueue(queue,pop(stack));
                for(f=1; f<numberHops+1; f++)
                    fprintf(outputText,"Frame #%d MAC address change: New sender MAC %s, new receiver MAC %s\n",f,clientMacAdress(First_Client),clientMacAdress(Second_Client));
                    enqueue(queue,pop(stack)); enqueue(queue,pop(stack));
                g++;
            }
        }
        else if(strcmp(str,"PRINT_LOG")==0) { //PRINT_LOG COMMAND
            char clientId[2];
            fscanf(commandsData,"%s",clientId);
            fprintf(outputText,"---------------------------------\n");
            fprintf(outputText,"Command: PRINT_LOG %s\n",clientId);
            fprintf(outputText,"---------------------------------\n");
        }
        else { // OTHER COMMANDS
            char *invalidCommand = malloc(500);
            fgets(invalidCommand,500,commandsData);
            fprintf(outputText,"---------------------------------\n");
            fprintf(outputText,"Command: %s%s",str,invalidCommand);
            fprintf(outputText,"---------------------------------\n");
            fprintf(outputText,"Invalid command.\n");
        }
    }

    fclose(commandsData);
    return 0;
}
