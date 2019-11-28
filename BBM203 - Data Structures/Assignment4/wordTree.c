#include<stdio.h>
#include<stdlib.h>

struct node
{
    char *key;
    int password;
    //struct node *nodeList[26];
    struct node *right; struct node *left;
    struct node *a,*b,*c,*d,*e,*f,*g,*h,*i,*j,*k,*l,*m;
    struct node *n,*o,*p,*q,*r,*s,*t,*u,*v,*w,*x,*y,*z;
};

// A utility function to create a new BST node
struct node *newNode(char *word)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    int i;
    temp->key = word;
    //temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%s \n", root->key);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, char *key)
{
    if (strcmp(key,node->key)<0)
        node->left  = insert(node->left, key);
    else if (strcmp(key,node->key)>0)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
              p
           /    \       pin, pim, pan, pat
          i      a
        /  \    /  \
       n    m  n    t */
    struct node *root = NULL;
    root = insert(root, "root");
    insert(root, "pelin");
    insert(root, "selin");
    insert(root, "selim");
    insert(root, "ali");

    // print inoder traversal of the BST
    inorder(root);

    return 0;
}
