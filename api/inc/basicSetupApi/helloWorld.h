#pragma once
#include <string>

namespace basicSetup::api{
    class helloWorld{
        public: 
            helloWorld();
            explicit helloWorld(const std::string &name);

        private:
            void _print(const std::string &name = "") const;
    };
}