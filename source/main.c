#include <stdio.h>
#include <string.h>
#include <unistd.h> // readlink / access / usleep 都是 POSIX 接口 Linux 上可用 和 win 平台不通用
#include "main.h"
#include "FileSet.h"

/* * * * * * * 名单路径查找 * * * * * * *
 * 顺序: 可执行文件旁边 -> 可执行文件所在目录的上一级
 * 两处都没有就返回 0 由 main 打印提示并退出
 * 路径查到后存进全局 csv_path 读取 写入 备份三处共用
 */

static int csv_exists(const char *path) {
	return access(path, F_OK) == 0; // F_OK 只检查存在性
}

static int csv_in_dir(const char *dir) {
	int written = snprintf(csv_path, sizeof(csv_path), "%s/%s", dir, CSV_FILE_NAME);
	if (written < 0 || (size_t)written >= sizeof(csv_path)) {
		return 0; // 路径超长 视为不可用
	}
	return csv_exists(csv_path);
}

// 借助 /proc/self/exe 拿到可执行文件的真实位置 Linux 特有 win 平台得换 GetModuleFileNameA
static int exe_dir(char *out, size_t size) {
	char buffer[PATH_LEN];
	ssize_t len = readlink("/proc/self/exe", buffer, sizeof(buffer) - 1);
	if (len <= 0) {
		return 0;
	}
	buffer[len] = '\0';
	char *last_slash = strrchr(buffer, '/');
	if (last_slash == NULL) {
		return 0;
	}
	*last_slash = '\0'; // 去掉可执行文件名 只留目录
	snprintf(out, size, "%s", buffer);
	return 1;
}

static int csv_path_init(void) {
	char dir[PATH_LEN];

	if (exe_dir(dir, sizeof(dir)) == 0) {
		return csv_in_dir("."); // 拿不到 /proc/self/exe 就退回当前工作目录
	}

	if (csv_in_dir(dir) == 1) {
		return 1; // 先找可执行文件旁边
	}

	char *last_slash = strrchr(dir, '/');
	if (last_slash == NULL) {
		return 0;
	}
	if (last_slash == dir) {
		return 0; // 已经在根目录 没有上一级了
	}
	*last_slash = '\0';
	return csv_in_dir(dir); // 再找上一级
}

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

	// 找名单 找不到就别往下走了
	if (csv_path_init() == 0) {
		printf("\033[31m没有找到舰娘名单\033[0m\n");
		printf("\033[33m已尝试: 可执行文件旁边 以及它的上一级目录\033[0m\n");
		usleep(300000); // 就这里用了 和 win 平台不通用
		return 1;
	}

	printf("正在由 %s 导入舰队信息\n", csv_path);
	// CSV 文件真实行数统计
	if (CSVLineCount() != 0) {
		printf("\033[31m舰队名单统计失败 程序退出\033[0m\n");
		usleep(300000);
		return 1;
	}
	// CSV 文件读取
	if (CSVRead() != 0) {
		printf("\033[31m舰队名单读取失败 程序退出\033[0m\n");
		usleep(300000);
		return 1;
	}
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
	if (scanf("%d", &seaid_reset) != 1) {
		seaid_reset = 0; // 输入结束或输入非法 当作不重置
	}
	// scanf 是不安全的 前面读取到的 \n 还在缓冲区中 需要清一下缓冲区才能用 fgets 以后尽量全用 fgets
	int clear_ch;
	while((clear_ch = getchar()) != '\n' && clear_ch != EOF) {
		; // 读到行尾或文件结束为止 原来写成 while(getchar() != '\n'); 输入结束时会死循环
	}

	if (seaid_reset == 1) { // 此时重置海域信息
		for(int i = 1; i < TureRows; i++) {
			Kanmutsu_copy[i].sea = 0;
		}
		printf("★ 舰娘海域派遣信息已重置 ★\n");
		if (CSVSave() == 0) {
			printf("\033[32m★ 已写回名单文件 ★\033[0m\n");
		} else {
			printf("\033[33m★ 写回名单文件失败 本次改动只在内存中 ★\033[0m\n");
		}

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
		if (scanf("%d", &workmodeid) != 1) {
			printf("\n\033[33m输入结束 程序退出\033[0m\n");
			break; // 输入流结束就退出 否则下面会一直循环空转
		}
		
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
			// 贴条信息查看
			printf(">贴条信息查看<\n");
			EXSeaPrint();
			workmodeid = 99;
		} else if(workmodeid == 4) {
			// 贴条信息输出
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
	return 0;
}

/* * * * 范例 * * * * /
int main(){
	a = 0;
	printf("a = %d\n", a);
	fuction1(&a); // 向函数1传入a变量
	printf("a = %d\n", a);
}
/* * * * * * * * * * */
