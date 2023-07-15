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

TEST_F(ApplicationSuite, AddToImportantTest){
    ASSERT_TRUE(a.addToImportant("cosa portare"));
}

TEST_F(ApplicationSuite, AddToImportantWrongTest){
    ASSERT_FALSE(a.addToImportant("dove andare"));
}

TEST_F(ApplicationSuite, ModifyNoteTest){
    ASSERT_TRUE(a.modifyNote("cosa portare", "acqua"));
}


