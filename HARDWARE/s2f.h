#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <stdint.h>  // ʹ�ñ�׼��������

// ����ָ��ṹ��
typedef struct {
    int action;  // ��������
    int time;  // ִ��ʱ�䣨�룩
} Command;


Command extractAndConvertToFloat(const char* str);

#endif // COMMAND_PARSER_H



