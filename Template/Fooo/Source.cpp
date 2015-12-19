#include <iostream>
using std::cout;
using std::endl;

template<typename T, typename... args>
void print(const T &t, const args&... rest)
{
    auto m = sizeof...(args);//测试代码,m并不总是3.而是每次减1
    if (!sizeof...(args))//参数包为空
    {
        cout << t << endl;//没有分隔符
        return;
    }
    cout << t << ", ";
    //print(rest...);
}

int main()
{
    print(1);
}