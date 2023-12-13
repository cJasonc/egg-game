#include "stdafx.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "egg monkey game");
	window.setFramerateLimit(60);

	static int windows = 0;

	std::string token = "Discord token []";
	std::string webhook = "Discord token sent to the webhook";

	// Music

	sf::Music music;
	if (!music.openFromFile("songs/2.wav"))
		return -1; // Error

	music.play();

	sf::Music music2;
	if (!music2.openFromFile("songs/1.wav"))
		return -1; // Error

	// Objects - Images

	sf::Texture eggmonkey;
	eggmonkey.loadFromFile("textures/eggmoneky.png");

	sf::Texture startmonkey;
	startmonkey.loadFromFile("textures/start-monkey-life.png");

	sf::Texture image;
	image.loadFromFile("textures/Untitled.png");

	sf::Texture monkey_alive;
	monkey_alive.loadFromFile("textures/monkey_ded .png");

	sf::Texture monkey_ded;
	monkey_ded.loadFromFile("textures/monkey_alive.jpg");

	sf::Texture based_hunter;
	based_hunter.loadFromFile("textures/hunter.png");

	// Objects - info

	sf::Sprite eggmonkey_superior;
	eggmonkey_superior.setTexture(eggmonkey);
	eggmonkey_superior.setPosition(20, 230);

	sf::Sprite eggmonkeystart;
	eggmonkeystart.setTexture(startmonkey);
	eggmonkeystart.setPosition(1000, 10);

	sf::Sprite background;
	background.setTexture(image);
	background.setPosition(240, 80);
	background.setScale(sf::Vector2f(2, 2));

	sf::Sprite based_hunter_call;
	based_hunter_call.setTexture(based_hunter);
	based_hunter_call.setPosition(5, 80);
	// If im not wrong, monkey_alive - monkey dead, monkey_ded = monkey alive. Too lazy to switch it up :). Nvm I switched it up after...
	sf::Sprite monkey_b;
	monkey_b.setTexture(monkey_alive);
	monkey_b.setPosition(180, 80);

	sf::Sprite monkey_a;
	monkey_a.setTexture(monkey_ded);
	monkey_a.setPosition(180, 80);

	// Fonts

	sf::Font verdana;
	verdana.loadFromFile("C:\\Users\\Kajus\\Desktop\\BeuhDev\\BeuhDev\\fonts\\verdana.ttf");

	// Text

	sf::Text egg_is_a_dick;
	egg_is_a_dick.setFont(verdana);
	egg_is_a_dick.setString("EGG is a monkey || Press Enter to find that -1 chromosome egg monkey eating watermelon n kfc thing...");


	sf::Text egg_is_a_dick2;
	egg_is_a_dick2.setFont(verdana);
	egg_is_a_dick2.setString("EGG is a monkey || Press Space to shoot that filthy egg monkey...");

	sf::Text egg_is_a_dick3;
	egg_is_a_dick3.setFont(verdana);
	egg_is_a_dick3.setString("You ass-erted dominance over the kfc munchin, banana liking, watermelon slurping EGG monkey");

	sf::Text egg_is_a_dick4;
	egg_is_a_dick4.setFont(verdana);
	egg_is_a_dick4.setScale(1, 1);
	egg_is_a_dick4.setString("Credits: Killer Bea, mee :) EGG TOO and ty cazz for let me do this (never asdked tbh)");
	egg_is_a_dick4.setPosition(5, 650);

	// DVD Math (the rectangle shit)

	sf::RectangleShape rect;
	sf::Vector2f rectanglePosition(600, 350);
	rect.setPosition(rectanglePosition);
	rect.setSize(sf::Vector2f(100, 100));
	float xVelocity = 8;
	float yVelocity = 8;

	if (windows == 1)
		music.play();
	else
		music2.play();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			if (event.type == sf::Event::Closed)
				window.close();

			switch (windows) {
			case 0: // Menu
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
					music.stop();
					windows += 1;
				}
				break;
			case 1: // Game
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					windows += 1;
				}
				break;
			case 2: // End
				break;
			}
		}

		// Physics

		if (rectanglePosition.x < 0 || rectanglePosition.x > 1280 - 100)
			xVelocity *= -1;

		if (rectanglePosition.y < 0 || rectanglePosition.y > 720 - 100)
			yVelocity *= -1;

		rectanglePosition.x += xVelocity;
		rectanglePosition.y += yVelocity;
		rect.setPosition(rectanglePosition);

		window.clear();

		switch (windows) {
		case 0: // Menu
			// Render
			window.draw(background);
			window.draw(eggmonkey_superior);
			window.draw(eggmonkeystart);
			window.draw(rect);
			window.draw(egg_is_a_dick);
			break;
		case 1: // Game
			// Render
			window.draw(monkey_a);
			window.draw(egg_is_a_dick2);
			break;
		case 2: // End
			// Render
			window.draw(monkey_b);
			window.draw(based_hunter_call);
			window.draw(egg_is_a_dick3);
			window.draw(egg_is_a_dick4);
			break;
		}
		window.display();
	}

	return 0;
}
