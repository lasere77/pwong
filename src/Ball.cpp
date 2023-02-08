#include "../include/Ball.hpp"

int setRngOnColition();

bool up = false;
bool down = true;
bool right = true;
bool left = false;

Ball::Ball(float speed, float x, float y) {
    std::cout << "a ball has been generated." << std::endl; 
    this->speed = speed;
    this->rngSpeed = speed;
    spriteBall.setRadius(5.0f);
    spriteBall.setPosition(x, y);
    if(!texture.loadFromFile("assets/Ball/Texture/Ball.jpg") || !bufferSound.loadFromFile("assets/Ball/Sound/onColition.wav")) {
        std::cerr << "error to load texture for ball or sound, please check your assets" << '\n';
    }
    sound.setBuffer(bufferSound);
    spriteBall.setTexture(&texture);
}

void Ball::move() {
    if(down) {
        spriteBall.setPosition(spriteBall.getPosition().x, spriteBall.getPosition().y + speed);
    }
    if(up) {
        spriteBall.setPosition(spriteBall.getPosition().x, spriteBall.getPosition().y - speed);
    }
    if(left) {
        spriteBall.setPosition(spriteBall.getPosition().x - rngSpeed - (speed / 2), spriteBall.getPosition().y);
    }
    if(right) {
        spriteBall.setPosition(spriteBall.getPosition().x + rngSpeed + (speed / 2), spriteBall.getPosition().y);
    }

    //debug
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        std::cout << "up {" << up << "}" << std::endl;
        std::cout << "down {" << down << "}" << std::endl;
        std::cout << "left {" << left << "}" << std::endl;
        std::cout << "right {" << right << "}" << std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        spriteBall.setPosition(540.0f, 360.0f);
    }
}


void Ball::colition(sf::RectangleShape player1, sf::RectangleShape player2, float height) {
    //border colition    
    if(spriteBall.getPosition().y <= 0) {
        up = false;
        down = true;
        std::cout << "colition" << std::endl;
        rngSpeed = setRngOnColition();
        sound.play();
    }
    if(spriteBall.getPosition().y >= height) {
        up = true;
        down = false;
        std::cout << "colition" << std::endl;
        rngSpeed = setRngOnColition();
        sound.play();
    }
    //player colition
    if(spriteBall.getPosition().y >= player2.getPosition().y && spriteBall.getPosition().y <= player2.getPosition().y + player2.getSize().y && spriteBall.getPosition().x >= player2.getPosition().x && spriteBall.getPosition().x <= player2.getPosition().x + 20) {
        left = false;
        right = true;
        std::cout << "colition" << std::endl;
        rngSpeed = setRngOnColition();
        sound.play();
    }
    if(spriteBall.getPosition().y >= player1.getPosition().y && spriteBall.getPosition().y <= player1.getPosition().y + player1.getSize().y && spriteBall.getPosition().x >= player1.getPosition().x - 20 && spriteBall.getPosition().x <= player1.getPosition().x) {
        left = true;
        right = false;
        std::cout << "colition" << std::endl;
        rngSpeed = setRngOnColition();
        sound.play();
    }
 }

float Ball::getSpeed() { 
    return speed;
}
void Ball::setSpeed(int _speed) {
    if(_speed > 16){
        _speed = 16;
    }
    speed = _speed;
}

int setRngOnColition() {
    return rand() % 5;
}