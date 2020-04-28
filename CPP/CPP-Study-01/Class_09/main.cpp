#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

class House;
class Friend {

public:
	void VistBy_GoodFriend(House *host);
	void VistBy_NGPONG(House *host);
};

class House {

	/* 全局函数声明 */
	friend void fun_test(House *host);

	/* 类声明 */
	friend class Friend;

	/* 类中的成员函数声明 */
	friend void Friend::VistBy_GoodFriend(House *host);

private:
	void Go2_BedRoom(void) {
		cout << "Enter BedRoom" << endl;
	}
	
public:
	void Go2_Toliet(void) {
		cout << "Enter toliet" << endl;
	}
};

void Friend::VistBy_GoodFriend(House *host) {
	host->Go2_BedRoom();
}

void Friend::VistBy_NGPONG(House *host) {
	host->Go2_BedRoom();
}

void fun_test(House *host) {
	host->Go2_BedRoom();
}


int main(void) {

	House *house = new House();

	Friend *fre = new Friend();
	fre->VistBy_GoodFriend(house);
	fre->VistBy_NGPONG(house);

	fun_test(house);


	delete fre;
	delete house;

	system("pause");
	return EXIT_SUCCESS;
}
