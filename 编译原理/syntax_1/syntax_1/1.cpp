#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;
/*
E->S
S->BB
B->aB
B->b
*/

unordered_map<string, unordered_map<string, string>>analy_map;
unordered_map<int, unordered_map<string, string>>p;

int main() {
	p[0]["S"] = "E";
	p[1]["BB"] = "S";
	p[2]["aB"] = "B";
	p[3]["b"] = "B";
	string input;
	cin >> input;
	while (input != "end") {
		int start = 0;
		string lleft;
		string rleft;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '+') {
				lleft = input.substr(start, i - start);
				start = i;
			}
			else if (input[i] == '-') {
				rleft = input.substr(start + 1, i - start - 1);
				start = i + 1;
				i++;
			}
		}
		analy_map[lleft][rleft] = input.substr(start + 1);
		cin >> input;
	}

	cout << "«Î ‰»Î ‰»Î¥Æ£∫" << endl;
	string input_str;
	cin >> input_str;
	vector<string> symbol_st;
	vector<string> state_st;
	state_st.push_back("S0");
	symbol_st.push_back("#");
	for (int i = 0; i < input_str.size(); i++) {
		string str;
		str.push_back(input_str[i]);
		string state = state_st[state_st.size() - 1];
		string curr_str = "";
		cout << "◊¥Ã¨’ª: ";
		for (auto out : state_st) {
			cout << out << " ";
		}
		//cout << endl;
		cout << "∑˚∫≈’ª: ";
		for (auto out : symbol_st) {
			cout << out << " ";
		}
		cout << "µ±«∞ ‰»Î¥Æ: " << input_str.substr(i) << " ";
		if (analy_map[state].count(str) == 0) {
			cout << "Find Error !!!" << endl;
			cout << "current symbol&input_str is" << state << " " << input_str << endl;
			break;
		}
		else {
			curr_str = analy_map[state][str];
		}
		int lenOfcurr_str = curr_str.size();
		if (curr_str == "acc") {
			cout << "acc" << endl;
			break;
		}
		if (lenOfcurr_str == 0) {
			cout << "curr_str's size is zero,please examine your code" << endl;
			break;
		}
		else {
			if (curr_str[0] == 'r') {
				string stipulation_str = p[curr_str[1] - '0'].begin()->second;
				string other_str = p[curr_str[1] - '0'].begin()->first;
				int cnt = 0;
				while (symbol_st.size() > 0 && state_st.size() > 0 && cnt < other_str.size()) {
					symbol_st.pop_back();
					state_st.pop_back();
					cnt++;
				}
				curr_str = analy_map[state_st[state_st.size() - 1]][stipulation_str];
				state_st.push_back(curr_str);
				symbol_st.push_back(stipulation_str);
				i--;
				cout << "GOTO:" << curr_str << endl;
			}
			else {
				state_st.push_back(curr_str);
				symbol_st.push_back(str);
				cout << "ACTION:" << curr_str << endl;
			}
		}
	}
}/*
 S0+a->S3
S0+b->S4
S0+S->S1
S0+B->S2
S1+#->acc
S2+a->S6
S2+b->S7
S2+B->S5
S3+a->S3
S3+b->S4
S3+B->S8
S4+a->r3
S4+b->r3
S5+#->r1
S6+a->S6
S6+b->S7
S6+B->S9
S7+#->r3
S8+a->r2
S8+b->r2
S9+#->r2
end

 ‰»Î¥Æ£∫bb#
*/