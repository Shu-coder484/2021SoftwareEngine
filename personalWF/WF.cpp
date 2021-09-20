#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
//使用结构体表示每个字母出现的次数 
typedef struct{
	char letter;	//字母 
	int num;	//出现次数 
	double rate;	//出现频率 
}alphabet;
alphabet alphabets[26];
int letterNums=0; //文本当中的字母数总和

//使用结构体表示出现的单词
typedef struct words{
	int num;	//出现次数
	char wordName[60];	//单词名称	
}word[1000];
int wordNums=0;	//文本中出现的单词总数 

//初始化结构体 alphabet 
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

// -c 输出英文文本中26个字母出现的频率
void printAlphabetRate(){
	FILE *fp;
	int i,j;
	alphabet temp;
	//检查文件是否为空 
	if((fp=fopen("text.txt","r"))==NULL){
		printf("file can not open\n");
		return;
	}
	initAlphabet();
	//从文件中读取字符进行比对、统计
	char l;
	//fscanf()：读取文本中的字符  fgetc()：读取文本中的字符 
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
	
	//计算频率
	 for(i=0;i<26;i++){
	 	alphabets[i].rate=(1.0*alphabets[i].num/letterNums*1.0)*100.0;
	 }
	//排序 alphabets
	for(i=0;i<26;i++){
		for(j=0;j<26-i;j++){
			if(alphabets[j].rate<alphabets[j+1].rate){
				temp=alphabets[j];
				alphabets[j]=alphabets[j+1];
				alphabets[j+1]=temp;
			}
		}
	}
	//测试 & 输出 
		printf("字母 出现频率 百分比\n");
	for(i=0;i<26;i++){
		printf(" %c      %d     %.2f%%\n",alphabets[i].letter,alphabets[i].num,alphabets[i].rate);
	}
	printf("总的字母数：%d\n",letterNums);
	printf("----------------------------------------------\n");
	return;
} 

// -f 输出单个文件中的前 N 个最常出现的英语单词。文本必须以标点符号结尾 
// -n [num] 输出排名前n的单词 
void printFrequentWord(int n){
	FILE *fp;
	char w[60],ch;	//w[60]表示临时存放单词,ch表示从文本中获取的字母 
	int i=0,j=0,flag=0,m=1,k=0;	//flag表示1个单词是否已放入w[60];m表示是否有单词相同 
	//检查文件是否为空 
	if((fp=fopen("text.txt","r"))==NULL){
		printf("file can not open\n");
		return;
	}
	//统计单词数量
	words word[1000];
	while((ch=fgetc(fp))!=EOF){
		//大写字母转小写字母
		if(ch>='A'&&ch<='Z'){
			ch=ch+32;
		} 
		if(ch>='a'&&ch<='z'){
			w[i]=ch; //开始存入单词到临时表 
			i++;
			flag=1;
		}
		else{
			if(ch=='-'&&(ch=fgetc(fp))=='\n'){	//非字母，非空格 
				flag=0;
			}
			else{
				if(flag==1){
					//写入w完成+'\0' 
					w[i]='\0';
					i=0;
					flag=0;
					m=0;
					for(j=0;j<k;j++){
						if(strcmp(w,word[j].wordName)==0){
							m=1;	//表示前面有单词相同 
							break;
						}
					}
					if(m){
						word[j].num++;	//单词数量加1 
					}
					else{	//存入结构体word表 
						word[k].num=1;
						strcpy(word[k].wordName,w);
						k++;
					}
				}
			}
		}
	}
	int l=0,n1=0;
	//统计文本中出现的单词总数
	while(word[l].num){
		wordNums++;
		l++;
	}
	//排序
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
	//测试 & 输出
	l=0;
	//printf("出现次数    单词\n");
	if(n==0){
		printf("出现次数    单词\n");
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
		printf("出现次数最多的前%d个单词：\n",n);
		printf("出现次数    单词\n");
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
	printf("总的单词数：%d\n",wordNums);
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
