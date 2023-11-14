 #include <stdio.h>     // stdio ��� ȣ��
#define MAXLINE 80      // ��ũ�� ����� MAXLINE�� 80 �̶�� ���ڿ��� ġȯ
int main(int argc, char* argv[]) {  // argc : main()�Լ��� ���޵Ǵ� �������� ����, argv : main()�Լ��� ���޵Ǵ� �������� ������(������ �̸�)
    FILE *fp;   // ���� ������ fp ����
    int line = 0;   // int�� ������ ���� line ����
    char buffer[MAXLINE];   // buffer[80] : 80ũ�⸸ŭ�� char�� �迭 buffer ����
    
    if( (fp = fopen(argv[1], "r")) == NULL) {   // argv[1]�̸��� ������ ������ ��� r(�б� ����)�� ������ ��� fp ���� �����Ϳ� ������ NULL�Ͻ�
        fprintf(stderr, "���� ���� ����\n");     // argv[1]�̸��� ������ �������� ���� ��� ���� �޼��� ���;
    	exit(2);                                
    }
    while (fgets(buffer, MAXLINE, fp) != NULL) {    // fp�� ����Ű�� ���� ���� �� �� �б�
	line++;                             // line �� �� ����
	printf("%3d %s", line, buffer);     // buffer�� �ִ� ������ ������ �� ��ȣ�� �Բ� ���
    }
    exit(0);
}
