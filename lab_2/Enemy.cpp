#include "Enemy.h"

int Enemy::setTexture(const sf::Texture& enemy_texture, sf::Sprite& enemy) {
    enemy.setTexture(enemy_texture);
    return 0;
}

Enemy::Enemy(enemyType enemy_type, const sf::Texture& enemy_texture) : type(enemy_type) {
    if (type == enemyType::Stone) {
        enemy.setPosition(1920.f, 984.f);
    }
    else {
        enemy.setPosition(1920.f, 790.f);
    }
    setTexture(enemy_texture, enemy);
    enemy.setScale(0.3f, 0.3f);
}

void Enemy::move(float time) {
    enemy.move((-0.5) * time, 0.f);
}

void Enemy::draw(sf::RenderWindow& window) {
    window.draw(enemy);
}

sf::Sprite Enemy::getEnemy() {
    return enemy;
}