#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CSVSave.h"
#include "CSVLineCount.h" // TureRows 的 extern 声明在这里
#include "FileSet.h"

/* * * * * * * 名单写回 * * * * * * *
 * 触发点: 增派 改派 取消派遣 启动时重置海域
 * 做法: 只覆盖第 SEA_CLOS 列(出击海域) 其余格子原样抄
 *       先整份写进 <名单>.tmp 列数校验通过后再替换
 *       原文件改名为 <名单>.bak 留底 替换失败就把备份放回去
 */

// 第 row 行对应的舰娘现在的 sea 从 Kanmutsu_copy 里按舰 ID 查
// CSV 行序和 Kanmutsu_copy 行序不一样 因为 CSVUsefulDataPick 里做过 qsort 只能靠 ID 找
static int sea_of_row(int row) {
	if (CSVData[row][0] == NULL) {
		return -1;
	}
	int id = atoi(CSVData[row][0]);
	for (int i = 1; i < TureRows; i++) {
		if (Kanmutsu_copy[i].ID == id) {
			return Kanmutsu_copy[i].sea;
		}
	}
	return -1; // 没找到 这行原样保留
}

int CSVSave() {
	if (TureRows <= 1) {
		printf("\033[33mCSVSave 名单行数不足 放弃写回\033[0m\n");
		return 1;
	}
	if (csv_path[0] == '\0') {
		printf("\033[33mCSVSave 名单路径为空 放弃写回\033[0m\n");
		return 1;
	}

	char tmp_name[PATH_LEN + 8];
	char bak_name[PATH_LEN + 8];
	snprintf(tmp_name, sizeof(tmp_name), "%s.tmp", csv_path);
	snprintf(bak_name, sizeof(bak_name), "%s.bak", csv_path);

	// 以表头列数为准 后面每行都要对得上 对不上就整单放弃 不动原文件
	int columns = 0;
	while (columns < MAX_CLOS && CSVData[0][columns] != NULL) {
		columns++;
	}
	if (columns <= SEA_CLOS) {
		printf("\033[33mCSVSave 表头列数异常(%d) 放弃写回\033[0m\n", columns);
		return 1;
	}

	// 先写临时文件
	FILE *fp = fopen(tmp_name, "w");
	if (fp == NULL) {
		printf("\033[33mCSVSave 无法创建临时文件 %s\033[0m\n", tmp_name);
		return 1;
	}

	for (int i = 0; i < TureRows; i++) {
		int sea = (i == 0) ? -1 : sea_of_row(i); // 表头那行原样保留
		int j = 0;
		for (; j < columns; j++) {
			if (CSVData[i][j] == NULL) {
				break;
			}
			if (j > 0) {
				fputc(',', fp);
			}
			if (j == SEA_CLOS && sea >= 0) {
				fprintf(fp, "%d", sea); // 只覆盖这一格
			} else {
				fputs(CSVData[i][j], fp);
			}
		}
		if (j != columns) { // 列数对不上 说明内存表和文件不一致 放弃
			printf("\033[33mCSVSave 第 %d 行列数不符 放弃写回\033[0m\n", i);
			fclose(fp);
			remove(tmp_name);
			return 1;
		}
		fputc('\n', fp);
	}

	if (fclose(fp) != 0) {
		printf("\033[33mCSVSave 临时文件写入失败 放弃写回\033[0m\n");
		remove(tmp_name);
		return 1;
	}

	// 原文件改名留底 再把临时文件改名成正式名单
	remove(bak_name);
	if (rename(csv_path, bak_name) != 0) {
		printf("\033[33mCSVSave 原文件改名失败 名单未改动\033[0m\n");
		remove(tmp_name);
		return 1;
	}
	if (rename(tmp_name, csv_path) != 0) {
		printf("\033[33mCSVSave 新文件改名失败 已恢复原文件\033[0m\n");
		rename(bak_name, csv_path); // 把备份放回去
		remove(tmp_name);
		return 1;
	}

	return 0;
}
