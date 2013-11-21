#include "HexGrid.hpp"

HexGrid::HexGrid() : defHeight(0),
defWidth(0),
defRadius(0),
defColor(0,0,0,0),
hexNumber(0),
yRow(1)
{}

HexGrid::HexGrid(int height, int width, float radius, sf::Color color){

	defHeight = height;
	defWidth = width;
	defRadius = radius;
	defColor = color;
	hexNumber = width * height;
	yRow = 1;
}

HexGrid::HexGrid(const HexGrid &grid){
	defHeight = grid.getHeight();
	defWidth = grid.getWidth();
	defRadius = grid.getRadius();
	defColor = grid.getColor();
	hexNumber = defWidth * defHeight;
	yRow = 1;
}

void HexGrid::draw(sf::RenderWindow &App){

	hexagon.setRadius(defRadius);
	hexagon.setPointCount(6);
	hexagon.setFillColor(defColor);
	hexagon.setOutlineThickness(1);
	hexagon.setOutlineColor(sf::Color::Black);

	xPos = hexagon.getRadius();
	yPos = hexagon.getRadius();

	for(int i = 1; i <= hexNumber; ++i){
		
		hexagon.setPosition(xPos, yPos);

		if( i % defWidth == 0 && i != 0 ){
			if (yRow % 2 == 0){
				xPos = hexagon.getRadius();
				yPos += hexagon.getRadius() * 1.55;
			}
			else{
				xPos = sqrt(3) * hexagon.getRadius() + ((hexagon.getRadius() / 10) + 1.3 );
				yPos += hexagon.getRadius() * 1.55;
			}

			++yRow;
		}

		else
			xPos += sqrt(3) * hexagon.getRadius() + 0.5;

		App.draw(hexagon);

	}

}

void HexGrid::setHeight(int height){
	defHeight = height;
	hexNumber = defHeight * defWidth;
}

int HexGrid::getHeight(){
	return defHeight;
}

void HexGrid::setWidth(int width){
	defWidth = width;
	hexNumber = defHeight * defWidth;
}

int HexGrid::getWidth(){
	return defWidth;
}

void HexGrid::setRadius(float radius){
	defRadius = radius;
}

float HexGrid::getRadius(){
	return defRadius;
}

void HexGrid::setColor(sf::Color color){
	defColor = color;
}

sf::Color HexGrid::getColor(){
	return defColor;
}
