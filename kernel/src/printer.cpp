#pragma once
#include "../inc/printer.h"

basicSetup::kernel::printer::printer(const std::string &str){
    _print(str);
}

void basicSetup::kernel::printer::_print(const std::string &str) const {
    std::cout << str << std::endl;
}
