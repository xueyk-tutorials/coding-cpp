#include <cstdio>
#include <iostream>
#include <string>
#include <memory>

using namespace std;

float div(float a, float b)
{
    float res = 0;

    return a/b;
    try
    {
        res = a/b;
    }
    // catch(...){
    //     cout << "catch" << endl;
    // }
    catch(const char *msg){
        cout << "11111" << endl;
        cerr << msg << endl;
    }
    catch(std::exception &ex)
    {
        cout << "22222" << endl;
        cout << ex.what() << endl;
    }
    return res;
}

float get_value(float *p)
{
    return *p;
}
void test01()
{
    for(int i=0; i<10; ++i)
    {
        float a = i;
        float b = i;
        if(i == 3){
            b = 0;
        }
        cout << "a=" << i << ", " << div(a, b) << endl;
    }
}
void test02()
{
    float *p = NULL;
    float a = 0;
    try{
        a = get_value(p);
    }
    catch(std::exception &ex)
    {
        cout << "11111" << endl;
        throw;
    }
    catch(...){
        cout << "catch" << endl;
    }
    
}
int main(int argc, char *argv[])
{
    test01();
    test02();
    return 0;
}