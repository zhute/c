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
	printf("�������\n");
	while (1){
		printf("������Ҫ����λ�õ����꣨�� �У�");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("���������������������\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			//���λ��������
			printf("�������λ��������\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
}
void computermove(){
	printf("��������\n");
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
//����x���ʤ����o����ʤ���ؿո�ʤ��δ�ַ���q����
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
	//�Ƿ����
	if (isfull()){
		return 'q';
	}
	return ' ';
}
int main()
{
	//1.�������β���ʼ����������
	Init();
	char winner = ' ';
	while (1){
		printchessboard();

		//2.��ӡ����
		playermove();
		//3Ҫ��������ӣ����û���������
		winner = checkwinner();
		if (winner != ' '){
			break;
		}
		//4�ж���Ϸʤ��
		computermove();
		//5Ҫ��������ӣ��������
		winner = checkwinner();
		if (winner != ' '){
			break;
		}
		//6�ж���Ϸʤ��
		//7�ص�2ѭ��ִ��
	}
	if (winner == 'x'){
		printf("��Ӯ��\n");
	}
	else if (winner == 'o'){
		printf("������\n");
	}
	else {
		printf("���忪\n");
	}
	system("pause");
	return 0;
}