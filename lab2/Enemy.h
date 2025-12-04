#ifndef LAB2_ENEMY_H
#define LAB2_ENEMY_H
#include <SFML/Graphics.hpp>

enum class enemyType { Stone, Stick };

class Enemy {
private:
    sf::Sprite enemy;
    static int setTexture(const sf::Texture& enemy_texture, sf::Sprite& enemy);
    enemyType type;
public:
    Enemy(enemyType enemy_type, const sf::Texture& enemy_texture);
    void move(float time);
    void draw(sf::RenderWindow& window);
    sf::Sprite getEnemy();
};

#endif //LAB2_ENEMY_H