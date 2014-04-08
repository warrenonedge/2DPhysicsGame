#ifndef PHYSICS_H
#define PHYSICS_H
#include <vector>

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
        // objects -> need a data structure to store world objects ?vector of objects?
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
        double centerx,centery,mass,xaccel,yaccel;
        vector<Point> points;
    public:
        Wobject(double,double,vector<Point>,double,double,double);
        void setCenterX(double);
        void setCenterY(double);
        void setMass(double);
        void setXAccel(double);
        void setYAccel(double);


        double getCenterX(void);
        double getCenterY(void);
        double getMass(void);
        double* getPoints(void);
        double getXAccel(void);
        double getYAccel(void);
};

#endif // PHYSICS_H
