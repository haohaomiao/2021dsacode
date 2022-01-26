
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[10001];
 
char * replace(char * s, int len, int index, char c){
    char * rs = (char *) malloc(len);
    for (int i = 0; i < len; i++){
        rs[i] = s[i];
    }
    rs[index] = c;
    return rs;
}

int is_teacher_win(char *s, int len){
    if(len == 0){
        return 0;
    }
    int top = 0; //ջ��
    for (int i = 0; i < len; i++){
        if(s[i] == '-'){ //��ʾֱ���õ�
            continue;
        }
        if(s[i] == 'C'){
            char* rs1 = replace(s, len, i, 'A');
            char* rs2 = replace(s, len, i, 'B');
            char* rs3 = replace(s, len, i, '-');
            int r1 = is_teacher_win(rs1, len);
            int r2 = is_teacher_win(rs2, len);
            int r3 = is_teacher_win(rs3, len);
            free(rs1);
            free(rs2);
            free(rs3);
            return r1 || r2 || r3;
        }
        if (s[i] == 'A'){//A
            top++;//��ջ
        }else if(s[i] == 'B'){ //B
            if(top == 0){ //ջ����,˵��B��ǰ��ûA��
                return 0;
            }
            top--;//��ջ
        }
    }
    return top == 0;// Ϊ0 ��ʾ AB ��ƥ����
}
 
 
int main() {
    int n;
    scanf("%d\n",&n);
    if(n == 1){
        printf("False");
        return 0;
    }

    for (int i = 0; i < n; i++){
        scanf("%c",&s[i]);
    }
    if(is_teacher_win(s, sizeof(s)))
    printf("True");
    else
    printf("False");
    return 0;
}