#include "header.hpp"





int main() {
	RenderWindow window(VideoMode(windowWidth, windowHight), "color invertor ");
	RectangleShape MyRectangle;
	Texture txt1;
	Image image;
	txt1.loadFromFile("ressource/image.png");
	MyRectangle.setSize(size);
	MyRectangle.setTexture( &txt1 , true);
	image.loadFromFile("ressource/image.png");
	for (int i = 0; i < image.getSize().x ; i++) {
		for (int j = 0; j < image.getSize().y ; j++) {
			image.setPixel(i, j, Color(255 - image.getPixel(i, j).r, 255 - image.getPixel(i, j).g, 255 - image.getPixel(i, j).b));
		}
	}
	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyPressed) {
				if (event.key.code == Keyboard::S) {
					txt1.update(image);
					MyRectangle.setTexture(&txt1, true);
				}
			}
		}
		window.clear(Color::White);
		window.draw(MyRectangle);
		window.display();
	}

}