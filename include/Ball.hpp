#pragma once
#include "Libs.hpp"

class Ball {
    public:
        Ball(float speed, float x, float y);
        void colition(sf::RectangleShape player1, sf::RectangleShape player2, float height);
        void move();
        sf::CircleShape spriteBall;
        float getSpeed();
        void setSpeed(int _speed);

    private:
        sf::SoundBuffer bufferSound;
        sf::Texture texture;
        sf::Sound sound;
        float speed;
        float rngSpeed;
};