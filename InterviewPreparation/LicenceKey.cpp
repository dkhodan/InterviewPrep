#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	string licenseKeyFormatting(string s, int k) {
		string str;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '-') continue;

			str += s[i];
		}

		string key;

		if (str.size() == 1)
		{
			key += toupper(str[0]);
			return key;
		}

		int mod = str.size() % k;
		int pointer = 0;
		int dash_counter = 0;

		if (mod != 0)
		{
			for (; pointer < mod; pointer++)
			{
				key += toupper(str[pointer]);
			}

			key += '-';
		}
		for (; pointer < str.length(); pointer++)
		{
			if (dash_counter == k)
			{
				key += '-';
				dash_counter = 0;
			}

			key += toupper(str[pointer]);
			dash_counter++;
		}
		return key;
	}
};

int main_1()
{
	Solution sol;

	std::cout << sol.licenseKeyFormatting("2-4A0r7-4k", 3) << std::endl;
	return 0;
}