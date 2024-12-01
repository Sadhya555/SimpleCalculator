#include <iostream>
#include <vector>
#include <string>

void error(std::string errortext) {
	std::cerr << errortext << '\n';
	exit(1);
}

int main()
{

	std::cout << "Please enter expression (+ or - or * or /)\n";
	std::cout << "Add an x to end expression: ";

	int lval = 0;
	int rval = 0;
	std::cin >> lval;
	if (!std::cin)
		error("no first operand");
	for (char op; std::cin >> op;) {
		if (op != 'x')
			std::cin >> rval;
		if (!std::cin)
			error("no second operand");
		switch (op) {
		case '+':
			lval += rval;
			break;
		case '-':
			lval -= rval;
			break;
		case '*':
			lval *= rval;
			break;
		case '/':
			lval /= rval;
			break;
		default:
			std::cout << "Result: " << lval << "\n";
			return 0;
		}
	}
	error("bad expression");

}