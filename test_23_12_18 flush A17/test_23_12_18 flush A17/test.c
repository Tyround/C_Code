#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct
{
	char color;
	char amount;
}Poke;

int num_poke(Poke hh)
{
	if (hh.amount >= '2' && hh.amount <= '9')
	{
		return hh.amount - '1';
	}
	int fk = 9;
	if (hh.amount == 'T')//9
	{
		return fk;
	}
	else
		fk++;
	if (hh.amount == 'J')//10
	{
		return fk;
	}
	else
		fk++;
	if (hh.amount == 'Q')//11
	{
		return fk;
	}
	else
		fk++;
	if (hh.amount == 'K')//12
	{
		return fk;
	}
	else
		fk++;
	if (hh.amount == 'A')//13
	{
		return fk;
	}
	else
		fk++;
	return 0;
}

int comp_poke(Poke l, Poke r)
{
	if (num_poke(l) > num_poke(r))
		return 1;
	else
		return 0;
}

void judge_hand(Poke hand[])
{
	//先排序
	for (int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4 - i;j++)
		{
			if (comp_poke(hand[j], hand[j + 1]))
			{
				Poke trans = { 0 };
				trans = hand[j];
				hand[j] = hand[j + 1];
				hand[j + 1] = trans;
			}
		}
	}

	//现在判断对子类的
	int flush = 0, str = 0;
	//四张
	if (hand[0].amount == hand[3].amount || hand[1].amount == hand[4].amount)
	{
		printf("four of a kind\n");
		return;
	}
	//葫芦
	else if ((hand[0].amount == hand[2].amount && hand[3].amount == hand[4].amount )||( hand[0].amount == hand[1].amount&&hand[2].amount == hand[4].amount))
	{
		printf("full house\n");
		return;
	}
	//三条
	else if (hand[0].amount == hand[2].amount || hand[1].amount == hand[3].amount || hand[2].amount == hand[4].amount)
	{
		printf("three of a kind\n");
		return;
	}
	//两对
	else if ((hand[0].amount == hand[1].amount && hand[2].amount == hand[3].amount) || (hand[0].amount == hand[1].amount && hand[3].amount == hand[4].amount) || (hand[1].amount == hand[2].amount && hand[3].amount == hand[4].amount))
	{
		printf("two pairs\n");
		return;
	}
	//对子
	else if (hand[0].amount == hand[1].amount || hand[1].amount == hand[2].amount || hand[2].amount == hand[3].amount || hand[3].amount == hand[4].amount)
	{
		printf("pair\n");
		return;
	}


	//同花
	if (hand[0].color == hand[1].color && hand[1].color == hand[2].color && hand[2].color == hand[3].color && hand[3].color == hand[4].color)
	{
		flush = 1;
	}

	//顺子
	if (num_poke(hand[0]) + 1 == num_poke(hand[1]) && num_poke(hand[1]) + 1 == num_poke(hand[2]) && num_poke(hand[2]) + 1 == num_poke(hand[3]) && num_poke(hand[3]) + 1 == num_poke(hand[4]))
	{
		str = 1;
	}
	if (num_poke(hand[0]) + 1 == num_poke(hand[1]) && num_poke(hand[1]) + 1 == num_poke(hand[2]) && num_poke(hand[2]) + 1 == num_poke(hand[3]) && 13 == num_poke(hand[4]))
	{
		str = 1;
	}


	if (flush && str)
	{
		printf("straight flush\n");
		return;
	}

	if (flush)
	{
		printf("flush\n");
		return;
	}

	if (str)
	{
		printf("straight\n");
		return;
	}

	printf("others\n");
	return;
}

int main()
{
	Poke pokeHand[6] = {0};
	Poke def = { 0 };
	int count = 0;
	while (1)
	{	
		/*scanf("%c", &def.color);
		
		scanf("%c ", &def.amount)
		
		
		{

			if (def.color == '0')
				break;
		}*/
		char fuck[1000] = { 0 };

		scanf("%s", fuck);
		if (!strcmp(fuck, "0"))
		{
			break;
		}
		else
		{
			def.color = fuck[0];
			def.amount = fuck[1];
		}


		
		if (def.color == 'D' || def.color == 'C' || def.color == 'H' || def.color == 'S')
		{
			if (def.amount == '2' || def.amount == '3' || def.amount == '4' || def.amount == '5' || def.amount == '6' || def.amount == '7' || def.amount == '8' || def.amount == '9' || def.amount == 'T' || def.amount == 'J' || def.amount == 'Q' || def.amount == 'K' || def.amount == 'A')
			{	
				for (int k = 0; k <= count; k++)
				{
					if (k == count)
					{
						pokeHand[count] = def;
						count++;
						break;
					}
					if (def.color == pokeHand[k].color && def.amount == pokeHand[k].amount)
					{
						break;
					}
					
				}
				
			}
		}
		if (count == 5)
		{
			count = 0;
			judge_hand(pokeHand);
			
		}
	}
	//D4 C3 PP HA HA ST H9 0
	
	return 0;
}