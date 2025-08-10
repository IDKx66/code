#include <iostream>
#include <unordered_map>
using namespace  std;
void test1()
{
    unordered_map<string,string> hash_table;
    hash_table.insert(make_pair(string("插入"),string("insert")));
    hash_table.insert(make_pair(string("推"),string("push")));
    hash_table.insert(make_pair(string("删除"),string("delete")));
    //遍历
    for(auto str : hash_table)
    {   //语法糖for
        cout << str.first  << " " << str.second << " ";
    }    
    cout << endl;
    // cout << (hash_table.find(string("插入")) != hash_table.end()) << endl;
    cout << hash_table[string("插入")] << std::endl;
}
int main()
{
    test1();
    return 0;
}