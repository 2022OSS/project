#include <stdio.h>
#include "pcmanage.h"
int createUser(User *u){
    printf("\n");
    printf("사용자 이름은? ");
    scanf("%s",u->name);

    printf("시작 시간은?(예:1330->13시30분) ");
    scanf("%d",&u->s_time);

    for(int i=0;i<3;i++) u->eat[i]=0;

    printf("==> 추가됨\n"); 
    return 1;
}
int updateUser(User *u){
    printf("\n");
    printf("사용자 이름은? ");
    scanf("%s",u->name);

    printf("시작 시간은?(예:1330->13시30분) ");
    scanf("%d",&u->s_time);

    printf("김밥 주문 수량은? ");
    scanf("%d",&u->eat[0]);
    printf("라면 주문 수량은? ");
    scanf("%d",&u->eat[1]);
    printf("아메리카노 주문 수량은? ");
    scanf("%d",&u->eat[2]);

    printf("==> 수정됨\n");
    return 1;
}
