#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

using namespace std;
using std::ios;

static int bfCmd[30000];
static unsigned int index = 0;

void brainfuck(char cmd[]) {
	int i, loop, indexChar;
	
	for(i = 0; cmd[i] != '\0'; i++) {
		indexChar = cmd[i];
		switch(indexChar) {
			case '>':
				++index;
				break;
			case '<':
				--index;
				break;
			case '+':
				++bfCmd[index];
				break;
			case '-':
				--bfCmd[index];
				break;
			case '.':
				putchar(bfCmd[index]);
				break;
			case ',':
				bfCmd[index] = getchar();
				break;
			case '[':
				if(!bfCmd[index]) {
					loop = 1;
					while(loop) {
						i++;
						if(cmd[i] == '[') loop++;
						if(cmd[i] == ']') loop--;
					}
				}
				break;
			case ']':
				if(bfCmd[index]) {
					loop = 1;
					while(loop) {
						i--;
						if(cmd[i] == ']') loop++;
						if(cmd[i] == '[') loop--;
					}
				}
				break;
		}
	}
	
}

int main(int argc, char* argv[]) {
	char str[65565];
	
	if(argc <= 1) {
		printf("�ѼƤ����I�и�Ū meow -? \n");
		exit(1);
	}else if (argc == 2) {
		if (strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "-help") == 0) {
			printf("�ϥΤ覡: meow [-text meowLang | -meow filename]\n\n");
			printf("	�S���޼�                    ��ܿ��~�T��\n");
			printf("	-?                          ��ܨϥΤ�k <�M -help �ۦP>\n");
			printf("	-text meowLang                �������� meowLang\n");
			printf("	-meow filename                ������ filename ���p�p�y�ɮ�\n");
		}else {
			printf("�ѼƤ����I�и�Ū meow -? \n");
			exit(1);
		}
	}else if (argc >= 3) {
		if (strcmp(argv[1], "-text") == 0) {  //�����bcmd�̼g�p�p�y�ð��� 
			strcpy(str, argv[2]);
		}else if (strcmp(argv[1], "-meow") == 0) { //Ū���p�p�y�ɮרð��� 
			fstream file;
			file.open(argv[2], ios::in);
			if (!file) {
				printf("�L�k��즹�ɮשθ��|���~�I");
				exit(1);
			}
			file.read(str, 65565);
			file.close();
			//TODO ���TŪ����� 
		}else if (strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "-help") == 0) {
			printf("�ϥΤ覡: meow [-text meowLang | -meow filename]\n\n");
			printf("�S���޼�                    ��ܿ��~�T��\n");
			printf("-?                          ��ܨϥΤ�k <�M -help �ۦP>\n");
			printf("-text meowLang                �������� meowLang\n");
			printf("-meow filename                ������ filename ���p�p�y�ɮ�\n");
		}else {
			printf("�ϥο��~�I");
		}
	}
	
	//���p�p�y���Ψ�meowCells�� 
	char *pch;
	char* meowCells[65565];
	int meowCellIndex = 0;
	pch = strtok (str," \n");
	while (pch != NULL) {
		meowCells[meowCellIndex] = pch;
		pch = strtok (NULL, " \n");
		meowCellIndex++;
	}
	
	/*���p�p�y�নbrainfuck
	* >   �p�I �p�p
	* <   �p�H �p�p
	* +   �p�I �p�I
	* -   �p�H �p�I
	* .   �p�p �p�I
	* ,   �p�p �p�H
	* [   �p�H �p�H
	* ]   �p�I �p�H 
	*/
	char meowToBf[30000];
	int bfIndex = 0;
	for(int i = 0; i < meowCellIndex; i = i + 2) {
		if(strcmp(meowCells[i], "�p�I") == 0 && strcmp(meowCells[i + 1], "�p�p") == 0) {
			meowToBf[bfIndex] = '>';
		}else if(strcmp(meowCells[i], "�p�H") == 0 && strcmp(meowCells[i + 1], "�p�p") == 0) {
			meowToBf[bfIndex] = '<';
		}else if(strcmp(meowCells[i], "�p�I") == 0 && strcmp(meowCells[i + 1], "�p�I") == 0) {
			meowToBf[bfIndex] = '+';
		}else if(strcmp(meowCells[i], "�p�H") == 0 && strcmp(meowCells[i + 1], "�p�I") == 0) {
			meowToBf[bfIndex] = '-';
		}else if(strcmp(meowCells[i], "�p�p") == 0 && strcmp(meowCells[i + 1], "�p�I") == 0) {
			meowToBf[bfIndex] = '.';
		}else if(strcmp(meowCells[i], "�p�p") == 0 && strcmp(meowCells[i + 1], "�p�H") == 0) {
			meowToBf[bfIndex] = ',';
		}else if(strcmp(meowCells[i], "�p�H") == 0 && strcmp(meowCells[i + 1], "�p�H") == 0) {
			meowToBf[bfIndex] = '[';
		}else if(strcmp(meowCells[i], "�p�I") == 0 && strcmp(meowCells[i + 1], "�p�H") == 0) {
			meowToBf[bfIndex] = ']';
		}else {
			i--; //i--�Ai = i + 2�۷��i++
			meowToBf[bfIndex] = ' ';  // ��ꤣ�O�����o�������(��) 
		}
		bfIndex++;
	}
	
    brainfuck(meowToBf);
	return 0;
}
