#pragma once
#include "Tiles.h"
#include <iostream>
#include <sstream>

class World {
public:
    int map[worldMaxH][worldMaxW];
    int tileswide, tileshigh, tilewidth, tileheight;

    World();

    bool loadUsingFile(std::string& filename);

    void draw(GamesEngineeringBase::Window& canvas, const Camera& cam, TileSet& tiles);

    int getTilesWidth();
    int getTilesHeight();

    int getTileW();
    int getTileH();
};



       
