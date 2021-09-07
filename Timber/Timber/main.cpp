#include "include/SFML/Graphics.hpp"

int main() 
{
	#pragma region Creating the window
	//Create a window at resolution 1920 by 1080 
	sf::VideoMode vm(1920, 1080);
	//Call the resolution and name of the title bar and make it full screen 
	sf::RenderWindow window(vm, "Timber", sf::Style::Fullscreen);
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
		/*Draw the scene*/
		/*Clear the scene*/
		window.clear();
		/*Render the scene*/
		window.display();
		#pragma endregion


	}
#pragma endregion



	//Return 0 will tell the program nothing bad happened and can end
	return 0;
}