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


TEST_F(SentenceTestFixture, 01_AlphabetDiffLoc) {
	cal.setStrings(string("ASD"), string("DSA"));
	EXPECT_EQ(40, cal.getAlphabetScore());
}
TEST_F(SentenceTestFixture, 02_AlphabetAllDifferentTest) {
	cal.setStrings(string("A"), string("BB"));
	EXPECT_EQ(0, cal.getAlphabetScore());
}
TEST_F(SentenceTestFixture, 03_AlphabetAllSameCatTest) {
	cal.setStrings(string("AAABB"), string("BA"));
	EXPECT_EQ(40, cal.getAlphabetScore());
}
TEST_F(SentenceTestFixture, 04_AlphabetPartialSameTest) {
	cal.setStrings(string("AA"), string("AAE"));
	EXPECT_EQ(20, cal.getAlphabetScore());
}
