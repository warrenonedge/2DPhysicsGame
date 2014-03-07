#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>
#include "Physics.h"


bool active(int objx, int objy, int w, int h, int mousex, int mousey);
std::string number_to_string(int number);

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
    int mass = 1;
    int velocity = 1;
    int angle = 0;
    int score = 0;

    sf::CircleShape ball(37);
    ball.setPosition(87,476);
    ball.setFillColor(sf::Color::Red);

    sf::RectangleShape line;
    line.setPosition(87+ball.getRadius(),476+ball.getRadius());
    line.setOutlineThickness(0);
    line.setOutlineColor(sf::Color::White);
    line.setSize(sf::Vector2f(100,1));
    line.setFillColor(sf::Color::White);

    sf::RectangleShape bottom;
    bottom.setPosition(0,476+(ball.getRadius()*2));
    bottom.setOutlineThickness(0);
    bottom.setOutlineColor(sf::Color::White);
    bottom.setSize(sf::Vector2f(1000,1));
    bottom.setFillColor(sf::Color::White);

    sf::RectangleShape rectLeft;
    rectLeft.setPosition(750,412);
    rectLeft.setSize(sf::Vector2f(62,(476+(ball.getRadius()*2)-412)));
    rectLeft.setFillColor(sf::Color::Blue);

    sf::RectangleShape rectRight;
    rectRight.setPosition(875,412);
    rectRight.setSize(sf::Vector2f(62,(476+(ball.getRadius()*2)-412)));
    rectRight.setFillColor(sf::Color::Cyan);

    sf::RectangleShape rectTop;
    rectTop.setPosition(750,355);
    rectTop.setSize(sf::Vector2f(187,57));
    rectTop.setFillColor(sf::Color::Green);

    sf::CircleShape triangleTop(80,3);
    triangleTop.setPosition(765,235);
    triangleTop.setFillColor(sf::Color::Magenta);

    sf::Text massText("Mass: "+number_to_string(mass),font,20);
    massText.setColor(sf::Color::White);
    massText.setPosition(10,225);

    sf::Text velocityText("Velocity: "+number_to_string(velocity),font,20);
    velocityText.setColor(sf::Color::White);
    velocityText.setPosition(10,300);

    sf::Text angleText("Angle: "+number_to_string(angle)+"°",font,20);
    angleText.setColor(sf::Color::White);
    angleText.setPosition(10,375);

    sf::Text replayText("Replay",font,20);
    replayText.setColor(sf::Color::White);
    replayText.setStyle(sf::Text::Underlined);
    int replayx = 10;
    int replayy = 50;
    replayText.setPosition(replayx,replayy);

    sf::Text scoreText("Score: "+number_to_string(score),font,24);
    scoreText.setPosition(500-(scoreText.getLocalBounds().width/2),50);
    scoreText.setColor(sf::Color::White);

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
                            printf("\n ONLY ONE KEY AT A TIME \n (, or /) \t   to -/+ Mass \n (Left or Right)   to -/+ Velocity \n (Up or Down)      to -/+ Angle(degree)");
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
            sf::Text level("Level 1",font,24);
            level.setPosition(10,0);
            level.setColor(sf::Color::White);
            level.setStyle(sf::Text::Bold);

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
                if (event.type == sf::Event::KeyPressed)
                {
                    if (event.key.code == sf::Keyboard::Comma)
                    {
                        if (mass > 1)
                            mass-=1;
                        else
                            mass = 1;
                    }
                    if (event.key.code == sf::Keyboard::Slash)
                    {
                        if (mass < 50)
                        {
                            mass+=1;
                        }
                        else
                            mass = 50;
                    }
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        if (velocity > 1)
                            velocity-=1;
                        else
                            velocity = 1;
                        line.setSize(sf::Vector2f(100+velocity,1));
                    }
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        if (velocity < 50)
                        {
                            velocity+=1;
                        }
                        else
                            velocity = 50;
                        line.setSize(sf::Vector2f(100+velocity,1));
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        line.rotate(angle);
                        if (angle > 0)
                            angle-=1;
                        else
                            angle = 0;
                        line.rotate((-1)*angle);
                    }
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        line.rotate(angle);
                        if (angle < 45)
                        {
                            angle+=1;
                        }
                        else
                            angle = 45;
                        line.rotate((-1)*angle);
                    }
                    massText.setString("Mass: " + number_to_string(mass));
                    velocityText.setString("Velocity: " + number_to_string(velocity));
                    angleText.setString("Angle: " + number_to_string(angle) + "°");
                }
            }
            app.clear();
            app.draw(level);
            app.draw(bottom);
            app.draw(line);
            app.draw(ball);
            app.draw(rectLeft);
            app.draw(rectRight);
            app.draw(rectTop);
            app.draw(triangleTop);
            app.draw(massText);
            app.draw(velocityText);
            app.draw(angleText);
            app.draw(replayText);
            app.draw(scoreText);
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

std::string number_to_string(int number)
{
	return dynamic_cast<std::stringstream *> (&(std::stringstream() << number))->str();
}
