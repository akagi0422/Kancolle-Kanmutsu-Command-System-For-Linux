#include <stdio.h>
#include <stdlib.h>
#include "CSVLineCount.h"
#include "FileSet.h"

int CSVLineCount() {
	//	打开 KanmutsuList
	FILE *file = fopen(csv_path, "r");
	if(file == NULL) {
		printf("\033[33mCSVLineCount 打开文件 文件打开失败\033[0m\n");
		return 1;
	}

	//	逐行读取文件 相关变量初始化
	char* CSV_Line_Count_Buffer; // 初始化 CSV 临时行缓冲区 局部变量
	CSV_Line_Count_Buffer = NULL; // 不初始化会在主函数分舰种打印信息时报错
	size_t CSV_Line_Count_Buffer_Size; // 行缓冲区大小 局部变量
	CSV_Line_Count_Buffer_Size = 0; // getline 要求 *lineptr 为 NULL 时 *size 必须为 0 原来没初始化 属于未定义行为
	ssize_t ClosReturn; // 跳出下面 while 循环用的临时返回值 局部变量
	TureRows = 0; // 初始化行字符数 全局变量

	while((ClosReturn = getline(&CSV_Line_Count_Buffer, &CSV_Line_Count_Buffer_Size, file)) != -1) {
		TureRows++;
		if(TureRows >= MAX_ROWS) { // 超过 MAX_ROWS 后面的行本来也装不下 提前提醒
			printf("\033[33mCSVLineCount 名单达到 %d 行上限 请在 FileSet.h 调大 MAX_ROWS\033[0m\n", MAX_ROWS);
			break;
		}
	}

	free(CSV_Line_Count_Buffer); // getline 申请的内存用完要还 虽然只读一次 还了更干净

	// 关闭 KanmutsuList
	fclose(file);

	return 0;
}
