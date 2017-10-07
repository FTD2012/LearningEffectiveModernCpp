/*
 * @name main.cpp
 * @project cpp_test
 * @author lvjiaming
 * @date 2017/9/21-21:12
 * @ref []
 */

#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename U>
auto decltypeInCPP11(T&& t, U&& u) -> decltype(std::forward<T>(t) + std::forward<U>(u)) {
    return std::forward<T>(t) + std::forward<U>(u);
}


template<typename T, typename U>
decltype(auto) decltypeInCPP14(T&& t, U&& u) {
    return std::forward<T>(t) + std::forward<U>(u);
}


int main(int argc, char** argv) {

    int x = 1;
    decltype(x) y = 2.0;

    cout << "1111 = " << decltypeInCPP11(1, 2) << endl;
    cout << "2222 = " << decltypeInCPP11(1.1, 2.0) << endl;

    cout << "1111 = " << decltypeInCPP14(1, 2) << endl;
    cout << "2222 = " << decltypeInCPP14(1.1, 2.0) << endl;



    return EXIT_SUCCESS;

}








