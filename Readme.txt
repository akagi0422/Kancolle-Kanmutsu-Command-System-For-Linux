于 Linux 平台开发的 kancolle 锁船分配系统

可能需要用户更改的地方
    导入文件路径目前是写死在 FileSet.h 文件中的 编译好就没法改读取文件路径了 得改
        (但既然是开源软件...改 FileSet.h 文件中的路径对用户来说应该也很轻松吧:)
    在 main.c line2 中引用了 <unistd.h> 在 win 平台需要改为 <windows.h>
    在 main.c line87 中使用了 usleep 函数 在 win 平台得换

实现的功能
    POI 舰队信息导入
    舰队信息查看
    活动海图编辑
    舰娘作战海域分配
    海域锁船信息查看
    海域锁船信息导出