using namespace std;
#include "string"

class Calculate
{
public:
	/*explicit Calculate(string _p1, string _p2) :
		p1(_p1), p2(_p2) {}*/
	void setStrings(string _p1, string _p2)
	{
		p1 = _p1; p2 = _p2;
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
private:
	string p1;
	string p2;
	int SCORE_FOR_FULL_SUCCESS = 60;
};