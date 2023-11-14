#include <stdio.h> // 전처리기가 정의한 stdio.h파일의 내용을 읽어 삽입한다.
#include <stdlib.h> // 전처리기가 정의한 stdlib.h파일의 내용을 읽어 삽입한다.
#include <fcntl.h> // 전처리기가 정의한 fcntl.h파일의 내용을 읽어 삽입한다.
int main(int argc, char* argv[]) {	// main 함수로서 컴파일러에 시작지점이라는 것을 알려주는 역활을 하며 한 번만 기술한다.
	int fd;							// int형 변수 fd를 선언
	if ((fd = open(argv[1], O_RDWR)) == -1)		// open 함수를 통해 path가 가리키는 argv[1]의 파일을 열고 성공시 파일 디스크립터(열린 파일을 나타내는 번호)를 실패 시 -1을 리턴받는다, 대상 파일을 여는 입출력 방식은 O_RDONLY(읽기/쓰기 모드)로 read(), write()
		printf("Error: File Open\n");			// 위의 조건문이 참일 경우 print 해주는 문으로 문자열을 출력시 "내용" 으로 표시한다.
	else printf("Success: File %s open : %d\n", argv[1], fd);		// 위의 조건문이 거짓일 경우 출력하는 문으로서 %s는 argv[1]을, %d는 fd의 값( = 파일 디스크립터, 열린 파일의 번호)을 출력한다.
	close(fd); 	// fd가 나타내는 파일을 닫는다. 성공하면 0, 실패하면 -1을 리턴한다.
	exit(0); 		// 프로그램 종료를 나타내는 함수로서 return 함수와 동일하며 –1값과 0값은 부모 프로세스에게 종료상태를 알려줄 수 있는 값이 된다.
} // 메인함수의 범위를 나타낸다.