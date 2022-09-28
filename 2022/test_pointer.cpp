#include "iostream"
using namespace std;
template <typename T>
struct is_pointer
{
    static constexpr bool value {false};
};

template <typename T>
struct is_pointer<T*>
{
    static constexpr bool value {true};
};

void test_is_pointer()
{

}