#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char *name,*pass;
    struct Node *child[26];
    struct Node *p;
};
struct Node *newNode(char *name) {
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->name = malloc(strlen(name)+1);
    strcpy(new_node->name,name);
    return new_node;
}

struct Node* search(struct Node* root, char *name, int startPosition) {
    // Base Cases: root is null or key is present at root
    if (root == NULL || strcmp(root->name,name)==0) { return root; }
    else {return search(root->child[startPosition], name, startPosition+1); }
}

int main()
{
    struct Node *root=newNode("root");
    root->child[0]=newNode("ali");
    root->child[1]=newNode("veli");
    root->child[2]=newNode("kýrkdokuz");
    root->child[3]=newNode("elli");
    printf("%s",root->child[0]->name);
    search(root,"veli",0);

    return 0;
}
