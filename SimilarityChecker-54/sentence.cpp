using namespace std;
#include "string"
#include "vector"
#include <iostream>
class Calculate
{
public:
	/*explicit Calculate(string _p1, string _p2) :
		p1(_p1), p2(_p2) {}*/
	void setStrings(string _p1, string _p2)
	{
		p1 = _p1; p2 = _p2;
	}
	void setStrings(string _p1)
	{
		p1 = _p1; p2 = "";
	}
	float getPartialScore(string p1, string p2)
	{
		int long_string_digit = p1.size() >= p2.size() ? p1.size() : p2.size();
		int short_string_digit = p1.size() >= p2.size() ? p2.size() : p1.size();
		int gap = long_string_digit - short_string_digit;
		return (1 - float(float(gap) / float(short_string_digit))) * SCORE_FOR_FULL_SUCCESS;
	}
	float getLengthScore()
	{
		if (p1.size() == p2.size())
			return SCORE_FOR_FULL_SUCCESS;
		if ((p1.size() >= 2 * p2.size()) || (p2.size() >= 2 * p1.size()))
			return 0;

		return getPartialScore(p1, p2);
	}

	vector<char> putAlphabetToVector(string str)
	{
		vector<char> vec;
		for (char c : str)
		{
			bool found = false;
			for (int i = 0; i < vec.size(); i++) {
				if (vec[i] == c)				{
					found = true;
					break;
				}
					
			}
			if (!found)			{
				vec.push_back(c);
				
			}
		}
		return vec;
	}
	
	int getTotalCnt()
	{
		/*vector<char> candidates_a = putAlphabetToVector(p1);
		vector<char> candidates_b = putAlphabetToVector(p2);*/
		vector<char> total = putAlphabetToVector(p1 + p2);
		return total.size();
	}
	int getSameCnt()
	{
		vector<char> candidates_a = putAlphabetToVector(p1);
		vector<char> candidates_b = putAlphabetToVector(p2);

		int cnt = 0;
		for (char a : candidates_a)
		{
			for (char b : candidates_b)
			{
				if (a == b) cnt++;
			}
		}
		return cnt;
	}
	int getAlphabetScore()
	{
		int sameCnt = getSameCnt();
		int totalCnt = getTotalCnt();
		return (sameCnt * 40 / totalCnt);
	}
private:
	string p1;
	string p2;
	int SCORE_FOR_FULL_SUCCESS = 60;
};