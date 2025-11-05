#include "World.h"

World::World() {
	for (int y = 0; y < worldMaxH; y++)
		for (int x = 0; x < worldMaxW; x++) {
			map[y][x] = 0;
		}
}

bool World::loadUsingFile(std::string& filename) {
	std::ifstream f(filename);
	int w = 0, h = 0, tw = -1, th = -1;
	bool inLayer = false;
	int rowsRead = 0;

	std::string line;
	while (std::getline(f, line)) {
		if (isEmpty(line)) continue;

		if (!inLayer) {
			if (startsWithKey(line, "tileswide")) { std::istringstream iss(line); std::string k; iss >> k >> W;  continue; }
			if (startsWithKey(line, "tileshigh")) { std::istringstream iss(line); std::string k; iss >> k >> H;  continue; }
			if (startsWithKey(line, "tilewidth")) { std::istringstream iss(line); std::string k; iss >> k >> tw; continue; }
			if (startsWithKey(line, "tileheight")) { std::istringstream iss(line); std::string k; iss >> k >> th; continue; }
			if (startsWithKey(line, "layer")) {
			}
		}
	}
}

void World::draw(GamesEngineeringBase::Window& canvas, const Camera& cam, TileSet& tiles) {
	
}

int World::getTilesWidth() { return tileswide; }
int World::getTilesHeight() { return tileshigh; }

int World::getTileH() { return tileheight; }
int World::getTileW() { return tilewidth; }