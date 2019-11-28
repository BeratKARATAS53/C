#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct LLNode1 {
    int number1, number2;
    LLNode1* down;
    LLNode1* next1;
    LLNode1* next2;
};

class linkedList {
    private:
    LLNode1 *head, *tail;
    public:
    linkedList() {
        head=NULL;
        tail=NULL;
    }
    void createnode(int numb1, int numb2) { /** Added Node to Linked List*/
        LLNode1 *temp=new LLNode1;
		temp->number1=numb1;
		temp->down->number2=numb2;
		temp->next1=NULL;
		temp->next2=NULL;
		if(head==NULL) { /** For first node.*/
            head=temp;
			tail=temp;
			temp=NULL;
        }
		else {
			tail->next1=temp;
			tail=temp;
		}
    }

    void display() {
        LLNode1 *temp=new LLNode1;
        temp=head;
        while(temp!=NULL) {
            cout<<temp->number1<<"\t";
            temp=temp->next1;
        }
    }
};

int main() {
    linkedList lst1;
    lst1.createnode(14,2);
    lst1.createnode(14,2);
    lst1.display();
    return 0;
}
