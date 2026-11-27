// 宏用于头文件保护 避免重复包含 宏通常大写定义
#ifndef CSVSave_H
#define CSVSave_H

// 把内存中的海域分配信息覆盖写回名单 CSV 成功返回 0 失败返回 1
// 机制: 先整份写到 <名单>.tmp 校验通过后再替换 原文件留成 <名单>.bak
int CSVSave();

#endif // CSVSave_H
