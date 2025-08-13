#include <ctype.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int action;  // 动作代码（如 4:右转）
    int time;    // 执行时间（如 3秒）
} Command;

// 返回结构体，包含动作和时间
Command extractAndConvertToFloat(const char* str) {
    Command cmd = {0, 0};

		const char* first_colon = strchr(str, ':');
		
		const char* second_colon = strchr(first_colon + 1, ':');
		
    cmd.action = atoi(first_colon + 1);      // 解析动作代码
    cmd.time = atoi(second_colon + 1);  // 解析时间
		
    return cmd;
}





//float extractAndConvertToFloat(const char* str) {
//    const char* colon = strchr(str, ':');  // 查找冒号位置
//    
//    colon++;  // 跳过冒号
//    
//    char buffer[16];  // 数字缓冲区
//    int index = 0;
//    
//    // 提取数字（包括可能的负号）
//    while (colon[index] != '\0' && index < sizeof(buffer)-1) {
//        if (isdigit((unsigned char)colon[index]) || 
//            (colon[index] == '-' && index == 0)) {  // 仅允许负号在开头
//            buffer[index] = colon[index];
//            index++;
//        } else {
//            break;  // 遇到非数字字符立即停止
//        }
//    }
//    
//    buffer[index] = '\0';  // 字符串终止
//    return (float)atoi(buffer);  // 转为整数再转float（避免atof开销）
//}