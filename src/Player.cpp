#include "../include/Player.hpp"

Player::Player(float sizeX, float sizeY, float x, float y, std::string img, int id) {
    this->id = id;
    spritePlayer.setSize(sf::Vector2f(sizeX, sizeY));
    spritePlayer.setPosition(x, y);
    if(!texture.loadFromFile("assets/Player/Texture/" + img)) {
        std::cerr << "error to load texture for player, please check your assets" << '\n';
    }
    spritePlayer.setTexture(&texture);
    std::cout << "a player has been generated." << std::endl;
}

void Player::move() {
    if(id == 0) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y + 4.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y - 4.0f);
        }
    }
    if (id == 1) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y + 4.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y - 4.0f);
        }
    }
}

void Player::colition(float height) {
    if(spritePlayer.getPosition().y < 0) {
        spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y + 4.0f);
    }
    if(spritePlayer.getPosition().y > height - 250) {
        spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y - 4.0f);
    }
}