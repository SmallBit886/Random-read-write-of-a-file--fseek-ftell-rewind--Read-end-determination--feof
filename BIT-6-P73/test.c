#define _CRT_SECURE_NO_WARNINGS 1
//5. 文件的随机读写
//5.1 fseek	----	int fseek( FILE *stream, long offset, int origin );
//根据文件指针的位置和偏移量来定位文件指针。
#include <stdio.h>
#include <errno.h>

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	//定位文件指针
//	fseek(pf, 3, SEEK_SET);
//	//读取文件
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

//5.2 ftell -----  返回文件指针相对于起始位置的偏移量	----- long int ftell(FILE * stream);
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

//5.3 rewind	让文件指针的位置回到文件的起始位置	void rewind ( FILE * stream );
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
//	fputc(n, pFile);//将字母放入文件中
//
//	rewind(pFile);//指针回到起始位置
//	fread(buffer, 1, 26, pFile);//读26为放入buffer中
//	fclose(pFile);//关闭文件
//	buffer[26] = '\0';//末尾放入\0
//	puts(buffer);	//输出ABCDEFGHIJKLMNOPQRSTUVWXYZ \0
//	return 0;
//}



//7. 文件读取结束的判定
/*7.1 被错误使用的feof
牢记：在文件读取过程中，不能用feof函数的返回值直接来判断文件的是否结束。
feof 的作用是：当文件读取结束的时候，判断是读取结束的原因是否是：遇到文件尾结束。
*/

//文本文件读取是否结束，判断返回值是否为 EOF （ fgetc ），或者 NULL （ fgets ）
// 
//2. 二进制文件的读取结束判断，判断返回值是否小于实际要读的个数。
//fread判断返回值是否小于实际要读的个数。
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
//	int c; // 注意：int，非char，要求处理EOF
//	FILE* fp = fopen("test1.txt", "r");
//	if (!fp) {
//		perror("File opening failed");//File opening failed: No such file or directory
//		return EXIT_FAILURE;
//	}
//	//fgetc 当读取失败的时候或者遇到文件结束的时候，都会返回EOF
//	while ((c = fgetc(fp)) != EOF) // 标准C I/O读取文件循环
//	{
//		putchar(c);//ABCDEFGHIJKLMNOPQRSTUVWXYZE
//	}
//	//判断是什么原因结束的
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