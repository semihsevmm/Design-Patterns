//
// Created by Semih on 11.05.2021.
//

#ifndef COMPOSITEPATTERN_COMPOSITE_H
#define COMPOSITEPATTERN_COMPOSITE_H
#include <list>

class Component{
protected:
    Component *parent;
    std::string name;
public:
    void setParent(Component *parent){
        this->parent = parent;
    }
    Component *getParent(){
        return this->parent;
    }
    virtual void add(Component *component){}
    virtual void remove(Component *component){}
    virtual bool isComposite(){
        return false;
    }
    void setName(std::string name){
        this->name = name;
    }
    virtual void getPath(std::string tab) = 0;
};

class File: public Component{
public:
    File(){}
    File(std::string name){
        this->name = name;
    }
    void getPath(std::string tab) override{
        std::cout<<tab<<"File Name: " << this->name<<std::endl;
    }
};


class Directory: public Component{
protected:
    std::list<Component*> children;
public:
    Directory(){}
    Directory(std::string name){
        this->name = name;
    }
    void add(Component *component) override{
        this->children.push_back(component);
        component->setParent(this);
    }

    void remove(Component *component) override{
        children.remove(component);
        component->setParent(nullptr);
    }
    bool isComposite() override{
        return true;
    }

    void getPath(std::string tab) override{
        std::cout<<tab<<"Directory Name: "<<this->name<<std::endl;
        for (Component *c : children){
            c->getPath(tab+"\t");
        }
    }
};

#endif //COMPOSITEPATTERN_COMPOSITE_H
