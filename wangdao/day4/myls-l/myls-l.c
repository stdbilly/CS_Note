#include <func.h>

void file_mode(struct stat *buf) {
	int i;
	char mode[11]="----------";
	switch(buf->st_mode & S_IFMT) {
		case S_IFIFO:
			mode[0]='f';
			break;
		case S_IFDIR:
			mode[0]='d';
			break;
		case S_IFSOCK:
			mode[0]='s';
			break;
		case S_IFBLK:
			mode[0]='b';
			break;
		case S_IFLNK:
			mode[0]='l';
			break;
	}
    
    if(buf->st_mode & S_IRUSR) 
        mode[1]='r';
    if(buf->st_mode & S_IWUSR)
        mode[2]='w';
    if(buf->st_mode & S_IXUSR)
        mode[3]='x';
    if(buf->st_mode & S_IRGRP)
        mode[4]='r';
    if(buf->st_mode & S_IWGRP)
        mode[5]='w';
    if(buf->st_mode & S_IXGRP)
        mode[6]='x';
    if(buf->st_mode & S_IROTH)
        mode[7]='r';
    if(buf->st_mode & S_IWOTH)
        mode[8]='w';
    if(buf->st_mode & S_IXOTH)
        mode[9]='x';

    for(i=0;i<10;i++) {
        printf("%c",mode[i]);
    }
}

int main(int argc,char* argv[]) {
	if(argc==1)
        argv[1]=".";
	DIR* dir;
	dir=opendir(argv[1]);
	ERROR_CHECK(dir,NULL,"opendir");
	struct dirent *fp;
	int ret;
  	struct stat buf;
    char path[1024]={0},time[50]={0};
	while(fp=readdir(dir)) {
         if(!strcmp(fp->d_name,".")||!strcmp(fp->d_name,"..")) {
             continue;
         }
         strcpy(path,argv[1]);
         strcat(path,"/");
         strcat(path,fp->d_name);
         ret=stat(path,&buf);
         ERROR_CHECK(ret,-1,"stat");

         file_mode(&buf);
         strcpy(time,ctime(&buf.st_mtime));
         time[16]=0;
         printf(" %ld %s %s %5ld %s %s\n",buf.st_nlink,getpwuid(buf.st_uid)->pw_name,getgrgid(buf.st_gid)->gr_name,buf.st_size,time+4,fp->d_name);
	}	
	closedir(dir);
	return 0;
}
