#include <stdio.h>      // stdio ��� ȣ��
/* ���� ���� ���α׷� */
int main(int argc, char* argv[]) {  // argc : main()�Լ��� ���޵Ǵ� �������� ����, argv : main()�Լ��� ���޵Ǵ� �������� ������(������ �̸�)
    char c;     // char ������ ���� c ���� (���丮 c)
    FILE *fp1, *fp2;    // ���� ������ fp1, fp2 ����
    
    if(argc != 3) {     // �������� ������ 3���� �ƴҽ�
	    fprintf(stderr, "����:  %s ����1 ����2\n", argv[0]); // copy ���� ���
	    return 1;   // return 1
    }
    
    fp1 = fopen(argv[1], "r");      //  argv[1]�� ������ "r" = ȣ���� ���� ����
    
    if (fp1 == NULL) {      // ���� �����Ͱ� NULL�Ͻ�
	    fprintf(stderr, "���� %s ���� ����\n", argv[1]);  // ���� �߻� �޽��� ���
	    return 2;   // return 2
    }

    fp2 = fopen(argv[2], "w");      //  argv[1]�� ������ "w" = ȣ���� ���� ����
    
    while ((c = fgetc(fp1)) != EOF)     // fp1���� ���� ������ fgetc�� �޾Ƽ� ������ ���� �ƴҋ����� while�� ����
	fputc(c, fp2);  // fgetc(fp1)�� ���� �����͸� ���ڷ� ���� c�� "w"�Ӽ��� fp2 ���� �������� ���Ͽ� ���ڸ� �ϳ��� ����(����Ѵ�).
    fclose(fp1);    // fp1 ������ �ݴ´�. (�����Ͻ� 0 �׷��� ������ EOF(-1)�� ��ȯ�Ѵ�.)
    fclose(fp2);    // fp2 ������ �ݴ´�. (�����Ͻ� 0 �׷��� ������ EOF(-1)�� ��ȯ�Ѵ�.)
    return 0;       // return 0
} 
