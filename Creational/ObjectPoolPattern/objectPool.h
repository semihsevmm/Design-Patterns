//
// Created by Semih on 31.03.2021.
//

#ifndef OBJECTPOOLPATTERN_OBJECTPOOL_H
#define OBJECTPOOLPATTERN_OBJECTPOOL_H
#include <map>
class Renk{
public:
    std::string name;
    Renk(){
        name ="black";
        this->red = 0;
        this->green = 0;
        this->blue = 0;
    }
    Renk(int red=0, int green=0, int blue=0, std::string name ="black"){
        this->name = name;
        this->red = red;
        this->green = green;
        this->blue = blue;
    }
    int getRed(){
        return this->red;
    }
    int getGreen(){
        return this->green;
    }
    int getBlue(){
        return this->blue;
    }
private:
    int red, green, blue;
};
//Object Pool Class
template <class T>
class Palet{
private:
    std::map<std::string, T*> objectPool;

public:
    T* getObject(std::string key){
        T* buffer = objectPool.at(key);
        objectPool.erase(key);
        return buffer;
    }

    void addObject(T* object){
        this->objectPool[object->name] = object;
        object = NULL;
    }

};

#endif //OBJECTPOOLPATTERN_OBJECTPOOL_H
