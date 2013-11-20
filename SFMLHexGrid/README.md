This class allows you to simply create an hexagonal grid. Just invoke it's constructor like such:

HexGrid name(nofhexup,nofhexside,radiusofhex,colorofhex);

then inside the game loop use draw(sf::RenderWindow &App) to draw it, as such:

name.draw(renderwindow);
