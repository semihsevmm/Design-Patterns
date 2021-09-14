//
// Created by Semih on 6.05.2021.
//

#ifndef ITERATORPATTERN_ITERATOR_H
#define ITERATORPATTERN_ITERATOR_H
#include <vector>
class Film{
private:
    std::string filmAdi;
    std::string filmTuru;
public:
    Film(){}
    Film(std::string filmAdi, std::string filmTuru){
        this->filmAdi = filmAdi;
        this->filmTuru = filmTuru;
    }
    void getInfo(){
        std::cout<<"Film Adi: "<< this->filmAdi<< std::endl<< "Film Turu: "<< this->filmTuru<<std::endl;
    }
};

template <class T>
class Iterator{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone()  = 0;
    virtual T currentItem()  = 0;
};


template <class T>
class Aggregate{
public:
    virtual Iterator<T> * createIterator() = 0;
    virtual int count()  = 0;
    virtual void append (T nesne) = 0;
};

//ConcreteAggregate3

template <class T>
class VectorAggregate : public Aggregate<T>{
public:
    VectorAggregate(){}

    Iterator<T> *createIterator() {
        return new VectorIterator<T>(this);
    }

    int count(){
        return myVector.size();
    }

    void append(T nesne){
        myVector.push_back(nesne);
    }

    T get(int index) {
        return myVector.at(index);
    }
private:
    std::vector<T> myVector;
};

//ConcreteIterator
template <class T>
class VectorIterator : public Iterator<T>{
public:
    VectorIterator<T>(VectorAggregate<T> * vector) : myCollection(vector), myIndex(0){}

    void first(){
        myIndex = 0;
    }

    void next(){
        myIndex++;
    }

    bool isDone() {
        return (myCollection->count() <= myIndex);
    }

    T currentItem(){
        return myCollection->get(myIndex);
    }
private:
    VectorAggregate<T> * myCollection;
    int myIndex;
};

#endif //ITERATORPATTERN_ITERATOR_H
