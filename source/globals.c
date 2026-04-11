#include "FileSet.h"

// 所有变量的实际定义
char *CSVData[MAX_ROWS][MAX_CLOS];
char *UsefulData[MAX_ROWS][USEFUL_CLOS];
char sea_name[MAX_SEA][50];
int AR_num = 0;
int BB_num = 0;
int LHA_num = 0;
int CV_num = 0;
int AV_num = 0;
int DE_num = 0;
int AS_num = 0;
int SSV_num = 0;
int SS_num = 0;
int CT_num = 0;
int CAV_num = 0;
int BBV_num = 0;
int CVB_num = 0;
int AO_num = 0;
int CL_num = 0;
int CVL_num = 0;
int CA_num = 0;
int CLT_num = 0;
int DD_num = 0;
int EXSea_num = 0;
int TureRows = 0;

KanmutsuData Kanmutsu[MAX_ROWS];
KanmutsuData Kanmutsu_copy[MAX_ROWS];
KanmutsuData AR[10];
KanmutsuData BB[80];
KanmutsuData LHA[15];
KanmutsuData CV[50];
KanmutsuData AV[20];
KanmutsuData DE[50];
KanmutsuData AS[10];
KanmutsuData SSV[20];
KanmutsuData SS[40];
KanmutsuData CT[10];
KanmutsuData CAV[20];
KanmutsuData BBV[20];
KanmutsuData CVB[20];
KanmutsuData AO[20];
KanmutsuData CL[80];
KanmutsuData CVL[40];
KanmutsuData CA[60];
KanmutsuData CLT[20];
KanmutsuData DD[400];
