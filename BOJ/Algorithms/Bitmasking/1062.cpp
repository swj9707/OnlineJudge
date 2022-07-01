#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int end_bit = 26;

vector<int> check_mask;
vector<int> bit_words;

void check(int bits_for_check, int now_pos, int cnt){
    if(cnt == 0){
        check_mask.push_back(bits_for_check);
        return;
    }

    if(now_pos == end_bit){
        return;
    }

    int new_bits_for_check = (bits_for_check | (1 << now_pos));

    check(new_bits_for_check, now_pos + 1, cnt - 1);
    check(bits_for_check, now_pos + 1, cnt);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int word, spell; cin >> word >> spell;
    vector<string> words;

    for(int i = 0; i < word; i++){
        string s; cin >> s;
        words.push_back(s);
    }

    if(spell < 5){
        cout << "0\n";
        return 0;
    }

    for(string s : words){
        int new_bit = 0;
        for(char c : s){
            new_bit |= (1 << (c - 97));
        }
        bit_words.push_back(new_bit);
    }

    check(0, 0, spell);

	int answer = 0;

	for (int check_bit : check_mask)
	{
		int new_answer = 0;
		for (int bit_word : bit_words)
		{
			if ((check_bit & bit_word) == bit_word) new_answer++;
		}

		if (new_answer > answer) answer = new_answer;
	}

	cout << answer << '\n';

	return 0;

}