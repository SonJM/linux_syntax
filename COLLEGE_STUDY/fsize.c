#include <stdio.h>		// 전처리기가 정의한 stdio.h파일의 내용을 읽어 삽입한다.
#include <stdlib.h>		// 전처리기가 정의한 stdlib.h파일의 내용을 읽어 삽입한다.
#include <unistd.h>		// 전처리기가 정의한 unistd.h파일의 내용을 읽어 삽입한다.
#include <fcntl.h>		// 전처리기가 정의한 fcntl.h파일의 내용을 읽어 삽입한다.
#define BUFSIZE 512		// 프로그램 실행 시 매크로 상수 BUFSIZE를 512로 문자열 값을 치환한다.
int main(int argc, char* argv[]) {	// main 함수로서 컴파일러에 시작지점이라는 것을 알려주는 역활을 하며 한 번만 기술한다.
	char buf[BUFSIZE];	// 문자형으로 buf를 선언 하고 buf의 값의 범위를 위에 선언했던 512의 값을 넣어준 것이다.
	int fd;				// 정수형 변수 fd를 선언한다.
	ssize_t nread;		// ssize_t(= signed integer)형 변수 nread를 선언한다.
	long total = 0; 	// 32bit 정수형 변수 total를 선언한다.
	if ((fd = open(argv[1], O_RDONLY)) == -1)		// open 함수를 통해 path가 가리키는 argv[1]의 파일을 열고 성공시 파일 디스크립터(열린 파일을 나타내는 번호)를 실패 시 -1을 리턴받는다, 대상 파일을 여는 입출력 방식은 O_RDONLY(읽기/쓰기 모드)로 read(), write()
		perror(argv[1]);							// 위의 조건문이 참일 경우 실행, perror함수는 오류 처리 함수로서 open 함수의 값이 fd에 입력되었을때 -1(= 오류)일 경우 오류 내용을 출력하는 함수 
	while ((nread = read(fd, buf, BUFSIZE)) > 0)	// read함수를 통해 fd가 나타내는 파일을 최대 BUFSIZE(512) byte크기만큼 읽고 buf에 저장, ssize_t 형 nread에 read()값을 대입 후 비교 연산자를 통한 조건 성립 확인
		total += nread; 							// 32bit 정수형 변수인 total에 기존 total 값 + nread의 값을 더해준다.
	close(fd);	// fd가 나타내는 파일을 닫는다. 성	공하면 0, 실패하면 -1을 리턴한다.
	printf("%s File Size: %ld byte \n", argv[1], total);	// printf는 출력하는 함수로서 " "의 사이의 내용을 출력하며 %s는 문자열 출력이며  argv[1]의 값을 출력, %ld는 정수형 출력으로 total 값을 출력한다. 
	exit(0);	// 프로그램 종료를 나타내는 함수로서 return 함수와 동일하며 -1값과 0 값은 부모 프로세스에게 종료상태를 알려줄 수 있는 값이 된다.
}