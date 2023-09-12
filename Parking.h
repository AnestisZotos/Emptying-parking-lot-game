#ifndef AI_GAME_CARS_PARKING_H
#define AI_GAME_CARS_PARKING_H
#define WIDTH 100
#define HEIGHT 100
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Parking {
    private:
    pair<bool,string> cars[WIDTH][HEIGHT]; //says in which cells exist cars and if there exists which is their direction
    bool obstacles[WIDTH][HEIGHT]; //says in which cells exist obstacles
    pair<pair<int,int>,string> action_info; //says which auto was moved(in coordinates) and in which direction it was moved
    Parking * prev;  //pointer to previous state

    public:
    Parking();
    void setPrevious(Parking * p);
    void setActionInfo(int x,int y,string action);
    bool operator==(const Parking& o) const;
    bool isFree(int x,int y);    //checks if the cell with coordinates (x,y) is free
    string getDirection(int x,int y);   //gets direction of the auto that is in the coordinates (x,y)
    vector<pair<int,int>> getAllCars();     //returns the coordinates of all existing cars in the parking
    void setCar(int x,int y,string direction);       //sets a car at the wanted coordinates
    void removeCar(int x,int y);    //removes car from its coordinates
    bool goNorth(vector<Parking> &n);
    bool goSouth(vector<Parking> &n);
    bool goEast(vector<Parking> &n);
    bool goWest(vector<Parking> &n);
    vector<Parking> expand();








};


#endif
