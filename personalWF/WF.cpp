#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
//ʹ�ýṹ���ʾÿ����ĸ���ֵĴ��� 
typedef struct{
	char letter;	//��ĸ 
	int num;	//���ִ��� 
	double rate;	//����Ƶ�� 
}alphabet;
alphabet alphabets[26];
int letterNums=0; //�ı����е���ĸ���ܺ�

//ʹ�ýṹ���ʾ���ֵĵ���
typedef struct words{
	int num;	//���ִ���
	char wordName[60];	//��������	
}word[1000];
int wordNums=0;	//�ı��г��ֵĵ������� 

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

// -c ���Ӣ���ı���26����ĸ���ֵ�Ƶ��
void printAlphabetRate(){
	FILE *fp;
	int i,j;
	alphabet temp;
	//����ļ��Ƿ�Ϊ�� 
	if((fp=fopen("text.txt","r"))==NULL){
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
	printf("----------------------------------------------\n");
	return;
} 

// -f ��������ļ��е�ǰ N ������ֵ�Ӣ�ﵥ�ʡ��ı������Ա����Ž�β 
// -n [num] �������ǰn�ĵ��� 
void printFrequentWord(int n){
	FILE *fp;
	char w[60],ch;	//w[60]��ʾ��ʱ��ŵ���,ch��ʾ���ı��л�ȡ����ĸ 
	int i=0,j=0,flag=0,m=1,k=0;	//flag��ʾ1�������Ƿ��ѷ���w[60];m��ʾ�Ƿ��е�����ͬ 
	//����ļ��Ƿ�Ϊ�� 
	if((fp=fopen("text.txt","r"))==NULL){
		printf("file can not open\n");
		return;
	}
	//ͳ�Ƶ�������
	words word[1000];
	while((ch=fgetc(fp))!=EOF){
		//��д��ĸתСд��ĸ
		if(ch>='A'&&ch<='Z'){
			ch=ch+32;
		} 
		if(ch>='a'&&ch<='z'){
			w[i]=ch; //��ʼ���뵥�ʵ���ʱ�� 
			i++;
			flag=1;
		}
		else{
			if(ch=='-'&&(ch=fgetc(fp))=='\n'){	//����ĸ���ǿո� 
				flag=0;
			}
			else{
				if(flag==1){
					//д��w���+'\0' 
					w[i]='\0';
					i=0;
					flag=0;
					m=0;
					for(j=0;j<k;j++){
						if(strcmp(w,word[j].wordName)==0){
							m=1;	//��ʾǰ���е�����ͬ 
							break;
						}
					}
					if(m){
						word[j].num++;	//����������1 
					}
					else{	//����ṹ��word�� 
						word[k].num=1;
						strcpy(word[k].wordName,w);
						k++;
					}
				}
			}
		}
	}
	int l=0,n1=0;
	//ͳ���ı��г��ֵĵ�������
	while(word[l].num){
		wordNums++;
		l++;
	}
	//����
	words temp;
	for(i=0;i<26;i++){
		for(j=0;j<26-i;j++){
			if(word[j].num<word[j+1].num){
				temp=word[j];
				word[j]=word[j+1];
				word[j+1]=temp;
			}
		}
	}
	//���� & ���
	l=0;
	//printf("���ִ���    ����\n");
	if(n==0){
		printf("���ִ���    ����\n");
		while(word[l].num){
			printf("  %d         ",word[l].num);
			while(word[l].wordName[n1]){
				printf("%c",word[l].wordName[n1]);
				n1++;
			}
			l++;
			n1=0;
			printf("\n");
		}
	}
	else{
		printf("���ִ�������ǰ%d�����ʣ�\n",n);
		printf("���ִ���    ����\n");
		for(l=0;l<n;l++){
			printf("  %d         ",word[l].num);
			while(word[l].wordName[n1]){
				printf("%c",word[l].wordName[n1]);
				n1++;
			}
			n1=0;
			printf("\n");
		}
	}
	printf("�ܵĵ�������%d\n",wordNums);
	printf("----------------------------------------------\n");
	return;
}

int main(int argc,char *argv[]){
	int n=10;
	char *input1,*input2;
	input1=argv[1];
	input2=argv[2];
	if(strcmp(input1,"c")==0){
		printAlphabetRate();
	}
	if(strcmp(input2,"f")==0){
		if(strcmp(argv[3],"n")==0){
			printFrequentWord(atoi(argv[4]));
		}
		else{
			printFrequentWord(0);
		}
		//printFrequentWord(n);
	}
	return 0;
}
