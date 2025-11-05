#pragma once
#include "Tiles.h"
#include <fstream>
#include <iostream>

class World {
public:
    TileSet ts;

    unsigned int* tarray;
    unsigned int size;

    int tileswide, tileshigh, tilewidth, tileheight;
    bool isWater[24];

    World();

    World(const std::string& filename) : ts() {
        std::ifstream fin(filename);
        fin >> size; // first number is the world size
        tarray = new unsigned int[size];

        // read order
        for (unsigned int i = 0; i < size; i++) {
            if (!(fin >> tarray[i])) {
                std::cerr << "File does not contain enough numbers.\n";
                delete[] tarray;
                tarray = nullptr;
                size = 0;
                return;
            }
        }
        fin.close();
    }
    void draw(GamesEngineeringBase::Window& canvas, unsigned int y) {

        unsigned int offset = y % 384;
        unsigned int Y = y / 384;

        ts[tarray[Y % size]].draw(canvas, (canvas.getHeight() / 2) + offset);
        ts[tarray[(Y + 1) % size]].draw(canvas, offset);
        ts[tarray[(Y + 2) % size]].draw(canvas, offset - (canvas.getHeight() / 2));
    }
};



       
