//
// Created by Semih on 30.03.2021.
//

#ifndef FACTORYPATTERN_FACTORY_H
#define FACTORYPATTERN_FACTORY_H
// Model Abstract classı
class Shape{
protected:
    Shape(std::string name){
        this->name = name;
    }
private:
    std::string name;
public:
    virtual void printShape() = 0;
public:
    void getName(){
        std::cout<<this->name<<"\n";
    }
};

class StraightTetro : public Shape{
public:
    void printShape(){
        std::cout<<"\n####\n";
    }
private:
    StraightTetro(std::string name):Shape(name){}

    friend class Tetris;
};

class SquareTetro : public Shape{
public:
    void printShape(){
        std::cout<<"\n##\n##\n";
    }
private:
    SquareTetro(std::string name):Shape(name){}

    friend class Tetris;
};

class TTetro : public Shape{
public:
    void printShape(){
        std::cout<<"\n###\n #\n";
    }
private:
    TTetro(std::string name):Shape(name){}

    friend class Tetris;
};
//Factory Class
class Tetris{
public:
    Shape* createShape(int sekil){
        if(sekil == 1){
            return new StraightTetro("Straight Tetromino");
        }
        if(sekil == 2){
            return new SquareTetro("Square Tetromino");
        }
        if(sekil == 3){
            return new TTetro("T Tetromino");
        }
        return nullptr;
    }
};
#endif //FACTORYPATTERN_FACTORY_H
