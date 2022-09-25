#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

void test01()
{
    std::set<std::string> name{"alex", "bill", "charlie"};
    for(std::set<std::string>::iterator it=name.begin(); it!=name.end(); ++it)
    {
        cout << *it << endl;
    }

}
/**
 * @description: 根据vector来初始化set，可以将vector中重复的元素去掉！
 * @return {*}
 * @author: xueyuankui
 */
void test02()
{
    std::vector<std::string> vec_names{"alex", "bill", "charlie", "alex", "deny", "bill"};
    cout << "vec_names:" << endl;
    for(auto name : vec_names)
    {
        cout << name << " ";
    }
    cout << endl;
    cout << "由vector初始化set" << endl;
    std::set<std::string> set_names(vec_names.begin(), vec_names.end());
    cout << "set_names:" << endl;
    for(auto name : set_names)
    {
        cout << name << " ";
    }
    cout << endl;
}
int main(int argc, char *argv[])
{
    // if(argc < 2)
    // {
    //     std::cout << "Help:" << std::endl;
    //     std::cout << "./set <test01>" << std::endl;
    // }
    // else
    // {
    //     std::string fun(argv[1]);
    //     if(fun == "test01")
    //     {
    //         test01();
    //     }
    //     else if(fun == "test02")
    //     {
    //         test02();
    //     }
    // }
    test01();
    return 0;
}