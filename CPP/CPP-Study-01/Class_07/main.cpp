#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class Person {

private:
    static int Age;
public:
    static char *Name;

    static void Set_Age(int age) {

        Age = age;
    }

    static void Print();
};
int Person::Age;
char *Person::Name = (char *)"NGPONG";
void Person::Print() {

    cout << "Person name = " << Person::Name << endl;
    cout << "Person age = " << Person::Age << endl;
};

int main(void) {

    Person::Set_Age(23);
    Person::Print();

	system("pause");
	return EXIT_SUCCESS;
}
