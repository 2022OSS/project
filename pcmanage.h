typedef struct{
	char name[60];
	int s_time;
	int eat[3];
} User;

int selectMenu(); // �޴� ����
int createUser(User *u); // ������ ����
void readUser(User *u, int count); // ������ ����ȸ
int updateUser(User *u); // ������ ����
int deleteUser(User *u); // ������ ����
void order(User *u); // ���� �ֹ�
int calc(User *u,int e_time); // ����� ���� �ð��� ���� �ð��� ���� ��� ���
int selectDataNo(User *u,int count); // index �Է¹ޱ�
void listUser(User *u,int count); // ������ ��ü ��ȸ
void saveData(User *u,int count); // ������ ����
int loadData(User *u); // ������ ���� �ε�
