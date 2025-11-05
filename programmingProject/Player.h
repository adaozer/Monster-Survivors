#pragma once
#include <iostream>
#include "Camera.h"
#include "Character.h"
#include "Helper.h"

class Bullet;
class Melee;
class Ranged;

class Player : public Character {
public:
    float timeElapsed = 0.f; // To check if enough time has passed to shoot a bullet
    Bullet* barr[bulletSize]; // Bullet array we'll use to store our bullets we shoot with auto attack

    float shootSpeed = 1.f; // How often the player shoots
    float powerupTime = 0.f; // To track how long the powerup has been active
    bool invul = false; // To check if the player is invulnerable (used after getting hit for a brief moment)
    float invulTime = 0.f; // To track how long the player has been invulnerable

    bool powerup = false; // Check if powerup is active
    float powerupCD = 20.f; // Cooldown of the powerup so its not spammed
    float powerupCDTim = 0.f; // Check how long the powerup has been on cooldown
    float powerupLength = 10.f; // To set powerup time to later

    float aoeCD = 10.f; // AOE Attack cooldown and timer to keep track
    float aoeCDTim = 0.f;

    Player(float _posX, float _posY, std::string filepath, int _health, int _speed, int _damage);

    int findNearestEnemyIndex(Melee** enemies, Ranged** renemies, bool& pickRanged);

    bool alreadyPicked(Character* c, Character** charList, int arrSize);

    int findTopNMaxHealth(Melee** enemies, int mCount, Ranged** renemies, int rCount, Character** charList, int N);

    void activatePowerup();

    void takeDamage(int dmg);

    void draw(GamesEngineeringBase::Window& canvas, Camera& cam);

    void updateBullets(float dt, GamesEngineeringBase::Window& canvas, Camera& cam);

    void castAOE(Melee** enemies, Ranged** renemies, int baseN, Camera& cam, GamesEngineeringBase::Window& canvas);

    void autoAttack(Melee** enemies, Ranged** renemies);

    void checkBulletEnemyCollision(Melee** enemies, Ranged** ranged);

    void update(float dt, int x, int y);
};