//  strategy design pattern helps to scale 

#include <bits/stdc++.h>
using namespace std;


// !<<<-----------------------Without Strategy Design Pattern--------------------->>>

class Vehicle{
    void drive()
    {
        cout<<" Normal Driving Capabality.....";
    }
};

class PassengerVehicle:Vehicle{


};

class SportsVehicle:Vehicle{
    void drive()
    {
        cout<<"Sports Driving Capability....";
    }
};

class OffRoadVehicle:Vehicle{
    void drive()
    {
        cout<<"OffRoad Driving Capability....";
    }
};


// * <<<--------------With Strategy Design Pattern----------------->>>

class DriveStrategy{
    void drive();
};

class NormalDrive:DriveStrategy{
    void drive()
    {
        cout<<" Normal Driving Capabality.....";
    }
};

class SportsDrive:DriveStrategy{
    void drive()
    {
      cout<<"Sports Driving Capability....";  
    }
};


class Vehicle{
    DriveStrategy driveObj;
 public: Vehicle(DriveStrategy obj)
    {
        this->driveObj=obj;
    }

    void drive()
    {
        driveObj.drive();
    }
};

class PassengerVehicle: public Vehicle{
     public: PassengerVehicle (  DriveStrategy obj) : Vehicle( new NormalDrive() ) {} 
};

class SportsVehicle: public Vehicle{
   public: SportsVehicle (  DriveStrategy obj) : Vehicle( new SportsDrive() ) {}  
};

class OffRoadVehicle: public Vehicle{
    public: OffRoadVehicle (  DriveStrategy obj) : Vehicle( new SportsDrive() ) {}
};

