#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>

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
		printf("參數不足!請詳讀 meow -? \n");
		exit(1);
	}else if (argc == 2) {
		if (strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "-help") == 0) {
			printf("使用方式: meow [-text meowLang | -meow filename]\n\n");
			printf("	沒有引數                    顯示錯誤訊息\n");
			printf("	-?                          顯示使用方法 <和 -help 相同>\n");
			printf("	-text meowLang                直接執行 meowLang\n");
			printf("	-meow filename                執行位於 filename 的meow.語檔案\n");
		}else {
			printf("參數不足!請詳讀 meow -? \n");
			exit(1);
		}
	}else if (argc >= 3) {
		if (strcmp(argv[1], "-text") == 0) {  //直接在cmd裡寫meow.語並執行 
			strcpy(str, argv[2]);
		}else if (strcmp(argv[1], "-meow") == 0) { //讀取meow.語檔案並執行
			fstream file;
			file.open(argv[2], ios::in);
			if (!file) {
				printf("無法找到此檔案或路徑錯誤!");
				exit(1);
			}
			//file.read(str, 65565);
			file.close();
			//TODO 正確讀取文件 
		}else if (strcmp(argv[1], "-?") == 0 || strcmp(argv[1], "-help") == 0) {
			printf("使用方式: meow [-text meowLang | -meow filename]\n\n");
			printf("沒有引數                    顯示錯誤訊息\n");
			printf("-?                          顯示使用方法 <和 -help 相同>\n");
			printf("-text meowLang                直接執行 meowLang\n");
			printf("-meow filename                執行位於 filename 的meow.語檔案\n");
		}else {
			printf("使用錯誤!");
		}
	}
	
	//把meow.語分割到meowCells裡 
	char *pch;
	char* meowCells[65565];
	int meowCellIndex = 0;
	pch = strtok (str," \n");
	while (pch != NULL) {
		meowCells[meowCellIndex] = pch;
		pch = strtok (NULL, " \n");
		meowCellIndex++;
	}
	
	/*把meow.語轉成brainfuck
	* >   meow! meow.
	* <   meow? meow.
	* +   meow! meow!
	* -   meow? meow!
	* .   meow. meow!
	* ,   meow. meow?
	* [   meow? meow?
	* ]   meow! meow? 
	*/
	char meowToBf[30000];
	int bfIndex = 0;
	for(int i = 0; i < meowCellIndex; i = i + 2) {
		if(strcmp(meowCells[i], "meow!") == 0 && strcmp(meowCells[i + 1], "meow.") == 0) {
			meowToBf[bfIndex] = '>';
		}else if(strcmp(meowCells[i], "meow?") == 0 && strcmp(meowCells[i + 1], "meow.") == 0) {
			meowToBf[bfIndex] = '<';
		}else if(strcmp(meowCells[i], "meow!") == 0 && strcmp(meowCells[i + 1], "meow!") == 0) {
			meowToBf[bfIndex] = '+';
		}else if(strcmp(meowCells[i], "meow?") == 0 && strcmp(meowCells[i + 1], "meow!") == 0) {
			meowToBf[bfIndex] = '-';
		}else if(strcmp(meowCells[i], "meow.") == 0 && strcmp(meowCells[i + 1], "meow!") == 0) {
			meowToBf[bfIndex] = '.';
		}else if(strcmp(meowCells[i], "meow.") == 0 && strcmp(meowCells[i + 1], "meow?") == 0) {
			meowToBf[bfIndex] = ',';
		}else if(strcmp(meowCells[i], "meow?") == 0 && strcmp(meowCells[i + 1], "meow?") == 0) {
			meowToBf[bfIndex] = '[';
		}else if(strcmp(meowCells[i], "meow!") == 0 && strcmp(meowCells[i + 1], "meow?") == 0) {
			meowToBf[bfIndex] = ']';
		}else {
			i--; //i--再i = i + 2相當於i++
			meowToBf[bfIndex] = ' ';  // 其實不是很懂這有什麼用(汗) 
		}
		bfIndex++;
	}
	
    brainfuck(meowToBf);
	return 0;
}
