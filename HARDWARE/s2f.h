#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <stdint.h>  // 使用标准整数类型

// 定义指令结构体
typedef struct {
    int action;  // 动作代码
    int time;  // 执行时间（秒）
} Command;


Command extractAndConvertToFloat(const char* str);

#endif // COMMAND_PARSER_H



