#ifndef PHYSICS_H
#define PHYSICS_H
#include <vector>
#include<stdio.h>
#include <SFML/Graphics.hpp>

using namespace std;

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

    public:
        Wrect(sf::RectangleShape*,double,double,double);

        void setPosition(double,double);
        void Move(double,double);

        double getCenterX(void);
        double getCenterY(void);
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
