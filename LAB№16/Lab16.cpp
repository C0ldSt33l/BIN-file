#include<iostream>

/*19.�������� ��������� ������ � N �������� ������: �������, ���� �������� (�����, ����� � ���).
������� �� ����� ������� ��� ��������, � ���� ������� ���� �������� (����������� ���� ������� � ����������).*/

struct student
{
	char name[100];
	int D, M, Y;
};

void fillStructByKeyboard(student s[], int& size, const int max)
{
	printf("������� ����� ��������� (�� 1 �� %d: ", max);

	do
	{
		scanf_s("%d", &size);

		if (size < 1 || size > max)
			printf("������� ������������ �����. ��������� ����\n");
	} while (size < 1 || size > max);

	printf("������� ��� �������� � ���� ��� ���������:\n");
	for (int i = 0; i < size; i++)
		scanf_s("%d. %s\n%d%d%d", i + 1, s[i].name, 100, &s[i].D, &s[i].M, &s[i].Y);
}

void fillStructByTXTFile(student s[], int& size, const char* filename)
{
	FILE* a;
	
	if (fopen_s(&a, filename, "r"))
	{
		printf("couldn't open file %s", filename);
		exit(1);
	}

	fscanf_s(a, "%d", &size);

	for (int i = 0; i < size; i++)
	{
		fscanf_s(a, "%s%d%d%d", s[i].name, 100, &s[i].D, &s[i].M, &s[i].Y);
	}

	fclose(a);
}

void saveStructInTXTFile(student s[], int size, const char* filename)
{
	FILE* a;

	if (fopen_s(&a, filename, "wt"))
	{
		printf("couldn't open file %s", filename);
		exit(1);
	}

	fprintf(a, "%d\n", size);

	for (int i = 0; i < size; i++)
	{
		fprintf_s(a, "%s %2d/%2d/%d\n", s[i].name, s[i].D, s[i].M, s[i].Y);
	}

	fclose(a);
}

void fillStructByBINFile(student s[], int& size, const char* filename)
{
	FILE* f;

	if (fopen_s(&f, filename, "rb"))
	{
		printf("couldn't open file %s", filename);
		exit(1);
	}

	fread(&size, sizeof(int), 1, f);
	fread(s, sizeof(student), size, f);

	fclose(f);
}

void saveStructInBINFile(student s[], int size, const char* filename)
{
	FILE* f;

	if (fopen_s(&f, filename, "wb"))
	{
		printf("couldn't open file %s", filename);
		exit(1);
	}

	fwrite(&size, sizeof(int), 1, f);
	fwrite(s, sizeof(student), size, f);

	fclose(f);
}

void printStruct(student s[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d. %s\n%d//%d//%d\n", i + 1, s[i].name, s[i].D, s[i].M, s[i].Y);
}

void printName(student s)
{
	printf("%s", s.name);
}

void bithday(student s[], int n, int D, int M)
{
	for (int i = 0; i < n; i++)
	{
		if (s[i].D == D && s[i].M == M) printName(s[i]);
	}

}

int main()
{
	system("chcp 1251");
	system("cls");

	const int SIZE = 5;
	student arr[SIZE];
	int way, D, M, Y, size;

	printf("�������� ������ ���������� �������:\n");
	printf("1 - � ����������\n");
	printf("2 - �� ���������� �����\n");
	printf("3 - �� ��������� �����\n");
	
	do
	{
		scanf_s("%d", &way);
	} while (way < 1 || way > 3);

	switch (way)
	{
	case 1:
		fillStructByKeyboard(arr, size, SIZE);
		printStruct(arr, size);

		break;
	case 2:
		fillStructByTXTFile(arr, size, "1.txt");
		printStruct(arr, size);
		
		break;
	case 3:
		fillStructByBINFile(arr, size, "2.bin");
		printStruct(arr, size);

		break;
	}

	printf("�������� ������ ���������� �������:\n");
	printf("1 - � ��������� ����\n");
	printf("2 - � �������� ����\n");
	
	do
	{
		scanf_s("%d", &way);
	} while (way < 1 || way > 2);

	switch (way)
	{
	case 1:
		saveStructInTXTFile(arr, size, "4.txt");

		break;
	case 2:
		saveStructInBINFile(arr, size, "3�.bin");

		break;
	}

	printf("������� ����:\n");
	scanf_s("%d%d%d", &D, &M, &Y);
	bithday(arr, size, D, M);

	return 0;
}