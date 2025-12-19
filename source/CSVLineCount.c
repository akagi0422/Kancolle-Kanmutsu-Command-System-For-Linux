#include "CSVLineCount.h"
#include "FileSet.h"

int CSVLineCount() {
	//	打开 KanmutsuList
	// printf("CSVLineCount 打开文件 文件路径为：%s\n", FILENAME);
	FILE *file = fopen(FILENAME, "r");
	if(file == NULL) {
		printf("\033[33mCSVLineCount 打开文件 文件打开失败\033[0m\n");
		return 1;
	}
	// printf("CSVLineCount 打开文件 文件打开成功\n");

	//	逐行读取文件 相关变量初始化
	char* CSV_Line_Count_Buffer; // 初始化 CSV 临时行缓冲区 局部变量
	CSV_Line_Count_Buffer = NULL; // 不初始化会在主函数分舰种打印信息时报错
	ssize_t CSV_Line_Count_Buffer_Size; // 设置行缓冲区大小为 0 局部变量
	int ClosReturn; // 跳出下面 while 循环用的临时返回值 局部变量
	TureRows = 0; // 初始化行字符数 全局变量

	while((ClosReturn = getline(&CSV_Line_Count_Buffer, &CSV_Line_Count_Buffer_Size, file)) != -1) {
		TureRows++;
	}

	// 关闭 KanmutsuList
	fclose(file);
	if(file == NULL) {
		printf("\033[33mCSVLineCount 关闭文件 文件关闭失败\033[0m\n");
		return 1;
	}
	// printf("CSVLineCount 关闭文件 文件已关闭\n");
}

