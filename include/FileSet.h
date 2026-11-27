#ifndef FileSet_H
#define FileSet_H

#define CSV_FILE_NAME "KanmutsuListUTF8.csv" // 名单文件名 Linux 读直接导出的 GBK 会乱码 需另存为 UTF8
#define PATH_LEN 512 // 存放 CSV 完整路径的缓冲区大小
#define MAX_ROWS 600 // 最大行数 600 行 可根据镇守府床位数自行修改
#define MAX_CLOS 59 // 最大列数 59 列 由 poi 插件导出 csv 文件列数决定
#define USEFUL_CLOS 6 // 有用数据 6 列 舰ID 舰名 出击海域 舰种 速力 等级
#define MAX_SEA 999 // 最大贴条数999 可根据实际活动贴条情况修改 但 999 应该是够了x
#define SEA_CLOS 4 // 出击海域在 CSV 中的列号 下标从 0 开始

typedef struct {
	int ID;
	char name[50]; // 假定最长舰名为 50 字节
	int sea;
	char type[20]; // 假定最长舰种为 20 字节
	int speed;
	int level;
} KanmutsuData;

// 改为 extern 声明
extern char csv_path[PATH_LEN]; // 名单 CSV 的完整路径 运行期由 main.c 查找后确定 读写备份共用
extern char *CSVData[MAX_ROWS][MAX_CLOS]; // 如果有多个头文件包含 CSVRead.h 应使用 extern char 否则会导致多重定义错误
extern char *UsefulData[MAX_ROWS][USEFUL_CLOS];  // 有用数据数组
extern char sea_name[MAX_SEA][50]; // 支持 MAX_SEA 个海图命名 名称最大长度 50 字节 sea_name[0] 设置为活动名称 !0 项为贴条名称
extern int AR_num;
extern int BB_num;
extern int LHA_num;
extern int CV_num;
extern int AV_num;
extern int DE_num;
extern int AS_num;
extern int SSV_num;
extern int SS_num;
extern int CT_num;
extern int CAV_num;
extern int BBV_num;
extern int CVB_num;
extern int AO_num;
extern int CL_num;
extern int CVL_num;
extern int CA_num;
extern int CLT_num;
extern int DD_num;
extern int EXSea_num;

extern KanmutsuData Kanmutsu[MAX_ROWS]; // 声明包含全部人员的结构体 结构体类型 数组名称 数组中元素个数
extern KanmutsuData Kanmutsu_copy[MAX_ROWS]; // 备份 用于编辑贴条信息
extern KanmutsuData AR[10]; // 声明 工作艦 结构体         ★★数目可根据自家镇守府情况修改(下同)★★
extern KanmutsuData BB[80]; // 声明 戦艦 结构体
extern KanmutsuData LHA[15]; // 声明 揚陸艦 结构体
extern KanmutsuData CV[50]; // 声明 正規空母 结构体
extern KanmutsuData AV[20]; // 声明 水上機母艦 结构体
extern KanmutsuData DE[50]; // 声明 海防艦 结构体
extern KanmutsuData AS[10]; // 声明 潜水母艦 结构体
extern KanmutsuData SSV[20]; // 声明 潜水空母 结构体
extern KanmutsuData SS[40]; // 声明 潜水艦 结构体
extern KanmutsuData CT[10]; // 声明 練習巡洋艦 结构体
extern KanmutsuData CAV[20]; // 声明 航空巡洋艦 结构体
extern KanmutsuData BBV[20]; // 声明 航空戦艦 结构体
extern KanmutsuData CVB[20]; // 声明 装甲空母 结构体
extern KanmutsuData AO[20]; // 声明 補給艦 结构体
extern KanmutsuData CL[80]; // 声明 軽巡洋艦 结构体
extern KanmutsuData CVL[40]; // 声明 軽空母 结构体
extern KanmutsuData CA[60]; // 声明 重巡洋艦 结构体
extern KanmutsuData CLT[20]; // 声明 重雷装巡洋艦 结构体
extern KanmutsuData DD[400]; // 声明 駆逐艦 结构体

#endif // FileSet_H

