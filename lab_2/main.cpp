#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Player.h"
#include "Enemy.h"
#include "Enemy_Manager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Simple Game");

    sf::Texture dinoTexture, en1Texture, en2Texture;
    if(!dinoTexture.loadFromFile("player.png")) {
        return -1;
    }
    if(!en1Texture.loadFromFile("en1.png")) {
        return -1;
    }
    if(!en2Texture.loadFromFile("en2.png")) {
        return -1;
    }
    Player player(dinoTexture);
    Enemy_Manager enemy_manager;
    sf::Clock clock;
    float timeSinceLastSpawn = 0.f;

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            player.jump();
        }
        player.update();

        enemy_manager.move_enemies(1.f + (clock.getElapsedTime().asSeconds()*0.05));


        if((clock.getElapsedTime().asSeconds() - timeSinceLastSpawn) > 2){
            if(rand()%2){
                enemy_manager.create_Enemy(enemyType::Stone, en2Texture);
            }
            else{
                enemy_manager.create_Enemy(enemyType::Stick, en1Texture);
            }
            timeSinceLastSpawn = clock.getElapsedTime().asSeconds();
        }

        window.clear();
        enemy_manager.draw_enemies(window);
        player.draw(window);
        if(enemy_manager.check_collission(player)){
            return 0;
        }
        window.display();
    }

    return 0;
}
