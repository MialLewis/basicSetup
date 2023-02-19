#pragma once
#include<iostream>

namespace basicSetup{
    namespace kernel{ 
        class helloWorld{
            public:
                helloWorld();

            private:
                void _print() const;
        };
    }
}