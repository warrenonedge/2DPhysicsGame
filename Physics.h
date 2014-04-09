#ifndef PHYSICS_H
#define PHYSICS_H
#include <vector>
#include<stdio.h>

using namespace std;

class Point {
    private:
        double x, y;
    public:
        Point(double x, double y);
        void setX(double newx);
        void setY(double newy);
        void move(double dx, double dy);

        double getX(void);
        double getY(void);

};

class World {
    private:
        double width,height,gforce;

    public:
        World(double,double,double);
        void setWidth(double);
        void setHeight(double);
        void setGforce(double);

        double getWidth(void);
        double getHeight(void);
        double getGforce(void);

};

class Wobject {
    private:
        double mass,xaccel,yaccel;
        vector<Point> points;
    public:
        Wobject(vector<Point> points,double,double,double);
        void setMass(double);
        void setXAccel(double);
        void setYAccel(double);


        double getMass(void);
        vector<Point> getPoints(void);
        double getXAccel(void);
        double getYAccel(void);
};

#endif // PHYSICS_H
