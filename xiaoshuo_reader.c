#include<../include/layout_v3.h>
FILE *fp;
int locate=0;
char ch=0,zh=0,limit=0,op=0,back=0;
int p(int input){
	printf("%d|%x\n",input,input,input);
}
int save(){
	FILE *save=fopen("./process","w");
	printf("%d\n",save);
	if(save==0){
		free(save);
		return 0;
	}
	fprintf(save,"%d",locate);
	exit(0);
}
int operation(){
	op=getch();
	if(op==27)
		save();
	else if(op==49){
		limit=0;
		while(limit<10){
			fseek(fp,--locate,0);
			ch=fgetc(fp);
			p(locate);
			if(ch==10)
				limit++;
			if(locate==0)
				break;
		}
	}else if(op==48){
		limit=0;
		while(limit<10){
			fseek(fp,++locate,0);
			ch=fgetc(fp);
			p(locate);
			if(ch==10)
				limit++;
			if(locate==0)
				break;
		}
	}
}
int main(){
	fp=fopen("./xiaoshu.txt","r");
	FILE *load=fopen("./process","r");
	fscanf(load,"%d",&locate);
	fclose(load);
	fseek(fp,locate,0);
	p(limit);
	if(!locate==0)
		if((ch=fgetc(fp))!=10)
			while(limit<10){
				fseek(fp,--locate,0);
				ch=fgetc(fp);
				if(ch==10)
					++limit;
				if(ch==0xff||locate==0)
					break;
			}
	limit=0;
	while(1){
		if(limit>20){
			printf("\n ");
			limit=0;
		}
		fseek(fp,locate,0);
		ch=fgetc(fp);
		locate++;
		if(ch==10){
			printf("\n ");
			operation();
			limit=0;
		}else if(isascii(ch)==1)
			printf("%c ",ch);
		else{
			printf("%c",ch);
			if(zh==2){
				++limit;
				zh=0;
			}
			else ++zh;
		}
	}
}