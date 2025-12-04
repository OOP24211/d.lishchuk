#include "Player.h"
#include <SFML/Graphics.hpp>
#include "iostream"
#include <vector>

int Player::setTexture(const sf::Texture& dinoTexture, sf::Sprite& player) {
    player.setTexture(dinoTexture);
    return 0;
}

void Player::setPosition(const std::pair<float, float>& Position_Player, sf::Sprite& player) {
    player.setPosition(Position_Player.first, Position_Player.second);
}

Player::Player(const sf::Texture& dinoTexture) {
    std::cerr << setTexture(dinoTexture, player);
    setPosition({100.f, 896.f}, player);
}

void Player::update() {
    if (isJumping) {
        speed_y += gravity;
        player.move(0.f, speed_y);
        if (player.getPosition().y >= 896) {
            isJumping = false;
            speed_y = 0.f;
        }
    }
}

void Player::jump() {
    if (!isJumping) {
        speed_y -= jump_straight;
        player.move(0.f, speed_y);
        isJumping = true;
    }
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(player);
}

bool Player::checkCollision(const sf::Sprite& enemy) {
    return player.getGlobalBounds().intersects(enemy.getGlobalBounds());
}