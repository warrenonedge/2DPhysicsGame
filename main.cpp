#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <cmath>
#include "Physics.h"

using namespace std;

//------Extra Functions--------------
//vector<vector<string>> CheckRectWallCollide(vector<Wrect*> objs, Wrect* barrier)
//{
//    vector<vector<string>> allCollides;
//    vector<string> objCollides;
//
//    for(unsigned int i=0;i<objs.size();i++)
//    {
//        for(int j=0;j<4;j++)
//        {
//            if(objs[i]->getPoints()[j]->getY() >= barrier->getPoints()[0]->getY())
//            {
//                objCollides.push_back("floor");
//            }
//            else
//            {
//                objCollides.push_back("none");
//            }
//
//            allCollides.push_back(objCollides);
//            objCollides.clear();
//        }
//    }
//
//    return allCollides;
// }
int ballrect = 0;

void HandleRectWallCollide(vector<Wrect*> objs, double winh)
{
    double objxvel;
    double objyvel;
    double objavel;
    double objmass;

    for(unsigned int i=0;i<objs.size();i++)
    {

        for(int j=0;j<4;j++)
        {
            if(objs[i]->getPoints()[j].getY() >= 3+winh)
            {
                objs[i]->Move(0,winh+3 - objs[i]->getPoints()[j].getY());
                //double xdist = objs[i]->getCenterX() - objs[i]->getPoints()[j].getX();
                //objs[i]->setAngVelocity(objs[i]->getAngVelocity()+xdist);
                //objs[i]->setXvelocity(objs[i]->getXvelocity()+(xdist/4));
                if (ballrect == 1)
                    if (objs[i]->getYvelocity()>0)
                        objs[i]->setYvelocity(-1.0*(objs[i]->getYvelocity())/1.1);
                    else
                        objs[i]->setYvelocity((objs[i]->getYvelocity())/1.1);
                else
                    objs[i]->setYvelocity(-775);
            }
        }
    }
}

void HandleBallWallCollide(vector<Wball*> objs, double barrierY)
{
    double objxvel;
    double objyvel;
    double objavel;
    double objmass;

    for(unsigned int i=0;i<objs.size();i++)
    {
        if(objs[i]->getCenterY()+objs[i]->getRadius() >= barrierY)
        {
            objs[i]->Move(0,barrierY - objs[i]->getCenterY()-objs[i]->getRadius());
            objs[i]->setYvelocity(-1.0*(objs[i]->getYvelocity())/1.1);
        }
    }
}

void HandleBallRectCollide(vector<Wrect*> Robjs, vector<Wball*> Bobjs) {

    for(unsigned i=0;i<Robjs.size();i++)
    {
        if (Bobjs[0]->getCenterX()+Bobjs[0]->getRadius() - Robjs[i]->getPoints()[0].getX() >= 0 &&
            Bobjs[0]->getCenterX()+Bobjs[0]->getRadius() - Robjs[i]->getPoints()[1].getX() <= 0 &&
            Bobjs[0]->getCenterY()>= Robjs[i]->getPoints()[0].getY() && Bobjs[0]->getCenterY() <= Robjs[i]->getPoints()[2].getY())
        {
            cout << "X collision" << endl;
            double BobjXvelo = Bobjs[0]->getXvelocity();
            double RobjsXvelo = Robjs[i]->getXvelocity();
            Robjs[i]->setXvelocity(BobjXvelo);
            //Bobjs[0]->setXvelocity(RobjsXvelo);
            Bobjs[0]->setXvelocity((-1.0)*BobjXvelo);
            ballrect = 1;
        }

        if (Bobjs[0]->getCenterX()+Bobjs[0]->getRadius() - Robjs[i]->getPoints()[0].getX() <= 0 &&
            Bobjs[0]->getCenterX()+Bobjs[0]->getRadius() - Robjs[i]->getPoints()[1].getX() >= 0 &&
            Bobjs[0]->getCenterY()>= Robjs[i]->getPoints()[0].getY() && Bobjs[0]->getCenterY() <= Robjs[i]->getPoints()[2].getY())
        {
            cout << "X collision" << endl;
            double BobjXvelo = Bobjs[0]->getXvelocity();
            double RobjsXvelo = Robjs[i]->getXvelocity();
            Robjs[i]->setXvelocity(BobjXvelo);
            //Bobjs[0]->setXvelocity(RobjsXvelo);
            Bobjs[0]->setXvelocity((-1.0)*BobjXvelo);
            ballrect = 1;
        }

        if(Bobjs[0]->getCenterY()+Bobjs[0]->getRadius() - Robjs[i]->getPoints()[0].getY() >=0 &&
           Bobjs[0]->getCenterY()+Bobjs[0]->getRadius() - Robjs[i]->getPoints()[1].getY() <=0 &&
           Bobjs[0]->getCenterX()>= Robjs[i]->getPoints()[0].getX() && Bobjs[0]->getCenterY() <= Robjs[i]->getPoints()[1].getX())
        {
            cout << "Y collision" << endl;
            double BobjYvelo = Bobjs[0]->getYvelocity();
            double RobjsYvelo = Robjs[i]->getYvelocity();
            Robjs[i]->setYvelocity(BobjYvelo);
            Bobjs[0]->setYvelocity(RobjsYvelo);
            //Bobjs[0]->setXvelocity((-1.0/3)*BobjYvelo);
            ballrect = 1;
        }

        if(Bobjs[0]->getCenterY()+Bobjs[0]->getRadius() - Robjs[i]->getPoints()[0].getY() <=0 &&
           Bobjs[0]->getCenterY()+Bobjs[0]->getRadius() - Robjs[i]->getPoints()[1].getY() >=0 &&
           Bobjs[0]->getCenterX()>= Robjs[i]->getPoints()[0].getX() && Bobjs[0]->getCenterY() <= Robjs[i]->getPoints()[1].getX())
        {
            cout << "Y collision" << endl;
            double BobjYvelo = Bobjs[0]->getYvelocity();
            double RobjsYvelo = Robjs[i]->getYvelocity();
            Robjs[i]->setYvelocity(BobjYvelo);
            Bobjs[0]->setYvelocity(RobjsYvelo);
            //Bobjs[0]->setXvelocity((-1.0/3)*BobjYvelo);
            ballrect = 1;
        }
    }


}

//------Extra Functions End----------


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
    sf::Text startText("Start",font,(w*1.0/h)*(72/5.0));
    startText.setColor(sf::Color::White);
    startText.setStyle(sf::Text::Underlined);
    startText.setPosition(w/2-(startText.getGlobalBounds().width/2),(3*h/4)-(startText.getGlobalBounds().height/2));
    bool mainScreen = true;
    int printed = 0;
    //Main Screen Objects End
//-----------------------------------------------------------------
    reintialize:
    //Game Screen Objects Start
    int launched,space = 0;
    int mass = 1;
    int velocity = 50;
    int angle = 0;

    sf::CircleShape ball((20.0/600)*h);
    ball.setPosition(87,h-100);
    ball.setFillColor(sf::Color::Red);

    sf::RectangleShape line;
    line.setPosition(ball.getPosition().x+ball.getRadius(),ball.getPosition().y+ball.getRadius());
    line.setOutlineThickness(0);
    line.setOutlineColor(sf::Color::White);
    line.setSize(sf::Vector2f(velocity,1));
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
    double x = rectLeft.getGlobalBounds().width/2;
    double y = rectLeft.getGlobalBounds().height/2;
    rectLeft.setOrigin(x,y);
    rectLeft.move(x,y);

    sf::Text level("Level 1",font,(w*1.0/h)*(72/5.0));
    level.setPosition(10,0);
    level.setColor(sf::Color::White);
    level.setStyle(sf::Text::Bold);

    sf::Text massText("Mass: "+number_to_string(mass)+" kg",font,(w*1.0/h)*(12.0));
    massText.setColor(sf::Color::White);
    massText.setPosition(level.getPosition().x,(225/600.0)*h);

    sf::Text velocityText("Velocity: "+number_to_string(velocity),font,(w*1.0/h)*(12.0));
    velocityText.setColor(sf::Color::White);
    velocityText.setPosition(massText.getPosition().x,massText.getPosition().y+75);

    sf::Text angleText("Angle: "+number_to_string(angle)+"°",font,(w*1.0/h)*(12.0));
    angleText.setColor(sf::Color::White);
    angleText.setPosition(velocityText.getPosition().x,velocityText.getPosition().y+75);

    sf::Text replayText("Replay",font,(w*1.0/h)*(12.0));
    replayText.setColor(sf::Color::White);
    replayText.setStyle(sf::Text::Underlined);
    replayText.setPosition(massText.getPosition().x,50);

    sf::Text scoreText("",font,50);
    scoreText.setPosition(w/2.0-(scoreText.getLocalBounds().width/2.0),h/2-(scoreText.getLocalBounds().height/2));
    scoreText.setColor(sf::Color::White);

    //Game Screen Objects End
//-----------------------------------------------------------------
    //Physics Engine initialization

    World world = World(w,h,10);

    Wrect rectL = Wrect(&rectLeft,1.3,0,-775,0);
    world.addRectObject(&rectL);

    Wball Lball = Wball(&ball,0.1,0,0);
    world.addBallObject(&Lball);
    //world.getRectObjects()[1]->getPoints()[3]->setY(10);

    //Physics Engine Initialization End
//-----------------------------------------------------------------

    double fps = 60;
    double objMass;
    double objxvelo;
    double objyvelo;
    double objavelo;

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
                            if (printed == 0)
                            {
                                printf("\n ONLY ONE KEY AT A TIME \n (, or /) \t   to -/+ Mass \n (Left or Right)   to -/+ Velocity \n (Up or Down)      to -/+ Angle(degree)");
                                printed = 1;
                            }
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
            //Execute Physics Engine
            if (world.getElapsedTime() > 1000/fps)
            {
                //--------Handle Rect Wall Collides----------------
                HandleRectWallCollide(world.getRectObjects(), world.getHeight());
                HandleBallWallCollide(world.getBallObjects(),bottom.getPosition().y);
                HandleBallRectCollide(world.getRectObjects(),world.getBallObjects());
                //--------End Handle Rect Wall Collides------------

                for (unsigned int i=0;i<world.getRectObjects().size();i++)
                {
                    objMass = world.getRectObjects()[i]->getMass();
                    objyvelo = world.getRectObjects()[i]->getYvelocity();
                    world.getRectObjects()[i]->setYvelocity(objyvelo+(world.getGforce()*objMass));

                    objxvelo = world.getRectObjects()[i]->getXvelocity();
                    if (objxvelo < 0)
                        world.getRectObjects()[i]->setXvelocity(objxvelo+abs(objxvelo*objMass*.012)/objMass);
                    else if (objxvelo > 0)
                        world.getRectObjects()[i]->setXvelocity(objxvelo-abs(objxvelo*objMass*.012)/objMass);

                    //objavelo = world.getRectObjects()[i]->getAngVelocity();
                    //world.getRectObjects()[i]->setAngVelocity(objavelo*objMass);
                }
                if (launched == 1)
                {
                    for (unsigned int i=0; i<world.getBallObjects().size(); i++)
                    {
                        objMass = world.getBallObjects()[i]->getMass();
                        objyvelo = world.getBallObjects()[i]->getYvelocity();
                        world.getBallObjects()[i]->setYvelocity(objyvelo+(world.getGforce()*objMass));

                        objxvelo = world.getBallObjects()[i]->getXvelocity();
                        if (objxvelo < 0)
                            world.getBallObjects()[i]->setXvelocity(objxvelo+abs(objxvelo*objMass*.012)/objMass);
                        else if (objxvelo > 0)
                            world.getBallObjects()[i]->setXvelocity(objxvelo-abs(objxvelo*objMass*.012)/objMass);

                        //objavelo = world.getRectObjects()[i]->getAngVelocity();
                        //world.getRectObjects()[i]->setAngVelocity(objavelo*objMass);
                    }

                    for (unsigned int i=0; i<world.getBallObjects().size(); i++)
                    {
                        objxvelo = world.getBallObjects()[i]->getXvelocity();
                        objyvelo = world.getBallObjects()[i]->getYvelocity();

                        world.getBallObjects()[i]->Move(objxvelo/fps,objyvelo/fps);
                    }
                }
                for (unsigned int i=0;i<world.getRectObjects().size();i++)
                {
                    objxvelo = world.getRectObjects()[i]->getXvelocity();
                    objyvelo = world.getRectObjects()[i]->getYvelocity();
                    //objavelo = world.getRectObjects()[i]->getAngVelocity();

                    world.getRectObjects()[i]->Move(objxvelo/fps,objyvelo/fps);
                    //world.getRectObjects()[i]->Rotate(objavelo/fps);
                }

                world.resetClock();
            }

            //Execute Physics Engine End
            //-----------------------------------------------------------------
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
                            goto reintialize;
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
                        if (mass < 10)
                        {
                            mass+=1;
                        }
                        else
                            mass = 10;
                    }
                    if (event.key.code == sf::Keyboard::Left)
                    {
                        if (velocity > 50)
                            velocity-=1;
                        else
                            velocity = 50;
                        line.setSize(sf::Vector2f(velocity,1));
                    }
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        if (velocity < 100)
                        {
                            velocity+=1;
                        }
                        else
                            velocity = 100;
                        line.setSize(sf::Vector2f(velocity,1));
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
                    if (event.key.code == sf::Keyboard::Space)
                    {
                        if (space == 0)
                        {
                            launched = 1;
                            world.getBallObjects()[0]->setMass(mass/10.0);
                            world.getBallObjects()[0]->setXvelocity(cos(angle*(3.14/180))*(velocity*10));
                            world.getBallObjects()[0]->setYvelocity(sin(angle*(3.14/180) )*(velocity*10));
                            line.setFillColor(sf::Color::Black);
                            space = 1;
                        }
                    }
                    if (event.key.code == sf::Keyboard::R)
                    {
                        mainScreen == false;
                        goto reintialize;
                    }
                    massText.setString("Mass: " + number_to_string(mass)+" kg");
                    velocityText.setString("Velocity: " + number_to_string(velocity));
                    angleText.setString("Angle: " + number_to_string(angle) + "°");
                }
            }
            if (rectLeft.getPosition().x > w)
                scoreText.setString("You Win");
            app.clear();
            app.draw(level);
            app.draw(line);
            app.draw(ball);
            app.draw(rectLeft);
            app.draw(massText);
            app.draw(velocityText);
            app.draw(angleText);
            app.draw(replayText);
            app.draw(scoreText);
            app.draw(bottom);
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
