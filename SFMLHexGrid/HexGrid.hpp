#ifndef HEXGRID_HPP_
#define HEXGRID_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class HexGrid {
public:

	HexGrid();
	HexGrid(int height, int width, float radius, sf::Color color);
	HexGrid(const HexGrid &grid);
	void draw(sf::RenderWindow &App);
	void setHeight(int height);
	int getHeight();
	void setWidth(int width);
	int getWidth();
	void setRadius(float radius);
	float getRadius();
	void setColor(sf::Color color);
	sf::Color getColor();

private:

	sf::CircleShape hexagon;
	sf::Color defColor;
	int defHeight;
	int defWidth;
	int hexNumber;
	int yRow;
	float defRadius;
	float xPos;
	float yPos;

};

#endif
