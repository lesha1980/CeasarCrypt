#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

int main() {

	setlocale(LC_ALL, "");
	cout << "������ ���������� � ����" << endl;

	char* file1 = new char[256];
	char* file2 = new char[256];
	char* line = new char[128];
	
	int offset = 0;

	cout << "������� ������������ ����� 1, �� �������� ����� ����������� ����������" << endl;
	cin >> file1;
	cout << "������� ������������ ����� 2, � ������� ����� ������������ ������������� ������ ����� 1" << endl;
	cin >> file2;
	cout << "������� ������ ������ ��� ����� ������" << endl;
	cin >> offset;

	FILE* f1;
	f1 = fopen(file1, "r");

	if (f1 == NULL) {
		cout << "���������� ������� ���� " << f1 << endl;
		return 0;
	}

	FILE* f2;
	f2 = fopen(file2, "a");

	if (f2 == NULL) {
		cout << "���������� ������� ���� " << f2 << endl;
		return 0;
	}

	int len = 0;
	offset = offset % 26;
	while (!feof(f1)) {
       
		fgets(line, 127, f1);
		len = strlen(line);
		if (line[len - 1] == '\n') {
			line[len - 1] = '\0';
		}

		char* crypt = new char[len];
		line = _strlwr(line);
		for (size_t i = 0; i < len - 1; i++) {
			if (line[i] != '-' && line[i] != ' ' && line[i] != ',' && line[i] != ':' && line[i] != '.' && line[i] != '!' && line[i] != '?' && line[i] != ';') {
				char c = line[i];
				int a = (int)c;
				a = a - 97;
				a = a + offset;

				if (a > 26) {
					a = a % 26;
				}

				a = a + 97;
				char ra = (char)a;
				crypt[i] = ra;

			}
			else {
				crypt[i] = line[i];
			}

		}
		crypt[len - 1] = '\0';
		fputs(crypt, f2);
		
	}

	fclose(f1);
	fclose(f2);

	_getch();




	return 0;
}