#include "default.h"

/*��������*/

#define Maxn 8	//������Ŀ�еĽ�����
#define M 100;	//����һ�������Ȩֵ�ܴ��ֵ

/*�����������ṹ*/
typedef struct HuffNode
{
	TElemtype data;
	int weight;				/*����Ȩֵ*/
	int parent;				/*����˫�׽��λ��*/
	int lchild;
	int rchild;
} *HTNode;

/*���������ṹ*/
typedef struct HuffTreeNode
{
	int n;					/*Ҷ�ӽ�����*/
	int root;				/*��������*/
	HTNode ht;				/*����ָ�����ָ��*/
} *HuffTree;

/*������������*/
HuffTree CreateHuffTree(int n, int w[], char data[])
{
	HuffTree hpt;
	hpt = (HuffTree)malloc(sizeof(struct HuffTreeNode));
	if (!hpt)
		return;
	int i = 0, j = 0;			//����ѭ������
	int x1, x2, min1, min2;		//������Сֵ�±ꡢ��Сֵ�±ꡢ��Сֵ����Сֵ
	int m = 2 * n - 1;			//�����ܹ�m��Ԫ��
	hpt->ht = (HTNode)malloc(sizeof(struct HuffNode) * m);
	if (!hpt->ht)
		return;

	/*��ʼ����������*/
	for (i = 0; i < m; i++)
	{
		hpt->ht[i].lchild = -1;		/*��ʼ��Ҷ�ڵ�����*/
		hpt->ht[i].rchild = -1;		/*��ʼ��Ҷ�ڵ��Һ���*/
		hpt->ht[i].parent = -1;		/*��ʼ��Ҷ�ڵ�˫��*/
		if (i < n)
		{
			hpt->ht[i].weight = w[i];	/*��ֵҶ�ӽ���Ȩֵ*/
			hpt->ht[i].data = data[i];	/*��ʼ��Ҷ�ӽ���data*/
		}
		else
		{
			hpt->ht[i].weight = -1;		/*��ʼ���ڲ����Ϊ-1*/
		}
	}

	/*��ʼ���ڲ����*/
	for (i = 0; i < n - 1; i++)			/*������n-1�����*/
	{
		min1 = M;		/*��ʼ����Сֵ*/
		min2 = M;
		x1 = -1;		/*��ʼ���±�*/
		x2 = -1;
		for (j = 0; j < n + i; j++)
		{
			/*�ҵ���Сֵ�±긳ֵ��x1, ��Сֵ��ֵ��min1*/
			if (hpt->ht[j].weight < min1 && hpt->ht[j].parent == -1)
			{
				min2 = min1;
				x2 = x1;
				min1 = hpt->ht[j].weight;
				x1 = j;
			}
			/*�ҵ���Сֵ�±긳ֵ��x2, ���ֵ��ֵ��min2*/
			else if (hpt->ht[j].weight < min2 && hpt->ht[j].parent == -1)
			{
				min2 = hpt->ht[j].weight;
				x2 = j;
			}
		}
		hpt->ht[n + i].weight = min1 + min2;	//��ʼ��������Ȩֵ
		hpt->ht[n + i].lchild = x1;				//����������Ӹ�ֵ
		hpt->ht[n + i].rchild = x2;				//��������Һ��Ӹ�ֵ
		hpt->ht[x1].parent = n + i;				//�����ӵĸ���㸳ֵ
		hpt->ht[x2].parent = n + i;				//���Һ��ӵĸ���㸳ֵ
	}
	hpt->root = 2 * n - 2;							//���ڵ�λ��
	hpt->n = n;										//����������Ҷ�ӽ����
	return hpt;
}

//�ú����������Ҷ�ӽ��Ĺ���������
void PrintHuffCode(int n, HuffTree hpt)
{
	int i = 0, num = 0, j = 0;	//����ѭ������
	int parent = 0;				//���常����±���ʱ����
	int times = 0;				//��¼ÿ��������������ĳ���
	int code[Maxn];
	for (i = 0; i < n; i++)		//ѭ����ÿ��Ҷ�ӽ����б���
	{
		num = i;				//��ʼ�����ڿ���ѭ���ı���
		j = 0;					//��ʼ�����ڿ�������code�ı���
		times = 0;
		while (hpt->ht[num].parent != -1)					//ѭ������ǰ���ĸ����Ϊ-1
		{
			parent = hpt->ht[num].parent;
			if (hpt->ht[parent].lchild == num)			//��ǰ���Ϊ���������ӣ�����Ϊ0
			{
				code[j] = 0;
				j++;
				times++;									//���볤�ȼ�1
			}
			else if (hpt->ht[parent].rchild == num)		//��ǰ���Ϊ�������Һ��ӣ�����Ϊ1
			{
				code[j] = 1;
				j++;
				times++;									//���볤�ȼ�1
			}
			num = parent;									//��num��ֵΪ������±�
		}
		printf("%c:", hpt->ht[i].data);		//�����i��Ҷ�ӽ���data
		for (j = times - 1; j >= 0; j--)		//�����i��Ҷ�ӽ��Ĺ���������
		{
			printf("%d", code[j]);
		}
		printf("\n");
	}
	return;
}

//�ú������ڴ�ӡ�������������н��
void PrintHuffTree(HuffTree hpt, int n)
{
	for (int i = 0; i < 2 * n - 1; i++)
	{
		printf("��%d�����:weight=%d  parent= %d  lchild=%d  rchild=%d\n", i, hpt->ht[i].weight, hpt->ht[i].parent, hpt->ht[i].lchild, hpt->ht[i].rchild);
	}
	return;
}


int main()
{
	int n = 8;
	int w[8] = { 5,29,7,8,14,23,3,11 };
	char data[8] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	HuffTree T = CreateHuffTree(n, w, data);

	return 0;
}