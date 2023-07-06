using namespace std;
#include "string"

class Sentence
{
public:
	explicit Sentence(string p1, string p2) :
		string1(p1), string2(p2), score(0){}

	string string1;
	string string2;
	int score;
private:
	
};

class Calculate
{
public:
	explicit Calculate(Sentence _sen) :
		sen(_sen) { }
	int getPartialScore(string p1, string p2)
	{
		int long_string_digit = p1.size() >= p2.size() ? p1.size() : p2.size();
		int short_string_digit = p1.size() >= p2.size() ? p2.size() : p1.size();
		int gap = long_string_digit - short_string_digit;
		return (1 - float(float(gap) / float(short_string_digit))) * 60;
	}
	int getLengthScore(string p1, string p2)
	{
		if (p1.size() == p2.size())
			return 60;
		if ((p1.size() >= 2 * p2.size()) || (p2.size() >= 2 * p1.size()))
			return 0;

		return getPartialScore(p1, p2);

	}
private:
	Sentence sen;
};