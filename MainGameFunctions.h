#pragma once

sf::View setWindowView(sf::RenderWindow& window, float length);

int mainMenuLoop(sf::RenderWindow& window);
int highScoreDisplayLoop(sf::RenderWindow& window);
int gameLoop(sf::RenderWindow& window);
int highScoreLoop(sf::RenderWindow& window, int score);

void resizeEvent(int code, sf::RenderWindow& window, int windowLength);
