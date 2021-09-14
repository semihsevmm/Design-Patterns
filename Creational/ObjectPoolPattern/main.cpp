#include <iostream>
#include "objectPool.h"
#include <map>
using namespace std;
int main() {
    Renk* red = new  Renk(255,0,0,"kirmizi");
    cout<<red->name<<" renk olusturuldu"<<endl<<"Adresi: "<<red<<endl;

    Renk* blue = new Renk(0,0,255,"mavi");
    cout<<blue->name<<" renk olusturuldu"<<endl<<"Adresi: "<<blue<<endl;

    //Object pool nesnesi
    Palet<Renk> myPalet;

    myPalet.addObject(red);
    myPalet.addObject(blue);

    Renk* red2 = myPalet.getObject("kirmizi");
    cout<<red2->name<<" tekrar kullaniliyor"<<endl<<"Adresi:"<<red2<<endl;
    Renk* blue2 = myPalet.getObject("mavi");
    cout<<blue2->name<<" tekrar kullaniliyor"<<endl<<"Adresi:"<<blue2<<endl;
    //std::cout<<red2<<endl;
    return 0;
}
