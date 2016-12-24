#include <iostream>
#include <vector>
#include <cassert>
#include <string>
using namespace std;

enum attribute {color, number, shape, shade};

//card is represented by string "wxyz"

vector<string> group3(vector<string> cards, int a, int b, int c){
	vector<string> ret;
	ret.clear();

	ret.push_back(cards[a]);
	ret.push_back(cards[b]);
	ret.push_back(cards[c]);

	return ret;
}

bool same(vector<string> cards, attribute att){
	assert(cards.size() == 3);
	return ((cards[0][att] == cards[1][att]) and (cards[1][att] == cards[2][att]));
}

bool diff(vector<string> cards, attribute att){
	assert(cards.size() == 3);
	return ((cards[0][att] != cards[1][att]) and
			(cards[1][att] != cards[2][att]) and 
			(cards[0][att] != cards[2][att]));
}

int main(){
	return 0;
}
