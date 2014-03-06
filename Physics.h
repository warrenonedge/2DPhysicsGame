#ifndef PHYSICS_H
#define PHYSICS_H


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

#endif // PHYSICS_H
