#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>

int const screen_width = 1000;
int const screen_height = 1000;

int const vector_lenght = screen_height / 2;
int const vector_one_item_size = screen_width / vector_lenght;

int const sort_count = 3;
int const shuffle_count = 5;

sf::Color const text_color1 = sf::Color::Color(0, 152, 121);
sf::Color const text_color2 = sf::Color::Color(0, 152, 71);

sf::Color const sort_color = sf::Color::Color(0, 152, 121);
sf::Color const background_color = sf::Color::White;

sf::Color const main_column_color = sf::Color::Color(255, 78, 0);
sf::Color const sub_column_color = sf::Color::Color(255, 191, 0);

sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "Sort visualization");

sf::Time long_sleep = sf::seconds(2);
sf::Time short_sleep = sf::seconds(0.1);

int faster = vector_lenght / 10;
bool draw = true;

struct Shuffle
{
	int times_shuffling, type_of_shuffle;
	int data_for_shuffle[5];
};
