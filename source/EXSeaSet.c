#include "EXSeaSet.h"
#include "FileSet.h"

int EXSeaSet() {
	// 贴条数目（及名称）设置
	EXSea_num = 0;
	printf("★ 输入贴条数量 ★\n");
	printf(">>");
	scanf("%d", &EXSea_num);
	printf("★ 贴条数目为 %d ★\n", EXSea_num);

	printf("\n");
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                        ┃\n");
	printf("┃   是否设置各贴条名称   ┃\n");
	printf("┃                        ┃\n");
	printf("┃    01 - 是  \033[31m00 - 否\033[0m    ┃\n");
	printf("┃                        ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
	int choise;
	choise = 0;
	scanf("%d", &choise);
	if (choise == 1)
	{
		printf("★ 输入活动名称 ★\n");
		printf(">>");
		while(getchar() != '\n'); // scanf 是不安全的 前面读取到的 \n 还在缓冲区中 需要清一下缓冲区才能用 fgets 以后尽量全用 fgets
		fgets(sea_name[0], 50, stdin); // 读取活动名称
		sea_name[0][strcspn(sea_name[0], "\n")] = '\0';
		printf("★ 活动名称为 %s ★\n\n", sea_name[0]);
		for (int i = 1; i <= EXSea_num; i++)
		{
			printf("★ 输入贴条 %d 名称 ★\n", i);
			printf(">>");
			fgets(sea_name[i], 50, stdin); // 读取活动名称
			sea_name[i][strcspn(sea_name[i], "\n")] = '\0';
			printf("★ 贴条 %d 名称为 %s ★\n\n", i, sea_name[i]);
		}
		
	} else if (choise == 0) { // 不设置 写为默认值
		printf("\033[31m不设置 将使用默认值\033[0m\n\n");
		sprintf(sea_name[0], "活动海域");
		for (int i = 1; i <= EXSea_num; i++)
		{
			sprintf(sea_name[i], "贴条 %d", i);
		}
		
	} else { // 输入错误 视同不设置
		printf("\033[38;5;211mしぐれ いくよ~\033[0m\n\n");
		sprintf(sea_name[0], "活动海域");
		for (int i = 1; i <= EXSea_num; i++)
		{
			sprintf(sea_name[i], "贴条 %d", i);
		}
		
	}
	
	

	// 依次编辑各海域锁船信息
	for(int i = 1; i <= EXSea_num; i++) {
		printf("★ 开始编辑贴条 %s ★\n", sea_name[i]);
		
		// 归零海域舰船计数
		int kanmutsu_count_i = 0; // 下面应重新赋实际值
		// 初始化打印舰种标志符
		int printid = 99;
		// 归零海域编辑完成标志符
		int sea_finished_flag_i = 1; // 置 1 继续编辑, 置 0 编辑下一海域 

		while(sea_finished_flag_i != 0) {
			// 检查海域是否分配舰船
			for(int j = 1; j < TureRows; j++) {
				if(Kanmutsu_copy[j].sea == i) {
					kanmutsu_count_i = kanmutsu_count_i + 1; // 如有 则增加 kanmutsu_count_i 计数
				}
			}
			if(kanmutsu_count_i == 0) {
				printf("★ 海域 %d 未分配舰娘 ★\n", i);
			} else {
				// 打印已分配到当前海域的舰船
				printf("★ 目前 %d 名舰娘已分配到海域 %d , 在该海域作战的舰娘为 ★\n", kanmutsu_count_i, i);
				for(int j = 1; j < TureRows; j++) {
					if(Kanmutsu_copy[j].sea == i) {
						printf("| %d || %s || %d |\n", Kanmutsu_copy[j].ID, Kanmutsu_copy[j].name, Kanmutsu_copy[j].level);
					}
				}
				kanmutsu_count_i = 0; // 归零计数信息
			}

			// 选择工作模式 01 - 增加舰船 02 - 移除舰船 00 - 编辑下一海域
			int modeid; // 初始化工作模式码
			modeid = 99; // 初始化工作模式码 设置为 99
			printf("\n");
			printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("┃                                                   ┃\n");
			printf("┃                   选择工作模式                    ┃\n");
			printf("┃                                                   ┃\n");
			printf("┃  01 - 增加舰娘  02 - 移除舰娘  \033[31m00 - 编辑下一海域\033[0m  ┃\n");
			printf("┃                                                   ┃\n");
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
			printf(">>");
			scanf("%d", &modeid);

			if(modeid == 1) { // 此时增加舰船
				while(printid != 0) {
					// 选择希望指定的舰种
					printf("\n");
					printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
					printf("┃                                                                                             ┃\n");
					printf("┃                                    增加舰娘 选择分配舰种                                    ┃\n");
					printf("┃                                                                                             ┃\n");
					printf("┃ 01 - 工作艦        02 - 戦艦          03 - 揚陸艦        04 - 正規空母      05 - 水上機母艦 ┃\n");
					printf("┃ 06 - 海防艦        07 - 潜水母艦      08 - 潜水空母      09 - 潜水艦        10 - 練習巡洋艦 ┃\n");
					printf("┃ 11 - 航空巡洋艦    12 - 航空戦艦      13 - 装甲空母      14 - 補給艦        15 - 軽巡洋艦   ┃\n");
					printf("┃ 16 - 軽空母        17 - 重巡洋艦      18 - 重雷装巡洋艦  19 - 駆逐艦        \033[31m00 - 退出\033[0m       ┃\n");
					printf("┃                                                                                             ┃\n");
					printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
					printf(">>");
					scanf("%d", &printid); // 读取希望分配的舰种
					printf("\n");
					if(printid == 1) {
						printf("工作艦 共 %d 名\n", AR_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "工作艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "工作艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 2) {
						printf("戦艦 共 %d 名\n", BB_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "戦艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "戦艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 3) {
						printf("揚陸艦 共 %d 名\n", LHA_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "揚陸艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "揚陸艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 4) {
						printf("正規空母 共 %d 名\n", CV_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "正規空母") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "正規空母") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 5) {
						printf("水上機母艦 共 %d 名\n", AV_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "水上機母艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "水上機母艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 6) {
						printf("海防艦 共 %d 名\n", DE_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "海防艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "海防艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 7) {
						printf("潜水母艦 共 %d 名\n", AS_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "潜水母艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "潜水母艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 8) {
						printf("潜水空母 共 %d 名\n", SSV_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "潜水空母") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "潜水空母") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 9) {
						printf("潜水艦 共 %d 名\n", SS_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "潜水艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "潜水艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 10) {
						printf("練習巡洋艦 共 %d 名\n", CT_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "練習巡洋艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "練習巡洋艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 11) {
						printf("航空巡洋艦 共 %d 名\n", CAV_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "航空巡洋艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "航空巡洋艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 12) {
						printf("航空戦艦 共 %d 名\n", BBV_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "航空戦艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "航空戦艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 13) {
						printf("装甲空母 共 %d 名\n", CVB_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "装甲空母") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "装甲空母") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 14) {
						printf("補給艦 共 %d 名\n", AO_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "補給艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "補給艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 15) {
						printf("軽巡洋艦 共 %d 名\n", CL_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "軽巡洋艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "軽巡洋艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 16) {
						printf("軽空母 共 %d 名\n", CVL_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "軽空母") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "軽空母") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 17) {
						printf("重巡洋艦 共 %d 名\n", CA_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "重巡洋艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "重巡洋艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 18) {
						printf("重雷装巡洋艦 共 %d 名\n", CLT_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "重雷装巡洋艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "重雷装巡洋艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 19) {
						printf("駆逐艦 共 %d 名\n", DD_num);
						for(int i = 0; i < TureRows; i++) {
							if(strcmp(Kanmutsu_copy[i].type, "駆逐艦") == 0 && Kanmutsu_copy[i].sea == 0) {
								printf("| %7d || %s || %d || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else if(strcmp(Kanmutsu_copy[i].type, "駆逐艦") == 0 && Kanmutsu_copy[i].sea != 0) {
								printf("\033[31m| %7d || %s || %d || %d |\033[0m\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].speed, Kanmutsu_copy[i].level);
							} else {
								; // 什么也不做
							}
						}
						//printid = 99;
					} else if(printid == 1120) {
						LayEggs();
					} else if(printid == 0) {
						printf("退出\n");
						printid = 0;
					} else {
						printf("\033[38;5;211m都说了别乱输! ⊙∩⊙\033[0m\n\n");
					}

					if(printid != 0 && printid < 20) {
						// 将希望在该海域作战的舰船 Kanmutsu_copy.sea 赋值为 i (以舰ID作为舰船的唯一识别标识符)
						int selected_id; // 初始化该海域舰船ID选择变量
						selected_id = 0; // 初始化该海域舰船ID选择变量
						int ship_find_flag; // 初始化舰船查找标识符 找到置一
						ship_find_flag = 0; // 初始化舰船查找标识符 找到置一
						int ship_find_index; // 查找到的舰船在 Kanmutsu_copy 结构体重的次序 初始置0
						ship_find_index = 0; // 查找到的舰船在 Kanmutsu_copy 结构体重的次序 初始置0
						int change_flag; // 舰船海域更改标识符 若更改置一
						change_flag = 0; // 舰船海域更改标识符 若更改置一
						printf("★ 根据舰 ID 选择舰娘 输入舰ID \033[31m(输入 0 放弃本次选择)\033[0m ★\n");
						printf(">>");
						scanf("%d", &selected_id);

						// 根据输入的 selected_id 查找名单中是否有该舰船
						for(int j = 1; j < TureRows; j++) {
							if(Kanmutsu_copy[j].ID == selected_id) {
								printf("★ 输入 ID 为 %d \033[32m该 ID 有效\033[0m ★\n\n", selected_id);
								ship_find_flag = 1;
								ship_find_index = j;
								break; // 找到直接跳出循环
							}
						}

						if(selected_id != 0) { // selected_id != 0
							if(ship_find_flag == 1) { // 有这条船 进一步判断是否已经去往其他海域
								if(Kanmutsu_copy[ship_find_index].sea != 0) { // 被派到其他海域了
									printf("\n");
									printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
									printf("┃                                      ┃\n");
									printf("┃  目标舰娘被派往\033[31m海域 %d \033[0m是否更改海域   ┃\n", Kanmutsu_copy[ship_find_index].sea);
									printf("┃                                      ┃\n");
									printf("┃         \033[31m01 - 更改\033[0m  00 - 放弃         ┃\n");
									printf("┃                                      ┃\n");
									printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
									scanf("%d", &change_flag);
										if(change_flag == 1) {
											printf("★ 已确认更改 舰娘 %d 前往海域 %d ★\n\n", Kanmutsu_copy[ship_find_index].ID, i);
											Kanmutsu_copy[ship_find_index].sea = i;
										} else if(change_flag == 0) {
											printf("★ 已放弃更改 ★\n\n");
										} else {
											printf("\033[38;5;211mOvO\033[0m\n\n");
										}
								} else { // 待机中 直接锁
									Kanmutsu_copy[ship_find_index].sea = i; // 锁船
								}
							} else { // 没这条船
								printf("\033[31m★ 未找到 舰ID 为 %d 的舰娘 ★\033[0m\n\n", selected_id);
							}
						} else { // selected_id == 0 放弃本次选择
							printf("★ 放弃本次选择 ★\n");
						}
					}

					if(printid != 0) {
						// 再次检查海域是否分配舰船
						for(int j = 1; j < TureRows; j++) {
							if(Kanmutsu_copy[j].sea == i) {
								kanmutsu_count_i = kanmutsu_count_i + 1; // 如有 则增加 kanmutsu_count_i 计数
							}
						}
						if(kanmutsu_count_i == 0) {
							printf("★ 海域 %d 未分配舰娘 ★\n", i);
						} else {
							// 打印已分配到当前海域的舰船
							printf("★ 目前 %d 名舰娘已分配到海域 %d , 在该海域作战的舰娘为 ★\n", kanmutsu_count_i, i);
							for(int j = 1; j < TureRows; j++) {
								if(Kanmutsu_copy[j].sea == i) {
									printf("| %d || %s || %d |\n", Kanmutsu_copy[j].ID, Kanmutsu_copy[j].name, Kanmutsu_copy[j].level);
								}
							}
							kanmutsu_count_i = 0; // 归零计数信息
						}
					}
				}
				printid = 99;

				// 判断是否完成该海域编辑 这块的判断移到开头选 增加 / 减少 舰船模式那里了
				// printf("是否继续当前海域编辑: \n");
				// printf("01 - 继续编辑当前海域     00 - 编辑下一海域\n");
				// scanf("%d", &sea_finished_flag_i);

			} else if (modeid == 2) { // 此时移除舰船
				int selected_id; // 初始化该海域舰船ID选择变量
				selected_id = 0; // 初始化该海域舰船ID选择变量
				
				while(1) { // 当 selected_id = 0时跳出循环
					int ship_find_flag; // 初始化舰船查找标识符 找到置一
					ship_find_flag = 0; // 初始化舰船查找标识符 找到置一
					int ship_find_index; // 查找到的舰船在 Kanmutsu_copy 结构体重的次序 初始置0
					ship_find_index = 0; // 查找到的舰船在 Kanmutsu_copy 结构体重的次序 初始置0
					int change_flag; // 舰船海域更改标识符 若更改置一
					change_flag = 0; // 舰船海域更改标识符 若更改置一

					// 输入需移除舰船 ID
					printf("\n");
					printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
					printf("┃                            ┃\n");
					printf("┃    输入舰 ID 以移除舰娘    ┃\n");
					printf("┃                            ┃\n");
					printf("┃     ID - ID  \033[31m00 - 退出\033[0m     ┃\n");
					printf("┃                            ┃\n");
					printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
					printf(">>");
					scanf("%d", &selected_id);

					if(selected_id != 0) { // selected_id != 0
						// 根据输入的 selected_id 查找名单中是否有该舰船
						for(int j = 1; j < TureRows; j++) {
							if(Kanmutsu_copy[j].ID == selected_id) { // ID 有效且已分配海域
								printf("★ 输入 ID 为 %d \033[32m该 ID 有效\033[0m ★\n\n", selected_id);
								ship_find_flag = 1;
								ship_find_index = j;
								break; // 找到直接跳出循环
							}
						}

						if(ship_find_flag == 1) { // 有这条船 进一步判断是否已经分配海域
							if(Kanmutsu_copy[ship_find_index].sea != 0) { // 已分配海域了
								printf("\n");
								printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
								printf("┃                                      ┃\n");
								printf("┃  目标舰娘被派往海域 %d 是否取消派遣   ┃\n", Kanmutsu_copy[ship_find_index].sea);
								printf("┃                                      ┃\n");
								printf("┃           \033[31m01 - 是\033[0m  00 - 否           ┃\n");
								printf("┃                                      ┃\n");
								printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
								printf(">>");
								scanf("%d", &change_flag);
									if(change_flag == 1) {
										printf("已取消 舰娘 %d 派遣计划\n\n", Kanmutsu_copy[ship_find_index].ID);
										Kanmutsu_copy[ship_find_index].sea = 0;
										// 打印当前海域锁船信息以供参考
										for(int j = 1; j < TureRows; j++) {
											if(Kanmutsu_copy[j].sea == i) {
												kanmutsu_count_i = kanmutsu_count_i + 1; // 如有 则增加 kanmutsu_count_i 计数
											}
										}
										if(kanmutsu_count_i == 0) {
											printf("★ 海域 %d 未分配舰娘 ★\n", i);
										} else {
											// 打印已分配到当前海域的舰船
											printf("★ 目前 %d 名舰娘已分配到海域 %d , 在该海域作战的舰娘为 ★\n", kanmutsu_count_i, i);
											for(int j = 1; j < TureRows; j++) {
												if(Kanmutsu_copy[j].sea == i) {
													printf("| %d || %s || %d |\n", Kanmutsu_copy[j].ID, Kanmutsu_copy[j].name, Kanmutsu_copy[j].level);
												}
											}
											kanmutsu_count_i = 0; // 归零计数信息
										}
									} else if(change_flag == 0) {
										printf("已放弃更改\n\n");
										// 打印当前海域锁船信息以供参考
										for(int j = 1; j < TureRows; j++) {
											if(Kanmutsu_copy[j].sea == i) {
												kanmutsu_count_i = kanmutsu_count_i + 1; // 如有 则增加 kanmutsu_count_i 计数
											}
										}
										if(kanmutsu_count_i == 0) {
											printf("★ 海域 %d 未分配舰娘 ★\n", i);
										} else {
											// 打印已分配到当前海域的舰船
											printf("★ 目前 %d 名舰娘已分配到海域 %d , 在该海域作战的舰娘为 ★\n", kanmutsu_count_i, i);
											for(int j = 1; j < TureRows; j++) {
												if(Kanmutsu_copy[j].sea == i) {
													printf("| %d || %s || %d |\n", Kanmutsu_copy[j].ID, Kanmutsu_copy[j].name, Kanmutsu_copy[j].level);
												}
											}
											kanmutsu_count_i = 0; // 归零计数信息
										}
									} else {
										printf("⊙ ω ⊙\n");
										// 打印当前海域锁船信息以供参考
										for(int j = 1; j < TureRows; j++) {
											if(Kanmutsu_copy[j].sea == i) {
												kanmutsu_count_i = kanmutsu_count_i + 1; // 如有 则增加 kanmutsu_count_i 计数
											}
										}
										if(kanmutsu_count_i == 0) {
											printf("★ 海域 %d 未分配舰娘 ★\n", i);
										} else {
											// 打印已分配到当前海域的舰船
											printf("★ 目前 %d 名舰娘已分配到海域 %d , 在该海域作战的舰娘为 ★\n", kanmutsu_count_i, i);
											for(int j = 1; j < TureRows; j++) {
												if(Kanmutsu_copy[j].sea == i) {
													printf("| %d || %s || %d |\n", Kanmutsu_copy[j].ID, Kanmutsu_copy[j].name, Kanmutsu_copy[j].level);
												}
											}
											kanmutsu_count_i = 0; // 归零计数信息
										}
									}
							} else { // 待机中
								printf("\033[38;5;211m★ 该舰娘摸鱼中:) ★\033[0m\n\n"); // 锁船
								// 打印当前海域锁船信息以供参考
								for(int j = 1; j < TureRows; j++) {
									if(Kanmutsu_copy[j].sea == i) {
										kanmutsu_count_i = kanmutsu_count_i + 1; // 如有 则增加 kanmutsu_count_i 计数
									}
								}
								if(kanmutsu_count_i == 0) {
									printf("★ 海域 %d 未分配舰娘 ★\n", i);
								} else {
									// 打印已分配到当前海域的舰船
									printf("★ 目前 %d 名舰娘已分配到海域 %d , 在该海域作战的舰娘为 ★\n", kanmutsu_count_i, i);
									for(int j = 1; j < TureRows; j++) {
										if(Kanmutsu_copy[j].sea == i) {
											printf("| %d || %s || %d |\n", Kanmutsu_copy[j].ID, Kanmutsu_copy[j].name, Kanmutsu_copy[j].level);
										}
									}
									kanmutsu_count_i = 0; // 归零计数信息
								}
							}
							ship_find_flag = 0;
						} else { // 没这条船
							printf("未找到 \033[31m舰ID 为 %d \033[0m的舰娘\n\n", selected_id);
							// 打印当前海域锁船信息以供参考
							for(int j = 1; j < TureRows; j++) {
								if(Kanmutsu_copy[j].sea == i) {
									kanmutsu_count_i = kanmutsu_count_i + 1; // 如有 则增加 kanmutsu_count_i 计数
								}
							}
							if(kanmutsu_count_i == 0) {
								printf("★ 海域 %d 未分配舰娘 ★\n", i);
							} else {
								// 打印已分配到当前海域的舰船
								printf("★ 目前 %d 名舰娘已分配到海域 %d , 在该海域作战的舰娘为 ★\n", kanmutsu_count_i, i);
								for(int j = 1; j < TureRows; j++) {
									if(Kanmutsu_copy[j].sea == i) {
										printf("| %d || %s || %d |\n", Kanmutsu_copy[j].ID, Kanmutsu_copy[j].name, Kanmutsu_copy[j].level);
									}
								}
								kanmutsu_count_i = 0; // 归零计数信息
							}
						}
					} else { // selected_id == 0 返回上一级
						printf("返回上一级\n\n");
						break;
					}
				}
			} else if (modeid == 0) { // 跳出循环 编辑下一海域
				sea_finished_flag_i = 0;
			} else { // 输入错误
				printf("\033[38;5;211m都说了别乱输! ⊙∩⊙\033[0m\n\n");
			}
		}
	}
}





















