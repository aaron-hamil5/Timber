#include "include/SFML/Graphics.hpp"

int main() 
{
	#pragma region Creating the window
	//Create a window at resolution 1920 by 1080 
	sf::VideoMode vm(1920, 1080);
	//Call the resolution and name of the title bar and make it full screen 
	sf::RenderWindow window(vm, "Timber", sf::Style::Fullscreen);
	#pragma endregion

	#pragma region Loading Textures

	#pragma region Background

	#pragma region Load Background Image
	/*Create a texture to hold the background*/
	sf::Texture bacGroTex;
	/*Link the image to the texture background*/
	bacGroTex.loadFromFile("assets/graphics/background.png");
	#pragma endregion

	#pragma region Load Sprite for background
	/*Creating a sprite to display the background*/
	sf::Sprite bacGroSpr;
	/*Linking the sprite to the texture*/
	bacGroSpr.setTexture(bacGroTex);
	#pragma endregion

	#pragma region Location of Sprite
	/*Seeing the location of the sprite(0,0)*/
	bacGroSpr.setPosition(0, 0);
	#pragma endregion

	#pragma endregion

	#pragma region Tree

	#pragma region Load Tree Image
	/*Create a texture to hold the Tree*/
	sf::Texture treeTex;
	/*Link the image to the texture Tree*/
	treeTex.loadFromFile("assets/graphics/tree.png");
	#pragma endregion

	#pragma region Load Sprite for Tree
	/*Creating a sprite to display the background*/
	sf::Sprite treeSpr;
	/*Linking the sprite to the texture*/
	treeSpr.setTexture(treeTex);
	#pragma endregion

	#pragma region Location of Sprite
	/*Seeing the location of the sprite(810,0)*/
	treeSpr.setPosition(810, 0);
	#pragma endregion

	#pragma endregion

	#pragma region Bee

	#pragma region Load Bee Image
	/*Create a texture to hold the Bee*/
	sf::Texture beeTex;
	/*Link the image to the texture Bee*/
	beeTex.loadFromFile("assets/graphics/bee.png");
	#pragma endregion

	#pragma region Load Sprite for Bee
	/*Creating a sprite to display the Bee*/
	sf::Sprite beeSpr;
	/*Linking the sprite to the texture*/
	beeSpr.setTexture(beeTex);
	#pragma endregion

	#pragma region Location of Sprite
	/*Seeing the location of the sprite(250,100)*/
	beeSpr.setPosition(250, 100);
	#pragma endregion

	#pragma endregion

	#pragma region Clouds

	#pragma region Cloud1

	#pragma region Load Cloud Image
	/*Create a texture to hold the Cloud*/
	sf::Texture clo1Tex;
	/*Link the image to the texture Cloud*/
	clo1Tex.loadFromFile("assets/graphics/cloud.png");
	#pragma endregion

	#pragma region Load Sprite for Cloud
	/*Creating a sprite to display the Cloud*/
	sf::Sprite clo1Spr;
	/*Linking the sprite to the texture*/
	clo1Spr.setTexture(clo1Tex);
	#pragma endregion

	#pragma region Location of Sprite
	/*Seeing the location of the sprite*/
	clo1Spr.setPosition(65, 25);
	#pragma endregion
	#pragma endregion

	#pragma region Cloud2
	#pragma region Load Sprite for Cloud
	/*Creating a sprite to display the Cloud*/
	sf::Sprite clo2Spr;
	/*Linking the sprite to the texture*/
	clo2Spr.setTexture(clo1Tex);
	#pragma endregion

	#pragma region Location of Sprite
	/*Seeing the location of the sprite*/
	clo2Spr.setPosition(198, 156);
	#pragma endregion
	#pragma endregion

	#pragma region Cloud3

	#pragma region Load Sprite for Cloud
	/*Creating a sprite to display the Cloud*/
	sf::Sprite clo3Spr;
	/*Linking the sprite to the texture*/
	clo3Spr.setTexture(clo1Tex);
	#pragma endregion

	#pragma region Location of Sprite
	/*Seeing the location of the sprite*/
	clo3Spr.setPosition(1680, 35);
	#pragma endregion
	#pragma endregion

	#pragma endregion

	#pragma endregion

	#pragma region Object Movement

	#pragma region Object speed
	/*Creating the variables to hold the cloud movement speed*/
	float clo1Spe = 0.0f;
	float clo2Spe = 0.0f;
	float clo3Spe = 0.0f;
	int beeSpe = 0;
	#pragma endregion

	#pragma region Control Time
	/*Creating a variable to control Time*/
	sf::Clock clock;
	#pragma endregion

	/*Lanch the bee/cloud not moving so it Initializes on start*/
	bool beeActive = false;
	bool clo1Active = false;
	bool clo2Active = false;
	bool clo3Active = false;
	

	#pragma endregion

	#pragma region While Window Is Open
	while (window.isOpen()) 
	{
		#pragma region Closing Window
		//Detect if the user had hit esc and quit program
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			/*Close the window*/
			window.close();
		}
		#pragma endregion

		#pragma region Effecting the scene
		/*Update the scene*/
		//Measure Time
		sf::Time deltaTime = clock.restart();

		#pragma region Bee Movement

		/*Adding movement to bee*/
		if (!beeActive) 
		{
			//Creating Random speed
			srand((int)time(0));
			beeSpe = (rand() % 200) + 200;

			srand((int)time(0));
			float beeheigt = (rand() % 500) + 500;
			beeSpr.setPosition(2000, beeheigt);

			beeActive = true;
		}
		else {
			/*Adding the movement to the bee*/
			beeSpr.setPosition(beeSpr.getPosition().x - (beeSpe * deltaTime.asSeconds()), beeSpr.getPosition().y);
			/*Edge Remove*/
			if (beeSpr.getPosition().x < -100) {
				beeActive = false;
			}
		}

		#pragma endregion

		#pragma region Cloud One Movement

		/*Adding movement to cloud*/
		if (!clo1Active)
		{
			//Creating Random speed
			srand((int)time(0));
			clo1Spe= (rand() % 200) + 200;

			srand((int)time(0));
			float clo1height = (rand() % 250) + 10;
			clo1Spr.setPosition(2000, clo1height);


			clo1Active = true;
		}
		else {
			/*Adding the movement to the bee*/
			clo1Spr.setPosition(clo1Spr.getPosition().x - (clo1Spe * deltaTime.asSeconds()), clo1Spr.getPosition().y);
			/*Edge Remove*/
			if (clo1Spr.getPosition().x < -100) {
				clo1Active = false;
			}
		}

		#pragma endregion
		#pragma region Cloud Two Movement

		/*Adding movement to cloud*/
		if (!clo2Active)
		{
			//Creating Random speed
			srand((int)time(0));
			clo2Spe = (rand() % 200) + 200;

			srand((int)time(0));
			float clo2height = (rand() % 350) + 10;
			clo2Spr.setPosition(2000, clo2height);


			clo2Active = true;
		}
		else {
			/*Adding the movement to the bee*/
			clo2Spr.setPosition(clo2Spr.getPosition().x - (clo2Spe * deltaTime.asSeconds()), clo2Spr.getPosition().y);
			/*Edge Remove*/
			if (clo2Spr.getPosition().x < -100) {
				clo2Active = false;
			}
		}

		#pragma endregion
		#pragma region Cloud Three Movement

		/*Adding movement to cloud*/
		if (!clo3Active)
		{
			//Creating Random speed
			srand((int)time(0));
			clo3Spe = (rand() % 200) + 200;

			srand((int)time(0));
			float clo3height = (rand() % 350) + 10;
			clo3Spr.setPosition(2000, clo3height);


			clo3Active = true;
		}
		else {
			/*Adding the movement to the bee*/
			clo3Spr.setPosition(clo3Spr.getPosition().x - (clo3Spe * deltaTime.asSeconds()), clo3Spr.getPosition().y);
			/*Edge Remove*/
			if (clo3Spr.getPosition().x < -100) {
				clo3Active = false;
			}
		}

		#pragma endregion

		/*Clear the scene*/
		window.clear();

		#pragma region Drawing the Scene
		/*Draw the scene*/
		window.draw(bacGroSpr); //Background
		#pragma region draw Clouds
		window.draw(clo1Spr);
		window.draw(clo2Spr);
		window.draw(clo3Spr);
		#pragma endregion				//Clouds
		window.draw(treeSpr);	//Tree
		window.draw(beeSpr);	//Bee
		#pragma endregion

		/*Render the scene*/
		window.display();
		#pragma endregion
	}
#pragma endregion

	//Return 0 will tell the program nothing bad happened and can end
	return 0;
}