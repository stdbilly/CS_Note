#include <func.h>

typedef struct student_t{
	int num;
	char name[20];
	float score;
}Student_t,*pStudent_t;

int main(int argc,char *argv[]) {
	ARGS_CHECK(argc,2);
	Student_t s[3]={{1005,"lisi",86.3},{1002,"lele",78.4},{1006,"zhansan",89.5}},tmp;
	int fd=open(argv[1],O_RDWR|O_CREAT,0666);
	ERROR_CHECK(fd,-1,"open");
	for(int i=0;i<3;i++) {
		write(fd,&s[i],sizeof(Student_t));
	}
	lseek(fd,0,SEEK_SET);
	for(int i=0;i<3;i++) {
		read(fd,&tmp,sizeof(Student_t));
		printf("%d\t%s\t%5.2f\n",tmp.num,tmp.name,tmp.score);
	}
	
}
