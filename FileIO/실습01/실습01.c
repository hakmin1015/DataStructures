#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Info {
	char name[10];
	char gender;
	char region[10];
	char major[15];
	float grade;
	int height;
	int weight;
};

int main(void){
	struct Info* list;		// �л��� �� = �迭�� ũ��

	FILE* f = NULL;
	f = fopen("list.txt", "r");

	int cnt_line = 1;
	char c;

	if (f == NULL){			// ���� ó��
		printf("Can't Open a File.");
		return 1;
	}

	while (fscanf(f, "%c", &c) != EOF) {			//������ �� ���� ���ϱ� (�л��� ��) 
		if (c == '\n') {
			cnt_line++;
		}
	}
	fseek(f, 0L, SEEK_SET);			// ó�� ��ġ�� ����

	list = (struct Info*)malloc(cnt_line * sizeof(struct Info));		// list�迭 ũ�⿡ ���� �����Ҵ� 

	if (list == NULL){
		printf("�޸� �Ҵ� ����\n");
		exit(1);
	}

	for (int i = 0; i < cnt_line; i++) {
		fscanf(f, "%s %c %s %s %f %d %d", &list[i].name, &list[i].gender, &list[i].region, &list[i].major, &list[i].grade, &list[i].height, &list[i].weight);
	}

	fclose(f);

	for (int i = 0; i < cnt_line; i++) {
		printf("%s %c %s %s %0.2f %d %d\n", list[i].name, list[i].gender, list[i].region, list[i].major, list[i].grade, list[i].height, list[i].weight);
	}

	free(list);

	return 0;
}