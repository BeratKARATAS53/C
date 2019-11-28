#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

/** Linked List And Node Structure*/
struct node {
	string footballerName, homeTeam, awayTeam, goalMinute, matchID;
	node *next;
};
class linkList {
    private:
    node *head, *tail;
    public:
    linkList() {
        head=NULL;
        tail=NULL;
    }
    void createnode(string name, string home, string away, string goal, string match) { /** Added Node to Linked List*/
        node *temp=new node;
		temp->footballerName=name;
		temp->homeTeam=home;
		temp->awayTeam=away;
		temp->goalMinute=goal;
		temp->matchID=match;
		temp->next=NULL;
		if(head==NULL) { /** For first node.*/
            head=temp;
			tail=temp;
			temp=NULL;
        }
		else {
			tail->next=temp;
			tail=temp;
		}
    }

    void goalArray(ofstream &outputFile) { /** 1. Output; THE MOST SCORED HALF*/
        node *mostScored=new node; mostScored=head;
        int goal_Array[2]={0,0}; /** goal_Array store a number of goal. First index, first half. Second index, second half*/
        while(mostScored!=NULL) {
            string goal_min=mostScored->goalMinute; int goal_minInt=0; stringstream change(goal_min); change>>goal_minInt; /** String to int.*/
	        if(goal_minInt>=46) { goal_Array[1]++; } /** If Goal Minute is greater than 45, first half goal scored.*/
	        else { goal_Array[0]++; } /** If Goal Minute is less than 45, second half goal scored.*/
            mostScored=mostScored->next;
        }
        if(goal_Array[0]>goal_Array[1]) {
            outputFile<<"1)THE MOST SCORED HALF\n0"<<endl; }
        else if(goal_Array[0]==goal_Array[1]) {
            outputFile<<"1)THE MOST SCORED HALF\n-1"<<endl; }
        else {
            outputFile<<"1)THE MOST SCORED HALF\n1"<<endl; }
    }

    void goalScorer(ofstream &outputFile) { /** 2. Output; GOAL SCORER */
        node *mostGoal=new node; mostGoal=head; vector<string> playerArray, allPlayerArray;
        playerArray.push_back(mostGoal->footballerName);
        allPlayerArray.push_back(mostGoal->footballerName);
        mostGoal=mostGoal->next;
        while(mostGoal!=NULL) { /** Firstly, the player name list is created. The list is playerArray.*/
            if(find(playerArray.begin(), playerArray.end(), mostGoal->footballerName) != playerArray.end()) { }
            else { playerArray.push_back(mostGoal->footballerName); }
            allPlayerArray.push_back(mostGoal->footballerName);
            mostGoal=mostGoal->next;
        }
        vector<int> scoreArray; int i=0, maxGoal=0;
        while(i<playerArray.size()) { /** Secondly, calculated how many goals each player scored.*/
            string playerName=playerArray[i];
            int cnt = count(allPlayerArray.begin(), allPlayerArray.end(), playerName);
            scoreArray.push_back(cnt);
            if(cnt>maxGoal){ maxGoal=cnt; } /** If the player has scored more goals than the previous one, the most scorer will be updated as the current player. */
            i++;
        }
        outputFile<<"2)GOAL SCORER\n";
        for(int i=0; i<playerArray.size(); ++i) {
            if(scoreArray[i]==maxGoal) { outputFile<<playerArray[i]<<endl; }
        }
    }

    void hatTrick(ofstream &outputFile) { /** 3.Output; THE NAMES OF FOOTBALLERS WHO SCORED HAT-TRICK*/
        node *threeGoal=new node; threeGoal=head; vector<string> playerArray;
        playerArray.push_back(threeGoal->footballerName); threeGoal=threeGoal->next;
        while(threeGoal!=NULL) { /** The player name list is created. The list is playerArray.*/
            if(find(playerArray.begin(), playerArray.end(), threeGoal->footballerName) != playerArray.end()) { }
            else { playerArray.push_back(threeGoal->footballerName); }
            threeGoal=threeGoal->next;
        }
        outputFile<<"3)THE NAMES OF FOOTBALLERS WHO SCORED HAT-TRICK\n";
        for(int i=0; i<playerArray.size(); i++) {
            int hatTrickCount=whichMatch(playerArray,playerArray[i]); /** Each of the players, more than 3 goals scored in the match, it is looked at. */
            if(hatTrickCount>0) {
                outputFile<<playerArray[i]<<endl;}
        }
    }

    int whichMatch(vector<string> player_Array, string player_name) { /** Each of the players, more than 3 goals scored in the match, it is looked at. */
        node *which=new node; which=head; vector<int> match_ID; int matchIDCount=0;
        while(which!=NULL) {
            if(which->footballerName.compare(player_name)==0) {
                string matchIDs=which->matchID; int match=0; stringstream turn(matchIDs); turn>>match;
                match_ID.push_back(match);
            }
            which=which->next;
        }
        for(int fz=0; fz<match_ID.size(); fz++) {
            int countID=count(match_ID.begin(), match_ID.end(), match_ID[fz]);
            if(countID<3) { matchIDCount=-1; }
            else if(countID>matchIDCount) {
                matchIDCount=match_ID[fz];
                break;
            }
        }
        return matchIDCount;
    }

    void teamList(ofstream &outputFile) { /** 4.Output; LIST OF TEAMS*/
        node *teamNames=new node; teamNames=head; vector<string> teamArray;
        teamArray.push_back(teamNames->homeTeam); teamNames=teamNames->next;
        while(teamNames!=NULL) { /** The team list is created. This list is teamArray.*/
            if(find(teamArray.begin(), teamArray.end(), teamNames->homeTeam) != teamArray.end()) { }
            else { teamArray.push_back(teamNames->homeTeam); }
            teamNames=teamNames->next;
        }
        outputFile<<"4)LIST OF TEAMS\n";
        for(int i=0; i<teamArray.size(); ++i)
            outputFile<<teamArray[i]<<endl;
    }

    void footballerList(ofstream &outputFile) { /** 5.Output; LIST OF FOOTBALLERS*/
        node *footballer=new node; footballer=head; vector<string> playerArray;
        playerArray.push_back(footballer->footballerName); footballer=footballer->next;
        while(footballer!=NULL) { /** The player name list is created. The list is playerArray.*/
            if(find(playerArray.begin(), playerArray.end(), footballer->footballerName) != playerArray.end()) { }
            else { playerArray.push_back(footballer->footballerName); }
            footballer=footballer->next;
        }
        outputFile<<"5)LIST OF FOOTBALLERS\n";
        for(int i=0; i<playerArray.size(); ++i)
            outputFile<<playerArray[i]<<endl;
    }

    void matchGiveFootballer(ofstream &outputFile, string str1, string str2) { /** 6.Output; MATCHES OF GIVEN FOOTBALLER*/
        node *firstPlayer=new node; firstPlayer=head;
        outputFile<<"6)MATCHES OF GIVEN FOOTBALLER\nMatches of "<<str1<<"\n";
        while(firstPlayer!=NULL) { /** For the first footballer.*/
            if(str1.compare(firstPlayer->footballerName)==0) {
                outputFile<<"Footballer Name: "<<str1<<",Away Team: "<<firstPlayer->awayTeam;
                outputFile<<",Min of Goal: "<<firstPlayer->goalMinute<<",Match ID: "<<firstPlayer->matchID<<endl;
            }
            firstPlayer=firstPlayer->next;
        }
        outputFile<<"Matches of "<<str2<<"\n";
        node *secondPlayer=new node; secondPlayer=head;
        while(secondPlayer!=NULL) { /** For the second footballer.*/
            if(str2.compare(secondPlayer->footballerName)==0) {
                outputFile<<"Footballer Name: "<<str2<<",Away Team: "<<secondPlayer->awayTeam;
                outputFile<<",Min of Goal: "<<secondPlayer->goalMinute<<",Match ID: "<<secondPlayer->matchID<<endl;
            }
            secondPlayer=secondPlayer->next;
        }

    }

    void Ascending_Or_Descending_Order(ofstream &outputFile, string str1, string str2, int which) { //7-8. Output; ASCENDING OR DESCENDING ORDER ACCORDING TO MATCH ID
        /** The matches of the players given as parameters are stored in a vector. Those vectors are "firstMatchArray" & "secondMatchArray".*/
        node *firstPlayer=new node; firstPlayer=head; vector<string> firstMatchArray;
        while(firstPlayer!=NULL) {
            if(str1.compare(firstPlayer->footballerName)==0) {
                if(find(firstMatchArray.begin(), firstMatchArray.end(), firstPlayer->matchID) != firstMatchArray.end()) {}
                else { firstMatchArray.push_back(firstPlayer->matchID); }
            }
            firstPlayer=firstPlayer->next;
        }
        node *secondPlayer=new node; secondPlayer=head; vector<string> secondMatchArray;
        while(secondPlayer!=NULL) {
            if(str2.compare(secondPlayer->footballerName)==0) {
                if(find(secondMatchArray.begin(), secondMatchArray.end(), secondPlayer->matchID) != secondMatchArray.end()) {}
                else { secondMatchArray.push_back(secondPlayer->matchID); }
            }
            secondPlayer=secondPlayer->next;
        }
        /** The order is determined by the 4th parameter.*/
        int a,b;
        if(which==0) { /** If parameter is equal to "0", it means is "Ascending Order"*/
            outputFile<<"7)ASCENDING ORDER ACCORDING TO MATCH ID\n";
            for(a=0; a<firstMatchArray.size(); a++) {
                outputFile<<"footballer Name: "<<str1<<",Match ID: "<<firstMatchArray[a]<<endl;
            }
            for(b=0; b<secondMatchArray.size(); b++) {
                outputFile<<"footballer Name: "<<str2<<",Match ID: "<<secondMatchArray[b]<<endl;
            }
        }
        else { /** If parameter is equal to "1", it means is "Descending Order"*/
            outputFile<<"8)DESCENDING ORDER ACCORDING TO MATCH ID\n";
            for(a=firstMatchArray.size()-1; a>=0; a--) {
                outputFile<<"footballer Name: "<<str1<<",Match ID: "<<firstMatchArray[a]<<endl;
            }
            for(b=secondMatchArray.size()-1; b>=0; b--) {
                if(b==0) { outputFile<<"footballer Name: "<<str2<<",Match ID: "<<secondMatchArray[b]; }
                else { outputFile<<"footballer Name: "<<str2<<",Match ID: "<<secondMatchArray[b]<<endl; }
            }
        }
    }

    void sortArray2(string GoalArray[][2], int len) {
        for(int i=0;i<len;i++) {
            for(int j=i+1;j<len;j++) {
                if(GoalArray[i][0]<GoalArray[j][0]) {
                    swap(GoalArray[i],GoalArray[j]); } } }
    }
};
/**
* The sort function is used to sort the data in the file before adding it to the linked list.
* MyArray: is an 2d dimensional array, which store the data.
* len: is size of MyArray.
*/
void sortArray1(string MyArray[][5], int len) {
    for(int i=0;i<len-1;i++) {
        for(int j=i+1;j<len;j++) {
            /** 4 transactions in sequence are "string to int" operations.*/
            string matchID1=MyArray[i][4]; int match1=0; stringstream turn1(matchID1); turn1>>match1;
            string matchID2=MyArray[j][4]; int match2=0; stringstream turn2(matchID2); turn2>>match2;
            string goalID1=MyArray[i][3]; int goal1=0; stringstream turn1_1(goalID1); turn1_1>>goal1;
            string goalID2=MyArray[j][3]; int goal2=0; stringstream turn2_1(goalID2); turn2_1>>goal2;
            if(MyArray[i][0]>MyArray[j][0]) {
                swap(MyArray[i],MyArray[j]); }
            if((MyArray[i][0].compare(MyArray[j][0])==0) && match1>match2) {
                swap(MyArray[i],MyArray[j]); }
            if((MyArray[i][0].compare(MyArray[j][0])==0) && match1==match2 && goal1>goal2) {
                swap(MyArray[i],MyArray[j]); }
        }
    }
}

int main()
{
    ifstream inputFile("input2.txt"); /** Input File*/

    string name,homeTeam,awayTeam,line,myString;
    int goalMinute=0,matchID=0,lineCount = 0;
    while(getline(inputFile,line)) { lineCount++; }

    inputFile.clear(); inputFile.seekg(0);
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
    sortArray1(footballerInfo,arrayLength);

    ifstream operationFile("operations2.txt"); /** Operations File*/

    string operationName1,operationName2,fileLine,operationsArray[3][2];
    int j,h=0;
    while(getline(operationFile,fileLine)) {
        stringstream ss(fileLine);
        getline(ss,operationName1,','); operationsArray[h][0]=operationName1;
        getline(ss,operationName2,','); operationsArray[h][1]=operationName2;
        h++;
    }

    linkList firstLinkedList;
    for(int i=0;i<arrayLength;i++) { /** Create a Linked List.*/
            firstLinkedList.createnode(footballerInfo[i][0],footballerInfo[i][1],footballerInfo[i][2],footballerInfo[i][3],footballerInfo[i][4]); }

    ofstream outputFile;
    outputFile.open ("output.txt"); /** Output File*/

    firstLinkedList.goalArray(outputFile);
    firstLinkedList.goalScorer(outputFile);
    firstLinkedList.hatTrick(outputFile);
    firstLinkedList.teamList(outputFile);
    firstLinkedList.footballerList(outputFile);
    firstLinkedList.matchGiveFootballer(outputFile,operationsArray[0][0],operationsArray[0][1]);
    firstLinkedList.Ascending_Or_Descending_Order(outputFile,operationsArray[1][0],operationsArray[1][1],0);
    firstLinkedList.Ascending_Or_Descending_Order(outputFile,operationsArray[2][0],operationsArray[2][1],1);

    outputFile.close();
}
