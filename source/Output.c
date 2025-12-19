#include "Output.h"
#include "FileSet.h"

int Output() {
    // 文件名称设置
    char output_file_name[100];
    snprintf(output_file_name, sizeof(output_file_name), "%s 锁船表.csv", sea_name[0]);

    // 创建并打开导出文件
    FILE *fp = fopen(output_file_name, "w");
    if (fp == NULL)
    {
        printf("\033[33m导出文件创建失败\033[0m\n");
    } else {
        printf("\033[32m导出文件创建成功 文件名为：%s\033[0m\n", output_file_name);
    }
    printf("正在导出当前锁船信息\n");

    // 写入 “活动名称”锁船表
    fprintf(fp, "%s 锁船表\n", sea_name[0]);

    // 写入各海域锁船信息
    for (int i = 1; i <= EXSea_num; i++)
    {
        // 写入海域名称
        printf("%s\n", sea_name[i]);
        fprintf(fp, "%s\n", sea_name[i]);
        printf("艦种,艦名,等级\n");
        fprintf(fp, "艦种,艦名,等级\n");
        // 检查海域是否锁船
        int kanmutsu_count_i;
        kanmutsu_count_i = 0;
        for(int j = 1; j < TureRows; j++) {
            if(Kanmutsu_copy[j].sea == i) {
                kanmutsu_count_i = kanmutsu_count_i + 1; // 如有 则增加 kanmutsu_count_i 计数
            }

        }

        if(kanmutsu_count_i == 0) {
            printf("未分配\n");
            fprintf(fp, "未分配\n");
        } else {
            // 打印指定海域锁船信息
            for (int j = 0; j < TureRows; j++)
            {
                if(Kanmutsu_copy[j].sea == i) {
                    printf("%s,%s,%d\n", Kanmutsu_copy[j].type, Kanmutsu_copy[j].name, Kanmutsu_copy[j].level);
                    fprintf(fp, "%s,%s,%d\n", Kanmutsu_copy[j].type, Kanmutsu_copy[j].name, Kanmutsu_copy[j].level);
                }

            }

        }

    }
    

    printf("\033[32m当前锁船信息导出完毕\033[0m\n");
    fclose(fp); // 关闭导出文件
}