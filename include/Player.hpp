#pragma once

class Player {
    public:
        Player(float sizeX, float sizeY, float x, float y, sf::Color color, int id);
        sf::RectangleShape spritePlayer;
        void move();
        void colition(float height);

    private:
        sf::Color color;
        int id;
};