#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

std::string readTextFile(const std::string& filename) 
{
    std::ifstream ifs(filename, std::ios::in);
    assert(ifs.is_open());
    std::stringstream ss;
    ss << ifs.rdbuf();
    ifs.close();
    return ss.str();
}

void test01() 
{
    std::string content = readTextFile("/media/alex/Develop/alex-github/drone_tutorials/gazebo/demos/demo_WarehouseRobot/models/mobile_warehouse_robot/model.sdf");

    std::cout << content << std::endl;
}

void test02()
{
    std::stringstream ss("0.123");
    double a;
    ss >> a;
    std::cout << a << std::endl;
}
int main(int argc, char *argv[])
{
    // test01();
    test02();
    // test03();
    return 0;
}