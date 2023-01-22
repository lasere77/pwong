#pragma once

#include "Player.hpp"
#include "Ball.hpp"
#include "Menu.hpp"

bool scene0 = false;
bool scene1 = true;
bool scene2 = false;

bool modeSolo = false;

sf::RenderWindow window(sf::VideoMode(0, 0), "copy of pong", sf::Style::Fullscreen);

float width = window.getSize().x;
float height = window.getSize().y;

bool running = false;

int player1Point = -1;
int player2Point = 0;

Ball ball = Ball(4, width, height);

Player player1 = Player(20.0f, 250.0f, (width - 40.f), 100.0f, "player1.jpg", 0);
Player player2 = Player(20.0f, 250.0f, 10.0f, 100.0f, "player2.jpg", 1);

Button btnStart = Button("start", 250.0f, 50.0f, (width / 2 - 125.0f), 280.0f, true);
Button btnSetting = Button("setting", 250.0f, 50.0f, (width / 2 - 125.0f), 360.0f, true);
Button btnExit = Button("exit", 250.0f, 50.0f, (width / 2 - 125.0f), 440.0f, true);

Button btnBack = Button("back", 250.0f, 50.0f, (width / 2 - 125.0f), 360.0f, false);
Button btnSolo = Button("mode solo", 250.0f, 50.0f, (width / 2 - 125.0f), 440.0f, false);