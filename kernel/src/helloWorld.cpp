#pragma once
#include "../inc/helloWorld.h"

basicSetup::kernel::helloWorld::helloWorld(){
    _print();
}

void basicSetup::kernel::helloWorld::_print() const {
    std::cout << "Hello world" << std::endl;
}
