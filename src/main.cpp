#include <iostream>
#include <cstdio>

#include <SFML/Graphics.hpp>

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"

namespace rj = rapidjson;

int main() {
    // p2d::system::Instance game;


    FILE* pFile = fopen("../resources/blueprints/test01.json", "rb");
    char buffer[4096];
    rj::FileReadStream is(pFile, buffer, sizeof(buffer));

    rj::Document d;
    d.ParseStream(is);
    
    fclose(pFile);
    return 0;
} // Main function