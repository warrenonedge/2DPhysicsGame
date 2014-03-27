#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include "Physics.h"


bool active(int objx, int objy, int w, int h, int mousex, int mousey);
std::string number_to_string(int number);

int main()
{
    int w = 1000;
    int h = 600;
    // Create the main window
    sf::RenderWindow app(sf::VideoMode(w,h), "SFML window");
//-----------------------------------------------------------------
    //Main Screen Start Objects
    sf::Texture texture;
    if (!texture.loadFromFile("GameMainScreen.bmp"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setScale(w/sprite.getGlobalBounds().width,h/sprite.getGlobalBounds().height);
    sprite.setPosition(w/2-(sprite.getGlobalBounds().width/2),h/2-(sprite.getGlobalBounds().height/2));
    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        return EXIT_FAILURE; // error...
    }
    sf::Text startText("Start",font,24);
    startText.setColor(sf::Color::White);
    startText.setStyle(sf::Text::Underlined);
    startText.setPosition(w/2-(startText.getGlobalBounds().width/2),(3*h/4)-(startText.getGlobalBounds().height/2));
    //Main Screen Objects End
//-----------------------------------------------------------------
    //Game Screen Objects Start
    int mass = 1;
    int velocity = 1;
    int angle = 0;
    int score = 0;

    sf::CircleShape ball((20.0/600)*h);
    ball.setPosition(87,h-100);
    ball.setFillColor(sf::Color::Red);

    sf::RectangleShape line;
    line.setPosition(ball.getPosition().x+ball.getRadius(),ball.getPosition().y+ball.getRadius());
    line.setOutlineThickness(0);
    line.setOutlineColor(sf::Color::White);
    line.setSize(sf::Vector2f(100,1));
    line.setFillColor(sf::Color::White);

    sf::RectangleShape bottom;
    bottom.setPosition(0,ball.getPosition().y+(ball.getRadius()*2));
    bottom.setOutlineThickness(0);
    bottom.setOutlineColor(sf::Color::White);
    bottom.setSize(sf::Vector2f(w,1));
    bottom.setFillColor(sf::Color::White);

    sf::RectangleShape rectLeft;
    rectLeft.setPosition(2.5*w/4,2.75*h/4);
    rectLeft.setSize(sf::Vector2f(50,(ball.getPosition().y+(ball.getRadius()*2)-rectLeft.getPosition().y)));
    rectLeft.setFillColor(sf::Color::Blue);

    sf::RectangleShape rectRight;
    rectRight.setPosition(rectLeft.getPosition().x+125,rectLeft.getPosition().y);
    rectRight.setSize(rectLeft.getSize());
    rectRight.setFillColor(sf::Color::Blue);

    sf::RectangleShape rectTop;
    rectTop.setPosition(rectLeft.getPosition().x,rectLeft.getPosition().y-rectLeft.getSize().x);
    rectTop.setSize(sf::Vector2f((3.0/2*rectLeft.getSize().x)+(2*rectLeft.getGlobalBounds().width),rectLeft.getSize().x));
    rectTop.setFillColor(sf::Color::Green);

    sf::CircleShape triangleTop1(rectTop.getGlobalBounds().width/4,3);
    triangleTop1.setPosition(rectLeft.getPosition().x,rectTop.getPosition().y-triangleTop1.getGlobalBounds().height);
    triangleTop1.setFillColor(sf::Color::Magenta);

    sf::CircleShape triangleTop2(rectTop.getGlobalBounds().width/4,3);
    triangleTop2.setPosition(rectRight.getPosition().x-triangleTop2.getGlobalBounds().width/2.0,rectTop.getPosition().y-triangleTop2.getGlobalBounds().height);
    triangleTop2.setFillColor(sf::Color::Magenta);

    sf::Text level("Level 1",font,24);
    level.setPosition(10,0);
    level.setColor(sf::Color::White);
    level.setStyle(sf::Text::Bold);

    sf::Text massText("Mass: "+number_to_string(mass),font,20);
    massText.setColor(sf::Color::White);
    massText.setPosition(level.getPosition().x,(225/600.0)*h);

    sf::Text velocityText("Velocity: "+number_to_string(velocity),font,20);
    velocityText.setColor(sf::Color::White);
    velocityText.setPosition(massText.getPosition().x,massText.getPosition().y+75);

    sf::Text angleText("Angle: "+number_to_string(angle)+"�",font,20);
    angleText.setColor(sf::Color::White);
    angleText.setPosition(velocityText.getPosition().x,velocityText.getPosition().y+75);

    sf::Text replayText("Replay",font,20);
    replayText.setColor(sf::Color::White);
    replayText.setStyle(sf::Text::Underlined);
    replayText.setPosition(massText.getPosition().x,50);

    sf::Text scoreText("Score: "+number_to_string(score),font,24);
    scoreText.setPosition(w/2.0-(scoreText.getLocalBounds().width/2),50);
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
                    if (active(startText.getPosition().x,startText.getPosition().y,startText.getLocalBounds().width,startText.getLocalBounds().height,mousex,mousey))
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
                        if (active(startText.getPosition().x,startText.getPosition().y,startText.getLocalBounds().width,startText.getLocalBounds().height,mousex,mousey))
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
                    if (active(replayText.getPosition().x,replayText.getPosition().y,replayText.getLocalBounds().width,replayText.getLocalBounds().height,mousex,mousey))
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
                        if (active(replayText.getPosition().x,replayText.getPosition().y,replayText.getLocalBounds().width,replayText.getLocalBounds().height,mousex,mousey)){
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
                    angleText.setString("Angle: " + number_to_string(angle) + "�");
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
            app.draw(triangleTop1);
            app.draw(triangleTop2);
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
