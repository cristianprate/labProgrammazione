//
// Created by prate on 15/07/2023.
//

#include <iostream>
#include "BlockedObserver.h"

BlockedObserver::BlockedObserver(Collection* subject) : c(subject){
    c->registerO(this);
}

BlockedObserver::~BlockedObserver() {
        c->removeO(this);
}

void BlockedObserver::update() {
    std::cout<<std::endl;
    std::cout << "STATO DELLA COLLEZIONE " << c->getName() << " ALTERATO:" << std::endl;
    std::cout << "Numero note bloccate: " << c->getTotBlocked() << ";" << std::endl;
}
