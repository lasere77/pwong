#pragma once
#include "Libs.hpp"

class Button {
    public:
        Button(std::string lable, float sizeX, float sizeY, float x, float y);
        bool isSelected(sf::Vector2i vector);
        sf::RectangleShape spriteButton;
        sf::Text text;

    private:
        sf::SoundBuffer bufferSound;
        sf::Texture texture;
        std::string label;
        sf::Sound sound;
        sf::Font font;
        //bool onScene;
        float x;
        float y;
        float sizeX;
        float sizeY;
};