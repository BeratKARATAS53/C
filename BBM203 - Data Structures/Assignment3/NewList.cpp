#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node{
    string word;
    int c;
    struct Node *next;
};

struct LinkedList{
    struct Node *head;
    struct Node *tail;
};

struct LinkedList* createLinkedList (struct Node *firstNode){
    struct LinkedList *newLinkedList;
    newLinkedList->head = firstNode;
    newLinkedList->tail = firstNode;
    return newLinkedList;
}
struct LinkedList *newLinkedList = createLinkedList(newNode);
