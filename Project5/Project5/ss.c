#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Menu(){
	printf("==========\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
	printf("==========\n");
	printf("���������֣�");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Game(){
	int toGuess = rand() % 100 + 1;
	while (1){
		printf("����1-100");
		int num = 0;
		scanf("%d", &num);
		if (num < toGuess){
			printf("����\n");
		}
		else if (num>toGuess){
			printf("����\n");
		}
		else{
			printf("��ȷ\n");
			break;
		}

	}


}
int main()
{
	while (1)
	{
		int choice = Menu();
		if (choice == 1){
			Game();
		}
		else if (choice == 0){
			printf("��������\n");
			break;
		}
		else{
			printf("���������䣺\n");
		}

	}
	system("pause");
	return 0;
  

}
