#include "basicSetupApi/helloWorld.h"
#include "basicSetupKernel/printer.h"

basicSetup::api::helloWorld::helloWorld(){_print();}
basicSetup::api::helloWorld::helloWorld(const std::string &name){_print(name);}
void basicSetup::api::helloWorld::_print(const std::string &name) const {
    std::string printStr;
    if(name == ""){
        printStr = "Hello World";
    }else{
        printStr = "Hello World, my name is " + name;
    }
    basicSetup::kernel::printer test(printStr);
}
