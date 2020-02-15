//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	/*char str[255];
//	sprintf(str, "%x", 100);*/
//	int i;
//	char buffer[33];
//	printf("Enter a number: ");
//	scanf("%d", &i);//20
//	itoa(i, buffer, 10);
//	printf("decimal: %s\n", buffer); //20
//	itoa(i, buffer, 16);
//	printf("hexadecimal: %s\n", buffer); //14
//	itoa(i, buffer, 2);
//	printf("binary: %s\n", buffer); //10100
//	return 0;
//}

//int main()
//{
//	int n;
//	char* str = "20.50";
//	n = atoi(str);
//	printf("int= %d\n", n);
//	return 0;
//}
//int main()
//{
//	int j = 1;
//	char c = *(char*)(&j);
//	if (c == 1)
//		printf("小端\n");
//	else
//		printf("大端\n");
//
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char str1[20] = "aabbcc";
	char  str2[] = "aa";
	printf("The string: %s\n", str1);		
	memmove(str1+4, str2, sizeof(str2));//由第二个开始前四位
	printf("New string: %s\n", str1);
	return 0;
}

//int main()
//{
//	char dest[10] = "asdfgh";
//	char* ch=strchr(dest,'h' );
//	printf("result= %s\n", ch);
//	return 0;
//}
//int main()
//{
//	char dest[10] = "asdfg";
//	char src[10] = "asdf";
//	printf("result=%d\n", strcmp(dest, src));
//	return 0;
//}
//int main()
//{
//	char dest[10] = "asdfg";
//	char src[10] = "asdf";
//	strcpy(dest,src );
//	printf("dest= %s\n src=%s\n", dest,src);
//	return 0;
//}
//int main()
//{
//	char buffe[20] = "asdfdfd";
//	int n = strlen(buffe);
//	printf("len = %d\n", n);
//	return 0;
//}
