#ifndef PHYSICS_H
#define PHYSICS_H
#include <vector>
#include<stdio.h>
#include <SFML/Graphics.hpp>

using namespace std;

class Point {
    private:
        double x,y;
    public:
        Point(double,double);
        double getX(void);
        double getY(void);

        void Move(double,double);

        void setX(double);
        void setY(double);
};


class Wshape {
    protected:
        double mass,xvelo,yvelo;

    public:
        void setMass(double);
        void setXvelocity(double);
        void setYvelocity(double);

        double getMass(void);
        double getXvelocity(void);
        double getYvelocity(void);
};

class Wrect : public Wshape {
    private:
        sf::RectangleShape* shape;
        vector<Point*> points;
        double width, height;

    public:
        Wrect(sf::RectangleShape*,double,double,double);

        void setPosition(double,double);
        void Move(double,double);

        double getCenterX(void);
        double getCenterY(void);
        double getWidth(void);
        double getHeight(void);
        vector<Point*> getPoints(void);

};


class World {
    private:
        double width,height,gforce;
        sf::Clock clock;
        vector<Wrect*> rectObjects;

    public:
        World(double,double,double);
        void setWidth(double);
        void setHeight(double);
        void setGforce(double);
        void resetClock(void);

        int getElapsedTime(void);
        void addRectObject(Wrect*);
        vector<Wrect*> getRectObjects(void);

        double getWidth(void);
        double getHeight(void);
        double getGforce(void);

};


#endif // PHYSICS_H
