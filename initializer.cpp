#include <iostream>
#include <string>
using namespace std;

class SomeRandomClass {
	int value;
public:
	SomeRandomClass(int value = 0) {
		this->value = value;
	}
	int getValue() {
		return this->value;
	}
	void setValue(int value) {
		this->value = value;
	}
	friend istream& operator>>(istream &in, SomeRandomClass &src);
	friend ostream& operator<<(ostream &out, SomeRandomClass src);
};

istream& operator>>(istream &in, SomeRandomClass &src) {
	in >> src.value;
	return in;
}

ostream& operator<<(ostream &out, SomeRandomClass src) {
	out << src.value;
	return out;
}

void initializer() {

}

template<typename First, typename ... Rest>
void initializer(First &first, Rest &... rest) {
	cout << "Enter the value of the argument type " << typeid(first).name()
			<< endl;
	cin >> first;
	initializer(rest...);
}

int main() {
	int i { };
	float f { };
	double d1 { }, d2 { };
	char c { };
	long long ll { };
	SomeRandomClass src { };
	string str;
	initializer(i, f, d1, d2, c, ll, str, src);
	cout << i << endl << f << endl << d1 << endl << d2 << endl << c << endl
			<< ll << endl << str << endl << src << endl;

	return 0;
}
