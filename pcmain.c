#include <stdio.h>
#include "pcmanage.h"

int main(void){
    int count = 0, menu;
    int index=count;
    User u[20];
    // count = loadData(u);
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if ((menu==1) || (menu == 3) || (menu == 4)|| (menu == 6)|| (menu == 7))
            if(count == 0) {
                continue;
            }
        if (menu == 1){
            listUser(u, count);
        }
        else if (menu == 2){
            if(createUser(&u[index++]) == 1){
                count++;
            printf("√ﬂ∞°µ !\n");
            }
            continue;
        }
        else if (menu == 3){
            int no = selectDataNo(u, count);
            if(no == 0){
                printf("=>√Îº“µ !\n");
                continue;
            }
            if(updateUser(&u[no-1]) == 1)
              printf("==> ºˆ¡§µ \n"); 
        }
        else if (menu == 4){
            int no = selectDataNo(u, count);
            if(no == 0){
                printf("=>√Îº“µ !\n");
                continue;
            }
            if(deleteUser(&u[no-1]) == 0){
            count--;
        }
        }
        // else if (menu == 5){
        //     saveFile(u, count);
        // }
        else if(menu == 6){
        int no = selectDataNo(u, count);
            if(no == 0){
                printf("=>√Îº“µ !\n");
                continue;
            }
            order(&u[no-1]);
        }
        // else if(menu == 7)
        //     searchWay(u, count);
        // else if(menu == 8)
        //     searchCost(u, count);
        else if(menu == 7)
            readUser(u, count);
    }
    printf("¡æ∑·µ !\n");
    return 0;
}