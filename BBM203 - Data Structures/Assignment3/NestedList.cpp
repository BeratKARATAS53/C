#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

/**
* First Linked List store "footballer name" and "home team" value.
*/
struct node {
	string footballerName, homeTeam;
	node *next;
};
struct nodeLis {
    string awayTeam, goalMin, matchId;
    nodeLis *next;
};
class list {
    private:
    node *head, *tail;
    public:
    list() {
        head=NULL;
        tail=NULL;
    }
    void createnode(string name, string team) {
        node *temp=new node;
		temp->footballerName=name;
		temp->homeTeam=team;
		temp->next=NULL;
		if(head==NULL) {
            head=temp;
			tail=temp;
			temp=NULL;
        }
		else {
			tail->next=temp;
			tail=temp;
		}
    }
    void listNodeAdd(string footballer_name, string away_Team, string goal_Min, string match_Id, list *lst) {
        node *real_head = lst->head;
        while(lst->head->next!=NULL) {
            if((lst->head->footballerName).compare(footballer_name)==0) {
                node *lst_in = lst->head->footballerName;
                node *real_head_in = lst_in->head;
                while(lst_in->head!=NULL) {
                    nodeLis *newNode = createnode(away_Team);
                    newNode->awayTeam=away_Team;
                    newNode->goalMin=goal_Min;
                    newNode->matchId=match_Id;
                    newNode->next=NULL;
                    if(lst_in->head==NULL) {
                        lst_in->head=newNode;
                        lst_in->tail=newNode;
                        newNode=NULL;
                    }
                    else {
                        lst_in->tail->next=newNode;
                        lst_in->tail=newNode;
                    }
                }
            }
        }

    }
    string nodeData() {
        return tail->footballerName;
    }
    void deleteNode() {
        node *current=new node;
		node *previous=new node;
		current=head;
		while(current->next!=NULL) {
			previous=current;
			current=current->next;
		}
		tail=previous;
		previous->next=NULL;
		delete current;
    }
    void display() {
        node *temp=new node;
        temp=head;
        while(temp!=NULL) {
            cout<<temp->footballerName<<"--"<<temp->homeTeam;
            temp=temp->next;
            cout<<endl;
        }
    }
};


/**
* The sort function is used to sort the data in the file before adding it to the linked list.
* MyArray: is an 2d dimensional array, which store the data.
* len: is size of MyArray.
*/
void sort(string MyArray[][5], int len) {
    for(int i=0;i<len;i++) {
        for(int j=i+1;j<len;j++) {
            if(MyArray[i][0]>MyArray[j][0]) { // If footballer name is greater than the next footballer name, then swap it.
                swap(MyArray[i],MyArray[j]);
            }
        }
    }
}

int main()
{
    ifstream inputFile("input1.txt");

    string name,homeTeam,awayTeam;
    string line;
    string myString;
    int goalMinute=0,matchID=0;

    int lineCount = 0;
    while(getline(inputFile,line)) {
        lineCount++; }

    inputFile.clear();
    inputFile.seekg(0);

    string footballerInfo[lineCount][5];

    int i=0;
    while(getline(inputFile,line)) {
        stringstream ss(line);
        getline(ss,name,','); footballerInfo[i][0] = name;
        getline(ss,homeTeam,','); footballerInfo[i][1] = homeTeam;
        getline(ss,awayTeam,','); footballerInfo[i][2] = awayTeam;
        getline(ss,myString,','); footballerInfo[i][3] = myString;
        stringstream goalMin(myString);
        goalMin>>goalMinute;

        getline(ss,myString,','); footballerInfo[i][4] = myString;
        stringstream match(myString);
        match>>matchID;
        i++;
    }

    inputFile.close();

    int arrayLength = lineCount;
    int a,b;
    sort(footballerInfo,arrayLength);
    /*for (a=0; a<lineCount; a++) {
        for (b=0; b<5; b++) {
            cout<<footballerInfo[a][b]<<" ";
        }
        cout<<endl;
    }*/

    list firstLinkedList;
    firstLinkedList.createnode(footballerInfo[0][0],footballerInfo[0][1]);
    for (a=1; a<arrayLength; a++) {
        string value = firstLinkedList.nodeData();
        if(value == footballerInfo[a][0]) {}
        else {
            firstLinkedList.createnode(footballerInfo[a][0],footballerInfo[a][1]); }
    }
    firstLinkedList.display();
}
