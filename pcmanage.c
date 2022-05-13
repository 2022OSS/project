#include <stdio.h>
#include <string.h>
#include "pcmanage.h"

int selectMenu(){
    int menu;
    printf("\n*** �������� ***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ��������\n");
    printf("6. ���� �ֹ�\n");
    printf("7. ȸ������ȸ\n");
    printf("0. ����\n\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
    return menu;
}

int createUser(User *u){
    printf("\n");
    printf("����� �̸���? ");
    scanf("%s",u->name);

    printf("���� �ð���?(��:1330->13��30��) ");
    scanf("%d",&u->s_time);

    for(int i=0;i<3;i++) u->eat[i]=0;

    return 1;
}
int updateUser(User *u){
    printf("\n");
    printf("����� �̸���? ");
    scanf("%s",u->name);

    printf("���� �ð���?(��:1330->13��30��) ");
    scanf("%d",&u->s_time);

    printf("��� �ֹ� ������? ");
    scanf("%d",&u->eat[0]);
    printf("��� �ֹ� ������? ");
    scanf("%d",&u->eat[1]);
    printf("�Ƹ޸�ī�� �ֹ� ������? ");
    scanf("%d",&u->eat[2]);

    return 1;
}
int deleteUser(User *u){
    int e_time,bill;    
    printf("����ð���? ");
    scanf("%d",&e_time);
    bill=calc(u,e_time);
    printf("%d�� ������Ź�帳�ϴ�. �ȳ��� ������!\n",bill);
    u->s_time=-1;
    return 0;
}
void readUser(User *u, int count){
    int num;
    listUser(u, count);
    printf("���ϴ� ȸ���� ��ȣ��? ");
    scanf("%d", &num);
    printf("\n%d %3s : %d�� %d��\n", num, u[num-1].name,u[num-1].s_time/100, u[num-1].s_time%100);
    printf("\n******* �ֹ� ���� *******\n");
    printf("��� : %d��\n", u[num-1].eat[0]);
    printf("��� : %d��\n", u[num-1].eat[1]);
    printf("�Ƹ޸�ī�� : %d��\n", u[num-1].eat[2]);
    //���Ŀ� calc �Լ� call
}
void listUser(User *u, int count){
    printf("No ȸ�� �̸�    ���� �ð�\n");
    printf("===============================\n");
    for(int i=0; i<count; i++){
        if(u[i].s_time == -1) continue;
    printf("%d %s    %d : %d\n", i+1, u[i].name, u[i].s_time/100, u[i].s_time%100);
    }
} 
void order(User *u){
    int m,c;
    printf("\n");
    printf("*****�޴���*****\n");
    printf("[1]���: 3000��\n");
    printf("[2]���: 1500��\n");
    printf("[3]�Ƹ޸�ī��: 1500��\n");
    while(1){
        int flag=1;
        printf("�ֹ��Ͻ� �޴���ȣ��? ");
        scanf("%d",&m);
        printf("������? ");
        scanf("%d",&c);
        u->eat[m-1]+=c;
        printf("�ֹ��� �����ðڽ��ϱ�?(1:�� 2:�߰� �ֹ�) ");
        scanf("%d",&flag);
        if(flag==1) break;
    }
    printf("�ֹ� �Ϸ�!\n");
}
int calc(User *u,int e_time){
    int t_time;//�� �ð�(��)
    int t_bill=0;//�ð� ���
    int o_bill=0;//�ֹ� ���
    u->s_time=(u->s_time/100)*60+(u->s_time%100);
    e_time=(e_time/100)*60+(e_time%100);
    t_time=e_time-u->s_time;
    if(t_time%30==0) t_bill=(t_time/30)*500;
    else t_bill=(t_time/30 + 1)*500;
    o_bill+=u->eat[0]*3000;
    o_bill+=u->eat[1]*1500;
    o_bill+=u->eat[2]*1500;
    return t_bill + o_bill;
}

int selectDataNo(User *u,int count){
    int no;
    listUser(u,count);
    printf("��ȣ�� (���:0)?");
    scanf("%d",&no);
    getchar();
    return no;
}

int loadData(User *u){
        int i=0;
        FILE *fp;
        fp=fopen("pcuser.txt","rt");
        if(fp==NULL){
                printf("No File\n");
                return 0;
        }
        while(1){
                fscanf(fp,"%d %d %d %d",&u[i].s_time,&u[i].eat[0],&u[i].eat[1],&u[i].eat[2]);
                fgets(u[i].name,100,fp);
                u[i].name[strlen(u[i].name)-1]='\0';
                if(feof(fp)) break;
                i++;
        }
        fclose(fp);
        printf("Load Success\n");
        return i;
}
void saveData(User *u,int index){
        FILE *fp;
        fp=fopen("pcuser.txt","wt");
        for(int i=0;i<index;i++){
                if(u[i].s_time==-1) continue;
                fprintf(fp,"%d %d %d %d %s\n",u[i].s_time,u[i].eat[0],u[i].eat[1],u[i].eat[2],u[i].name);
        }
        fclose(fp);
}