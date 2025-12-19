#include "KanmutsuDataPrint.h"

int KanmutsuDataPrint() {
	int printid = 99;

	while(printid  != 0) {
		printf("\n");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                                                                             ┃\n");
		printf("┃                                     输入希望查看的舰种                                      ┃\n");
		printf("┃                                                                                             ┃\n");
		printf("┃ 01 - 工作艦        02 - 戦艦          03 - 揚陸艦        04 - 正規空母      05 - 水上機母艦 ┃\n");
		printf("┃ 06 - 海防艦        07 - 潜水母艦      08 - 潜水空母      09 - 潜水艦        10 - 練習巡洋艦 ┃\n");
		printf("┃ 11 - 航空巡洋艦    12 - 航空戦艦      13 - 装甲空母      14 - 補給艦        15 - 軽巡洋艦   ┃\n");
		printf("┃ 16 - 軽空母        17 - 重巡洋艦      18 - 重雷装巡洋艦  19 - 駆逐艦        \033[31m00 - 退出\033[0m       ┃\n");
		printf("┃                                                                                             ┃\n");
		printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
		printf(">>");

		// printf("printid 初始值为 %d\n", printid);
		scanf("%d", &printid);
		// printf("printid 输入值为 %d\n", printid);

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
		} else if(printid == 0) {
			printf("退出\n");
			printid = 0;
		} else if(printid == 1120) {
			LayEggs();
		} else {
			printf("\033[38;5;211m服务器向你扔了一只猫娘 错误代码: 201\033[0m\n");
		}
	}
}