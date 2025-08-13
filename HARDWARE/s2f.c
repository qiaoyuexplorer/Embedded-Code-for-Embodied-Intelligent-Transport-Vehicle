#include <ctype.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int action;  // �������루�� 4:��ת��
    int time;    // ִ��ʱ�䣨�� 3�룩
} Command;

// ���ؽṹ�壬����������ʱ��
Command extractAndConvertToFloat(const char* str) {
    Command cmd = {0, 0};

		const char* first_colon = strchr(str, ':');
		
		const char* second_colon = strchr(first_colon + 1, ':');
		
    cmd.action = atoi(first_colon + 1);      // ������������
    cmd.time = atoi(second_colon + 1);  // ����ʱ��
		
    return cmd;
}





//float extractAndConvertToFloat(const char* str) {
//    const char* colon = strchr(str, ':');  // ����ð��λ��
//    
//    colon++;  // ����ð��
//    
//    char buffer[16];  // ���ֻ�����
//    int index = 0;
//    
//    // ��ȡ���֣��������ܵĸ��ţ�
//    while (colon[index] != '\0' && index < sizeof(buffer)-1) {
//        if (isdigit((unsigned char)colon[index]) || 
//            (colon[index] == '-' && index == 0)) {  // ���������ڿ�ͷ
//            buffer[index] = colon[index];
//            index++;
//        } else {
//            break;  // �����������ַ�����ֹͣ
//        }
//    }
//    
//    buffer[index] = '\0';  // �ַ�����ֹ
//    return (float)atoi(buffer);  // תΪ������תfloat������atof������
//}