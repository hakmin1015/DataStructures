#include <iostream>
#include <fstream>
using namespace std;

struct StudentInfo {
	char name[10];
	char gender[5];
	char region[10];
	char major[30];
	float grade;
	int height;
	int weight;
};
ifstream fcin;
StudentInfo* slist;		// 동적 할당
int nlines = 0;			// nlines는 input.txt의 줄 개수
int STUD_NUM = 44;

int count_lines(const char fn[])
{
	fcin.open(fn);
	char str[256];
	int i = 0;
	while (fcin.getline(str, sizeof(str)))
		i++;
	fcin.close();
	return i;
}

void process_create()
{
	slist = new StudentInfo[100];			// slist는 학생의 정보를 담을 공간
}

void process_load(char arr[32])
{
	ifstream fcin;
	fcin.open(arr);

	for (int i = 0; i < STUD_NUM; i++)
	{
		fcin >> slist[i].name >> slist[i].gender;
		fcin >> slist[i].region >> slist[i].major;
		fcin >> slist[i].grade >> slist[i].height >> slist[i].weight;
	}

	for (int i = 0; i < STUD_NUM - 1; i++)
		for (int j = i + 1; j < STUD_NUM; j++)
		{
			char tmp[20];
			if (strcmp(slist[i].name, slist[j].name) > 0)
			{
				StudentInfo temp;
				temp = slist[i];
				slist[i] = slist[j];
				slist[j] = temp;
			}
		}

	fcin.close();
}

void process_print()
{
	for (int i = 0; i < STUD_NUM; i++)
	{
		cout << slist[i].name << " " << slist[i].gender << " ";
		cout << slist[i].region << " " << slist[i].major << " ";
		cout << slist[i].grade << " " << slist[i].height << " ";
		cout << slist[i].weight << endl;
	}
}

void process_insert(char arr1[32], char arr2[32], char arr3[32], char arr4[32], float arr5, int arr6, int arr7)
{
	for (int i = 0; i < STUD_NUM; i++)
	{
		if (strcmp(arr1, slist[i].name) < 0)
		{
			for (int j = STUD_NUM - 1; j >= i; j--)		// 뒤로 한 칸씩 옮기기
			{
				slist[j + 1] = slist[j];
			}
			strcpy_s(slist[i].name, arr1);
			strcpy_s(slist[i].gender, arr2);
			strcpy_s(slist[i].region, arr3);
			strcpy_s(slist[i].major, arr4);
			slist[i].grade = arr5;
			slist[i].height = arr6;
			slist[i].weight = arr7;
			
			STUD_NUM++;
			break;
		}
	}
}

void process_delete(char arr[32])
{
	for (int i = 0; i < STUD_NUM; i++)
	{
		if (strcmp(arr, slist[i].name) == 0)
		{
			for (int j = i + 1; j < STUD_NUM; j++)		// 앞으로 한 칸씩 옮기기
			{
				slist[j - 1] = slist[j];
			}

			STUD_NUM--;
			break;
		}
	}
}

void process_search(char arr[32])
{
	for (int i = 0; i < STUD_NUM; i++)
	{
		if (strcmp(arr, slist[i].name) == 0)
		{
			cout << slist[i].name << " " << slist[i].gender << " ";
			cout << slist[i].region << " " << slist[i].major << " ";
			cout << slist[i].grade << " " << slist[i].height << " ";
			cout << slist[i].weight << endl;

			break;
		}
	}
}

int main(void)
{
	// 0. 명령어 line 수 세기
	nlines = count_lines("input.txt");
	cout << nlines << endl;

	fcin.open("input.txt");

	char tok1[32], tok2[32], tok3[32], tok4[32], tok5[32];	//토큰(input파일에 관련한 변수) 선언
	float tok6;
	int tok7, tok8;

	for(int i = 0; i < nlines; i++) {			// 9번 반복, tok의 값이 바뀌어야함
		fcin >> tok1;

		if (strcmp(tok1, "CREATE") == 0) {
			process_create();
		}
		else if (strcmp(tok1, "LOAD") == 0) {
			fcin >> tok2;
			//fcin.close();
			process_load(tok2);
		}
		else if (strcmp(tok1, "PRINT") == 0) {
			process_print();
		}
		else if (strcmp(tok1, "INSERT") == 0) {
			fcin >> tok2 >> tok3 >> tok4 >> tok5 >> tok6 >> tok7 >> tok8;
			process_insert(tok2, tok3, tok4, tok5, tok6, tok7, tok8);
		}
		else if (strcmp(tok1, "DELETE") == 0) {
			fcin >> tok2;
			process_delete(tok2);
		}
		else if (strcmp(tok1, "SEARCH") == 0) {
			fcin >> tok2;
			process_search(tok2);
		}
		else {
			cout << tok1 << "is not a keyword.\n";
		}
		cout << tok1 << " done ===============\n\n";
		}

		fcin.close();
		delete slist;

	return 0;
}