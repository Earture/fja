#include<stdio.h>
#include<stdlib.h>

int convertJa();

int main() 
{
   
    convertJa();
    return 0;
    
}

int convertJa() 
{
    unsigned char c[] = {0, 0, 0, 0};
    unsigned char fc[] = {0, 0, 0, 0};
    char temp = '0';
    while(1) {

        temp = getchar();
        if (temp == EOF) return 0;
        if ((unsigned char)temp > 0x80) {
            c[0] = (unsigned char)temp;
            for (int i = 1; i < 3; i++) {
                c[i] = getchar();
            }
            for (int i = 0; i < 3; i++){
                printf("%c", c[i]);
            }
        } else {
            c[0] = (unsigned char)temp;
        }

        

        if (c[0] == 0x20){  //space
            printf("%s", "　");
        } else if (c[0] == '\n'){
            printf("\n");
        } else if (c[0] <= 0x60){
            fc[2] = c[0] + 0x60;
            fc[1] = 0xBC;
            fc[0] = 0xEF;
            for (int i = 0; i < 3; i++){
                printf("%c", fc[i]);
            }
        }else if(c[0] > 0x60 && c[0] < 0x80){
            fc[2] = c[0] + 0x20;
            fc[1] = 0xBD;
            fc[0] = 0xEF;
            for (int i = 0; i < 3; i++){
                printf("%c", fc[i]);
            }
        }
    }
}
