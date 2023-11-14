#include <unistd.h> // 전처리기가 정의한 stdio.h파일의 내용을 읽어 삽입한다.
#include <fcntl.h>  // 전처리기가 정의한 stdio.h파일의 내용을 읽어 삽입한다.
#include <stdlib.h> // 전처리기가 정의한 stdio.h파일의 내용을 읽어 삽입한다.
#include <stdio.h>  // 전처리기가 정의한 stdio.h파일의 내용을 읽어 삽입한다.
int main(int argc, char* argv[]) {  // main 함수로서 컴파일러에 시작지점이라는 것을 알려주는 역활을 하며 한 번만 기술한다.
                                    // main 함수 실행 시 데이터(매개 변수) 갯수를 저장하는 argc와 실질적인 데이터를 담는 char형 포인터 변수 argv를 선언해준다
                                    // ex) ./fopen fopen.c fopen.cc 를 하게되면 argv[0] = ./fopen, argv[1] = fopen.c, argv[2] = fopen.cc가 된다.
    int fd1, fd2;                   // int형 변수 fd1, fd2을 선언한다. 줄의 맨 마지막에 줄의 끝을 알리는 세미콜론(;)을 작성해준다.

    if((fd1 = creat("myfile", 0600)) == -1) // creat() 함수를 통해 fd1에 "myfile"이라는 이름의 파일을 접근권한 0600으로 생성해서 그 값을 파일 디스크립터 fd1에 대입한다.
                                            // 조건문 if()함수에 의해 파일 생성 오류시(참) 다음에 나오는 코드를 실행한다.
	perror("myfile");                       // perror함수는 오류 처리 함수로서 "myfile"에 대한 오류 내용을 출력하는 함수 

    write(fd1, "Hello! Linux", 12);         // write()함수를 통해 파일 디스크립터 fd1에 정상적으로 "myfile"이라는 파일이 생성 되었을 시 파일 안에 "Hello! Lunux"라는 내용을 12byte크기만큼 작성한다.
    fd2 = dup(fd1);                         // dup()함수를 통해 fd2에 fd1에 대한 파일 디스크립터 복사본을 만든다.
    write(fd2, "Bye! Linux", 10);           // write()함수를 통해 파일 디스크립터 fd2에 "Bye! Linux"라는 내용을 10byte 크기만큼 작성한다.
    exit(0);                                // 프로그램 종료를 나타내는 함수로서 return 함수와 동일하며 값이 0일시엔 프로그램 정상종료를 의미한다.
}
