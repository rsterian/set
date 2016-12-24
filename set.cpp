#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

enum Color {red, green, purple};
enum Shape {oval, diamond, squiggle};

class Card {
public:
	Card(Color c, int num, Shape s) : color(c), number(num), shape(s) {}

	Color color;
	int number;
	Shape shape;
};

vector<Card> group3(vector<Card> cards, int a, int b, int c){
	vector<Card> ret;
	ret.clear();

	ret.push_back(cards[a]);
	ret.push_back(cards[b]);
	ret.push_back(cards[c]);

	return ret;
}

bool same_color(vector<Card> cards){
	assert(cards.size() == 3);
	return ((cards[0].color == cards[1].color) and (cards[1].color == cards[2].color));
}

bool diff_color(vector<Card> cards){
	assert(cards.size() == 3);
	return ((cards[0].color != cards[1].color) and
			(cards[1].color != cards[2].color) and 
			(cards[0].color != cards[2].color));
}

int main(){
	return 0;
}
