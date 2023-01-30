#pragma once
#include <SFML/Graphics.hpp>
#include "Header.h"
#include "brick.h"
#include "ball.h"
#include "bat.h"
#include "brickrow.h"

bool pointInRect(sf::RectangleShape rect, sf::Vector2f point) {
	return	rect.getPosition().x <= point.x &&
		point.x <= rect.getPosition().x + rect.getSize().x &&
		rect.getPosition().y <= point.y &&
		point.y <= rect.getPosition().y + rect.getSize().y;
}
void ballCollidedWithBricks(Ball& ball, Brickfield& brickfield) {
	sf::Vector2f midLeft{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	sf::Vector2f midTop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y
	};
	sf::Vector2f midBottom{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS
	};
	sf::Vector2f midRight{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS
	};
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {

			if (pointInRect(brickfield.Arr[i][j].shape, midTop) && brickfield.Arr[i][j].color != sf::Color::Black) {
				brickfield.Arr[i][j].color = sf::Color::Black;
				brickfield.Arr[i][j].shape.setFillColor(sf::Color::Black);
				ball.speedY = -ball.speedY;
				break;
			}
			else if (pointInRect(brickfield.Arr[i][j].shape, midLeft) && brickfield.Arr[i][j].color != sf::Color::Black) {
				brickfield.Arr[i][j].color = sf::Color::Black;
				brickfield.Arr[i][j].shape.setFillColor(sf::Color::Black);
				ball.speedX = -ball.speedX;
				break;
			}
			else if (pointInRect(brickfield.Arr[i][j].shape, midRight) && brickfield.Arr[i][j].color != sf::Color::Black) {
				brickfield.Arr[i][j].color = sf::Color::Black;
				brickfield.Arr[i][j].shape.setFillColor(sf::Color::Black);
				ball.speedX = -ball.speedX;
				break;
			}
			else if (pointInRect(brickfield.Arr[i][j].shape, midBottom)) {
				brickfield.Arr[i][j].color = sf::Color::Black;
				brickfield.Arr[i][j].shape.setFillColor(sf::Color::Black);
				ball.speedY = -ball.speedY;
				break;
			}
		}
	}
}
void ballCollidedWithBat(Ball& ball, Bat& bat) {
	sf::Vector2f righttop{ 
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y };
	sf::Vector2f midtop{
		ball.shape.getPosition().x + BALL_RADIUS,
		ball.shape.getPosition().y };
	sf::Vector2f lefttop{ 
		ball.shape.getPosition().x,
		ball.shape.getPosition().y};
	sf::Vector2f rightmid{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + BALL_RADIUS };
	sf::Vector2f leftmid{ 
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + BALL_RADIUS };
	sf::Vector2f rightbottom{
		ball.shape.getPosition().x + 2 * BALL_RADIUS,
		ball.shape.getPosition().y + 2 * BALL_RADIUS };
	sf::Vector2f leftbottom{
		ball.shape.getPosition().x,
		ball.shape.getPosition().y + 2 * BALL_RADIUS };
	if (pointInRect(bat.shape, midtop) && pointInRect(bat.shape, righttop) ||
		pointInRect(bat.shape, midtop) && pointInRect(bat.shape, lefttop)) {
		ball.speedY = -ball.speedY;
	}
	if (pointInRect(bat.shape, lefttop) && pointInRect(bat.shape, leftmid) ||
		pointInRect(bat.shape, leftbottom) && pointInRect(bat.shape, leftmid)) {
		ball.speedX = -ball.speedX;
	}
	if (pointInRect(bat.shape,rightmid) && pointInRect(bat.shape, righttop) ||
		pointInRect(bat.shape, rightmid) && pointInRect(bat.shape,rightbottom)) {
		ball.speedX = -ball.speedX;
	}
	if (pointInRect(bat.shape, rightbottom) || pointInRect(bat.shape, leftbottom)) {
		ball.speedY = -ball.speedY;
	}
}
