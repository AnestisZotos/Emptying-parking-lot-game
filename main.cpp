#include <iostream>
#include <queue>
#include <unordered_map>
#include "Parking.h"
using namespace std;


bool SearchVector(Parking &n,vector<Parking> &v){  //checks if state n is in vector v
    for(int i=0;i<v.size();i++){
        if(v[i]==n){
            return true;
        }
    }
    return false;


}


Parking BFS1(Parking initial,Parking goal,bool &flag){  // flag stores if a solution was found or not

    queue<Parking> agenda;
    vector<Parking> closed;
    agenda.push(initial);
    flag=true;

    while(agenda.size()>0){

        Parking s=agenda.front();
        agenda.pop();
        if(!SearchVector(s,closed)){
            if(s==goal){
                return s;
            }
            closed.push_back(s);
            vector<Parking> temp=s.expand();
            for(int i=0;i<temp.size();i++){
                agenda.push(temp[i]);
            }

        }

    }
    flag=false;
    return initial;



}




int main() {

    return 0;
}

