#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <dos.h>
#include <conio.h>

//16���� 2���� ��ȯ�Լ� ����.
void Convert16to2(char *Hex_array);



FILE *fp;
char *Hex_array; // ���ϼ� �о�� 16������ ���ڿ��� �б� ���� ������ ����
unsigned int fetched_inst; //��ɾ��� 16������ ���������� �б� ���� ����

////////////////////////////////////////////////////////////////
int operand; // (0�϶� read data, 1 write data)  <- data cache , 2 instruction fetch <- instruction cache  
char binary[33];//16 -> 2������ ��ȯ ���� ����
///////////////////////////////////////////////////////////////

int main()
{
	char str_file[20] = { 0 };

	// Trace file �Է� �ޱ�
	printf("File : ");
	scanf("%s", str_file);

	//  Ʈ���̽� ���� �б�
	if((fp=fopen(str_file, "r")) == NULL) {		
		printf("file open error");
		exit(1);
	}
	
	Hex_array = (char *)malloc(sizeof(char) * 11);
	
	while(feof(fp)==0)		//���� ������ ���ڿ� �ҷ�����.
	{
		fscanf(fp, "%d", &operand);
		fscanf(fp, "%s", Hex_array); //��ɾ ���ڿ��� ����
		/* Trace file ��ɾ ���������� �б� - ��ɾ ���ڿ��� �д� �Լ��� ��ü�� Ȱ�� ����
		fscanf(fp, "%x", &fetched_inst);
		*/
		Convert16to2(Hex_array); //16���� ���ڿ��� 2���� ������ ���ڿ��� ����
		//���������� ��ɾ �о��ٸ� Convert16to2 �Լ��� Ȱ���� �ʿ� ����
		
		//������ ��ɾ��� Ư�� bit �ڸ��� ���� (tag 22bit, index 8bit, direct-mapped cache)
		//index = (fetched_inst<<22);
		//index = (index>>24); -> index�� �ش��ϴ� ���� �����
		
		if(operand == 0 || operand == 1)		//data cahce ���� ����
		{
			printf("data %d    %s    %s\n",operand, Hex_array, binary);
		}
		if(operand == 2)				//inst cache ���� ����
		{
			printf("inst %d    %s    %s\n",operand, Hex_array, binary);
		}
	}
	
	return 0;
}


//16���� 2���� ��ȯ�Լ�.
void Convert16to2(char *Hex_array)
{
	int res=0;
	char temp;
	unsigned long Hex = strtoul(Hex_array, NULL, 16);

	for (int i = 0; i < 32; i++)
	{
		res = Hex & (0x01 << (31 - i));
		if (res == 0)
		{
			temp = '0';
			binary[i] = temp;
		}
		else
		{
			temp = '1';
			binary[i] = temp;
		}
	}
}