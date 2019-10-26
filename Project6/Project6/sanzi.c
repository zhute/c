#define _CRT_SECURE_NO_WARNINGS 
#define MAX_ROW 3
#define MAX_COL 3
#include<stdio.h>
#include<stdlib.h>

char chess_board[MAX_ROW][MAX_COL];
void Init(){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chess_board[row][col] = ' ';
		}
	}

}

void printchessboard(){
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		printf("+---+---+---+\n");
	}
}
void playermove(){
	printf("玩家落子\n");
	while (1){
		printf("请输入要落子位置的坐标（行 列）");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("你的输入有误，请重新输入\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			//这个位置有子了
			printf("你输入的位置有子了\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
void computermove(){
	printf("电脑落子\n");
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (chess_board[row][col] != ' '){
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
}
int isfull(){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			if (chess_board[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}
//返回x玩家胜返回o电脑胜返回空格胜负未分返回q和棋
char checkwinner(){
	for (int row = 0; row < MAX_ROW; row++){
		if (chess_board[row][0] != ' '&&chess_board[row][0] == chess_board[row][1] && chess_board[row][2] == chess_board[row][1]){
			return chess_board[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++){
		if (chess_board[0][col] != ' '&&chess_board[1][col] == chess_board[0][col] && chess_board[1][col] == chess_board[2][col]){
			return chess_board[col][0];
		}
	}
	if (chess_board[0][0] != ' '&&chess_board[0][0] == chess_board[2][2] && chess_board[0][0] == chess_board[1][1]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] != ' '&&chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	//是否和棋
	if (isfull()){
		return 'q';
	}
	return ' ';
}
int main()
{
	//1.创建期盼并初始化，空棋盘
	Init();
	char winner = ' ';
	while (1){
		printchessboard();

		//2.打印棋盘
		playermove();
		//3要求玩家落子，让用户输入坐标
		winner = checkwinner();
		if (winner != ' '){
			break;
		}
		//4判定游戏胜负
		computermove();
		//5要求电脑落子，随机落子
		winner = checkwinner();
		if (winner != ' '){
			break;
		}
		//6判定游戏胜负
		//7回到2循环执行
	}
	if (winner == 'x'){
		printf("你赢了\n");
	}
	else if (winner == 'o'){
		printf("你输了\n");
	}
	else {
		printf("五五开\n");
	}
	system("pause");
	return 0;
}