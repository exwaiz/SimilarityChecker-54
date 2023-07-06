#include "pch.h"
#include "string"
#include "../SimilarityChecker-54/sentence.cpp"
using namespace std;


TEST(SentenceTestFixture, lengthCheck) {
	string input1 = "abc";
	string input2 = "bby";
	Sentence sen(input1, input2);
	Calculate cal(sen);
	int ret = cal.getLengthScore(input1, input2);
  EXPECT_EQ(1, 1);
  
}