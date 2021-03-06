#include "Physics.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;


World::World(double w, double h, double gf)
{
    this->width = w;
    this->height = h;
    this->gforce = gf;
    this->clock.restart();
}

int World::getElapsedTime() {
    sf::Time time = this->clock.getElapsedTime();
    return time.asMilliseconds();
}

void World::resetClock() {
    this->clock.restart();
}

void World::addRectObject(Wrect* newobject) {
    this->rectObjects.push_back(newobject);
}

void World::addBallObject(Wball* newobject) {
    this->ballObjects.push_back(newobject);
}

vector<Wrect*> World::getRectObjects() {
    return this->rectObjects;
}

vector<Wball*> World::getBallObjects() {
    return this->ballObjects;
}

void World::setWidth(double w) {
    this->width = w;
}

void World::setHeight(double h) {
    this->height = h;
}

void World::setGforce(double gf) {
    this->gforce = gf;
}

double World::getWidth() {
    return this->width;
}

double World::getHeight() {
    return this->height;
}

double World::getGforce() {
    return this->gforce;
}

double Wshape::getMass() {
    return this->mass;
}

void Wshape::setMass(double newmass) {
    this->mass = newmass;
}

void Wshape::setXvelocity(double newXvelo) {
    this->xvelo = newXvelo;
}

void Wshape::setYvelocity(double newYvelo) {
    this->yvelo = newYvelo;
}

void Wshape::setAngVelocity(double newAvelo) {
    this->avelo = newAvelo;
}

double Wshape::getXvelocity() {
    return this->xvelo;
}

double Wshape::getYvelocity() {
    return this->yvelo;
}

double Wshape::getAngVelocity() {
    return this->avelo;
}


Wrect::Wrect(sf::RectangleShape* shape,double mass,double xvelo,double yvelo, double avelo)
{
    this->mass = mass;
    this->xvelo = xvelo;
    this->yvelo = yvelo;
    this->avelo = avelo;
    this->shape = shape;
    this->width = shape->getGlobalBounds().width;
    this->height = shape->getGlobalBounds().height;
    //Point p = Point(abs((this->width/2)-getCenterX()),abs((this->height/2)-getCenterY()));//topLeftPoint
    Point p = Point(this->shape->getPosition().x,this->shape->getPosition().y);
    points.push_back(p);

    //p = Point(abs((this->width/2)+getCenterX()),abs((this->height/2)-getCenterY()));  //topRightPoint
    p = Point(this->shape->getPosition().x+this->width,this->shape->getPosition().y);
    points.push_back(p);

    //p = Point(abs((this->width/2)-getCenterX()),abs((this->height/2)+getCenterY())); //botLeftPoint
    p = Point(this->shape->getPosition().x,this->shape->getPosition().y+this->height);
    points.push_back(p);

    //p = Point(abs((this->width/2)+getCenterX()),abs((this->height/2)+getCenterY()));//botRightPoint
    p = Point(this->shape->getPosition().x+this->width,this->shape->getPosition().y+this->height);
    points.push_back(p);

}

double Wrect::getCenterX() {
    return this->shape->getOrigin().x;
}

double Wrect::getCenterY() {
    return this->shape->getOrigin().y;
}

void Wrect::setPosition(double newx, double newy) {
    this->shape->setPosition(newx, newy);
}

void Wrect::Move(double dx,double dy) {
    for (int i=0;i<4;i++)
    {
        this->points[i].PMove(dx,dy);
    }

    this->shape->move(dx,dy);
}

void Wrect::Rotate(double da) {
    this->shape->rotate(da);

    double orgx;
    double orgy;

    for (int i=0;i<4;i++)
    {
        orgx = this->points[i].getX();
        orgy = this->points[i].getY();

        orgx = orgx*cos(this->shape->getRotation()*.017)-(orgy*sin(this->shape->getRotation()*.017));
        orgy = orgx*sin(this->shape->getRotation()*.017)-(orgy*cos(this->shape->getRotation()*.017));

        this->points[i].setX(orgx);
        this->points[i].setY(orgy);
    }
}

double Wrect::getWidth() {
    return this->width;
}

double Wrect::getHeight() {
    return this->height;
}

vector<Point> Wrect::getPoints() {
    return this->points;
}

Wball::Wball(sf::CircleShape* shape,double mass, double xvelo, double yvelo) {
    this->shape = shape;
    this->mass = mass;
    this->xvelo = xvelo;
    this->yvelo = yvelo;
}

void Wball::Move(double dx, double dy) {
    this->shape->move(dx,dy);
}

double Wball::getRadius() {
    return this->shape->getRadius();
}

double Wball::getCenterX() {
    return this->shape->getPosition().x + this->shape->getRadius();
}

double Wball::getCenterY() {
    return this->shape->getPosition().y + this->shape->getRadius();
}




Point::Point(double x,double y) {
    this->x = x;
    this->y = y;
}

void Point::setX(double newx) {
    this->x = newx;
}

void Point::setY(double newy) {
    this->y = newy;
}

void Point::PMove(double dx,double dy) {
    this->x += dx;
    this->y += dy;
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}
