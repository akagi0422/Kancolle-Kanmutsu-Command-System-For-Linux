#include "CSVRead.h"
#include "FileSet.h"

int CSVRead(){
	//	打开 KanmutsuList
	// printf("CSVRead 打开文件 文件路径为：%s\n", FILENAME);
	FILE *file = fopen(FILENAME, "r");
	if(file == NULL) {
		printf("\033[33mCSVRead 打开文件 文件打开失败\033[0m\n");
		return 1;
	}
	// printf("CSVRead 打开文件 文件打开成功\n");

	// 初始化数二维数组指针为 NULL
	int i = 0; // 表格行计数 局部变量
	int j = 0; // 表格列计数 局部变量

	for(i = 0; i < MAX_ROWS; i++) {
		for(j = 0; j < MAX_CLOS; j++) {
			CSVData[i][j] = NULL;
		}
	}

	// 清零行列计数 待用
	i = 0; // 表格行计数 局部变量
	j = 0; // 表格列计数 局部变量

	//	逐行读取文件 相关变量初始化
	char *CSV_Line_Buffer = NULL; // CSV 行缓冲区 局部变量
	ssize_t CSV_Line_Buffer_Size = 0;  // CSV 行缓冲区大小 局部变量
	ssize_t Line_Char_Num = 0; // CSV 每行字符数 局部变量
	char *CSV_Divid_Part = NULL; // 每行 CSV 中拆分出的表格字段 局部变量

	//	getline 逐行读取文件
	while((Line_Char_Num = getline(&CSV_Line_Buffer, &CSV_Line_Buffer_Size, file)) != -1) {
		CSV_Line_Buffer[strcspn(CSV_Line_Buffer, "\n")] = '\0'; // 移除换行符
		// printf("第 %d 行, 共%ld字符: %s\n", i, Line_Char_Num, CSV_Line_Buffer);
		
		// 拆分出每行第一列数据
		CSV_Divid_Part = strtok(CSV_Line_Buffer, ","); // 以 "," 为标志, 拆分 CSV_Line_Buffer 中的数据
		// printf("第%d 行 1 列数据为 %s\n", i, CSV_Divid_Part);

		// 写入每行数据
		while(CSV_Divid_Part != NULL && j < MAX_CLOS) {
			CSVData[i][j] = malloc(strlen(CSV_Divid_Part) + 1);  // 为第 i 行 j 列的数据动态分配内存
			// printf("第%d 行 %d 列数据分配内存成功\n", i, j);
			if(CSVData[i][j] != NULL) {
				strcpy(CSVData[i][j], CSV_Divid_Part);
			} else {
				printf("\033[33m第%d 行 %d 列数据分配内存失败\033[0m\n", i, j);
			}
			// 拆分出每行后续列数据
			CSV_Divid_Part = strtok(NULL, ","); // 以 "," 为标志, 拆分 CSV_Line_Buffer 中的数据 第二次及以后拆分同一行传入NULL即可
			j++; // 列计数+1

			// 当列计数达到 MAX_CLOS 上限时 重置列计数 以便写入下一行数据
			if(j == MAX_CLOS) {
				j = 0;
			} else {
				;
			}
		}

		Line_Char_Num = 0; // 重置行字符数
		i++; // 行计数 + 1
	}

	// 关闭 KanmutsuList
	fclose(file);
	if(file == NULL) {
		printf("\033[33mCSVRead 关闭文件 文件关闭失败\033[0m\n");
		return 1;
	}
	// printf("CSVRead 关闭文件 文件已关闭\n");

	//	debug
}



/* * * * 范例 * * * * /
int CSVRead(int *a){
	printf("a = %d\n", *a); // 显示传入的a变量
	*a = *a + 1; // a+1
}
/* * *  * * * * * * * */
