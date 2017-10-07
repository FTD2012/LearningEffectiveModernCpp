//
//  HasPtrMem.hpp
//  cpp-test
//
//  Created by 吕佳明 on 2017/9/18.
//  Copyright © 2017年 1. All rights reserved.
//

#ifndef HasPtrMem_hpp
#define HasPtrMem_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class HasPtrMem {
    
public:
    HasPtrMem(): d(new int(0)){
        cout << "n_cstr =  " << ++n_cstr << endl;
    }
    
    HasPtrMem(const HasPtrMem& h): d(new int(*h.d)) {
        cout << "n_cptr = " << ++n_cptr << endl;
    }

    HasPtrMem(HasPtrMem&& h): d(h.d) {
        h.d = nullptr;
        cout << "n_mstr = " << ++n_mstr << endl;
    }
    
    ~HasPtrMem() {
        delete d;
        cout << "n_dstr = " << ++n_dstr << endl;
    }
    
    
private:
    int *d;
    
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mstr;

};


#endif /* HasPtrMem_hpp */
