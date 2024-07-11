#include <iostream>
#include <string>
using namespace std;
class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal" << endl;
    }
};

class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Hello" << endl;
    }
};
int main()
{
    Animal *a1 = new Dog;
    a1->speak();
    // d1.speak();

    // Dog *d2 = new Dog;
    // d2->speak();

    // ptr.speak();

    return 0;
}