#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <dos.h>
#include <conio.h>

//16진수 2진수 변환함수 정의.
void Convert16to2(char *Hex_array);

//위치 정수로 반환
int FindLocation(char *index,int indexNum,int a);


FILE *fp;
char *Hex_array; // 파일서 읽어온 16진수를 문자열로 읽기 위한 포인터 변수
unsigned int fetched_inst; //명령어의 16진수를 정수형으로 읽기 위한 변수

////////////////////////////////////////////////////////////////
int operand; // (0일때 read data, 1 write data)  <- data cache , 2 instruction fetch <- instruction cache  
char binary[33];//16 -> 2진수로 변환 저장 공간
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
	// Trace file 입력 받기
	printf("File : ");
	scanf("%s", str_file);

	//  트레이스 파일 읽기
	if((fp=fopen(str_file, "r")) == NULL) {		
		printf("file open error");
		exit(1);
	}
	//cache size 입력
	printf("Unified cache size (KB) : ");
	scanf("%d",&cache_size);

	//index 비트 수 구하기
	a = cache_size/32;
	while(a!=1){
		a/=2;
		sum++;
	}
	indexNum = 10+sum;
	tagNum = 32-indexNum-5;

	//block number 구하기
	sum = indexNum;
	bn = 1;
	while(sum!=0){
		bn*=2;
		sum--;
	}

	//index, tag, cache 동적 할당
	index = (char*)malloc(sizeof(char)*indexNum);
	tag = (char*)malloc(sizeof(char)*tagNum);
	cache = (char**)malloc(sizeof(char*)*(bn));
	for(i=0;i<bn;i++){
		cache[i] = (char*)malloc(sizeof(char)*(tagNum+2)); //tag와 valid bit와 \n
		cache[i][0] = '0'; //valid bit 0으로 초기화
	}

	Hex_array = (char *)malloc(sizeof(char) * 11);
	
	while(feof(fp)==0)		//파일 끝까지 문자열 불러오기.
	{
		fscanf(fp, "%d", &operand);
		fscanf(fp, "%s", Hex_array); //명령어를 문자열로 읽음
		/* Trace file 명령어를 정수형으로 읽기 - 명령어를 문자열로 읽는 함수의 대체로 활용 가능
		fscanf(fp, "%x", &fetched_inst);
		*/
		Convert16to2(Hex_array); //16진수 문자열을 2진수 형식의 문자열로 변경
		//정수형으로 명령어를 읽었다면 Convert16to2 함수의 활용은 필요 없음
		
		//정수형 명령어의 특정 bit 자르기 예시 (tag 22bit, index 8bit, direct-mapped cache)
		//index = (fetched_inst<<22);
		//index = (index>>24); -> index에 해당하는 값이 저장됨

		// if(operand == 0 || operand == 1)		//data cahce 동작 구현
		// {
		// 	printf("data %d    %s    %s\n",operand, Hex_array, binary);
		// }
		// if(operand == 2)				//inst cache 동작 구현
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
		if(cache[blockLocation][0]=='0'){ //valid bit가 0이면
			missNum++; //miss
			cache[blockLocation][0]='1'; //valid bit 1로 변경
			for(i=1;i<=tagNum;i++){ //tag저장
				cache[blockLocation][i] = tag[i-1];
			}
		}
		else{ //valid bit가 1이면
			equal=1;
			for(i=1;i<=tagNum;i++){
				if(cache[blockLocation][i]!=tag[i-1]){
					equal = 0;
					break;
				}
			}
			
			if(equal){ //tag가 같으면 access
				access++;
			}
			else{//tag가 다르면 replace
				for(i=1;i<=tagNum;i++){ //tag저장
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


//16진수 2진수 변환함수.
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