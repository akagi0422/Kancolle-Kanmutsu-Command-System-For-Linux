#include <unistd.h> // 就这里用了 和 win 平台不通用
#include "main.h"
#include "FileSet.h"

int main(){
	printf("\n");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                 \033[9m军极密 ★ 0年\033[0m  ┃\n");
	printf("┃                                               ┃\n");
	printf("┃    ★ Welcome to Kanmutsu Command System! ★    ┃\n");
	printf("┃                                               ┃\n");
	printf("┃                                               ┃\n");
	printf("┃                                               ┃\n");
	printf("┃    Version: 1.0              Author: Akagi    ┃\n");
	printf("┃                                               ┃\n");
	printf("┃                                               ┃\n");
	printf("┃                                               ┃\n");
	printf("┃               海 军 程 序 本 部               ┃\n");
	printf("┃                                               ┃\n");
	printf("┃                   2025.12                     ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
	printf("正在由 %s 导入舰队信息\n", FILENAME);
	// CSV 文件真实行数统计
	CSVLineCount();
	// CSV 文件读取
	CSVRead();
	// 有用数据选取 拷贝进结构体
	CSVUsefulDataPick();
	printf("\033[32m舰队信息导入成功!\033[0m\n");

	// 判断是否需要复位海域标识符
	int seaid_reset;
	seaid_reset = 0;
	printf("\n");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                              ┃\n");
	printf("┃         是否需要重置舰娘海域分配信息         ┃\n");
	printf("┃                                              ┃\n");
	printf("┃               \033[31m01 - 是\033[0m  00 - 否               ┃\n"); // 3? 为背景色设置
	printf("┃                                              ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
	printf(">>");
	scanf("%d", &seaid_reset);
	while(getchar() != '\n'); // scanf 是不安全的 前面读取到的 \n 还在缓冲区中 需要清一下缓冲区才能用 fgets 以后尽量全用 fgets

	if (seaid_reset == 1) { // 此时重置海域信息
		for(int i = 1; i < TureRows; i++) {
			Kanmutsu_copy[i].sea = 0;
		}
		printf("★ 舰娘海域派遣信息已重置 ★\n");

	}  else if (seaid_reset == 0) { // 此时不重置海域信息
		printf("★ 舰娘海域派遣信息不重置 ★\n");

	} else { // 打错了 也不重置
		printf("Ciallo~ \033[38;5;211mあかぎがだいすき!\033[0m (∠'ω<)⌒☆\n"); // 3? 为背景色设置

	}
	

	// 工作模式选择
	int workmodeid = 99;
	while(workmodeid  != 0) {
		printf("\n");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                                                                             ┃\n");
		printf("┃                                       选择工作模式                                          ┃\n");
		printf("┃                                                                                             ┃\n");
		printf("┃                                                                                             ┃\n");
		printf("┃    01 - 查看舰队信息  02 - 海域贴条设置  03 - 贴条信息查看  04 - 贴条信息导出  \033[31m00 - 退出\033[0m    ┃\n");
		printf("┃                                                                                             ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
		printf(">>");
		scanf("%d", &workmodeid);
		
		if(workmodeid == 1) {
			// 舰队信息打印
			printf(">查看舰队信息<\n");
			KanmutsuDataPrint();
			workmodeid = 99;
		} else if(workmodeid == 2) {
			// 设置贴条信息
			printf(">海域贴条设置<\n\n");
			EXSeaSet();
			workmodeid = 99;
		} else if(workmodeid == 3) {
			printf(">贴条信息查看<\n");
			EXSeaPrint();
			workmodeid = 99;
		} else if(workmodeid == 4) {
			printf(">贴条信息输出<\n");
			Output();
			workmodeid = 99;
		} else if(workmodeid == 0) {
			printf("再见的说 Nya~\n");
			workmodeid = 0;
		} else {
			printf("\033[38;5;211m锟斤拷 烫烫烫 !!!\033[0m\n");
		}
	}

	usleep(300000); // 就这里用了 和 win 平台不通用
}

/* * * * 范例 * * * * /
int main(){
	a = 0;
	printf("a = %d\n", a);
	fuction1(&a); // 向函数1传入a变量
	printf("a = %d\n", a);
}
/* * * * * * * * * * */
