/*
 * @name main.cpp
 * @project cpp_test
 * @author lvjiaming
 * @date 2017/9/20-15:18
 * @ref []
 */

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void RunCode(T&& t) {
    cout << "t ===> " << t << endl;
}


template <typename T>
void PerfectForward(T&& t) {
    RunCode(std::forward<T>(t));
}

auto returnInitializer_list() {
    return 1;
}

int main(int argc, char** argv) {
    int a;
    int b;
    const int c = 1;
    const int d = 2;

    PerfectForward(a);
    PerfectForward(std::move(b));
    PerfectForward(c);
    PerfectForward(std::move(d));


    auto x1 = 27;
    auto x2(27);
    auto x3 = {27, 28};
    auto x4{28};

    cout << "x3.begin() = " << *x3.begin() << endl;

    cout << returnInitializer_list() << endl;



    std::vector<int> v;
    auto revsetV = [&v](const std::initializer_list<int>& newValue) {v = newValue;};
    revsetV({1,2,3});

    return EXIT_SUCCESS;

}








