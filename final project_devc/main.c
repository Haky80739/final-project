#include <stdio.h>
#include <stdlib.h>

typedef struct  _bill
{
	int mode1;
	char title[5];
	int price;
	int pocketbalance;
	int bankbalance;
	int receipt;
} bill;

char tt[]="hello";

bill data[101];

void print(int p);
void pname();
void pn(int n);
void calculate1(int c);
void calculate2(int c);
void calculate3(int c);
void calculate4(int c);
void calculate5(int c);
void calculate6(int c);
void fp(int f);
void inp(int l,int m);
void look(int l);
FILE* pFile;
rece[8]={0};


int main() {

	
	int mode;
	int i,j;
	int mode1;
	int last = 1;
	int confirm=0;
	

	pFile = fopen("d://money.txt", "a+");
	

	while (1)
	{
		while (1)
		{
			printf("\n\n\n�п�J�Ҧ�(�O�b:1/�d�ߩ���:2/��J�o���������X:3/�h�X�{��:0):");
			scanf_s("%d", &mode);
			if (mode > 0 || mode < 3) break;
		}

		/////////////////////////////////////////////////////////////////

		if (NULL == pFile) {
			printf("open failure");
		}
		else {
			last = 1;
			for (i = 1; i <= 101; i++)
			{
				fscanf(pFile, "\n%d", &data[i].mode1);
				if (data[i].mode1 <= 0 || data[i].mode1 >= 7)
				{
					last -= 1;
					break;
				}
				fscanf(pFile, "%s", data[i].title);
				fscanf(pFile, "%d", &data[i].price);
				fscanf(pFile, "%d", &data[i].pocketbalance);
				fscanf(pFile, "%d", &data[i].bankbalance);
				fscanf(pFile, "%d", &data[i].receipt);
				last += 1;
			}
			if(last == 0)
			{
				data[0].mode1=0;
				for(j=1;j<6;j++)
				{
					data[0].title[j] = tt[j-1];
				}
				
				data[0].price=0;
				printf("�п�J���]�_�l���B:");
				scanf("%d",&data[0].pocketbalance);
				printf("�п�J�Ȧ�s�ڰ_�l���B:");
				scanf("%d",&data[0].bankbalance);
				data[0].receipt=0;
				//fp(0);
			}
         


			///////////////////////////////////////////////////////////////////
			switch (mode)
			{
			case 0:
				system("pause");
				return 0;
				break;

				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 1:
				printf("\n�O�b:");
				while (1)
				{
					printf("\n�п�J���O(��X:1/���J:2/�s�J�b��:3/�b���X:4/�פJ�b��:5/�ץX�b��:6):");
					scanf("%d", &mode1);
					if (mode1 > 0 || mode1 < 6) break;
				}
				switch (mode1)
				{
				case 1:
					confirm = 0;
					while (confirm != 1)
					{
						printf("�п�J�W��:");
						for (j = 0; j < 6; j++)
						{
							scanf_s("%c", &data[last + 1].title[j]);
						}
						printf("�п�J���B:");
						scanf_s("%d", &data[last + 1].price);
						printf("�п�J�o�����X(8�X):");
						scanf_s("%d", &data[last + 1].receipt);
						printf("\n�T�{");
						pn(mode1);
						printf("\n�W��:");
						for (j = 1; j < 6; j++)
						{
							printf("%c", data[last + 1].title[j]);
						}	
						printf("\n���B:%d\n", data[last + 1].price);
						printf("�o�����X:%d\n", data[last + 1].receipt);
						printf("\n�T�{�Ы�1�A���s��J�Ы�0:");
						scanf("%d", &confirm);
					}
					calculate1(last);
					printf("OK!! \n");
					pname();
					print(last + 1);
					fp(last + 1);
					break;
				case 2:
				    inp(last,mode1);
					calculate2(last);
					printf("OK!! \n");
					pname();
					print(last + 1);
					fp(last + 1);
					
					break;
				case 3:
					inp(last,mode1);
					calculate3(last);
					printf("OK!!\n");
					pname();
					print(last + 1);
					fp(last + 1);
					
					break;
				case 4:
					inp(last,mode1);
					calculate4(last);
					printf("OK!!\n");
					pname();
					print(last + 1);
					fp(last + 1);
					break;
				case 5:
					inp(last,mode1);
					calculate5(last);
					printf("OK!!\n");
					pname();
					print(last + 1);
					fp(last + 1);
					break;
				case 6:
					inp(last,mode1);
					calculate6(last);
					printf("OK!!\n");
					pname();
					print(last + 1);
					fp(last + 1);
					break;
				}


				last += 1;
				break;


				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 2:
				printf("\n�d�ߩ���:\n\n");
				pname();
				for (i = 1; i <= last; i++)
				{
					print(i);
				}
				break;


				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			case 3:
				if(rece[0]==0)
				{
					printf("\n�п�J�o���������X:\n");
					printf("�S�O��(8�X):");
					scanf("%d",&rece[0]);
					printf("�S��(8�X):");
					scanf("%d",&rece[1]);
					printf("�Y��(8�X):");
					scanf("%d",&rece[2]);
					printf("�Y��(8�X):");
					scanf("%d",&rece[3]);
                	printf("�Y��(8�X):");
					scanf("%d",&rece[4]);
             	    printf("�W�}����(3�X):");
					scanf("%d",&rece[5]);
             	    printf("�W�}����(3�X):");
					scanf("%d",&rece[6]);
					printf("�W�}����(3�X):");
					scanf("%d",&rece[7]);
					printf("\n\n\n");
           		}
           		look(last);
				break;
			}

		}
		fclose(pFile);
	}
}
void pname()
{
	printf("����\t\t�W��\t���B\t���]�l�B\t�b��l�B\t�o�����X\n");
}

void inp(int l,int m)
{
	int j;
	int confirm = 0;
	while (confirm != 1)
	{
		printf("�п�J�W��:");
		for (j = 0; j < 6; j++)
		{
			scanf_s("%c", &data[l + 1].title[j]);
		}
		printf("�п�J���B:");
		scanf_s("%d", &data[l + 1].price);
		printf("\n�T�{");
		pn(m);
		printf("\n�W��:");
		for (j = 1; j < 6; j++)
		{
			printf("%c", data[l + 1].title[j]);
		}
		printf("\n���B:%d\n", data[l + 1].price);
		printf("\n�T�{�Ы�1�A���s��J�Ы�0:");
		scanf("%d", &confirm);
	}
	
}

void pn(int n)
{
	switch(n)
	{
		case 0:
		    printf("�_�l\t\t");
			break;
		case 1:
			printf("��X\t\t");
			break;
		case 2:
			printf("���J\t\t");
			break;
		case 3:
			printf("�s�J�b��\t");
			break;
		case 4:
			printf("�b���X\t");
			break;
		case 5:
			printf("�פJ�b��\t");
			break;
		case 6:
			printf("�ץX�b��\t");
			break;
	}
}

void print(int p)
{
	int r;
	pn(data[p].mode1);
	for (r = 1; r < 6; r++)
	{
	printf("%c", data[p].title[r]);
	}
	printf("\t");
	printf("%d\t", data[p].price);
	printf("%d\t\t", data[p].pocketbalance);
	printf("%d\t\t", data[p].bankbalance);
	printf("%d\n", data[p].receipt);
}

void calculate1(int c)
{
	data[c + 1].mode1 = 1;
	data[c + 1].pocketbalance = data[c].pocketbalance - data[c+1].price;
	data[c + 1].bankbalance = data[c].bankbalance;
}

void calculate2(int c)
{
	data[c + 1].receipt=0;
	data[c + 1].mode1 = 2;
	data[c + 1].pocketbalance = data[c].pocketbalance + data[c+1].price;
	data[c + 1].bankbalance = data[c].bankbalance;
}

void calculate3(int c)
{
	data[c + 1].receipt=0;
	data[c + 1].mode1 = 3;
	data[c + 1].pocketbalance = data[c].pocketbalance - data[c+1].price;
	data[c + 1].bankbalance = data[c].bankbalance + data[c+1].price;
}

void calculate4(int c)
{
	data[c + 1].receipt=0;
	data[c + 1].mode1 = 4;
	data[c + 1].pocketbalance = data[c].pocketbalance + data[c+1].price;
	data[c + 1].bankbalance = data[c].bankbalance - data[c+1].price;
}

void calculate5(int c)
{
	data[c + 1].receipt=0;
	data[c + 1].mode1 = 4;
	data[c + 1].pocketbalance = data[c].pocketbalance;
	data[c + 1].bankbalance = data[c].bankbalance + data[c+1].price;
}

void calculate6(int c)
{
	data[c + 1].receipt=0;
	data[c + 1].mode1 = 6;
	data[c + 1].pocketbalance = data[c].pocketbalance;
	data[c + 1].bankbalance = data[c].bankbalance - data[c+1].price;
}

void fp(int f)
{
	int r;
	fprintf(pFile, "%d ", data[f].mode1);
	for (r = 1; r < 6; r++)
	{
		fprintf(pFile, "%c", data[f].title[r]);
	}
	fprintf(pFile, " ");
	fprintf(pFile, "%d ", data[f].price);
	fprintf(pFile, "%d ", data[f].pocketbalance);
	fprintf(pFile, "%d ", data[f].bankbalance);
	fprintf(pFile, "%d\n", data[f].receipt);
}

void look(int l)
{
	int i,j;
	for (i=1;i<=l;i++)
	{
		if(data[i].receipt==rece[0])
		{
			printf("���߱z��1000�U!!\n");
			printf("�o�����X:%d",data[0].receipt);
		}
		if(data[i].receipt==rece[1])
		{
			printf("���߱z��200�U!!\n");
			printf("�o�����X:%d",data[1].receipt);
		}
		for(j=2;j<=4;j++)
		{
			if(data[i].receipt==rece[2])
			{
				printf("���߱z��20�U!!\n");
				printf("�o�����X:%d",data[i].receipt);
			}
			if(data[i].receipt%10000000==rece[j]%10000000)
			{
				printf("���߱z��4�U!!\n");
				printf("�o�����X:%d",data[i].receipt);
			}
			if(data[i].receipt%1000000==rece[j]%1000000)
			{
				printf("���߱z��1�U!!\n");
				printf("�o�����X:%d",data[i].receipt);
			}
			if(data[i].receipt%100000==rece[j]%100000)
				{
				printf("���߱z��4�d!!\n");
				printf("�o�����X:%d",data[i].receipt);
			}
			if(data[i].receipt%10000==rece[j]%10000)
			{
				printf("���߱z��1�d!!\n");
				printf("�o�����X:%d",data[i].receipt);
			}
			if(data[i].receipt%1000==rece[j]%1000)
			{
				printf("���߱z��2��!!\n");
				printf("�o�����X:%d",data[i].receipt);
			}
		}
		for(j=5;j<=7;j++)
		{
			if(data[i].receipt%1000==rece[j])
			{
				printf("���߱z��2��!!\n");
				printf("�o�����X:%d",data[i].receipt);
			}
		}
	}
}


