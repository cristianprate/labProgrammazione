//
// Created by prate on 11/07/2023.
//

#include <iostream>
#include "Application.h"

Application::~Application() {

}

void Application::notify(const std::string & title, const std::string & text, const std::string &collName) {
    for(auto collection : collections){
        if(collection->getName() == collName) {
            collection->update(title, text);
        }
    }
}

void Application::addToCollection(const std::string &title, const std::string &text, const std::string &collName) {
    notify(title, text, collName);
}

void Application::registerO(Observer *const obs) {
    collections.push_back(dynamic_cast<Collection*>(obs));
}

void Application::removeO(Observer *const obs) {
    collections.push_back(dynamic_cast<Collection*>(obs));
}

Application::Application(){
    newCollection("Important");
};

void Application::newCollection(const std::string name) {
    new Collection(name, this);
}

void Application::displayNotesFromCollection(const std::string name) {
    for(auto collection : collections){
        if(collection->getName() == name)
           collection->displayNotes();
    }
}

void Application::displayCollections() {
    for(auto collection : collections){
            std::cout << collection->getName() << std::endl;
    }
}

void Application::addToImportant(const std::string &title) {
    for(auto collection : collections){
        for(const auto& note : collection->getNotes()){
            if(note.getTitle() == title)
                addToCollection(note.getTitle(), note.getText(), "Important");
        }
    }
}

void Application::modifyNote(const std::string& title, const std::string& newText) {
    for(auto collection : collections){
        collection->modifyNote(title, newText);
    }
}

void Application::changeLock(const std::string title) {
    for(auto &collection : collections){
        for(const auto& note : collection->getNotes()){
            if(note.getTitle() == title)
                collection->changeLock(title);
        }
    }
}

