#include "Parking.h"
using namespace std;

Parking::Parking() {
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            cars[i][j].first=false;
            cars[i][j].second="";
            obstacles[i][j]=false;
        }
    }
    prev= nullptr;



}




bool Parking::operator==(const Parking &o) const {   // 2 Parking items are equal when they have the same number of cars in them
    for(int i=0;i<WIDTH;i++){

        for(int j=0;j<HEIGHT;j++){

            if(cars[i][j].first!=o.cars[i][j].first){
                return false;
            }
        }
    }
    return true;

}


void Parking::setPrevious(Parking * p){
    prev=p;
}

void Parking::setActionInfo(int x,int y,string action){
    pair<int,int> p(x,y);
    action_info.first=p;
    action_info.second=action;
}



bool Parking::isFree(int x, int y) {
    if(cars[x][y].first==false &&obstacles[x][y]== false){
        return true;
    }
    return false;

}


string Parking::getDirection(int x, int y) {
    if(cars[x][y].first) {
        return cars[x][y].second;
    }
    return "";
}

vector<pair<int,int>> Parking::getAllCars() {

    vector<pair<int,int>> vector1;

    for(int i=0;i<WIDTH;i++){

        for(int j=0;j<HEIGHT;j++){

            if(cars[i][j].first){       //car exists

                pair<int,int> p(i,j);
                vector1.push_back(p);

            }

        }
    }
    return vector1;
}


void Parking::setCar(int x, int y,string direction) {

    cars[x][y].first=true;
    cars[x][y].second=direction;

}

void Parking::removeCar(int x,int y){

    cars[x][y].first=false;
    cars[x][y].second="";
}




bool Parking::goNorth( vector<Parking> &n) {    //in n the created states exist
     vector<pair<int,int>> allCars=getAllCars();

     bool flag=false;

     for(int i=0;i<allCars.size();i++){   //for every car that is in parking

         int cord1=allCars[i].first;
         int cord2=allCars[i].second;
         string carDirection=getDirection(cord1,cord2);

         if((carDirection.compare("North")==0 || carDirection.compare("South")==0)&& cord2>0 && isFree(cord1, cord2 - 1)){

             Parking temp=*this;
             temp.setCar(cord1,cord2 - 1,carDirection);
             temp.removeCar(cord1,cord2);
             temp.setPrevious(this);
             temp.setActionInfo(cord1,cord2,"North");
             n.push_back(temp);
             flag=true;

         }
         else if((carDirection.compare("North")==0 || carDirection.compare("South")==0)&&cord2==0){ //remove auto
             Parking temp=*this;
             temp.removeCar(cord1,cord2);
             temp.setPrevious(this);
             temp.setActionInfo(cord1,cord2,"Removed");
             n.push_back(temp);
             flag=true;
         }
     }

     return flag;

}


bool Parking::goSouth(vector<Parking> &n){

    vector<pair<int,int>> allCars=getAllCars();

    bool flag=false;

    for(int i=0;i<allCars.size();i++){   //for every car that is in parking

        int cord1=allCars[i].first;
        int cord2=allCars[i].second;
        string carDirection=getDirection(cord1,cord2);

        if((carDirection.compare("North")==0 || carDirection.compare("South")==0)&& cord2<HEIGHT-1 && isFree(cord1, cord2 + 1)){

            Parking temp=*this;
            temp.setCar(cord1,cord2 + 1,carDirection);
            temp.removeCar(cord1,cord2);
            temp.setPrevious(this);
            temp.setActionInfo(cord1,cord2,"South");
            n.push_back(temp);
            flag=true;

        }
        else if((carDirection.compare("North")==0 || carDirection.compare("South")==0)&&cord2==HEIGHT-1){ //remove auto
            Parking temp=*this;
            temp.removeCar(cord1,cord2);
            temp.setPrevious(this);
            temp.setActionInfo(cord1,cord2,"Removed");
            n.push_back(temp);
            flag=true;
        }
    }

    return flag;




}


bool Parking::goEast(vector<Parking> &n){

    vector<pair<int,int>> allCars=getAllCars();

    bool flag=false;

    for(int i=0;i<allCars.size();i++){   //for every car that is in parking

        int cord1=allCars[i].first;
        int cord2=allCars[i].second;
        string carDirection=getDirection(cord1,cord2);

        if((carDirection.compare("East")==0 || carDirection.compare("West")==0)&& cord1<WIDTH-1 && isFree(cord1+1, cord2)){

            Parking temp=*this;
            temp.setCar(cord1+1,cord2,carDirection);
            temp.removeCar(cord1,cord2);
            temp.setPrevious(this);
            temp.setActionInfo(cord1,cord2,"East");
            n.push_back(temp);
            flag=true;

        }
        else if((carDirection.compare("East")==0 || carDirection.compare("West")==0)&&cord1==WIDTH-1){  //remove auto
            Parking temp=*this;
            temp.removeCar(cord1,cord2);
            temp.setPrevious(this);
            temp.setActionInfo(cord1,cord2,"Removed");
            n.push_back(temp);
            flag=true;
        }
    }

    return flag;


}



bool Parking::goWest(vector<Parking> &n){
    vector<pair<int,int>> allCars=getAllCars();

    bool flag=false;

    for(int i=0;i<allCars.size();i++){   //for every car that is in parking

        int cord1=allCars[i].first;
        int cord2=allCars[i].second;
        string carDirection=getDirection(cord1,cord2);

        if((carDirection.compare("East")==0 || carDirection.compare("West")==0)&& cord1>0 && isFree(cord1-1, cord2)){

            Parking temp=*this;
            temp.setCar(cord1-1,cord2,carDirection);
            temp.removeCar(cord1,cord2);
            temp.setPrevious(this);
            temp.setActionInfo(cord1,cord2,"East");
            n.push_back(temp);
            flag=true;

        }
        else if((carDirection.compare("East")==0 || carDirection.compare("West")==0)&&cord1==0){   //remove auto
            Parking temp=*this;
            temp.removeCar(cord1,cord2);
            temp.setPrevious(this);
            temp.setActionInfo(cord1,cord2,"Removed");
            n.push_back(temp);
            flag=true;
        }
    }

    return flag;


}






vector<Parking> Parking::expand() {
    vector<Parking> children; //vector that will be returned
    vector<Parking> states;  //helping vector

    if(goNorth(states)){                //move to NORTH
        for(int i=0;i<states.size();i++){
            children.push_back(states[i]);
        }
        for(int i=0;i<states.size();i++){
            states.pop_back();                  //emptying the helping vector so to use it later
        }
    }

    if(goEast(states)){                     //move East
        for(int i=0;i<states.size();i++){
            children.push_back(states[i]);
        }
        for(int i=0;i<states.size();i++){
            states.pop_back();
        }
    }

    if(goSouth(states)){                //move to South
        for(int i=0;i<states.size();i++){
            children.push_back(states[i]);
        }
        for(int i=0;i<states.size();i++){
            states.pop_back();
        }
    }

    if(goWest(states)){                //move to West
        for(int i=0;i<states.size();i++){
            children.push_back(states[i]);
        }
        for(int i=0;i<states.size();i++){
            states.pop_back();
        }
    }



    return children;
}





