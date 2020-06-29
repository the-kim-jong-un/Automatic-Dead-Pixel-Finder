#include <iostream>
#include <string>
#include "colorSFML.h"

#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    std::string n = "data/brown.png";
    colorSFML::manager(n);
    return 0;
}
