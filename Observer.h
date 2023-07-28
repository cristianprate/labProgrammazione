//
// Created by prate on 11/07/2023.
//

#ifndef LABPROGRAMMAZIONE_OBSERVER_H
#define LABPROGRAMMAZIONE_OBSERVER_H


#include <string>

class Observer {
private:

public:
    virtual void update() = 0;

    virtual ~Observer() {}

};


#endif //LABPROGRAMMAZIONE_OBSERVER_H
