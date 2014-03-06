#include "Physics.h"
#include <iostream>

using namespace std;

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




