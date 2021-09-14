#include <iostream>
#include "composite.h"

int main() {
    Component *desktop =  new  Directory();
    desktop->setName("Desktop");
    Component *documents = new Directory();
    documents->setName("Documents");
    Component *games = new Directory();
    games->setName("Games");
    Component *reports = new Directory();
    reports->setName("Reports");

    Component *recycleBin = new File("Recycle Bin");
    Component *doc1 = new File("Document_1");
    Component *doc2 = new File("Document_2");
    Component *game1 = new File("Game_1");
    Component *game2 = new File("Game_2");
    Component *report1 = new File("Report_1");
    Component *report2 = new File("Report_2");

    reports->add(report1);
    reports->add(report2);

    documents->add(doc1);
    documents->add(doc2);
    documents->add(reports);

    games->add(game1);
    games->add(game2);

    desktop->add(recycleBin);
    desktop->add(documents);
    desktop->add(games);

    desktop->getPath("");
}
