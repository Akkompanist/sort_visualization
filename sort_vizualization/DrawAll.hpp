#ifndef DRAWALL_HPP_INCLUDED
#define DRAWALL_HPP_INCLUDED
#include <SFML/Graphics.hpp>

class Window {
private:
	int size_of_screen;

public:
	Window(int size_of_screen);
	void draw();
};
#endif