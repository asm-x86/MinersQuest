#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemies.h"
#include "Map.h"
#include "UI.h"
#include <iostream>

class Game :
	public sf::Drawable
{
private:
	//Developer defined classes
	Player mPlayer;
	Enemies *mEnemies[2];
	Map mMap;
	UI *ui;


	int nrOfEnemies = 2;

	float bottom, left, right, top;
	float temp = mPlayer.getfallSpeed();



	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;


	sf::View view;
	float playerPosViewX;
	float playerPosViewY;
public:
	Game();
	~Game();


	//collision
	void CollisionCheck(Character *obj);
	bool collidesWithGround(Character *obj);
	bool collideLeft(Character *obj, int index);
	bool collideRight(Character *obj, int index);
	bool collideBottom(Character *obj, int index);
	void enemyCollision();

	//update
	void Update(float dt);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	//player related
	float getPlayerPosX() const;
	float getPlayerPosY() const;

	//UI
	UI getUI();
	sf::View getHUD();
	sf::View getView();
	void moveView();

	//Pausing starting etc
	void setPause(bool state);
	bool getPause() const;
	void setStart(bool state);
	bool getStart() const;


	//memorymanagement
	void removeEnemy(int index);

	//saving
	


};
