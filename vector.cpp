#include<iostream>
#include<vector>//vector 为类模板
#include<string>

using namespace std;

int main()
{
    vector<int> vec = {4,3,2,1,6};
    for(auto e: vec)    //auto为自动类型 随e而自动定义；该循环为范围循环语句，既循环vec内每个元素
        cout<<e<<endl;
    
    return 0;
}