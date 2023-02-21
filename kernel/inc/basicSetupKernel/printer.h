#pragma once
#include<iostream>
#include <string>

namespace basicSetup::kernel{
    class printer{
        public:
            printer(const std::string &str);

        private:
            void _print(const std::string &str) const;
    };
}