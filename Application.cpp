//
// Created by prate on 11/07/2023.
//

#include <iostream>
#include "Application.h"
#include "BlockedObserver.h"


Application::Application() {
    newCollection("Important");
};

void Application::addToCollection(const std::string &title, const std::string &text, const std::string &collName) {
    for (auto collection: collections) {
        if (collection->getName() == collName)
            collection->addNote(title, text);
    }
}

bool Application::newCollection(const std::string &name) {
    bool output = true;
    for (auto collection: collections) {
        if(collection->getName() == name)
            output = false;
    }
    if(output){
        auto *coll = new Collection(name);
        collections.emplace_back(coll);
        collectionsObs.push_back(new BlockedObserver(coll));
    }
    return output;
}

void Application::displayNotesFromCollection(const std::string &name) const {
    for (auto collection: collections) {
        if (collection->getName() == name) {
            std::cout << "Total number of notes in the collection: " << collection->getTotNotes() << std::endl;
            collection->displayNotes();
        }
    }
}

void Application::displayCollections() const {
    for (auto collection: collections) {
        std::cout << collection->getName() << std::endl;
    }
}

bool Application::addToImportant(const std::string &title) {
    Collection *appo;
    for (auto collection: collections) {
        if (collection->getName() == "Important")
            appo = collection;
    }
    for (auto collection: collections) {
        if (collection->findNote(title)) {
            appo->addNote(title, collection->getText(title));
            if (collection->isLocked(title)) {
                appo->changeLock(title);
            }
            return true;
        }
    }
    return false;
}

bool Application::modifyNote(const std::string &collTitle, const std::string &title, const std::string &newText) {
    bool output = false;
    for (auto collection: collections) {
        if (collTitle == collection->getName())
            output = collection->modifyNote(title, newText);
    }
    return output;
}

bool Application::changeLock(const std::string &collTitle, const std::string &title) {
    bool output = false;
    for (auto collection: collections) {
        if (collection->findNote(title) && collTitle == collection->getName()) {
            collection->changeLock(title);
            output = true;
        }
    }
    return output;
}

bool Application::deleteNote(const std::string &collTitle, const std::string &title) {
    bool output = false;
    for (auto collection: collections) {
        if (collTitle == collection->getName()) {
            output = collection->deleteNote(title);
        }
    }
    return output;
}

unsigned int Application::getCollectionsNumber() const {
    return collections.size();
}

Application::~Application() {

}

