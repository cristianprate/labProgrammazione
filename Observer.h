//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_OBSERVER_H
#define LABPROGRAMMAZIONE_OBSERVER_H


#include <string>

class Observer {
private:
    std::string name;

public:
    std::string getName(){
        return name;
    }
    virtual void update(const std::string& title, const std::string& text) =0;
    virtual ~Observer() =0;

};


#endif //LABPROGRAMMAZIONE_OBSERVER_H
