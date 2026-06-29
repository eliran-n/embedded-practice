#include <iostream>
#include <stdint.h>
#include <string.h>

using namespace std;

/* ################ EXAMPLE 1 ################ */

class Vehicle
{
    // Access specifier
    public:
    // method
    void honk( void )
    {
        cout << "Tuut, tuut! \n";
    }
};

class Car: public Vehicle
{
    public:
        string model = "Toyota";
};

/* ################ EXAMPLE 2 ################ */

// Base class
class Animal
{
    // Access specifier
    public:
        // Constructor
        Animal( uint32_t age ) // Constructor 
        {
            cout << "Animal age is: " << age << endl;
        }
};

// Derived class 
class Cat: public Animal
{
    // Private access specifier - members can't be access or viewd from outside the class. 
    private:
        string breed;

    public:
        // Left side: 
        // Required varialbes (declaration)
        // Right side: 
        // Initialization of base class and class attribute (assingnment)

        Cat( uint32_t age, string breed ): Animal(age), breed(breed)
        {
            cout << "I'm a cat. My breed is: " << breed << endl;
        }
};

int main( void )
{
    Car my_car;
    my_car.honk();
    cout << "My car model is: " << my_car.model << endl;

/*
    In C++, unlike Python, the base class constructor is automatically invoked
    when constructing a derived class object.

    Because the base class constructor runs automatically, its initialization
    must be satisfied, so any required parameters must be passed from the
    derived class to the base class.

    In Python, if the base class does not define a constructor,
    the derived class constructor will run normally using the default behavior.

    If both the base class and the derived class define constructors,
    and you want the base class constructor to run,
    you must explicitly call it using super().
*/

    Cat my_cat(3, "Persian");
}