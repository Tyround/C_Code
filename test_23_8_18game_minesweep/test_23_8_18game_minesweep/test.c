#include "game.h"

void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	InitiBoard(mine, '0');
	InitiBoard(show, '*');
	DisplayBoard(show);
	int x = 0;
	int y = 0;
	printf("��ʼɨ��\n������������");
	int ran = 1;
	while (1)
	{
		scanf("%d", &ran);
		if (ran < 1 || ran >= 80)
			printf("���벻�Ϸ�������������\n");
		else
			break;
	}
	//�˴��ڵ�һ��ɨ�׺��������ף���ֹ��һ�ξ�ɨ�����������
	while (1)
	{
		printf("������ɨ�����꣺");
		scanf("%d %d", &x, &y);
		if (x > 0 && x < 10 && y >0 && y < 10)
			;
		else
		{
			printf("����Ƿ�������������\n");
			continue;
		}
		mine[x][y] = '2';
		break;
	}
		create_mine(mine, ran);
		scan_super(mine, show, x, y);
		DisplayBoard(show);
		//�˴����ڼ�������
		DisplayBoard(mine);

	while (1)
	{
		printf("������ɨ�����꣺");
		scanf("%d %d", &x, &y);
		if (x > 0 && x < 10 && y >0 && y < 10)
			;
		else
		{
			printf("����Ƿ�������������\n");
			continue;
		}
		if (mine[x][y] == '1')
		{
			printf("\n��ը�ˣ���Ϸ����\n\n");
			break;
		}
		else if (mine[x][y] == '2' || mine[x][y] == '3')
		{
			printf("�ô��ѱ�ɨ�裬����������");
				continue;
		}
		else
		{
			scan_super(mine, show, x, y);
			
			printf("�ô���ȫ�������ɨ��\n");
			DisplayBoard(show);
		}
		int cont = 1;
		cont = End(mine);
		if (cont == 0)
		{
			printf("\nɨ����ɣ���Ϸʤ��\n\n");
			break;
		}

	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int play = 0;
	while (1)
	{
		menu();
		scanf("%d", &play);
		 if (play == 1)
		{
			game();
			printf("�Ƿ�����һ��\n");
		}
		else if (play == 0)
		{
			printf("��Ϸ����");
			break;
		}
		else
			printf("�������\n");
	}
	return 0;
}
