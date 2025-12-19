#ifndef FileSet_H
#define FileSet_H

#define FILENAME "/home/temp/Workbench/KCS/KanmutsuListUTF8.csv" // Linux 读直接导出的 GBK 会乱码 需另存为 UTF8 可根据文件存放位置与文件名修改
#define MAX_ROWS 600 // 最大行数 600 行 可根据镇守府床位数自行修改
#define MAX_CLOS 59 // 最大列数 59 列 由 poi 插件导出 csv 文件列数决定
#define USEFUL_CLOS 6 // 有用数据 6 列 舰ID 舰名 出击海域 舰种 速力 等级
#define MAX_SEA 999 // 最大贴条数999 可根据实际活动贴条情况修改 但 999 应该是够了x

typedef struct {
	int ID;
	char name[50]; // 假定最长舰名为 50 字节
	int sea;
	char type[20]; // 假定最长舰种为 20 字节
	int speed;
	int level;
} KanmutsuData;

char *CSVData[MAX_ROWS][MAX_CLOS]; // 如果有多个头文件包含 CSVRead.h 应使用 extern char 否则会导致多重定义错误
char *UsefulData[MAX_ROWS][USEFUL_CLOS];  // 有用数据数组
char sea_name[MAX_SEA][50]; // 支持 MAX_SEA 个海图命名 名称最大长度 50 字节 sea_name[0] 设置为活动名称 !0 项为贴条名称
int AR_num;
int BB_num;
int LHA_num;
int CV_num;
int AV_num;
int DE_num;
int AS_num;
int SSV_num;
int SS_num;
int CT_num;
int CAV_num;
int BBV_num;
int CVB_num;
int AO_num;
int CL_num;
int CVL_num;
int CA_num;
int CLT_num;
int DD_num;
int EXSea_num;

KanmutsuData Kanmutsu[MAX_ROWS]; // 声明包含全部人员的结构体 结构体类型 数组名称 数组中元素个数
KanmutsuData Kanmutsu_copy[MAX_ROWS]; // 备份 用于编辑贴条信息
KanmutsuData AR[10]; // 声明 工作艦 结构体         ★★数目可根据自家镇守府情况修改(下同)★★
KanmutsuData BB[80]; // 声明 戦艦 结构体
KanmutsuData LHA[15]; // 声明 揚陸艦 结构体
KanmutsuData CV[50]; // 声明 正規空母 结构体
KanmutsuData AV[20]; // 声明 水上機母艦 结构体
KanmutsuData DE[50]; // 声明 海防艦 结构体
KanmutsuData AS[10]; // 声明 潜水母艦 结构体
KanmutsuData SSV[20]; // 声明 潜水空母 结构体
KanmutsuData SS[40]; // 声明 潜水艦 结构体
KanmutsuData CT[10]; // 声明 練習巡洋艦 结构体
KanmutsuData CAV[20]; // 声明 航空巡洋艦 结构体
KanmutsuData BBV[20]; // 声明 航空戦艦 结构体
KanmutsuData CVB[20]; // 声明 装甲空母 结构体
KanmutsuData AO[20]; // 声明 補給艦 结构体
KanmutsuData CL[80]; // 声明 軽巡洋艦 结构体
KanmutsuData CVL[40]; // 声明 軽空母 结构体
KanmutsuData CA[60]; // 声明 重巡洋艦 结构体
KanmutsuData CLT[20]; // 声明 重雷装巡洋艦 结构体
KanmutsuData DD[400]; // 声明 駆逐艦 结构体

#endif // FileSet_H

