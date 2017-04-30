#include <iostream>
#include <vector>
#include <cassert>
#include <string>
#include <cstdlib>
using namespace std;

enum attribute {color, number, shape, shade};

//card is represented by string "wxyz"

/* 
	color w: (r, red), (p, purple), (g, green)
	number x: 1, 2, 3
	shape y: (o, oval), (d, diamond), (s, squiggle)
	shade z: (b, blank), (d, dashed), (f, filled)
*/

/*vector<string> group3(vector<string> cards, int a, int b, int c){
	vector<string> ret;
	ret.clear();

	ret.push_back(cards[a]);
	ret.push_back(cards[b]);
	ret.push_back(cards[c]);

	return ret;
}*/

bool same(string cardA, string cardB, string cardC, int att){
	return ((cardA[att] == cardB[att]) and (cardB[att] == cardC[att]));
}

bool diff(string cardA, string cardB, string cardC, int att){
	return ((cardA[att] != cardB[att]) and
			(cardB[att] != cardC[att]) and 
			(cardA[att] != cardC[att]));
}

string genrand(){
	//===================Look up rand() syntax===================//
	return "\0";
}

bool checkcorrect(string card){
	if((card[0] != 'r') and (card[0] != 'p') and (card[0] != 'g')){
		cout << "0" << '\n';
		return false;
	}

	if(((card[1] - '0') > 3) or ((card[1] - '0') < 1)){
		cout << (card[1] - '0') << '\n';
		cout << "1" << '\n';
		return false;
	}

	if((card[2] != 'o') and (card[2] != 'd') and (card[2] != 's')){
		cout << "2" << '\n';
		return false;
	}

	if((card[3] != 'b') and (card[3] != 'd') and (card[3] != 'f')){
		cout << "3" << '\n';
		return false;
	}

	return true;
}

string takeinput(){
	string newcard;

	while (true){
		cin >> newcard;
		if(newcard.length() != 4){
			cout << "string must be length 4\n";
			continue;
		}

		if(checkcorrect(newcard)){
			break;
		} else {
			cout << "check your input\n";
		}
	}

	return newcard;
}

bool isset(string cardA, string cardB, string cardC){
	int matchcounter = 0;

	for (int i = 0; i < 4; ++i){
		if(same(cardA, cardB, cardC, i) or diff(cardA, cardB, cardC, i)){
			matchcounter++;
		}
	}

	return (matchcounter == 4);
}

int main(){
	cout << "Enter 1 for old version, 2 for new version." << '\n';
	int temp;
	cin >> temp;

	int numcards;
	vector<string> cards;

	if(temp == 1){
		cout << "Find sets in how many cards? ";
		cin >> numcards;
		cards.reserve(numcards);

		cout << "Enter a string with length 4.\n" << 
			"color w: (r, red), (p, purple), (g, green)\n" << 
			"number x: 1, 2, 3\n" << 
			"shape y: (o, oval), (d, diamond), (s, squiggle)\n" << 
			"shade z: (b, blank), (d, dashed), (f, filled)\n";


		for(int i = 0; i < numcards; ++i){
			cards[i] = takeinput();
		}

	} else if(temp == 2){
		cards.reserve(12);
		for(int i = 0; i < 12; ++i){
			cards[i] = "";
		}
		char att;
		for(int i = 0; i < 4; ++i){
			cout << "enter attribute #" << i << '\n';
			for(int j = 0; j < 12; ++j){
				cin >> att;
				cards[j].push_back(att);
			}
		}

		numcards = 12;

	} else {
		return 0;
	}

	for (int i = 0; i < numcards; ++i){
		for (int j = i + 1; j < numcards; ++j){
			for (int k = j + 1; k < numcards; ++k){
				if (isset(cards[i], cards[j], cards[k])){
					cout << cards[i] << " " << cards[j] << " " << cards[k] << '\n';
				}
			}
		}
	}

	return 0;
}
