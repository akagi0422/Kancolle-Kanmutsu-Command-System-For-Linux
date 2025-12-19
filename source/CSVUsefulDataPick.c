#include "CSVUsefulDataPick.h"
#include "FileSet.h"

// 比较函数 用于分类与排序
int type_compare(const void* a, const void* b) {
	KanmutsuData* p1 = (KanmutsuData*)a;
	KanmutsuData* p2 = (KanmutsuData*)b;

	// 舰种升序 分开都能实现 合一起不好用
	int tr = strcmp(p1 -> type, p2 -> type);
	if(tr != 0)
		return tr;

	// 舰名升序
	int nr = strcmp(p1 -> name, p2 -> name);
	if(nr != 0)
		return nr;

	// 等级降序
	if(p1 -> level < p2 -> level)
		return 1;
	else if(p1 -> level > p2 -> level)
		return -1;
	else
		return 0;
}

// 提取有用数据 分类 排序 拆分数组
int CSVUsefulDataPick() {
	int UsefulClos[USEFUL_CLOS] = {0, 1, 4, 5, 6, 7}; // 有用列数数组 局部变量

	// 将 CSVData 数组中的有用数据写入 UsefulData 数组
	for(int i = 0; i < USEFUL_CLOS; i++) {
		for(int j = 0; j < TureRows; j++) {
			UsefulData[j][i] = CSVData[j][UsefulClos[i]];
		}
	}

	// 将 UsefulData 数组中除标题行外数据转换为结构体
	for(int i = 1; i < TureRows; i++) {
		Kanmutsu[i].ID = atoi(UsefulData[i][0]);
		strcpy(Kanmutsu[i].name, UsefulData[i][1]);
		Kanmutsu[i].sea= atoi(UsefulData[i][2]);
		strcpy(Kanmutsu[i].type, UsefulData[i][3]);
		Kanmutsu[i].speed = atoi(UsefulData[i][4]);
		Kanmutsu[i].level = atoi(UsefulData[i][5]);
	}

	// 按照舰种 舰名 等级 排序
	qsort(Kanmutsu, TureRows, sizeof(KanmutsuData), type_compare);

	// 分组
	for(int i = 1;  i < TureRows; i++) {
		if(strcmp(Kanmutsu[i].type, "工作艦") == 0) {
			memcpy(&AR[AR_num], &Kanmutsu[i], sizeof(KanmutsuData));
			AR_num++;
		}

		if(strcmp(Kanmutsu[i].type, "戦艦") == 0) {
			memcpy(&BB[BB_num], &Kanmutsu[i], sizeof(KanmutsuData));
			BB_num++;
		}

		if(strcmp(Kanmutsu[i].type, "揚陸艦") == 0) {
			memcpy(&LHA[LHA_num], &Kanmutsu[i], sizeof(KanmutsuData));
			LHA_num++;
		}

		if(strcmp(Kanmutsu[i].type, "正規空母") == 0) {
			memcpy(&CV[CV_num], &Kanmutsu[i], sizeof(KanmutsuData));
			CV_num++;
		}

		if(strcmp(Kanmutsu[i].type, "水上機母艦") == 0) {
			memcpy(&AV[AV_num], &Kanmutsu[i], sizeof(KanmutsuData));
			AV_num++;
		}
		
		if(strcmp(Kanmutsu[i].type, "海防艦") == 0) {
			memcpy(&DE[DE_num], &Kanmutsu[i], sizeof(KanmutsuData));
			DE_num++;
		}

		if(strcmp(Kanmutsu[i].type, "潜水母艦") == 0) {
			memcpy(&AS[AS_num], &Kanmutsu[i], sizeof(KanmutsuData));
			AS_num++;
		}
		
		if(strcmp(Kanmutsu[i].type, "潜水空母") == 0) {
			memcpy(&SSV[SSV_num], &Kanmutsu[i], sizeof(KanmutsuData));
			SSV_num++;
		}

		if(strcmp(Kanmutsu[i].type, "潜水艦") == 0) {
			memcpy(&SS[SS_num], &Kanmutsu[i], sizeof(KanmutsuData));
			SS_num++;
		}

		if(strcmp(Kanmutsu[i].type, "練習巡洋艦") == 0) {
			memcpy(&CT[CT_num], &Kanmutsu[i], sizeof(KanmutsuData));
			CT_num++;
		}

		if(strcmp(Kanmutsu[i].type, "航空巡洋艦") == 0) {
			memcpy(&CAV[CAV_num], &Kanmutsu[i], sizeof(KanmutsuData));
			CAV_num++;
		}

		if(strcmp(Kanmutsu[i].type, "航空戦艦") == 0) {
			memcpy(&BBV[BBV_num], &Kanmutsu[i], sizeof(KanmutsuData));
			BBV_num++;
		}

		if(strcmp(Kanmutsu[i].type, "装甲空母") == 0) {
			memcpy(&CVB[CVB_num], &Kanmutsu[i], sizeof(KanmutsuData));
			CVB_num++;
		}

		if(strcmp(Kanmutsu[i].type, "補給艦") == 0) {
			memcpy(&AO[AO_num], &Kanmutsu[i], sizeof(KanmutsuData));
			AO_num++;
		}

		if(strcmp(Kanmutsu[i].type, "軽巡洋艦") == 0) {
			memcpy(&CL[CL_num], &Kanmutsu[i], sizeof(KanmutsuData));
			CL_num++;
		}

		if(strcmp(Kanmutsu[i].type, "軽空母") == 0) {
			memcpy(&CVL[CVL_num], &Kanmutsu[i], sizeof(KanmutsuData));
			CVL_num++;
		}

		if(strcmp(Kanmutsu[i].type, "重巡洋艦") == 0) {
			memcpy(&CA[CA_num], &Kanmutsu[i], sizeof(KanmutsuData));
			CA_num++;
		}

		if(strcmp(Kanmutsu[i].type, "重雷装巡洋艦") == 0) {
			memcpy(&CLT[CLT_num], &Kanmutsu[i], sizeof(KanmutsuData));
			CLT_num++;
		}

		if(strcmp(Kanmutsu[i].type, "駆逐艦") == 0) {
			memcpy(&DD[DD_num], &Kanmutsu[i], sizeof(KanmutsuData));
			DD_num++;
		}
	}

	// 将 Kanmutsu 结构体中数据拷贝进 Kanmutsu_copy 结构体 第一行为无定义表头
	for(int i = 0; i < TureRows; i++) {
		memcpy(&Kanmutsu_copy[i], &Kanmutsu[i], sizeof(KanmutsuData));
	}

	/*// 重置 Kanmutsu_copy 结构体中 Kanmutsu_copy.sea 信息为 0 , 以备后续编辑
	for(int i = 1; i < TureRows; i++) { // 第一行是表头 不用重置
		Kanmutsu_copy[i].sea = 0;
	}*/

	//	debug
}
