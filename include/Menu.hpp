#pragma once
#include "Libs.hpp"

class Button {
    public:
        Button(std::string lable, float sizeX, float sizeY, float x, float y, bool canActivate);
        bool isSelected(sf::Vector2i vector);
        sf::Text getText();
        void setOnScene(bool onScene);
        sf::RectangleShape spriteButton;

    private:
        sf::SoundBuffer bufferSound;
        sf::Texture texture;
        sf::Sound sound;
        sf::Font font;
        sf::Text text;
        bool onScene;
        float x;
        float y;
};


class Entry{
    public:
        Entry(float sizeX, float sizeY, float x, float y, bool onScene);
        bool isSelected(sf::Vector2i vector);
        sf::Text getText();
        void setText(char text);
        void setOnScene(bool onScene);
        bool getCheckKeyboard();
        void setCheckKeyboard(bool checkKeyboard);
        void BackSpaceText();
        sf::RectangleShape spriteEntry;

    private:
        sf::SoundBuffer bufferSound;
        sf::Sound sound;
        sf::Font font;
        sf::Text text;
        bool checkKeyboard;
        bool onScene;
        float x;
        float y;
};