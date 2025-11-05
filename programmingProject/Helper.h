#pragma once
#include "Camera.h"

struct Position {
	int x, y;
};
bool circlesIntersect(int x1, int y1, int r1, int x2, int y2, int r2);

bool onScreen(float x, float y, float w, float h, Camera& cam, const GamesEngineeringBase::Window& canvas);

constexpr unsigned int bulletSize = 1000;
constexpr unsigned int enemySize = 1000;
extern int score;