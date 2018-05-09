#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1(void);
void filestat2(void);
void filetime1(void);
void filetime2(void);
void sizecmp(void);
void blockcmp(void);
void datecmp(void);
void timecmp(void);

int main(void)
{
	filestat1();
	filestat2();
	filetime1();
	filetime2();
	sizecmp();
	blockcmp();
	datecmp();
	timecmp();
}

void filestat1(void)

{

	if(stat("./text1", &stat1) == -1)
		printf("file1 stat error\n");

}



void filestat2(void)

{
	if(stat("./text2", &stat2) == -1)
		printf("file2 stat error\n");

}

void filetime1(void)
{
}

void filetime2(void)
{
}

void sizecmp(void)
{
	printf("size compare\n");
	if((int)(stat1.st_size) > (int)(stat2.st_size)){
		printf("text1 is bigger\n\n");
	}else if((int)(stat1.st_size) < (int)(stat2.st_size)){
		printf("text2 is bigger\n\n");
	}else{
		printf("sizes are same\n\n");
	}


}

void blockcmp(void)
{
	printf("block compare\n");
	if((int)(stat1.st_blocks) > (int)(stat2.st_blocks)){
		printf("text1 is bigger\n\n");
	}else if((int)(stat1.st_blocks) < (int)(stat2.st_blocks)){
		printf("text2 is bigger\n\n");
	}else{
		printf("blocks are same\n\n");
	}
}

void datecmp(void)
{
}

void timecmp(void)
{
}

