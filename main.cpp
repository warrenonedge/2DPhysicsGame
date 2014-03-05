#include <SFML/Graphics.hpp>
#include <stdio.h>

bool active(sf::Text text, int mousex, int mousey);

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("GameMainScreen.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        return EXIT_FAILURE; // error...
    }
    sf::Text text;
    text.setFont(font);
    text.setString("Start");
    text.setCharacterSize(24);
    text.setColor(sf::Color::White);
    text.setPosition(380,500);

	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
            if (event.type == sf::Event::MouseMoved)
            {
                int mousex = event.mouseMove.x;
                int mousey = event.mouseMove.y;
                if (active(text,mousex,mousey))

                {
                    text.setColor(sf::Color::Red);
                }
                else
                {
                    text.setColor(sf::Color::White);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    int mousex = event.mouseButton.x;
                    int mousey = event.mouseButton.y;
                    if (active(text,mousex,mousey))
                        printf("Button Clicked");
                    else
                        printf("Button Not Clicked");
                }
            }
        }

        // Clear screen
        app.clear();

        // Draw the sprite
        app.draw(sprite);
        app.draw(text);

        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

bool active(sf::Text text, int mousex, int mousey)
{
    //if(mousex > text.getPosition().x && mousex < text.getPosition().x + text.getLocalBounds().width && mousey > text.getPosition().y && mousey < text.getPosition().y + text.getLocalBounds().height)
    if(mousex > 380 && mousex < 380 + text.getLocalBounds().width && mousey > 500 && mousey < 500 + text.getLocalBounds().height)
    {
        return true;
    }

    return false;
}
