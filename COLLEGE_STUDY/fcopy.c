#include <stdio.h>  // 전처리기가 정의한 stdio.h파일의 내용을 읽어 삽입한다.
#include <stdlib.h> // 전처리기가 정의한 stdio.h파일의 내용을 읽어 삽입한다.
#include <unistd.h> // 전처리기가 정의한 stdio.h파일의 내용을 읽어 삽입한다.
#include <fcntl.h>  // 전처리기가 정의한 stdio.h파일의 내용을 읽어 삽입한다.
/* 파일 복사 프로그램 */
int main(int argc, char* argv[]) {  // main 함수로서 컴파일러에 시작지점이라는 것을 알려주는 역활을 하며 한 번만 기술한다.
                                    // main 함수 실행 시 데이터(매개 변수) 갯수를 저장하는 argc와 실질적인 데이터를 담는 char형 포인터 변수 argv를 선언해준다
                                    // ex) ./fopen fopen.c fopen.cc 를 하게되면 argv[0] = ./fopen, argv[1] = fopen.c, argv[2] = fopen.cc가 된다.
    int fd1, fd2, n;                // int형 변수 fd1, fd2, n을 선언한다. 줄의 맨 마지막에 줄의 끝을 알리는 세미콜론(;)을 작성해준다.
    char buf[BUFSIZ];               // BUFSIZ = 512(byte)만큼의 크기를 갖는 char형 변수 buf를 선언한다.

    if(argc != 3) {                 // 조건문을 알리는 if()함수를 통해 argc의 값이 3이 아닐때 괄호 안의 코드를 실행한다.
	fprintf(stderr,"사용법: %s file 1 file 2\n",argv[0]);  // fprintf()함수를 통해 stdio.h파일에 들어있는 기본파일 stderr을 파일 포인터로 지정하고  %s에 argv[0]의 값을 대입해 "사용법: %s file 1 file 2\n"을 출력한다.
   	exit(1);                        // 프로그램 종료를 나타내는 함수로서 return 함수와 동일하며 값이 1일시엔 에러메세지 출력과 함께 프로그램을 종료한다.
    }                               // 위의 if함수의 끝을 가리키는 중괄호이다.

    if((fd1 = open(argv[1], O_RDONLY)) == -1) { // open() 함수를 통해 path가 가리키는 argv[1]의 파일을 열고 성공시 파일 디스크립터(열린 파일을 나타내는 번호)를 실패 시 -1을 리턴받는다
                                                // 대상 파일을 여는 입출력 방식은 O_RDONLY(읽기/쓰기 모드)로 read(), write()
	perror(argv[1]);                // perror함수는 오류 처리 함수로서 open 함수의 값이 fd에 입력되었을때 -1(= 오류)일 경우 argv[1]에 대한 오류 내용을 출력하는 함수 
	exit(2);                        // 프로그램 종료를 나타내는 함수로서 return 함수와 동일하며 프로세스에 에러 코드 2를 반환한다.
    }

    if((fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644)) == -1) {   // open() 함수를 통해 path가 가리키는 argv[2]의 파일을 열고 성공시 파일 디스크립터(열린 파일을 나타내는 번호)를 실패 시 -1을 리턴받는다
                                                                        // O_WRONLY(쓰기 전용으로 열기), O_CREAT -> 0644(파일 접근 권한 지정), O_TRUNC(기존의 파일 내용을 모두 삭제) 옵션을 추가해서 argv[2] 파일을 연다.
	perror(argv[2]);                // perror함수는 오류 처리 함수로서 open 함수의 값이 fd에 입력되었을때 -1(= 오류)일 경우 argv[2]에 대한 오류 내용을 출력하는 함수 
	exit(3);                        // 프로그램 종료를 나타내는 함수로서 return 함수와 동일하며 프로세스에 에러 코드 3을 반환한다.
    }

    while((n = read(fd1, buf, BUFSIZ)) > 0)	// read()함수를 통해 fd1에 있는 파일의 내용을 끝까지 읽은 값(byte)을 버퍼를 통해 int형 변수 n에 대입한다
	write(fd2, buf, n);	            // write()함수를 통해 int형 변수 n만큼의 크기를 버퍼를 통해 fd2에 작성한다.
    exit(0);                        // 프로그램 종료를 나타내는 함수로서 return 함수와 동일하며 값이 0일시엔 프로그램 정상종료를 의미한다.
}
