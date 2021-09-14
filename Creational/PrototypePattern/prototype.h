//
// Created by Semih on 31.03.2021.
//

#ifndef PROTOTYPEPATTERN_PROTOTYPE_H
#define PROTOTYPEPATTERN_PROTOTYPE_H
class SinavKagidi{
public:
    int sure, soruSayisi;
    std::string sinavTur;
};

class Matematik: public SinavKagidi{
public:
    Matematik(){}
    Matematik(int sure, int soruSayisi, std::string tur){
        this->sure = sure;
        this->soruSayisi = soruSayisi;
        this->sinavTur = tur;
    }
    //Copy Constructure - Deep Copy
    Matematik(const SinavKagidi &kagit){
        this->sure = kagit.sure;
        this->soruSayisi = kagit.soruSayisi;
        this->sinavTur = kagit.sinavTur;
    }
    void getSinavBilgisi(){
        std::cout<<"Matematik Sinavi "<< std::endl;
        std::cout<<"Sinav Suresi: "<< this->sure<< std::endl;
        std::cout<<"Sinav Turu: "<< this->sinavTur<< std::endl;
        std::cout<<"Soru Sayisi: "<< this->soruSayisi<< std::endl;
        std::cout<<"Bellek Adresi: "<< this<< std::endl;
    }
};

class Turkce: public SinavKagidi{
public:
    Turkce()
    {}
    Turkce (int sure, int soruSayisi, std::string tur){
        this->sure = sure;
        this->soruSayisi = soruSayisi;
        this->sinavTur = tur;
    }
    //Copy Constructure - Deep Copy
    Turkce (const SinavKagidi &kagit){
        this->sure = kagit.sure;
        this->soruSayisi = kagit.soruSayisi;
        this->sinavTur = kagit.sinavTur;
    }
    void getSinavBilgisi(){
        std::cout<<"Turkce Sinavi "<< std::endl;
        std::cout<<"Sinav Suresi: "<< this->sure<< std::endl;
        std::cout<<"Sinav Turu: "<< this->sinavTur<< std::endl;
        std::cout<<"Soru Sayisi: "<< this->soruSayisi<< std::endl;
        std::cout<<"Bellek Adresi: "<< this<< std::endl;
    }
};

#endif //PROTOTYPEPATTERN_PROTOTYPE_H
