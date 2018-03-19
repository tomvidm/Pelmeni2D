#include <SFML/Graphics.hpp>

#include "pelmeni/system/Instance.hpp"
#include "pelmeni/utility/ResourceManager.hpp"

struct SomeClass {
    int a;
    int b;
};

int main() {
    //p2d::system::Instance instance;
    p2d::utility::ResourceManager<int> intManager;
    //intManager->["kkk"] = 3;
    return 0;
} // Main function