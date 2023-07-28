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
    ASSERT_TRUE(a.modifyNote("mare","cosa portare", "acqua"));
}

TEST_F(ApplicationSuite, DuplicateCollTest){
    ASSERT_FALSE(a.newCollection("mare"));
    ASSERT_EQ(2, a.getCollectionsNumber());
}

TEST_F(ApplicationSuite, WrongDeleteNoteTest){
    ASSERT_FALSE(a.deleteNote("mare", "cosa fare"));
    ASSERT_FALSE(a.deleteNote("montagna", "cosa portare"));
}

TEST_F(ApplicationSuite, CollNumberTest){
    a.newCollection("Montagna");
    ASSERT_EQ(3, a.getCollectionsNumber());
}




