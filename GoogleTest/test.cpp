#include "pch.h"
#include "string"
#include "../SimilarityChecker-54/sentence.cpp"
#include "cmath"
using namespace std;
class SentenceTestFixture : public testing::Test
{
public:
	Calculate cal {};

};

TEST_F(SentenceTestFixture, lengthCheck) {
	cal.setStrings(string("abc"), string("bby"));
  EXPECT_EQ(60, cal.getLengthScore());
}
TEST_F(SentenceTestFixture, lengthCheck0Case) {
	cal.setStrings(string("abc"), string("defopq"));
	EXPECT_EQ(0, cal.getLengthScore());
}

TEST_F(SentenceTestFixture, lengthCheckGetPartialScoreCase1) {
	cal.setStrings(string("AA"), string("AAE"));
	EXPECT_EQ(30, cal.getLengthScore());
}

TEST_F(SentenceTestFixture, lengthCheckGetPartialScoreCase2) {
	string input1 = "AAABB";
	string input2 = "BAA";
	cal.setStrings(string("AAABB"), string("BAA"));
	EXPECT_EQ(int(20), ceil(cal.getLengthScore()));
	//EXPECT_EQ(int(20), ret2);
}