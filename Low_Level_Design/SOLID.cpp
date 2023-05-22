#include <bits/stdc++.h>
using namespace std;

//!  1) S- single responsibilty principle

//  *A class should  have only 1 reason to change

class Marker
{
    string name;
    string color;
    int year;
    int price;
  
  public:
   Marker(string name,string color,int year,int price)
  {
    this->color=name;
    this->color=color;
    this->price=price;
    this->year=year;
  }
};

// !<<<<-----------------WRONG WAY-------------------------->>>>

class Invoice{
    private:
    Marker marker;
    int quantity;

    public:   
    
    Invoice(Marker marker, int quantity){
        this->marker=marker;
        this->quantity=quantity;
    }

//  *NOT Following single responsibility because of the following functions
//  *cuz if in future if we want to update somthing in the function we'll have to change the class
    int calculateTotal(){
        int price = (marker.price * this->quantity);
        return price;
    }

    void printInvoice()
    {
        // *print the invoice
    }

    void saveDB()
    {
        //  *Save the data to the DB
    }

};

// *<<<<<<<---------------------------- RIGHT WAY --------------------------------------->>>>>>>>

class Invoice{
    private:
    Marker marker;
    int quantity;

    public:   
    
    Invoice(Marker marker, int quantity){
        this->marker=marker;
        this->quantity=quantity;
    }

     int calculateTotal(){
        int price = (marker.price * this->quantity);
        return price;
    }

};


class InvoiceDAO 
{

Invoice invoice;
public:
    InvoiceDAO(Invoice invoice)
    {
       this->invoice=invoice; 
    }

    void saveToDB(){ 
        // *Save to DB
      }    
};

class InvoicePrinter 
{

Invoice invoice;
public:
    InvoicePrinter(Invoice invoice)
    {
       this->invoice=invoice; 
    }

    void printInvoice(){ 
        // *Print Invoice
      }    
};



// ! 2) O - Open/Closed Principle

//  *Open for Extension But Closed for Modification

//  *Previous Example continue 


// !<<<<-----------------WRONG WAY-------------------------->>>>

class InvoiceDAO 
{

Invoice invoice;
public:
    InvoiceDAO(Invoice invoice)
    {
       this->invoice=invoice; 
    }

    void saveToDB(){ 
        // *Save to DB
      }  

    void saveToFile(string filename)
    {
        // *save invoice in the file with the given name
    }  
};

// ? AN already tested class should not be modified .You can extend it for adding 
// ? functionality but you shouln't modify as it might Disturb the tested code 
//  ?and produce unnecessary errors



//  *<<<<<<<---------------------------- RIGHT WAY --------------------------------------->>>>>>>>

class InvoiceDAO 
{
public:
    void save(Invoice invoice);   
};

class DatabaseInvoiceDAO: public InvoiceDAO  
{

public:
    void save (Invoice invoice){ 
        // *save to DB
      }    
};


class FileInvoiceDAO: public InvoiceDAO  
{

public:
    void save (Invoice invoice){ 
        // *save to File
      }    
};


//! 3) L - Liskov Substitution Principle

// *If class B is subtype of class A , then we should be able to replace the obj of A with B 
//  * without breaking the behaviour of the program.

// ? subclass should extend the capability of parent class not narrow it.

//!  <<<----------------------------WRONG WAY------------------------>>>


class Bike{
    void turnOnEngine();
    void accelerate();
};

class MotorCylce: Bike{
    bool isEngineOn;
    int speed;

    void turnOnEngine(){
        //  ! turn on the engine
        
        isEngineOn=true;
    }

    void accelerate(){
        // ! increase the speed

        speed += 10;
    }
};

class Bicycle : Bike{
    bool isEngineOn;
    int speed;
   
   
    void turnOnEngine(){
        //  ! turn on the engine

        // ! exception -->
        throw "there is no engine";
        
        isEngineOn=true;
    }


    void accelerate(){
        // ! increase the speed

        speed += 10;
    }
};

//! HERE IN THE BICYCLE CLASS THE PARENT CLASS BIKE CAPABILITY IS DECRESED 
//! WHICH VIOLETS THE Liskov Substitution Principle.


//!  4)  I - Interface Segmented Principle

// *  Interfaces should be such that client should be able to 
//* implement unnecessary functions they do not need.

//!  <<<----------------------------WRONG WAY------------------------>>>

class RestaurantEmployee{
    void washDishes();
    void serveCustomers();
    void cookFood();
};

class Waiter : RestaurantEmployee{
    void washDishes()
    {
        throw "Not my JOB";
    }

    void serveCustomers()
    {
        cout<<"Serving the Customers";
    }

    void cookFood()
    {
        throw "Not my JOB";
    }
};

//  *<<<<<<<---------------------------- RIGHT WAY --------------------------------------->>>>>>>>

class waiterInterface{
    void serveCustomers();
    void takeOrders();
};

class ChefInterface{
    void cookFood();
    void decideMenu();
};

class Waiter:waiterInterface{
    void serveCustomers()
    {
        cout<<"Serving...";
    }

    void takeOrders()
    {
        cout<<"Taking Orders..";
    }
};

class Chef : ChefInterface
{
    void cookFodd()
    {
        cout<<"Cooking.....";
    }

    void decideMenu()
    {
        cout<<"Deciding the Menu..!";
    }
};



//! D - Dependency Inversion Principle

// * Class should depend on interface rather than concrete  classes


//!  <<<----------------------------WRONG WAY------------------------>>>

class WiredKeyboard
{

};

class WiredMouse{

};

class Mackbook
{
    private:
     WiredKeyboard keyboard;
     WiredMouse mouse;

     public : Mackbook()
     {
        keyboard =  WiredKeyboard();
        mouse =  WiredMouse();
     }
};

//  *<<<<<<<---------------------------- RIGHT WAY --------------------------------------->>>>>>>>

class Keyboard
{

};

class Mouse{

};

class Mackbook
{
    private:
     Keyboard keyboard;
     Mouse mouse;

     public : Mackbook(Keyboard Keyboard , Mouse mouse)
     {
        this->keyboard=keyboard;
        this->mouse=mouse;
     }
};

