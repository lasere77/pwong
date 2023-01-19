#include "../include/Ball.hpp"

void colitonActionOnMove(int rng);
int setRngOnColition();

bool up = false;
bool down = true;
bool right = true;
bool left = false;
bool rotateMove = false;

Ball::Ball(float speed, float x, float y) {
    std::cout << "a ball has been generated." << std::endl; 
    this->originalSpeed = speed;
    this->speed = speed;
    this->rngSpeed = speed;
    spriteBall.setRadius(5.0f);
    spriteBall.setPosition(x, y);
    if(!texture.loadFromFile("assets/Ball/Texture/Ball.jpg")) {
        std::cerr << "error to load texture for ball, please check your assets" << '\n';
    }
    spriteBall.setTexture(&texture);
}

void Ball::move() {
    if(rotateMove) {
        if(rngSpeed > 4) {
            while (rngSpeed < 4) {
                speed--;
            }
        }
        if(down) {
            spriteBall.setPosition(spriteBall.getPosition().x, spriteBall.getPosition().y + speed);
        }
        if(up) {
            spriteBall.setPosition(spriteBall.getPosition().x, spriteBall.getPosition().y - speed);
        }
        if(left) {
            spriteBall.setPosition(spriteBall.getPosition().x - rngSpeed, spriteBall.getPosition().y);
        }
        if(right) {
            spriteBall.setPosition(spriteBall.getPosition().x + rngSpeed, spriteBall.getPosition().y);
        }
    }else {
        rngSpeed = setRngOnColition();
        speed = originalSpeed;
        if(down) {
            spriteBall.setPosition(spriteBall.getPosition().x, spriteBall.getPosition().y + speed);
        }
        if(up) {
            spriteBall.setPosition(spriteBall.getPosition().x, spriteBall.getPosition().y - speed);
        }
        if(left) {
            spriteBall.setPosition(spriteBall.getPosition().x - speed, spriteBall.getPosition().y);
        }
        if(right) {
            spriteBall.setPosition(spriteBall.getPosition().x + speed, spriteBall.getPosition().y);
        }
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
    float rng = rand() % 5 + 1;
    if(spriteBall.getPosition().y <= 0) {
        up = false;
        down = true;
        std::cout << "colition" << std::endl;
        colitonActionOnMove(rng);
    }
    if(spriteBall.getPosition().y >= height) {
        up = true;
        down = false;
        std::cout << "colition" << std::endl;
        colitonActionOnMove(rng);
    }
    //player colition
    if(spriteBall.getPosition().y >= player2.getPosition().y && spriteBall.getPosition().y <= player2.getPosition().y + 250 && spriteBall.getPosition().x >= player2.getPosition().x && spriteBall.getPosition().x <= player2.getPosition().x + 20) {
        left = false;
        right = true;
        std::cout << "colition" << std::endl;
        colitonActionOnMove(rng);
    }
    if(spriteBall.getPosition().y >= player1.getPosition().y && spriteBall.getPosition().y <= player1.getPosition().y + 250 && spriteBall.getPosition().x >= player1.getPosition().x - 20 && spriteBall.getPosition().x <= player1.getPosition().x) {
        left = true;
        right = false;
        std::cout << "colition" << std::endl;
        colitonActionOnMove(rng);
    }
 }

int setRngOnColition() {
    srand(time(nullptr));
    return rand() % 8 + 1;
}

void colitonActionOnMove(int rng) {
    if(rng == 5) {
        rotateMove = true;
    }else {
        rotateMove = false;
    }
    setRngOnColition();
}