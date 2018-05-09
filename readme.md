# Project2

-------------------------------------------
팀장

2013722022 옥준영(wns1119)

팀원

2013722042 송민규(lilac778)

2013722073 김태영(kty9418)

2013722078 박종현(pjh6818)
-------------------------------------------
이 프로젝트는 'text1'파일정보를 받아오는 filestat1(), 'text'파일정보를 받아오는 filestat2(), 두 파일의 수정 시간을 받아오는 filetime1(), filetime2(), 두 파일의 사이즈와 블락 수를 비교하는 sizecmp(), blockcmp(), 두 파일의 수정 날짜와 시간을 비교하는 datacmp(), timecmp()로 구성되어 있다.
## Skeleton code
```
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

struct stat stat1, stat2;
struct tm time1, time2;

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
}
void filestat2(void)
{
}

void filetime1(void)
{
}

void filetime2(void)
{
}

void sizecmp(void)
{
}

void blockcmp(void)
{
}

void datecmp(void)
{
}

void timecmp(void)
{
}
```
* 2018.05.09 
   * struct tm *time1, *time2 --> struct tm time1, time2로 변경
## filestat1(), filestat2()
### stat()
``` 
#include <sys/types.h> 
#include <sys/stat.h>
#include <unistd.h> 

int stat(const char *path, struct stat *buf); 
```
* stat() : 파일 정보 받아오는 함수
  * 리턴 값 : 성공시 0, 실패시 -1
* const char *path : 파일 경로
* struct stat *buf : 파일 정보를 받아올 포인터
```
struct stat {
dev_t st_dev; /* ID of device containing file */
ino_t st_ino; /* inode number */
mode_t st_mode; /* protection */
nlink_t st_nlink; /* number of hard links */
uid_t st_uid; /* user ID of owner */
gid_t st_gid; /* group ID of owner */
dev_t st_rdev; /* device ID (if special file)
off_t st_size; /* total size, in bytes */
blksize_t st_blksize; /* blocksize for file system I/O */
blkcnt_t st_blocks; /* number of 512B blocks
allocated */
time_t st_atime; /* time of last access */
time_t st_mtime; /* time of last modification */
time_t st_ctime; /* time of last status change */
};
```
### 2018.05.09
```
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
```
* 'text1', 'text2' 파일의 정보가 struct stat 구조체 전역 변수 stat1, stat2에 각각 저장됨.
* stat() 파일의 정보를 얻어오지 못할 시 에러 출력

## filetime1(), filetime2()
### localtime()
```
#include <time.h>

struct tm *localtime(const time_t* timep);
```
* localtime() : time_t 타입의 시간을 활용할 수 있게 가공시켜주는 함수
* const time_t* timep : time_t타입의 변수를 가리키는 포인터
* struct tm* localtime : 시간 정보가 들어가는 구조체 포인터
```
struct tm {
int tm_sec; /* seconds */
int tm_min; /* minutes */
int tm_hour; /* hours */
int tm_mday; /* day of the month */
int tm_mon; /* month */
int tm_year; /* year */
nt tm_wday; /* day of the week */
int tm_yday; /* day in the year */
int tm_isdst; /* daylight saving time */
};
```
* month(tm_mon)의 경우 0부터 시작함
### 2018.05.09
```
void filetime1(void)
{
	time1 = *localtime(&stat1.st_mtime);
}

void filetime2(void)
{
	time2 = *localtime(&stat2.st_mtime);
}
```
* stat 구조체 변수인 stat1, stat2의 최종 수정 시간 변수인 time_t st_mtime을 localtime 함수의 인자로 넣어 tm 구조체 변수 time1, time2에 최종 수정 시간 정보를 얻어온다.
## sizecmp()
## blockcmp()
## datecmp()
## timecmp()
