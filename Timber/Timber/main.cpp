#include "include/SFML/Graphics.hpp"

int main() 
{
	#pragma region Creating the window
	//Create a window at resolution 1920 by 1080 
	sf::VideoMode vm(1920, 1080);
	//Call the resolution and name of the title bar and make it full screen 
	sf::RenderWindow window(vm, "Timber", sf::Style::Fullscreen);
	#pragma endregion


	#pragma region Load Background Image
	/*Create a texture to hold the background*/
	sf::Texture bacGroTex;
	/*Link the image to the texture background*/
	bacGroTex.loadFromFile("assets/graphics/background.png");
	#pragma endregion

	#pragma region Load Sprite for background
	/*Creating a sprite to displace the background*/
	sf::Sprite bacGroSpr;
	/*Linking the sprite to the texture*/
	bacGroSpr.setTexture(bacGroTex);
	#pragma endregion

	#pragma region Location of Sprite
	/*Seeing the location of the sprite(0,0)*/
	bacGroSpr.setPosition(0, 0);
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
		/*Clear the scene*/
		window.clear();
		/*Draw the scene*/
		window.draw(bacGroSpr);
		/*Render the scene*/
		window.display();
		#pragma endregion


	}
#pragma endregion

	//Return 0 will tell the program nothing bad happened and can end
	return 0;
}