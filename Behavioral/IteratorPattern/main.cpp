#include <iostream>
#include "iterator.h"

int main() {
    Aggregate<Film> * filmListem = new VectorAggregate<Film>();

    filmListem->append(Film("Esaretin Bedeli", "Drama"));
    filmListem->append(Film("Baba","Suc,Drama"));
    filmListem->append(Film("Baba2","Suc,Drama"));
    filmListem->append(Film("Kara Sovalye","Aksiyon,Suc,Drama"));
    filmListem->append(Film("12 Ofkeli Adam","Suc,Drama"));
    filmListem->append(Film("Schindler\'in Listesi","Biyografi,Drama,Tarih"));

    Iterator<Film> * filmIterator = filmListem->createIterator();

    for(filmIterator->first(); !filmIterator->isDone(); filmIterator->next())
    {
         filmIterator->currentItem().getInfo();
    }
}
