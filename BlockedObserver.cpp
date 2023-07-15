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
    system("cls");
    std::string input;
    do {
        std::cout << "STATO DELLA COLLEZIONE " << c->getName() << " ALTERATO:" << std::endl;
        std::cout << "Numero note bloccate: " << c->getTotBlocked() << ";" << std::endl;
        std::cout << "Premere 'a' per continuare..." << std::endl;
        std::cin >> input;
    }while(input != "a");
}
