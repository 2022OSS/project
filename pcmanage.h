typedef struct{
	char name[60];
	int s_time;
	int eat[3];
} User;
int createUser(User *u);
void readUser(User *u);
int updateUser(User *u);
int deleteUser(User *u);
void order(User *u,int count);
int calc(User *u,int index,int e_time);
int selectMenu();
int selectDataNo(User *u,int count);
void listUser(User *u,int count);
void saveData(User *u,int count);
int loadData(User *u);
