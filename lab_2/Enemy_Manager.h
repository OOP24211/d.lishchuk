#ifndef LAB2_ENEMY_MANAGER_H
#define LAB2_ENEMY_MANAGER_H

#include <SFML/Graphics.hpp>
#include "iostream"
#include <vector>
#include <cstdlib>
#include "Player.h"
#include "Enemy.h"

class Enemy_Manager{
private:
    std::vector<Enemy> enemy_list;
public:
    void create_Enemy(enemyType type, const sf::Texture& enemy_texture);
    void move_enemies(float time);
    void draw_enemies(sf::RenderWindow& window);
    bool check_collission(Player player);
};

#endif //LAB2_ENEMY_MANAGER_H
