#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

/**
* First Linked List store "footballer name" and "home team" value.
*/
struct node {
	string footballerName;
	vector<string> footList;
	node *next;
	node *down;
};
struct inNode {
    string matchID;
    inNode *next;
};
class linkList {
    private:
    node *headMain, *headMini, *tail;
    public:
    linkList() {
        headMain=NULL;
        tail=NULL;
    }
    void createnode(string name, string match) {
        node *temp=new node;
		temp->footList.push_back(name);
		temp->footballerName=name;
		inNode *temp2=new inNode;
		temp->next=NULL;
		if(headMain==NULL) {
            headMain=temp;
			tail=temp;
			temp=NULL;
        }
		else {
			tail->next=temp;
			tail=temp;
		}
    }

    void insertNode(string name) {
        if((find(temp->footList.begin(), temp->footList.end(), name) != temp->footList.end())) {
            cout<<1<<endl;
        }
        else {

        }
    }
    string nodeData() {
        return tail->footballerName;
    }
    void goalArray() { //1. Output; THE MOST SCORED HALF
        node *mostScored=new node;
        mostScored=headMain;

    }

    void goalScorer() { //2. Output; GOAL SCORER
        node *mostGoal=new node;
        mostGoal=headMain;

    }

    void hatTrick() { //3.Output; THE NAMES OF FOOTBALLERS WHO SCORED HAT-TRICK

    }

    void teamList(int lineSize) { //4.Output; LIST OF TEAMS


    }

    void footballerList() { //5.Output; LIST OF FOOTBALLERS

    }

    void matchGiveFootballer() { //6.Output; MATCHES OF GIVEN FOOTBALLER

    }

    void idAscendingOrder() { //7.Output; ASCENDING ORDER ACCORDING TO MATCH ID

    }

    void idDescendingOrder() { //8.Output; DESCENDING ORDER ACCORDING TO MATCH ID

    }

    void deleteNode() {
        node *current=new node;
		node *previous=new node;
		current=headMain;
		while(current->next!=NULL) {
			previous=current;
			current=current->next;
		}
		tail=previous;
		previous->next=NULL;
		delete current;
    }
    void display()
    {
        node *temp=new node;
        temp=headMain;
        while(temp!=NULL)
        {
            cout<<temp->footballerName<<"\t";
            temp=temp->next;
        }
    }
};

int main()
{
    linkList lst;
    lst.createnode("Burak","1");
    lst.display(); cout<<endl;
    lst.createnode("Burak","2");
    lst.display(); cout<<endl;
    lst.createnode("Burak","3");
    lst.display(); cout<<endl;
    lst.createnode("Burak","4");
    lst.display(); cout<<endl;
    lst.createnode("Veli","1");
    lst.display();
}
