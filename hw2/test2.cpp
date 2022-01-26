
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
    int top = 0; //栈顶
    for (int i = 0; i < len; i++){
        if(s[i] == '-'){ //表示直接拿掉
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
            top++;//入栈
        }else if(s[i] == 'B'){ //B
            if(top == 0){ //栈空了,说明B的前面没A了
                return 0;
            }
            top--;//弹栈
        }
    }
    return top == 0;// 为0 表示 AB 能匹配上
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