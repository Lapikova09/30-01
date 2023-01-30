#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"
#include "brick.h"
struct Brickfield {
	Brick Arr[ROWS][COLUMNS];
};
void brickFieldInit(Brickfield& brickfield)
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			sf::Color color;
			if (i == 0 || i == 1) color = sf::Color::Red;
			else if (i == 2 || i == 3) color = sf::Color{ 255,165,0 };
			else if (i == 4 || i == 5) color = sf::Color::Green;
			else if (i == 6 || i == 7) color = sf::Color::Yellow;
			sf::Vector2f position{ 0 + j * BRICK_WIDTH, 60.f + i * BRICK_HEIGHT };
			brickInit(brickfield.Arr[i][j], color, position);
		}
	}
}

void brickFieldUpdate(Brickfield& brickfield) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			brickUpdate(brickfield.Arr[i][j]);
		}
	}
}

void brickFieldDraw(sf::RenderWindow& window, const Brickfield& brickfield) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			brickDraw(window, brickfield.Arr[i][j]);
		}
	}
}