于 Linux 平台开发的 kancolle 锁船分配系统

编译与运行
    项目根目录下执行 make        会生成 build/main
    ./build/main 或 cd build && ./main 都能跑 名单文件放在可执行文件旁边或它的上一级目录

名单文件路径（不用再改源码了）
    程序启动时依次找 KanmutsuListUTF8.csv
        1. 可执行文件旁边 build/KanmutsuListUTF8.csv
        2. 可执行文件的上一级目录  项目根目录
    两处都没有则打印 "没有找到舰娘名单" 并退出
    想改文件名改 include/FileSet.h 里的 CSV_FILE_NAME 想改查找范围改 main.c 的 csv_path_init
    CSV 必须是 UTF8 编码 直接导出的 GBK 会乱码

海域信息自动写回
    增派 / 改派 / 取消派遣 / 启动时选择重置 这四种操作都会立刻把海域信息写回名单 CSV
    只覆盖第 5 列（出击海域） 表头行、其余列原样不动
    先整份写进 名单.csv.tmp 列数校验通过后替换
    替换前把原文件改名成 名单.csv.bak 留底 替换失败会把备份放回去

锁船表导出位置
    导出的 "活动名称 锁船表.csv" 和名单 CSV 放在同一个目录

修复
    CSVLineCount.c  getline 的缓冲区大小没初始化（未定义行为）
    CSVRead.c       行数超过 MAX_ROWS 会写穿数组；每行列计数只在写满 MAX_CLOS 列时才归零 列数不足的行会错位；
                    malloc 失败留 NULL 下游 strcpy 会崩；fclose 之后才判断 file == NULL
    Output.c        fopen 失败只打印一句就继续 fprintf 空指针 现在直接返回
    EXSeaPrint.c    sea_name[编号] 没有上界检查 输 1000 以上或负数会野读 现在拦下并提示 未命名的海域显示 "未命名海域"
    main.c          输入结束（EOF）时菜单会无限空转 现在直接退出
    Makefile        clean / debug 目标写法有误 已修好 顺手加了 -std=gnu11

实现的功能
    POI 舰队信息导入
    舰队信息查看
    活动海图编辑
    舰娘作战海域分配
    海域锁船信息查看
    海域锁船信息导出
