#pragma once
#include "Libs.hpp"

class Button {
    public:
        Button(std::string lable, float sizeX, float sizeY, float x, float y, bool canActivate);
        bool isSelected(sf::Vector2i vector);
        void setOnScene(bool onScene);
        bool getOnScene();
        bool getIsTick();
        sf::RectangleShape spriteButton;
        sf::Text text;


    private:
        sf::SoundBuffer bufferSound;
        sf::Texture texture;
        std::string label;
        sf::Sound sound;
        sf::Font font;
        bool onScene;
        float x;
        float y;
        float sizeX;
        float sizeY;
};