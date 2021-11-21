#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		if (s.empty()) return 0;
		if (s.size() == 1) return 1;

		vector<char> temp;
		int max_value = 0;

		for (int i = 0; i < s.size(); i++)
		{
			temp.push_back(s[i]);
			for (int flow_pointer = i + 1; flow_pointer <= s.size(); flow_pointer++)
			{
				if (flow_pointer == s.size())
				{
					return max_value < temp.size() ? temp.size() : max_value;
				}

				if (find(begin(temp), end(temp), s[flow_pointer]) == end(temp))
				{
					temp.push_back(s[flow_pointer]);
					continue;
				}

				if (max_value < temp.size()) max_value = temp.size();
				temp.clear();
				break;
			}
		}
		return max_value < temp.size() ? temp.size() : max_value;
	}
};

int main()
{
	Solution sol;

	std::cout << sol.lengthOfLongestSubstring("bbbbb") << std::endl;
	return 0;
}