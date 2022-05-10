typedef struct{
	char name[60];
	int s_time;
	int eat[3];
} User;

nt selectMenu(); // 메뉴 선택
int createUser(User *u); // 데이터 생성
void readUser(User *u, int count); // 데이터 상세조회
int updateUser(User *u); // 데이터 수정
int deleteUser(User *u); // 데이터 삭제
void order(User *u); // 음식 주문
int calc(User *u,int e_time); // 사용자 시작 시각과 종료 시각에 따른 비용 계산
int selectDataNo(User *u,int count); // index 입력받기
void listUser(User *u,int count); // 데이터 전체 조회
void saveData(User *u,int count); // 데이터 저장
int loadData(User *u); // 데이터 파일 로드
