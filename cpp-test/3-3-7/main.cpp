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

class HugeMem {

public:
    HugeMem(int size):
            sz(size>0?size:1),
            c(new int[sz])
    {
        cout << "HugeMem ----- constructor function." << endl;
    }

    HugeMem(HugeMem&& h):
            sz(h.sz),
            c(h.c)
    {
        h.c = nullptr;
        cout << "HugeMem ----- RValue function." << endl;
    }

    HugeMem(const HugeMem& h):
            HugeMem(h.sz)
    {
        cout << "HugeMem ----- const reference function." << endl;
    }

    ~HugeMem()
    {
        delete[] c;
        cout << "HugeMem ----- delete function." << endl;
    }


public:
    int* c;
    int sz;

};


class Moveable {

public:
    Moveable():
            d(new int(3)),
            h(1024)
    {
        cout << "Moveable ----- costructor function." << endl;
    };

    Moveable(Moveable&& m):
            d(m.d),
            h(std::move(m.h))
    {
        m.d = nullptr;
        cout << "Moveable ----- RValue function." << endl;
    }

    Moveable(const Moveable& m):
            d(new int(*m.d)),
            h(m.h)              /// DOUBT: Convert 'h(m.h)' to 'h(std::move(m.h))' still call 'HugeMem(const HugeMem& h)'. Why?
    {
        cout << "Moveable ----- const reference function." << endl;
    }


    ~Moveable()
    {
        delete d;
        cout << "Moveable ----- delete function." << endl;
    }

public:
    int *d;
    HugeMem h;

};

Moveable GetTemp() {
    return Moveable();
}



int main(int argc, const char * argv[]) {

    Moveable m(GetTemp());

    Moveable b(static_cast<Moveable>(Moveable()));

    return 0;
}
