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

vector<Wrect*> World::getRectObjects() {
    return this->rectObjects;
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

double Wshape::getXvelocity() {
    return this->xvelo;
}

double Wshape::getYvelocity() {
    return this->yvelo;
}


Wrect::Wrect(sf::RectangleShape* shape,double mass,double xvelo,double yvelo)
{
    this->mass = mass;
    this->xvelo = xvelo;
    this->yvelo = yvelo;
    this->shape = shape;
    this->width = shape->getSize().x;
    this->height = shape->getSize().y;
    Point p = Point(abs((this->width/2)-getCenterX()),abs((this->height/2)-getCenterY())); //topLeftPoint
    points.push_back(&p);

    p = Point(abs((this->width/2)+getCenterX()),abs((this->height/2)-getCenterY()));  //topRightPoint
    points.push_back(&p);

    p = Point(abs((this->width/2)-getCenterX()),abs((this->height/2)+getCenterY())); //botLeftPoint
    points.push_back(&p);

    p = Point(abs((this->width/2)+getCenterX()),abs((this->height/2)+getCenterY()));//botRightPoint
    points.push_back(&p);

}

double Wrect::getCenterX() {
    return this->shape->getPosition().x;
}

double Wrect::getCenterY() {
    return this->shape->getPosition().y;
}

void Wrect::setPosition(double newx, double newy) {
    this->shape->setPosition(newx, newy);
}

void Wrect::Move(double dx,double dy) {
    for (int i=0;i<4;i++)
    {
        this->points[i]->Move(dx,dy);
    }

    this->shape->move(dx,dy);
}

double Wrect::getWidth() {
    return this->width;
}

double Wrect::getHeight() {
    return this->height;
}

vector<Point*> Wrect::getPoints() {
    return this->points;
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

void Point::Move(double dx,double dy) {
    this->x += dx;
    this->y += dy;
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}
