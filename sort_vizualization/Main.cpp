#include "Menu.hpp"
#include "ShuffleAlgorithms.hpp"


#include <iostream>
// ---------------- const values
int main();
int const screen_width = 1000;
int const screen_height = 1000;

int const vector_lenght = screen_height / 2;
float const vector_one_item_size = screen_width / vector_lenght;

int const faster_const = vector_lenght / 50;

int faster;
int const max_speed = vector_lenght;
bool draw = true;

sf::RenderWindow window(sf::VideoMode(screen_width, screen_height), "Sort visualization");

sf::Time long_sleep = sf::seconds(2);
sf::Time short_sleep = sf::seconds(0.1);

ArrayDrawer drawer(screen_width, screen_height, vector_one_item_size, max_speed);
Menu menu(screen_width, screen_height);

bool key_press_for_visualizer(int draw) {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				drawer.set_sort_name("");
				main();
				exit(1);
				
			}
			if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D)
			{
				if (draw == true) {
					faster = faster_const;
				} else if (faster < max_speed) {
					faster += faster_const;
				}
				drawer.set_speed(faster);
				return false;
			}
			if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A)
			{
				if (faster != faster_const) {
					faster = faster_const;
				}
				drawer.set_speed(1);
				return true;
			}
		}
	}
	return draw * 1;
}

void drawing(std::vector<int> *array, int i, int first_column, int second_column) {
	draw = key_press_for_visualizer(draw);
	if (draw || i % faster == 0) {
		drawer.draw_array(window, *array, first_column, second_column, 1);
	}
}

// ---------------- main func 
void sort_visualization(){
	std::vector<std::string> sort_order = menu.get_sort_table();
	
	std::vector<Shuffle> shuffle_order = { generate_shuffle(true) };
	for (int i = 1; i < sort_order.size(); i++) {
		shuffle_order.push_back(generate_shuffle(false));
	}

	std::vector<int> array = menu.get_array();

	draw = true;
	faster = faster_const;
	drawer.set_speed(1);

	for (int i = 0; i < sort_order.size(); i++) {

		drawer.draw_array(window, array, -1, -1, 1);
		sf::sleep(long_sleep);

		drawer.set_sort_name("Shuffle");
		start_shuffle(&array, shuffle_order[i]);
		
		drawer.draw_array(window, array, -1, -1, 1);
		sf::sleep(long_sleep);

		draw = true;
		faster = faster_const;
		drawer.set_speed(1);

		drawer.set_sort_name(sort_order[i] + " sort");
		start_right_sort(&array, sort_order[i]);

		drawer.draw_array(window, array, -1, -1, 1);
		sf::sleep(long_sleep);
	}	
	sf::sleep(long_sleep);
}

int main()
{
	srand(time(NULL));

	while (true) {
		drawer.set_choice(menu.start(window));

		std::vector<sf::Color> colors = menu.get_colors();
		drawer.set_colors(colors[0], colors[2], colors[3], colors[4]);

		sort_visualization();
	}

    return 0;
}
