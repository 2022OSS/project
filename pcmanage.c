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
int deleteUser(User *u){
    int e_time,bill;    
    printf("종료시간은? ");
    scanf("%d",&e_time);
    bill=calc(u,e_time);
    printf("%d원 결제부탁드립니다. 안녕히 가세요!\n",bill);
    u->s_time=-1;
    printf("==> 삭제됨!\n");
    return 0;
}
void readUser(User *u, int count){
    int num;
    listUser(u, count);
    printf("원하는 회원의 번호는? ");
    scanf("%d", &num);
    printf("\n%d %3s : %d시 %d분\n", num, u[num-1].name,u[num-1].s_time/100, u[num-1].s_time%100);
    printf("\n******* 주문 내역 *******\n");
    printf("김밥 : %d개\n", u[num-1].eat[0]);
    printf("라면 : %d개\n", u[num-1].eat[1]);
    printf("아메리카노 : %d개\n", u[num-1].eat[2]);
    //이후에 calc 함수 call
}
void listUser(User *u, int count){
    printf("No 회원 이름    시작 시간\n");
    printf("===============================\n");
    for(int i=0; i<count; i++){
        if(u[i].s_time == -1)break;
    printf("%d %s    %d : %d\n", i+1, u[i].name, u[i].s_time/100, u[i].s_time%100);
    }
} 
void order(User *u){
    int m,c;
    printf("\n");
    printf("*****메뉴판*****\n");
    printf("[1]김밥: 3000원\n");
    printf("[2]라면: 1500원\n");
    printf("[3]아메리카노: 1500원\n");
    while(1){
        int flag=1;
        printf("주문하실 메뉴번호는? ");
        scanf("%d",&m);
        printf("수량은? ");
        scanf("%d",&c);
        u->eat[m-1]+=c;
        printf("주문을 끝내시겠습니까?(1:예 2:추가 주문) ");
        scanf("%d",&flag);
        if(flag==1) break;
    }
    printf("주문 완료!\n");
}
