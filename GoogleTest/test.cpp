#include "pch.h"
#include "string"
#include "../SimilarityChecker-54/sentence.cpp"
using namespace std;

class SentenceTestFixture : public testing::Test {
public:
	Calculate cal;
private:
};

TEST_F(SentenceTestFixture, lengthCheck) {
	string input1 = "abc";
	string input2 = "bby";
	int ret = cal.getLengthScore(input1, input2);
  EXPECT_EQ(1, 1);
  
}