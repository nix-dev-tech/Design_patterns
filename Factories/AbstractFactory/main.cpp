#include<iostream>
#include "HotDrinkFactory.hpp"
#include "DrinkFactory.hpp"
using namespace std;

unique_ptr<HotDrink> make_drink(string type) {
	unique_ptr<HotDrink> drink;
	if (type == "tea") {
		drink = make_unique<Tea>();
		drink->prepare(200);
	}
	else {
		drink = make_unique<Coffee>();
		drink->prepare(50);
	}
	return drink;
}

int main() {
	DrinkFactory df;
	auto c = df.make_drink("coffee");

}
