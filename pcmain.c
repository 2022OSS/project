#include <stdio.h>
#include "pcmanage.h"

int main(void){
    int count = 0, menu;
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
            if(createUser(&u[count++]) == 1){
            printf("추가됨!\n");
            }
            continue;
        }
        else if (menu == 3){
            int no = selectDataNo(u, count);
            if(no == 0){
                printf("=>취소됨!\n");
                continue;
            }
            if(updateUser(&u[no-1]) == 1)
              printf("==> 수정됨\n"); 
        }
        else if (menu == 4){
            int no = selectDataNo(u, count);
            if(no == 0){
                printf("=>취소됨!\n");
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
                printf("=>취소됨!\n");
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
    printf("종료됨!\n");
    return 0;
}