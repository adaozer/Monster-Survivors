#include "Helper.h"

bool circlesIntersect(int x1, int y1, int r1, int x2, int y2, int r2)
{
    int dx = x1 - x2;
    int dy = y1 - y2;
    int dist2 = dx * dx + dy * dy;
    int rsum = r1 + r2;
    return dist2 <= rsum * rsum;
}

bool onScreen(float x, float y, float w, float h, Camera& cam, const GamesEngineeringBase::Window& canvas)
{
    float sx = x - cam.getX();  
    float sy = y - cam.getY();
    return (sx + w >= 0 && sy + h >= 0 && sx <= canvas.getWidth() && sy <= canvas.getHeight());
}


int score = 0;
