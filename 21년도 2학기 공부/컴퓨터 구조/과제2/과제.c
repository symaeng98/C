#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <dos.h>
#include <conio.h>

//16���� 2���� ��ȯ�Լ� ����.
void Convert16to2(char *Hex_array);

//��ġ ������ ��ȯ
int FindLocation(char *index,int indexNum,int a);


FILE *fp;
char *Hex_array; // ���ϼ� �о�� 16������ ���ڿ��� �б� ���� ������ ����
unsigned int fetched_inst; //��ɾ��� 16������ ���������� �б� ���� ����

////////////////////////////////////////////////////////////////
int operand; // (0�϶� read data, 1 write data)  <- data cache , 2 instruction fetch <- instruction cache  
char binary[33];//16 -> 2������ ��ȯ ���� ����
///////////////////////////////////////////////////////////////

int main()
{
	char str_file[100];
	char *index;
	char *tag;
	int a,bn,i;
	int sum=0;
	int total=0;
	int equal;

	int blockLocation;
	int cache_size; //KB
	int valid; //valid bit
	int indexNum;
	int tagNum;
	char **cache;

	float ratio;
	int access = 0;
	int missNum = 0;
	// Trace file �Է� �ޱ�
	printf("File : ");
	scanf("%s", str_file);

	//  Ʈ���̽� ���� �б�
	if((fp=fopen(str_file, "r")) == NULL) {		
		printf("file open error");
		exit(1);
	}
	//cache size �Է�
	printf("Unified cache size (KB) : ");
	scanf("%d",&cache_size);

	//index ��Ʈ �� ���ϱ�
	a = cache_size/32;
	while(a!=1){
		a/=2;
		sum++;
	}
	indexNum = 10+sum;
	tagNum = 32-indexNum-5;

	//block number ���ϱ�
	sum = indexNum;
	bn = 1;
	while(sum!=0){
		bn*=2;
		sum--;
	}

	//index, tag, cache ���� �Ҵ�
	index = (char*)malloc(sizeof(char)*indexNum);
	tag = (char*)malloc(sizeof(char)*tagNum);
	cache = (char**)malloc(sizeof(char*)*(bn));
	for(i=0;i<bn;i++){
		cache[i] = (char*)malloc(sizeof(char)*(tagNum+2)); //tag�� valid bit�� \n
		cache[i][0] = '0'; //valid bit 0���� �ʱ�ȭ
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

		// if(operand == 0 || operand == 1)		//data cahce ���� ����
		// {
		// 	printf("data %d    %s    %s\n",operand, Hex_array, binary);
		// }
		// if(operand == 2)				//inst cache ���� ����
		// {
		// printf("inst %d    %s    %s\n",operand, Hex_array, binary);
		// }
		//data 1    c7e33050    1 1000 1111 1100 0110//0110 0000 10// 10000
		for(i=0;i<tagNum;i++){
			tag[i] = binary[i];
		}
		for(i=0;i<indexNum;i++){
			index[i] = binary[tagNum+i];
		}
		blockLocation = FindLocation(index,indexNum,bn);
		if(cache[blockLocation][0]=='0'){ //valid bit�� 0�̸�
			missNum++; //miss
			cache[blockLocation][0]='1'; //valid bit 1�� ����
			for(i=1;i<=tagNum;i++){ //tag����
				cache[blockLocation][i] = tag[i-1];
			}
		}
		else{ //valid bit�� 1�̸�
			equal=1;
			for(i=1;i<=tagNum;i++){
				if(cache[blockLocation][i]!=tag[i-1]){
					equal = 0;
					break;
				}
			}
			
			if(equal){ //tag�� ������ access
				access++;
			}
			else{//tag�� �ٸ��� replace
				for(i=1;i<=tagNum;i++){ //tag����
					cache[blockLocation][i] = tag[i-1];
				}
				missNum++;
			}
		}
		
		total++;
	}
	ratio = (float)missNum/(float)total;
	printf("Access : %d\n",access);
	printf("Miss : %d\n",missNum);
	printf("Miss ratio : %.4f\n",ratio);
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
int FindLocation(char *index,int indexNum, int a){
	int i=0;
	int d=1;
	int sum=0;
	for(i=indexNum-1;i>=0;i--){
		if(index[i]=='1') sum+=d;
		d*=2;
	}
	sum = sum%a;
	return sum;
}