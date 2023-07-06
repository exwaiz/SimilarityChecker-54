#include "pch.h"
#include "string"
#include "../SimilarityChecker-54/sentence.cpp"
#include "cmath"
using namespace std;


TEST(SentenceTestFixture, lengthCheck) {
	string input1 = "abc";
	string input2 = "bby";
	Sentence sen(input1, input2);
	Calculate cal(sen);
	int ret = cal.getLengthScore(input1, input2);
  EXPECT_EQ(60, ret);
}
TEST(SentenceTestFixture, lengthCheck0Case) {
	string input1 = "abc";
	string input2 = "defopq";
	Sentence sen(input1, input2);
	Calculate cal(sen);
	int ret = cal.getLengthScore(input1, input2);
	EXPECT_EQ(0, ret);
}

TEST(SentenceTestFixture, lengthCheckGetPartialScoreCase1) {
	string input1 = "AA";
	string input2 = "AAE";
	Sentence sen(input1, input2);
	Calculate cal(sen);
	int ret = cal.getPartialScore(input1, input2);
	EXPECT_EQ(30, ret);
}


TEST(SentenceTestFixture, lengthCheckGetPartialScoreCase2) {
	string input1 = "AAABB";
	string input2 = "BAA";
	Sentence sen(input1, input2);
	Calculate cal(sen);
	float ret = cal.getPartialScore(input1, input2);
	int ret2 = ceil(ret);
	EXPECT_EQ(int(20), ret2);
}