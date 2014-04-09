#include "Physics.h"
#include <iostream>

using namespace std;

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

void Point::setX(double newx) {
    this->x = newx;
}

void Point::setY(double newy) {
    this->y = newy;
}

void Point::move(double dx, double dy) {
    this->x += dx;
    this->y += dy;
}

double Point::getX() {
    return this->x;
}

double Point::getY() {
    return this->y;
}


World::World(double w, double h, double gf)
{
    this->width = w;
    this->height = h;
    this->gforce = gf;
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


Wobject::Wobject(vector<Point> points,double mass,double xaccel,double yaccel)
{
    this->mass = mass;
    this->xaccel = xaccel;
    this->yaccel = yaccel;

    for(int i=0;i<points.size();i++)
    {
        Point p = Point(points[i].getX(),points[i].getY());
        this.points.push_back(p);
    }
}

void Wobject::setCenterX(double newcenterx)
{
    this->centerx = newcenterx;
}

void Wobject::setCenterY(double newcentery)
{
    this->centery = newcentery;
}

void Wobject::setMass(double newmass)
{
    this->mass = newmass;
}

void Wobject::setXAccel(double newxvel)
{
    this->xaccel = newxvel;
}

void Wobject::setYAccel(double newyvel)
{
    this->yaccel = newyvel;
}

double Wobject::getCenterX()
{
    return this->centerx;
}

double Wobject::getCenterY()
{
    return this->centery;
}

double Wobject::getMass()
{
    return this->mass;
}

vector<Point> Wobject::getPoints()
{
    return this->points;
}

double Wobject::getXAccel()
{
    return this->xaccel;
}

double Wobject::getYAccel()
{
    return this->yaccel;
}
