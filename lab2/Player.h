#ifndef LAB2_PLAYER_H
#define LAB2_PLAYER_H
#include <SFML/Graphics.hpp>
#include "iostream"
#include <vector>
#include <cstdlib>

class Player{
private:
    sf::Sprite player;
    int static setTexture(const sf::Texture& dinoTexture, sf::Sprite& player);
    void static setPosition(const std::pair<float, float>& Position_Player, sf::Sprite& player);
    bool isJumping = false;
    float speed_y = 0.f;
    float gravity = 0.004;
    float jump_straight = 2;

public:
    explicit Player(const sf::Texture& dinoTexture);
    void update();
    void jump();
    void draw(sf::RenderWindow& window);
    bool checkCollision(const sf::Sprite& enemy);
};


#endif //LAB2_PLAYER_H
