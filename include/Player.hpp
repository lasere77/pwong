#pragma once
#include "Libs.hpp"

class Player {
    public:
        Player(float sizeX, float sizeY, float x, float y, std::string img, int id);
        sf::RectangleShape spritePlayer;
        void move();
        void colition(float height);
        void bot(float posBallY); 

    private:
        sf::Texture texture;
        int id;
};