#include <stdio.h>
#include <Windows.h>

int main(void) {

	char arrary[] = { '1','2','\0' };

	printf("%s\n", arrary);

	//for (size_t i = 0; i < sizeof(arrary) / sizeof(arrary[0]); i++)
	//{
	//	printf("%d\n", arrary[i]);
	//}

	system("paurse");
	return 0;
}