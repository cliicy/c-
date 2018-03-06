#include "iostream"

namespace solution{
	using namespace std;

		void sort(string& s){
			for (unsigned int i = 0; i < s.length(); i++){
				for (unsigned int k = 1; k < s.length(); k++)
				{
					if (s[i]>s[k])
					{
						char c = s[i];
						s[i] = s[k];
						s[k] = c;
					}
				}
			}
		}

		bool checkstr(string s1, string s2){
			sort(s1);
			sort(s2);
			return (s1 == s2);
		}

		bool isScreamble(string s1, string s2){
			if (s1 == "") return s2 == "";
			if (checkstr(s1, s2) == false) return false;
			int len = s1.length();
			if (len == 1)return true;

			for (unsigned int i = 1; i < s1.length(); i++){
				string left = s1.substr(0, i);
				string right = s1.substr(i);
				if (isScreamble(left, s2.substr(i)) && isScreamble(right, s2.substr(i)) || \
					isScreamble(left, s2.substr(len - i)) && isScreamble(right, s2.substr(len - i)))
					return true;

			}
			return false;
		}
}
