//
// Created by prate on 13/07/2023.
//

#include "gtest/gtest.h"
#include "../Application.h"

class ApplicationSuite : public ::testing::Test{
protected:
    virtual void SetUp(){
        a.newCollection("mare");
        a.addToCollection("cosa portare", "ombrellone, teli", "mare");
        a.addToImportant("mare");
    }

    Application a = Application();
};
