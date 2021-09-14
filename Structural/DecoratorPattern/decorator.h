//
// Created by Semih on 12.05.2021.
//

#ifndef DECORATORPATTERN_DECORATOR_H
#define DECORATORPATTERN_DECORATOR_H

class Drone{
public:
    std::string name;
    virtual void fly() = 0;
};

class Quadcopter: public Drone{
public:
    Quadcopter(){
        this->name = "Quadcopter";
    }
    void fly(){
        std::cout<<this->name<<" is flying..."<<std::endl;
    }
};

class Octocopter: public Drone{
public:
    Octocopter(){
        this->name = "Octocopter";
    }
    void fly(){
        std::cout<<this->name<<" is flying..."<<std::endl;
    }
};

class DroneDecorator: public Drone{
protected:
    Drone *myDrone;
public:
    DroneDecorator(Drone *myDrone){
        this->myDrone = myDrone;
    }
    void fly(){
        this->myDrone->fly();
    }
    virtual void operation() = 0;
};

class CameraDecorator: public DroneDecorator{
public:
    CameraDecorator(Drone *myDrone): DroneDecorator(myDrone){}

    void operation(){
        std::cout<<this->myDrone->name<<" is recording..."<<std::endl;
    }
};
class NavigationDecorator: public DroneDecorator{
public:
    NavigationDecorator(Drone *myDrone): DroneDecorator(myDrone){}

    void operation(){
        std::cout<<"Route created by "<<this->myDrone->name<<"..."<<std::endl;
    }
};
#endif //DECORATORPATTERN_DECORATOR_H
