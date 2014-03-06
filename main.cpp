#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "Physics.h"

bool active(int objx, int objy, int w, int h, int mousex, int mousey);

int main()
{
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(1000, 600), "SFML window");
//-----------------------------------------------------------------
    //Main Screen Start Objects
    sf::Texture texture;
    if (!texture.loadFromFile("GameMainScreen.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        return EXIT_FAILURE; // error...
    }
    sf::Text startText("Start",font,24);
    startText.setColor(sf::Color::White);
    startText.setStyle(sf::Text::Underlined);
    int startTextx = 500-(startText.getGlobalBounds().width/2);
    int startTexty = 460-(startText.getGlobalBounds().height/2);
    startText.setPosition(startTextx,startTexty);
    //Main Screen Objects End
//-----------------------------------------------------------------
    //Game Screen Objects Start
    sf::CircleShape ball(37);
    ball.setPosition(87,476);
    ball.setFillColor(sf::Color::Red);
    sf::Text massText("Mass:",font,20);
    massText.setColor(sf::Color::White);
    massText.setPosition(62,225);

    sf::Text velocityText("Velocity:",font,20);
    velocityText.setColor(sf::Color::White);
    velocityText.setPosition(62,300);

    sf::Text angleText("Angle:",font,20);
    angleText.setColor(sf::Color::White);
    angleText.setPosition(62,375);

    sf::Text replayText("Replay",font,20);
    replayText.setColor(sf::Color::White);
    replayText.setStyle(sf::Text::Underlined);
    int replayx = 62;
    int replayy = 75;
    replayText.setPosition(replayx,replayy);
    //Game Screen Objects End
//-----------------------------------------------------------------
    bool mainScreen = true;
	// Start the game loop
    while (app.isOpen())
    {
        if (mainScreen == true) //Main Screen Display
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
                    if (active(startTextx,startTexty,startText.getLocalBounds().width,startText.getLocalBounds().height,mousex,mousey))
                    {
                        startText.setColor(sf::Color::Red);
                    }
                    else
                    {
                        startText.setColor(sf::Color::White);
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        int mousex = event.mouseButton.x;
                        int mousey = event.mouseButton.y;
                        if (active(startTextx,startTexty,startText.getLocalBounds().width,startText.getLocalBounds().height,mousex,mousey))
                        {
                            mainScreen = false;
                            replayText.setColor(sf::Color::White);
                        }
                    }
                }
            }

            // Clear screen
            app.clear();

            // Draw the sprite
            app.draw(sprite);
            app.draw(startText);
        }
        else //Game Screen Display
        {

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
                    if (active(replayx,replayy,replayText.getLocalBounds().width,replayText.getLocalBounds().height,mousex,mousey))
                    {
                        replayText.setColor(sf::Color::Red);
                    }
                    else
                    {
                        replayText.setColor(sf::Color::White);
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        int mousex = event.mouseButton.x;
                        int mousey = event.mouseButton.y;
                        if (active(replayx,replayy,replayText.getLocalBounds().width,replayText.getLocalBounds().height,mousex,mousey)){
                            mainScreen = true;
                            startText.setColor(sf::Color::White);
                        }
                    }
                }
            }
            app.clear();
            app.draw(ball);
            app.draw(massText);
            app.draw(velocityText);
            app.draw(angleText);
            app.draw(replayText);
        }
        // Update the window
        app.display();
    }

    return EXIT_SUCCESS;
}

bool active(int objx, int objy, int w, int h, int mousex, int mousey)
{
    //if(mousex > text.getPosition().x && mousex < text.getPosition().x + text.getLocalBounds().width && mousey > text.getPosition().y && mousey < text.getPosition().y + text.getLocalBounds().height)
    if(mousex > objx && mousex < objx + w && mousey > objy && mousey < objy + h)
    {
        return true;
    }

    return false;
}
