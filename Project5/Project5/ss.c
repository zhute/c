#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Menu(){
	printf("==========\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("==========\n");
	printf("请输入数字：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void Game(){
	int toGuess = rand() % 100 + 1;
	while (1){
		printf("输入1-100");
		int num = 0;
		scanf("%d", &num);
		if (num < toGuess){
			printf("低了\n");
		}
		else if (num>toGuess){
			printf("高了\n");
		}
		else{
			printf("正确\n");
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
			printf("溜了溜了\n");
			break;
		}
		else{
			printf("错误！请重输：\n");
		}

	}
	system("pause");
	return 0;
  

}
