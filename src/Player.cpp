#include "../include/Player.hpp"

Player::Player(float sizeX, float sizeY, float x, float y, std::string img, int id) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;
    this->id = id;
    this->speed = 4.0f;
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
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y + speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y - speed);
        }
    }
    if (id == 1) {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y + speed);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
            spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y - speed);
        }
    }
}

void Player::colition(float height) {
    if(spritePlayer.getPosition().y < 0) {
        spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y + speed);
    }
    if(spritePlayer.getPosition().y > height - sizeY) {
        spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y - speed);
    }
}

void Player::bot(float posBallY) {
    bool orgineBotFailDir = botFailDir;
    if(spritePlayer.getPosition().y - botFail - sizeY / 2 > posBallY) {
        spritePlayer.setPosition(spritePlayer.getPosition().x,spritePlayer.getPosition().y - speed);
        botFailDir = 1;
    }else if(spritePlayer.getPosition().y + botFail + sizeY / 2 < posBallY) {
        spritePlayer.setPosition(spritePlayer.getPosition().x, spritePlayer.getPosition().y + speed);
        botFailDir = 0;
    }else {
        spritePlayer.setPosition(spritePlayer.getPosition().x,spritePlayer.getPosition().y);
    }
    if(botFailDir != orgineBotFailDir) {
        botFail = rand() % 11;
        std::cout << botFail << std::endl;
    }
}


void Player::changeSize(float _sizeY) {
    this->sizeY = _sizeY;
    spritePlayer.setSize(sf::Vector2(sizeX, sizeY));
}

float Player::getSpeed() {
    return speed;
}
void Player::setSpeed(float _speed) {
    if(_speed > 16){
        _speed = 16;
    }
    speed = _speed;
}