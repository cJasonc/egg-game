#include "stdafx.h"

int YOUKILLEDTHATMONKEY() {
	sf::RenderWindow main_window(sf::VideoMode(1280, 720), "egg monkey game YOU WON MY LITTLE POOKIE BEAR I SOOO LUV YOU <3 UwU <3");
	main_window.setFramerateLimit(60);

	sf::Texture textureBackground;
	textureBackground.loadFromFile("textures/monkey_ded .png");

	sf::Sprite background;
	background.setTexture(textureBackground);
	background.setPosition(180, 80);

	sf::Font verdana;

	verdana.loadFromFile("C:\\Users\\Kajus\\Desktop\\BeuhDev\\BeuhDev\\fonts\\verdana.ttf");

	sf::Text egg_is_a_dick;

	egg_is_a_dick.setFont(verdana);
	egg_is_a_dick.setString("You ass-erted dominance over the kfc munchin, banana liking, watermelon slurping EGG monkey");

	sf::Text egg_is_a_dick2;

	egg_is_a_dick2.setFont(verdana);
	egg_is_a_dick2.setScale(1, 1);
	egg_is_a_dick2.setString("Credits: Killer Bea, mee :) EGG TOO and ty cazz for let me do this (never asdked tbh)");
	egg_is_a_dick2.setPosition(5, 650);

	while (main_window.isOpen()) {

		sf::Event event2;
		while (main_window.pollEvent(event2)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				main_window.close();

			if (event2.type == sf::Event::Closed)
				main_window.close();
		}

		main_window.clear();
		main_window.draw(background);
		main_window.draw(egg_is_a_dick);
		main_window.draw(egg_is_a_dick2);
		main_window.display();
	}

	return 0;
}

int shoot_the_monkey() {
	sf::RenderWindow main_window(sf::VideoMode(1280, 720), "egg monkey game || SHOOT HIM, SHOOOOT HIM");
	main_window.setFramerateLimit(60);

	sf::Music music;
	if (!music.openFromFile("songs/1.wav"))
		return -1; // error

	music.play();

	sf::Texture textureBackground;
	textureBackground.loadFromFile("textures/monkey_alive.jpg");

	sf::Sprite background2;
	background2.setTexture(textureBackground);
	background2.setPosition(180, 80);

	sf::Font verdana;

	verdana.loadFromFile("C:\\Users\\Kajus\\Desktop\\BeuhDev\\BeuhDev\\fonts\\verdana.ttf");

	sf::Text egg_is_a_dick;

	egg_is_a_dick.setFont(verdana);
	egg_is_a_dick.setString("EGG is a monkey || Press Space to shoot that filthy egg monkey...");


	while (main_window.isOpen()) {

		sf::Event event2;
		while (main_window.pollEvent(event2)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				main_window.close();

			if (event2.type == sf::Event::Closed)
				main_window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				main_window.close();
				YOUKILLEDTHATMONKEY();
			}
		}

		main_window.clear();
		main_window.draw(background2);
		main_window.draw(egg_is_a_dick);
		main_window.display();
	}

	return 0;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "egg monkey game");
	window.setFramerateLimit(60);

	sf::Music music;
	if (!music.openFromFile("songs/2.wav"))
		return -1; // error

	music.play();

	sf::Texture eggmonkey;

	eggmonkey.loadFromFile("textures/eggmoneky.png");

	sf::Sprite eggmonkey_superior;
	eggmonkey_superior.setTexture(eggmonkey);
	eggmonkey_superior.setPosition(20, 230);

	sf::Texture startmonkey;
	startmonkey.loadFromFile("textures/start-monkey-life.png");
	sf::Sprite eggmonkeystart;
	eggmonkeystart.setTexture(startmonkey);
	eggmonkeystart.setPosition(1000, 10);



	sf::Texture textureBackground;
	textureBackground.loadFromFile("textures/Untitled.png");

	sf::Sprite background;
	background.setTexture(textureBackground);
	background.setPosition(240, 80);
	background.setScale(sf::Vector2f(2, 2));

	sf::Font verdana;

	verdana.loadFromFile("C:\\Users\\Kajus\\Desktop\\BeuhDev\\BeuhDev\\fonts\\verdana.ttf");

	sf::Text egg_is_a_dick;

	egg_is_a_dick.setFont(verdana);
	egg_is_a_dick.setString("EGG is a monkey || Press Enter to find that -1 chromosome egg monkey eating watermelon n kfc thing...");


	sf::RectangleShape rect;
	sf::Vector2f rectanglePosition(600, 350);
	rect.setPosition(rectanglePosition);
	rect.setSize(sf::Vector2f(100, 100));
	float xVelocity = 8;
	float yVelocity = 8;


	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
				music.stop();
				window.close();
				shoot_the_monkey();
			}
		}
		// physics
		if (rectanglePosition.x < 0 || rectanglePosition.x > 1280 - 100)
			xVelocity *= -1;

		if (rectanglePosition.y < 0 || rectanglePosition.y > 720 - 100)
			yVelocity *= -1;

		rectanglePosition.x += xVelocity;
		rectanglePosition.y += yVelocity;
		rect.setPosition(rectanglePosition);

		// render
		window.clear();
		window.draw(background);
		window.draw(eggmonkey_superior);
		window.draw(eggmonkeystart);
		window.draw(rect);
		window.draw(egg_is_a_dick);
		window.display();
	}

	return 0;
}