 #include <stdio.h>     // stdio 헤더 호출
#define MAXLINE 80      // 매크로 상수명 MAXLINE을 80 이라는 문자열로 치환
int main(int argc, char* argv[]) {  // argc : main()함수에 전달되는 데이터의 갯수, argv : main()함수에 전달되는 실제적인 데이터(파일의 이름)
    FILE *fp;   // 파일 포인터 fp 선언
    int line = 0;   // int형 데이터 변수 line 선언
    char buffer[MAXLINE];   // buffer[80] : 80크기만큼의 char형 배열 buffer 선언
    
    if( (fp = fopen(argv[1], "r")) == NULL) {   // argv[1]이름의 파일이 존재할 경우 r(읽기 전용)로 파일을 열어서 fp 파일 포인터에 대입후 NULL일시
        fprintf(stderr, "파일 열기 오류\n");     // argv[1]이름의 파일이 존재하지 않을 경우 오류 메세지 출력;
    	exit(2);                                
    }
    while (fgets(buffer, MAXLINE, fp) != NULL) {    // fp가 가리키는 파일 내용 한 줄 읽기
	line++;                             // line 한 줄 증가
	printf("%3d %s", line, buffer);     // buffer에 있는 파일의 내용을 줄 번호와 함께 출력
    }
    exit(0);
}
