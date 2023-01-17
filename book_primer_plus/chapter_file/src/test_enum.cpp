#include <iostream>
#include <string>

using namespace std;

enum STATE{
	INIT=1,
	WAIT,
	EXIT
};

typedef enum {
	INIT2=10,
	WAIT2,
	EXIT2
}STATE2;

class Drone{
public:
    enum TYPE{
        ROTOR=100,
        FIXWING,
        ROVER
    };
    void print_type(){
        cout << "Drone: ROTOR=" << ROTOR << endl;
        cout << "Drone: TYPE::ROTOR=" << TYPE::ROTOR << endl;
    }
private:
};

void test01()
{
    STATE state = INIT;
    cout << state << endl;
    cout << "WAIT=" << WAIT << endl;
    cout << "STATE::WAIT=" << STATE::WAIT << endl;
        
    cout << "INIT2=" << INIT2 << endl;
    cout << "STATE2::INIT2=" << STATE2::INIT2 << endl;
}

void test02()
{
    Drone drone;
    drone.print_type();

    // cout << "outside, ROTOR=" << ROTOR << endl;                   // 无法调用ROTOR，必须指定类定义域
    cout << "outside, Drone::ROTOR=" << Drone::ROTOR << endl;
    cout << "outside, Drone::TYPE::ROTOR=" << Drone::TYPE::ROTOR << endl;
}

int main(int argc, char *argv[]){

    test02();
    return 0;
}

