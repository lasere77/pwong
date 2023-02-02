#pragma once
#include "Libs.hpp"

class Player {
    public:
        Player(float sizeX, float sizeY, float x, float y, std::string img, int id);
        sf::RectangleShape spritePlayer;
        void colition(float height);
        void bot(float posBallY); 
        void move();
        float getSpeed();
        void setSpeed(float _speed);

    private:
        sf::Texture texture;
        float speed;
        int id;
        
};