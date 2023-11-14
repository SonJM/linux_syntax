#include <stdio.h>      // stdio 헤더 호출
/* 파일 복사 프로그램 */
int main(int argc, char* argv[]) {  // argc : main()함수에 전달되는 데이터의 갯수, argv : main()함수에 전달되는 실제적인 데이터(파일의 이름)
    char c;     // char 데이터 변수 c 선언 (디렉토리 c)
    FILE *fp1, *fp2;    // 파일 포인터 fp1, fp2 선언
    
    if(argc != 3) {     // 데이터의 갯수가 3개가 아닐시
	    fprintf(stderr, "사용법:  %s 파일1 파일2\n", argv[0]); // copy 사용법 출력
	    return 1;   // return 1
    }
    
    fp1 = fopen(argv[1], "r");      //  argv[1]의 파일을 "r" = 호출한 파일 열기
    
    if (fp1 == NULL) {      // 파일 포인터가 NULL일시
	    fprintf(stderr, "파일 %s 열기 오류\n", argv[1]);  // 오류 발생 메시지 출력
	    return 2;   // return 2
    }

    fp2 = fopen(argv[2], "w");      //  argv[1]의 파일을 "w" = 호출한 파일 쓰기
    
    while ((c = fgetc(fp1)) != EOF)     // fp1에서 열린 파일을 fgetc로 받아서 파일의 끝이 아닐떄까지 while문 진행
	fputc(c, fp2);  // fgetc(fp1)을 통해 데이터를 문자로 받은 c를 "w"속성인 fp2 파일 포인터의 파일에 문자를 하나씩 쓴다(출력한다).
    fclose(fp1);    // fp1 파일을 닫는다. (정상일시 0 그렇지 않을땐 EOF(-1)을 반환한다.)
    fclose(fp2);    // fp2 파일을 닫는다. (정상일시 0 그렇지 않을땐 EOF(-1)을 반환한다.)
    return 0;       // return 0
} 
