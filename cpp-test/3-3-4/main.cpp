//
//  main.cpp
//  cpp-test
//
//  Created by 吕佳明 on 2017/9/18.
//  Copyright © 2017年 1. All rights reserved.
//

#include <iostream>
#include <string>

#include "HasPtrMem.h"

using namespace std;

HasPtrMem getTemp() {
    return HasPtrMem();
}

template<class T>
void returnRValue(T&& i) {
    cout << "RValue i = " << i << endl;
    i = 2;
//    return std::move(i);
}


int main(int argc, const char * argv[]) {
//    HasPtrMem a = getTemp();


    int b = 0;
    int c = 1;
    int& bRef = b;
    int&& cRValue = 1;


    cout << "This is Break line" << endl;

    string str("This is string object.");

    returnRValue(b);

    cout << "b == " << b << endl;



    return 0;
}
