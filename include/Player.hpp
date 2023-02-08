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
        void changeSize(float);

    private:
        sf::Texture texture;
        float speed;
        float sizeX;
        float sizeY;
        bool botFailDir;
        int botFail;
        int id;
        
};