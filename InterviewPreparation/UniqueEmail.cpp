#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {		
		set<string> result;
		for (auto& email : emails)
		{
			string local = email.substr(0, email.find("@"));
			string domain = email.substr(email.find("@"), email.size());
			string name;

			for (auto& ch : local)
			{
				if(ch == '+') break;
				if(ch == '.') continue;

				name += ch;
			}

			result.insert(name.append(domain));
		}
		return result.size();
	}
};

int main_0()
{

	Solution sol;
	vector<string> vec = { "test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com" };
	std::cout << "size:" << sol.numUniqueEmails(vec) << " . " << std::endl;
	return 0;
}