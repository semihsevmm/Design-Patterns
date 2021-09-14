//
// Created by Semih on 1.04.2021.
//

#ifndef BUILDERPATTERN_BUILDER_H
#define BUILDERPATTERN_BUILDER_H
class LevelTemplate{
public:
    virtual void setYaratik(int maxYaratikSeviye) = 0;
    virtual void setAsker(int maxAskerSeviye) = 0;
    virtual void setOrtam(std::string ortam) = 0;
};

class GameLevel: public LevelTemplate{
public:
    void setYaratik(int maxYaratikSeviye){
        this->yaratikSeviye = maxYaratikSeviye;
    }
    void setAsker(int maxAskerSeviye){
        this->askerSeviye = maxAskerSeviye;
    }
    void setOrtam(std::string ortam){
        this->levelOrtam = ortam;
    }

    void getoyunLevelInfo(){
        std::cout<< "Max yaratik seviyesi: " << this->yaratikSeviye << std::endl;
        std::cout<< "Max asker seviyesi: " << this->askerSeviye << std::endl;
        std::cout<< "Oyunun gececegi ortam: " << this->levelOrtam;
    }
private:
    int yaratikSeviye, askerSeviye;
    std::string levelOrtam;
};
// Builder Abstract class
class LevelDesign{
public:
   virtual void yaratikOlustur() = 0;
   virtual void askerOlustur() = 0;
   virtual void ortamOlustur() = 0;
   virtual GameLevel* getOyunLevel() = 0;
};

class KolaySeviye: public LevelDesign{
private:
    GameLevel* kolaySeviye;
public:
    KolaySeviye(){
        kolaySeviye = new GameLevel();
    }
    void yaratikOlustur(){
        kolaySeviye->setYaratik(5);
    }
    void askerOlustur(){
        kolaySeviye->setAsker(5);
    }
    void ortamOlustur(){
        kolaySeviye->setOrtam("Orman");
    }

    GameLevel* getOyunLevel(){
        return this->kolaySeviye;
    }
};

class ZorSeviye: public LevelDesign{
private:
    GameLevel* zorSeviye;
public:
    ZorSeviye(){
        zorSeviye = new GameLevel();
    }
    void yaratikOlustur(){
        zorSeviye->setYaratik(50);
    }
    void askerOlustur(){
        zorSeviye->setAsker(50);
    }
    void ortamOlustru(){
        zorSeviye->setOrtam("Çöl");
    }

    GameLevel* getOyunLevel(){
        return this->zorSeviye;
    }
};

class Designer{
private:
    LevelDesign* levelDesign;
public:
    Designer(LevelDesign* levelDesign){
        this->levelDesign = levelDesign;
    }
    GameLevel* getOyunLevel(){
        return levelDesign->getOyunLevel();
    }
    void levelOlustur(){
        levelDesign->yaratikOlustur();
        levelDesign->askerOlustur();
        levelDesign->ortamOlustur();
    }


};
#endif //BUILDERPATTERN_BUILDER_H
