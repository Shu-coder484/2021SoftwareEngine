#include<stdio.h>
#include<string.h> 
//ʹ�ýṹ���ʾÿ����ĸ���ֵĴ��� 
typedef struct{
	char letter;	//��ĸ 
	int num;	//���ִ��� 
	double rate;	//����Ƶ�� 
}alphabet;
alphabet alphabets[26];
int letterNums=0; //�ı����е���ĸ���ܺ� 
//��ʼ���ṹ�� alphabet 
void initAlphabet(){
	int i;
	char a='a';
	for(i=0;i<26;i++){
		alphabets[i].letter=a;
		alphabets[i].num=0;
		alphabets[i].rate=0.0;
		a=a+1;
		//printf("%c %d\n",alphabets[i].letter,alphabets[i].num);
	}
	return;
}
//���Ӣ���ı���26����ĸ���ֵ�Ƶ��
void printAlphabetRate(){
	FILE *fp;
	int i,j;
	alphabet temp;
	//����ļ��Ƿ�Ϊ�� 
	if((fp=fopen("test.txt","r"))==NULL){
		printf("file can not open\n");
		return;
	}
	initAlphabet();
	//���ļ��ж�ȡ�ַ����бȶԡ�ͳ��
	char l;
	//fscanf()����ȡ�ı��е��ַ�  fgetc()����ȡ�ı��е��ַ� 
	while((l=fgetc(fp))!=EOF){
		if(l=='a'||l=='A'){
			alphabets[0].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='b'||l=='B'){
			alphabets[1].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='c'||l=='C'){
			alphabets[2].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='d'||l=='D'){
			alphabets[3].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='e'||l=='E'){
			alphabets[4].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='f'||l=='F'){
			alphabets[5].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='g'||l=='G'){
			alphabets[6].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='h'||l=='H'){
			alphabets[7].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='i'||l=='I'){
			alphabets[8].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='j'||l=='J'){
			alphabets[9].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='k'||l=='K'){
			alphabets[10].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='l'||l=='L'){
			alphabets[11].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='m'||l=='M'){
			alphabets[12].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='n'||l=='N'){
			alphabets[13].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='o'||l=='O'){
			alphabets[14].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='p'||l=='P'){
			alphabets[15].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='q'||l=='Q'){
			alphabets[16].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='r'||l=='R'){
			alphabets[17].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='s'||l=='S'){
			alphabets[18].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='t'||l=='T'){
			alphabets[19].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='u'||l=='U'){
			alphabets[20].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='v'||l=='V'){
			alphabets[21].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='w'||l=='W'){
			alphabets[22].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='x'||l=='X'){
			alphabets[23].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='y'||l=='Y'){
			alphabets[24].num++;
			letterNums++;
			//break;
			continue;
		}
		if(l=='z'||l=='Z'){
			alphabets[25].num++;
			letterNums++;
			//break;
			continue;
		}
	}
	
	//����Ƶ��
	 for(i=0;i<26;i++){
	 	alphabets[i].rate=(1.0*alphabets[i].num/letterNums*1.0)*100.0;
	 }
	//���� alphabets
	for(i=0;i<26;i++){
		for(j=0;j<26-i;j++){
			if(alphabets[j].rate<alphabets[j+1].rate){
				temp=alphabets[j];
				alphabets[j]=alphabets[j+1];
				alphabets[j+1]=temp;
			}
		}
	}
	//���� & ��� 
		printf("��ĸ ����Ƶ�� �ٷֱ�\n");
	for(i=0;i<26;i++){
		printf(" %c      %d     %.2f%%\n",alphabets[i].letter,alphabets[i].num,alphabets[i].rate);
	}
	printf("�ܵ���ĸ����%d\n",letterNums);
	return;
} 

int main(int argc,char *argv[]){
	char *input;
	input=argv[1];
	
	
	if(strcmp(input,"c")==0){
		printAlphabetRate();
	}
	return 0;
}
