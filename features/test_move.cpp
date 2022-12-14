#include <iostream>
#include <cassert>
#include <memory>
#include <vector>
using namespace std;


template<typename T>
void func(T& param) {
    cout << "传入的是左值" << endl;
}

template<typename T>
void func(T&& param) {
    cout << "传入的是右值" << endl;
}

template<typename T>
void warp(T&& param) {
    func(param);
}

void test2()
{
    int num = 2019;
    warp(num);
    warp(2019);
}

//转移 unique_ptr 的所有权
void test1(){

    unique_ptr<int> pInt = make_unique<int>(5);

    unique_ptr<int> pInt2 = std::move(pInt);    // 转移所有权
    //cout << *pInt << endl; // 出错，pInt为空
    cout << *pInt2 << endl;
    unique_ptr<int> pInt3(std::move(pInt2));
    vector<int> a;
    a.emplace_back(10);
}

//g++ -std=c++17 3_unique_ptr.cp
int main()
{    
    test1();
    return 0;
}