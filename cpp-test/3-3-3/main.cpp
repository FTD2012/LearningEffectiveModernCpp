//
//  main.cpp
//  cpp-test
//
//  Created by 吕佳明 on 2017/9/18.
//  Copyright © 2017年 1. All rights reserved.
//

#include <iostream>

#include "HasPtrMem.h"

using namespace std;

HasPtrMem getTemp() {
    return HasPtrMem();
}


int main(int argc, const char * argv[]) {
    HasPtrMem a = getTemp();

    
    cout << "This is Break line" << endl;
    
    return 0;
}
