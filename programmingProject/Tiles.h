#pragma once
#include "Camera.h"
#include "Helper.h"

class Tile {
public:
	GamesEngineeringBase::Image image;
	Tile();
	void load(std::string filename);
	void draw(GamesEngineeringBase::Window &canvas, int x, int y, Camera &cam);

	int getHeight();
	int getWidth();
	GamesEngineeringBase::Image& getSprite();
};

class TileSet {
public:
	Tile t[tileNum];
	TileSet(std::string pre = "");

	Tile& operator[](unsigned int index);
};
