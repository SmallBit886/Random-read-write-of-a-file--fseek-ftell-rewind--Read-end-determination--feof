#define _CRT_SECURE_NO_WARNINGS 1
//5. �ļ��������д
//5.1 fseek	----	int fseek( FILE *stream, long offset, int origin );
//�����ļ�ָ���λ�ú�ƫ��������λ�ļ�ָ�롣
#include <stdio.h>
#include <errno.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//��λ�ļ�ָ��
//	fseek(pf, 3, SEEK_SET);
//	//��ȡ�ļ�
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//d
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pFile;
//	pFile = fopen("example.txt", "wb");
//	fputs("This is an apple.", pFile);//This is an apple.
//	fseek(pFile, 9, SEEK_SET);
//	fputs(" sam", pFile);//This is a sample.
//	fclose(pFile);
//	return 0;
//}

//5.2 ftell -----  �����ļ�ָ���������ʼλ�õ�ƫ����	----- long int ftell(FILE * stream);
//int main()
//{
//	FILE* pFile;
//	long size;
//	pFile = fopen("test.txt", "rb");
//	if (pFile == NULL) perror("Error opening file");
//	else
//	{
//		fseek(pFile, 0, SEEK_END); // non-portable
//		size = ftell(pFile);
//		fclose(pFile);
//		printf("Size of test.txt: %ld bytes.\n", size);//Size of test.txt: 8 bytes.
//	}
//	return 0;
//}

//5.3 rewind	���ļ�ָ���λ�ûص��ļ�����ʼλ��	void rewind ( FILE * stream );
//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	int ch = fgetc(pf);
//	printf("%c\n", ch);//a
//
//
//	rewind(pf);
//	printf("%c\n", ch);//a
//
//	fgetc(pf);
//	long size = ftell(pf);
//	printf("%d\n", size);	//1
//
//	rewind(pf);
//	long size1 = ftell(pf);
//	printf("%d\n", size1);	//0
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

/* rewind example */

//int main()
//{
//	int n;
//	char buffer[27];
//	FILE* pFile = fopen("test1.txt", "w+");
//
//	for (n = 'A'; n <= 'Z'; n++)
//	fputc(n, pFile);//����ĸ�����ļ���
//
//	rewind(pFile);//ָ��ص���ʼλ��
//	fread(buffer, 1, 26, pFile);//��26Ϊ����buffer��
//	fclose(pFile);//�ر��ļ�
//	buffer[26] = '\0';//ĩβ����\0
//	puts(buffer);	//���ABCDEFGHIJKLMNOPQRSTUVWXYZ \0
//	return 0;
//}



//7. �ļ���ȡ�������ж�
/*7.1 ������ʹ�õ�feof
�μǣ����ļ���ȡ�����У�������feof�����ķ���ֱֵ�����ж��ļ����Ƿ������
feof �������ǣ����ļ���ȡ������ʱ���ж��Ƕ�ȡ������ԭ���Ƿ��ǣ������ļ�β������
*/

//�ı��ļ���ȡ�Ƿ�������жϷ���ֵ�Ƿ�Ϊ EOF �� fgetc �������� NULL �� fgets ��
// 
//2. �������ļ��Ķ�ȡ�����жϣ��жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
//fread�жϷ���ֵ�Ƿ�С��ʵ��Ҫ���ĸ�����
int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	rewind(pf);
	int ch = fgetc(pf);
	printf("%d\n", ch);//10

	fclose(pf);
	pf = NULL;		
	return 0;
}
// 
//#include <stdlib.h>
//int main(void)
//{
//	int c; // ע�⣺int����char��Ҫ����EOF
//	FILE* fp = fopen("test1.txt", "r");
//	if (!fp) {
//		perror("File opening failed");//File opening failed: No such file or directory
//		return EXIT_FAILURE;
//	}
//	//fgetc ����ȡʧ�ܵ�ʱ����������ļ�������ʱ�򣬶��᷵��EOF
//	while ((c = fgetc(fp)) != EOF) // ��׼C I/O��ȡ�ļ�ѭ��
//	{
//		putchar(c);//ABCDEFGHIJKLMNOPQRSTUVWXYZE
//	}
//	//�ж���ʲôԭ�������
//	if (ferror(fp))
//		puts("I/O error when reading");
//	else if (feof(fp))
//		puts("End of file reached successfully");//End of file reached successfully
//	fclose(fp);
//}


//perror
// 
//int main()
//{
//	FILE* pf = fopen("test2.txt", "r");
//	if (pf == NULL)
//	{
//		perror("hehe");//hehe: No such file or directory
//	}
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}