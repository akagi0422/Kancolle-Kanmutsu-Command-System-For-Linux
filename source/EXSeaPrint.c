#include "EXSeaSet.h"
#include "FileSet.h"

int EXSeaPrint() {
    // 查找 Kanmutsu_copy[600].sea 的最大值以确定贴条数目
    int max_sea; // 初始化海域计数器
    max_sea = 0;
    for (int i = 0; i < TureRows; i++)
    {
        if (Kanmutsu_copy[i].sea > max_sea)
        {
            max_sea = Kanmutsu_copy[i].sea;
        } else {
            ; // 什么也不做
        }
        
    }
    
    int sea_selectid; // 初始化海域选择 id
    sea_selectid = 0;
    // printf("共 %d 海域 输入海域编号以查看该海域锁船信息\n", max_sea);
    // printf("!0 - 编号  00 - 返回上一级");
    // scanf("%d", &sea_selectid);

    while (sea_selectid != 999) // 为零时返回上一级
    {
        printf("\n");
		printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("┃                                               ┃\n");
        printf("┃  共 %d 海域 输入海域编号以查看该海域锁船信息  ┃\n", max_sea);
        printf("┃                                               ┃\n");
        printf("┃ ?? - 编号  00 - 未分配人员  \033[31m999 - 返回上一级\033[0m  ┃\n"); // 999 应该够多了 肯定不会有 999 个贴条的
        printf("┃                                               ┃\n");
        printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n");
        printf(">>");
        scanf("%d", &sea_selectid);
        if(sea_selectid != 999) { // 999 应该够多了 肯定不会有 999 个贴条的
            // 输入海域编号
            printf("★ 当前选择海域 %d ★\n", sea_selectid);
            printf("★ %s ★\n", sea_name[sea_selectid]);

        
            // 检查海域是否锁船
            int kanmutsu_count_i;
            kanmutsu_count_i = 0;
            for(int i = 1; i < TureRows; i++) {
                if(Kanmutsu_copy[i].sea == sea_selectid) {
                    kanmutsu_count_i = kanmutsu_count_i + 1; // 如有 则增加 kanmutsu_count_i 计数
                }

            }

            if(kanmutsu_count_i == 0) {
                printf("★ 海域 %d 未分配舰娘 ★\n", sea_selectid);
            } else {
                // 打印指定海域锁船信息
                for (int i = 0; i < TureRows; i++)
                {
                    if(Kanmutsu_copy[i].sea == sea_selectid) {
                        printf("| %d || %s || %d |\n", Kanmutsu_copy[i].ID, Kanmutsu_copy[i].name, Kanmutsu_copy[i].level);
                    }

                }

            }

        } else {
            printf("返回上一级\n"); // 什么也不做
        }
        
    }

}