//
//  main.cpp
//  cpp-test
//
//  Created by 吕佳明 on 2017/9/18.
//  Copyright © 2017年 1. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Moveable {

public:
    Moveable(): d(new int(3)) {};
    Moveable(const Moveable& m): d(new int(*m.d)) {}
    Moveable(Moveable&& m): d(m.d) {
        m.d = nullptr;
        cout << "This Moveable RValue" << endl;
    }
    Moveable(int&& m): d(new int(m)){};

public:
    int *d;



};



int main(int argc, const char * argv[]) {

    Moveable m;
    Moveable n(std::move(m));
    Moveable f((Moveable()));   /// DOUBT: why there should be a pair of parentheses
                                /// EXPLANATION: MOST-VEXING-PARSE see detail in WIKIPEDIA [https://en.wikipedia.org/wiki/Most_vexing_parse]

    int a = 2;
    float b(static_cast<float>(a));

    cout << "bbb = " << b << endl;

    cout << "n.d = " << *n.d << endl;
    cout << "f.d = " << *f.d << endl;
    cout << "m.d = " << *m.d << endl;


    return 0;
}
