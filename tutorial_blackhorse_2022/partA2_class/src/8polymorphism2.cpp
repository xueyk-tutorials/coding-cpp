/**
 * 多态
 */
#include <iostream>
#include <string>
using namespace std;

class Vechile
{
public:
    virtual void move() = 0;
    void set_speed(float s){
        speed = s;
        cout << "set speed=" << speed << endl;
    }
    float speed;
};

class Car : public Vechile
{
public:
    void move() override
    {
        cout << "Car move" << endl;
    }
};
class Drone : public Vechile
{
public:
    void move() override
    {
        cout << "Drone fly" << endl;
    }
};
void fun_move(Vechile &v)
{
    v.move();
}
void test01()
{
    // 
    Car car;
    Drone drone;
    fun_move(car);
    car.set_speed(20);
    fun_move(drone);
    drone.set_speed(100);
}
void test02()
{
    Vechile *v = new Car();
}
int main()
{   
    test01();
}

