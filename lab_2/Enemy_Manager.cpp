#include "Enemy_Manager.h"

void Enemy_Manager::create_Enemy(enemyType type, const sf::Texture& enemy_texture){
        Enemy unit(type,enemy_texture);
        enemy_list.emplace_back(unit);
}
void Enemy_Manager::move_enemies(float time){
    for(auto& enemy: enemy_list){
        enemy.move(time);
    }
}
void Enemy_Manager::draw_enemies(sf::RenderWindow& window){
    for(auto& enemy: enemy_list){
        enemy.draw(window);
    }
}
bool Enemy_Manager::check_collission(Player player){
    for (auto& enemy : enemy_list) {
        if (player.checkCollision(enemy.getEnemy())) {
            std::cout << "Collision detected!" << std::endl;
            return true;
        }
    }
    return false;
}
