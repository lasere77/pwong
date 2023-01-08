#include "../include/Libs.hpp"
#include "../include/Player.hpp"

Player::Player(float sizeX, float sizeY, float x, float y, sf::Color color, int id) {
    this->color = color;
    this->id = id;
    spritePlayer.setSize(sf::Vector2f(sizeX, sizeY));
    spritePlayer.setFillColor(color);
    spritePlayer.setPosition(x, y);
    std::cout << "a player has been generated." << std::endl;
}

void Player::move() {
    if(id == 0) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y + 1.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y - 1.0f);
        }
    }
    if (id == 1) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y + 1.0f);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y - 1.0f);
        }
    }
}

void Player::colition() {
    if(spritePlayer.getPosition().y < 0) {
        spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y + 1.0f);
    }
    if(spritePlayer.getPosition().y > 720 - 250) {
        spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y - 1.0f);
    }
}