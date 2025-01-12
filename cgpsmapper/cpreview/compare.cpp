/*

 Created by: cgpsmapper
  
 This is open source software. Source code is under the GNU General Public License version 3.0 (GPLv3) license.

 Permission to modify the code and to distribute modified code is granted,
 provided the above notices are retained, and a notice that the code was
 modified is included with the above copyright notice.

*/

#include <string>
#include <memory.h>
#include <map>
#include "compare.h"

using namespace std;
namespace g_compare {

	unsigned char	sort_table[223];
	unsigned char	sort_table_a[223];

	int		code_page;
	int		lang_id;
/*
	const unsigned char LBL1252[] =
	{' ',0x1f,'�','�','�','�','�','�','�','_','�','`','^','�','�','�','�','�','-','�','�',',',';',':','!','�','?','�','.','�','�',0x27,'�','�','�','�','�','"','�','�','�','�','�','(',')','[',']','{','�','�','�','�','*','/','\\','&','#','%','�','�','�','�','�','�','$','�','�','�','�','+','�','�','�','�','<','=','>','�','|','�','~','0','1','�','�','�','2','�','3','�','�','4','5','6','7','8','9','a','A','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','b','B','c','C','�','�','d','D','�','�','e','E','�','�','�','�','�','�','�','�','f','F','�','g','G','h','H','i','I','�','�','�','�','�','�','�','�','j','J','k','K','l','L','m','M','n','N','�','�','o','O','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','p','P','q','Q','r','R','s','S','�','�','�','t','T','�','u','U','�','�','�','�','�','�','�','�','v','V','w','W','x','X','y','Y','�','�','�','�','z','Z','�','�','�'};
	const unsigned char LBL1252_a[] =
	{'9', '9','9','9','9','9','9','9','9','9','9','9','9','9','9','9','9','0','0', '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','b','b','c','c','c','c','d','d','d','d','e','e','e','e','e','e','e','e','e','e','f','f','f','g','g','h','h','i','i','i','i','i','i','i','i','i','i','j','j','k','k','l','l','m','m','n','n','n','n','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','1','1','p','p','q','q','r','r','s','s','s','s','s','t','t','t','u','u','u','u','u','u','u','u','u','u','v','v','w','w','x','x','y','y','y','y','y','y','z','z','2','2','3'};
*/
/*
	const unsigned char LBL1252[] =
	{' ',0x1f,'�','�','�','�','�','�','�','_','�','`','^','�','�','�','�','�','-','�','�',',',';',':','!','�','?','�','.','�','�',0x27,'�','�','�','�','�','"','�','�','�','�','�','(',')','[',']','{','�','�','�','�','*','/','\\','&','#','%','�','�','�','�','�','�','$','�','�','�','�','+','�','�','�','�','<','=','>','�','|','�','~','0','1','�','�','�','2','�','3','�','�','4','5','6','7','8','9','a','A','�','�','�','�','�','�','�','�','�','�','�','�','�','b','B','c','C','�','�','d','D','�','�','e','E','�','�','�','�','�','�','�','�','f','F','�','g','G','h','H','i','I','�','�','�','�','�','�','�','�','j','J','k','K','l','L','m','M','n','N','�','�','o','O','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','p','P','q','Q','r','R','s','S','�','�','�','t','T','�','u','U','�','�','�','�','�','�','�','�','v','V','w','W','x','X','y','Y','�','�','�','�','z','Z','�','�','�','�','�'};
	const unsigned char LBL1252_a[] =
	{'9', '9','9','9','9','9','9','9','9','9','9','9','9','9','9','9','9','0','0', '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','b','b','c','c','c','c','d','d','d','d','e','e','e','e','e','e','e','e','e','e','f','f','f','g','g','h','h','i','i','i','i','i','i','i','i','i','i','j','j','k','k','l','l','m','m','n','n','n','n','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','1','1','p','p','q','q','r','r','s','s','s','s','s','t','t','t','u','u','u','u','u','u','u','u','u','u','v','v','w','w','x','x','y','y','y','y','y','y','z','z','2','2','3','3','4'};
	*/

	const unsigned char LBL1252[] =
	{' ',0x1f,'�','�','�','�','�','�','�','_','�','`','^','�','�','�','�','�','-','�','�',',',';',':','!','�','?','�','.','�','�',0x27,'�','�','�','�','�','"','�','�','�','�','�','(',')','[',']','{','�','�','�','�','*','/','\\','&','#','%','�','�','�','�','�','�','$','�','�','�','�','+','�','�','�','�','<','=','>','�','|','�','~','0','1','�','�','�','2','�','3','�','�','4','5','6','7','8','9','a','A','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','b','B','c','C','�','�','d','D','�','�','e','E','�','�','�','�','�','�','�','�','f','F','�','g','G','h','H','i','I','�','�','�','�','�','�','�','�','j','J','k','K','l','L','m','M','n','N','�','�','o','O','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','p','P','q','Q','r','R','s','S','�','�','�','t','T','�','u','U','�','�','�','�','�','�','�','�','v','V','w','W','x','X','y','Y','�','�','�','�','z','Z','�','�','�'};
	const unsigned char LBL1252_a[] =
	{'9', '9','9','9','9','9','9','9','9','9','9','9','9','9','9','9','9','0','0', '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','a','a','a','a','a','a','a','a','a','a','a','a','a','a','a','A','A','b','b','c','c','c','c','d','d','d','d','e','e','e','e','e','e','e','e','e','e','f','f','f','g','g','h','h','i','i','i','i','i','i','i','i','i','i','j','j','k','k','l','l','m','m','n','n','n','n','o','o','o','o','o','o','o','o','o','o','o','o','o','o','o','1','1','p','p','q','q','r','r','s','s','s','s','s','t','t','t','u','u','u','u','u','u','u','u','u','u','v','v','w','w','x','x','y','y','y','y','y','y','z','z','2','2','4'};

/*
	const unsigned char LBL1251[] =
	{0x1f,'',' ','�','�','�','�','�','�','�','_','`','^','�','�','-','�','�',',',';',':','!','�','?','.','�','�',0x27,'�','�','�','�','�','"','�','�','�','�','�','(',')','[',']','{','�','�','�','�','*','/','\\','&','#','%','�','�','�','�','�','�','$','�','�','�','+','�','�','<','=','>','�','|','�','~','0','1','�','�','�','2','3','�','4','5','6','7','8','9',
	'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�'};
	
	const unsigned char LBL1251_a[] =
	{'0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' ,'0','0','0','0','0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',
	'a','a','b','b','c','c','d','d','e','e','f','f','g','g','h','h','i','i','j','j','k','k','l','l','m','m','n','n','o','o','p','p','q','q','r','r','s','s','t','t','u','u','v','v','w','w','x','x','y','y','z','z','a','a','b','b','c','c','d','d','e','e','f','f','g','g','h','h','i','i','j','j','k','k','l','l','m','m','n','n','o','o','p','q','q','r','r','s','s','t','t','u','u','v','v','w','w','x','x','y','y','x','x','A','A','B','B','C','C','D','D','E','E','F','F','G','G','H','I','I','J','J','K','K','L','L','M','M','N','N','O','P','P','Q'};
*/
	const unsigned char LBL1251[] =
	{0x1f,'',' ','�','_','`','^','�','-','�',',',';',':','!','?','.','�','�',0x27,'�','�','�','�','�','"','�','�','�','�','�','(',')','[',']','{','�','�','�','�','*','/', '\\','&','#','%','�','�','�','�','�','$','�','+','�','�','<','=','>','�','|','�','~','0','1','2','3','4','5','6','7','8','9','a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','�','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�'};
	const unsigned char LBL1251_a[] =
	{'0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0', '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0',  '0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','a','a','b','b','c','c','d','d','e','e','f','f','g','g','h','h','i','i','j','j','k','k','l','l','m','m','n','n','N','o','o','p','p','q','q','r','r','s','s','t','t','u','u','v','v','w','w','x','x','y','y','z','z','a','a','b','b','c','c','d','d','d','d','d','d','e','e','f','f','h','h','h','h','j','j','k','k','l','l','m','m','n','n','n','n','o','o','p','p','q','q','r','r','r','r','s','s','t','t','u','u','v','v','w','w','x','x','y','y','z','z','!','!','@','@','A','A','B','B','C','C','D','D','E','E','F','F','G','G','H','H','I','I','J','J','K','K','L','L','M','M','N','N','P','P','Q','Q','R','W'};

	const unsigned char LBL1256[] =
	{'',' ','�','�','�','�','�','�','�','�','�','�','�','�','`','�','^','�','�','�','_','�','-','�','�',',','�',';','�',':','!','?','�','.','�','�',0x27,'�','�','�','�','�','"','�','�','�','�','�','(',')','[',']','{','�','�','�','�','*','/','\\','&','#','%','�','�','�','�','�','�','+','�','�','�','<','=','>','�','|','�','~','�','�','$','�','�','�','0','1','�','�','�','2','�','3','�','�','4','5','6','7','8','9','a','A','�','�','b','B','c','C','�','d','D','e','E','�','�','�','�','f','F','�','g','G','h','H','i','I','�','�','j','J','k','K','l','L','m','M','n','N','o','O','�','�','�','p','P','q','Q','r','R','s','S','t','T','�','u','U','�','�','�','v','V','w','W','x','X','y','Y','z','Z','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�'};
	const unsigned char LBL1256_a[] =
	{'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','a','a','a','a','b','b','c','c','c','d','d','e','e','e','e','e','e','f','f','f','g','g','h','h','i','i','i','i','j','j','k','k','l','l','m','m','n','n','o','o','o','2','2','p','p','q','q','r','r','s','s','t','t','1','u','u','u','u','u','v','v','w','w','x','x','y','y','z','z','Z','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�'};

	const unsigned char LBL1257[] =
	{'',' ','�','�','�','�','�','�','�','�','�','�','�','�','`','�','^','�','�','�','�','�','_','�','-','�','�',',',';',':','!','?','.','�','�',0x27,'�','�','�','�','�','"','�','�','�','�','�','(',')','[',']','{','�','�','�','�','*','/','\\','&','#','%','�','�','�','�','�','�','+','�','�','�','<','=','>','�','|','�','~','�','�','$','�','�','0','1','�','�','�','2','�','3','�','�','4','5','6','7','8','9','a','A','�','�','�','�','�','�','�','�','�','b','B','c','C','�','�','�','�','d','D','e','E','�','�','�','�','�','�','�','�','�','f','F','g','G','�','�','h','H','i','I','�','�','�','�','j','J','k','K','�','�','l','L','�','�','�','�','m','M','n','N','�','�','�','�','o','O','�','�','�','�','�','�','�','�','�','�','p','P','q','Q','r','R','�','�','s','S','�','�','�','�','�','t','T','�','u','U','�','�','�','�','�','�','v','V','w','W','x','X','y','Y','z','Z','�','�','�','�','�','�','�'};
	const unsigned char LBL1257_a[] =
	{'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','a','a','a','a','a','a','a','a','a','A','A','b','b','c','c','c','c','c','c','d','d','e','e','e','e','e','e','e','e','e','e','e','f','f','g','g','g','G','h','h','i','i','i','i','i','i','j','j','k','k','k','K','l','l','L','L','L','L','m','m','n','n','n','n','n','n','o','o','o','o','o','o','o','o','o','o','o','o','p','p','q','q','r','r','r','r','s','s','s','s','s','s','S','t','t','T','u','u','u','u','u','u','u','u','v','v','w','w','x','x','y','y','z','z','z','z','z','z','z','1','2'};

	const unsigned char LBL1250[] =
	{'',' ','�','�','�','�','�','`','�','^','�','�','�','�','�','�','_','�','-','�','�',',',';',':','!','?','.','�','�',0x27,'�','�','�','�','�','"','�','�','�','�','�','(',')','[',']','{','�','�','�','�','*','/','\\','&','#','%','�','�','�','�','�','�','+','�','�','�','<','=','>','�','|','�','~','�','$','�','0','1','2','3','4','5','6','7','8','9','a','A','�','�','�','�','�','�','�','�','�','�','b','B','c','C','�','�','�','�','�','�','d','D','�','�','�','�','e','E','�','�','�','�','�','�','�','�','f','F','g','G','h','H','i','I','�','�','�','�','j','J','k','K','l','L','�','�','�','�','�','�','m','M','n','N','�','�','�','�','o','O','�','�','�','�','�','�','�','�','p','P','q','Q','r','R','�','�','�','�','s','S','�','�','�','�','�','�','�','t','T','�','�','�','�','�','u','U','�','�','�','�','�','�','�','�','v','V','w','W','x','X','y','Y','�','�','z','Z','�','�','�','�','�','�','�'};
	const unsigned char LBL1250_a[] =
	{'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0' ,'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','a','a','a','a','a','a','a','a','a','a','a','a','b','b','c','c','c','c','c','c','c','c','d','d','d','d','d','d','e','e','e','e','e','e','e','e','e','e','f','f','g','g','h','h','i','i','i','i','i','i','j','j','k','k','l','l','l','l','l','l','l','l','m','m','n','n','n','n','n','n','o','o','o','o','o','o','o','o','o','o','p','p','q','q','r','r','r','r','r','r','s','s','s','s','s','s','s','s','S','t','t','t','t','t','t','T','u','u','u','u','u','u','u','u','u','u','v','v','w','w','x','x','y','y','y','y','z','z','z','z','z','z','z','z','Z'};

	int get_codepage() {
		return code_page;
	}

	int get_lang_id() {
		return lang_id;
	}

	void init(int codepage) {
		code_page = codepage;
		if( codepage == 1250 ) {
			memcpy(sort_table,LBL1250,sizeof(LBL1250));
			memcpy(sort_table_a,LBL1250_a,sizeof(LBL1250_a));
			
			lang_id = 0x0c;
		}
		else if( codepage == 1251 ){
			memcpy(sort_table,LBL1251,sizeof(LBL1251));
			memcpy(sort_table_a,LBL1251_a,sizeof(LBL1251_a));
			lang_id = 8;
		}
		else if( codepage == 1252 ){
			memcpy(sort_table,LBL1252,sizeof(LBL1252));
			memcpy(sort_table_a,LBL1252_a,sizeof(LBL1252_a));
			lang_id = 7;
		}	else if( codepage == 1257 ) {
			memcpy(sort_table,LBL1257,sizeof(LBL1257));
			memcpy(sort_table_a,LBL1257_a,sizeof(LBL1257_a));
			lang_id = 0x11;
		} else if( codepage == 1256 ) {
			memcpy(sort_table,LBL1256,sizeof(LBL1256));
			memcpy(sort_table_a,LBL1256_a,sizeof(LBL1256_a));
			lang_id = 0x10;
		} else {
			memcpy(sort_table,LBL1252,sizeof(LBL1252));
			memcpy(sort_table_a,LBL1252_a,sizeof(LBL1252_a));
			code_page = 1252;
		}
	}

	char c_compare(unsigned char a,unsigned char b) {
		short a_pos,b_pos;
		//unsigned char x;
 /*
		a_i = sort_table.find(a);
		b_i = sort_table.find(b);

		if( a_i == sort_table.end() ) 
			a_pos = 0;
		else
			a_pos = (*a_i).second;

		if( b_i == sort_table.end() ) 
			b_pos = 0;
		else
			b_pos = (*b_i).second;
*/
		
		for( a_pos = 0; a_pos < 222; a_pos++ ) {
			//x = sort_table[a_pos];
			if( sort_table[a_pos] == a )
				break;
		}
		for( b_pos = 0; b_pos < 222; b_pos++ ) {
			//x = sort_table[b_pos];
			if( sort_table[b_pos] == b )
				break;
		}

		if( sort_table_a[a_pos] == sort_table_a[b_pos] && sort_table_a[a_pos] != '0' ) {
			//takie same - narodowe
			if( a_pos < b_pos )	return -2;
			if( a_pos > b_pos )	return 2;
			return 0;
		} else {
			//rozne litery - uwzgledniajac narodowe
			if( a_pos < b_pos )	return -1;
			if( a_pos > b_pos )	return 1;
		}
		
		return 0;
	}

	std::string upper_case(std::string text)
	{
		unsigned char z;
		std::string::iterator t_pos = text.begin();
		while( t_pos != text.end() )
		{
			z = *t_pos;
			if( z >='a' && z <= 'z' )
				*t_pos = 'A' + (*t_pos-'a');
			if( z >=0xe0 && z <= 0xff )
				*t_pos = *t_pos-0x20;
			t_pos++;
		}
		return text;
	}

	int compare(void* empty,int x_len,const void* x_c,int y_len,const void* y_c) {
		int		t_pozX = 0;
		int		t_pozY = 0;
		size_t	tmp;
		std::string	stringX,stringY;
		std::string	x,y;
		bool	overwrite;
		char	t_result,n_result;
		bool	national_char;
		n_result = 0;
		t_result = 0;

		x = std::string((const char*)x_c,x_len);		
		y = std::string((const char*)y_c,y_len);

		// pomijanie kodow specjalnych....
		// zmiana kolejnosci dla kodow 1e i 1f
/*
		if( x.find(0x1d) != x.npos) {
			t_pozX = static_cast<int>(x.find(0x1d));
			//stringX = x.substr(t_pozX+7);
			x = x.substr(0,t_pozX);
		}
		if( y.find(0x1d) != x.npos) {
			t_pozY = static_cast<int>(y.find(0x1d));
			//stringX = x.substr(t_pozX+7);
			y = y.substr(0,t_pozY);
		}
*/
		if( code_page != 1252 ) {
			for(size_t i = 0; i<x.size(); ++i) {
				if( ((unsigned char)x[i]) < 32 )
					x.erase(i,1);
			}
			for(size_t i = 0; i<y.size(); ++i) {
				if( ((unsigned char)y[i]) < 32 )
					y.erase(i,1);
			}
		}

		overwrite = true;
		stringX = upper_case(x);
		if( stringX.find(0x1e) != stringX.npos) {
			t_pozX = static_cast<int>(stringX.find(0x1e));
			stringX = x.substr(t_pozX+1);
			//stringX += x.substr(0,t_pozX);
			overwrite = false;
		}
		if( stringX.find(0x1f) != stringX.npos) {
			t_pozX = static_cast<int>(stringX.find(0x1f));
			//stringX = x.substr(t_pozX+1);
			stringX += x.substr(0,t_pozX);
			overwrite = false;
		}
		if( overwrite )
			stringX = x;

		overwrite = true;
		stringY = upper_case(y);
		if( stringY.find(0x1e) != stringY.npos) {
			t_pozY = static_cast<int>(stringY.find(0x1e));
			stringY = y.substr(t_pozY+1);
			//stringY += y.substr(0,t_pozY);
			overwrite = false;
		}
		if( stringY.find(0x1f) != stringY.npos) {
			t_pozY = static_cast<int>(stringY.find(0x1f));
			//stringY = y.substr(t_pozY+7);
			stringY += y.substr(0,t_pozY);
			overwrite = false;
		}
		if( overwrite )
			stringY = y;

		/*
		overwrite = true;
		stringY = upper_case(y);
		if( stringY.find("~[0X1E]") != stringY.npos) {
			t_pozY = static_cast<int>(stringY.find("~[0X1E]"));
			stringY = y.substr(t_pozY+7);
			stringY += y.substr(0,t_pozY);
			overwrite = false;
		}
		if( stringY.find("~[0X1F]") != stringY.npos) {
			t_pozY = static_cast<int>(stringY.find("~[0X1F]"));
			stringY = y.substr(t_pozY+7);
			stringY += y.substr(0,t_pozY);
			overwrite = false;
		}
		if( overwrite )
			stringY = y;
		*/
		t_pozY = 0;t_pozX=0;

		while( stringX.find("~") != stringX.npos ) {
			tmp = stringX.find("~");
			if( tmp != stringX.find("[")-1 ) {
				stringX = stringX.substr(0,tmp) + stringX.substr(tmp+1);
			}
			if( tmp == 0 ) 
				stringX = stringX.substr(stringX.find("]")+1);
			else
				stringX = stringX.substr(0,tmp) + stringX.substr(stringX.find("]")+1);
		}

		while( stringY.find("~") != stringY.npos ) {
			tmp = stringY.find("~");
			if( tmp != stringY.find("[")-1 ) {
				stringY = stringY.substr(0,tmp) + stringY.substr(tmp+1);
			}
			if( tmp == 0 )
				stringY = stringY.substr(stringY.find("]")+1);
			else
				stringY = stringY.substr(0,tmp) + stringY.substr(stringY.find("]")+1);
		}

		national_char = false;
		while(stringX.length() > t_pozX && stringY.length() > t_pozY) {

			//
			// ~[0x1b2b] - od tego ~[0x1e] - od tego symbolu sortowanie �
			// ~[0x1b2c] - do tego ~[0x1f]- do tego symbolu
			//
			t_result = c_compare(stringX[t_pozX],stringY[t_pozY]);			
			if( t_result == -1 ) return -1;
			if( t_result == 1 ) return 1;

			if( t_result == -2 ) {
				national_char = true;
				n_result = -1;
			}
			if( t_result == 2 ) {
				national_char = true;
				n_result = 1;
			}

			t_pozX++;
			t_pozY++;
		}
		if( national_char && stringX.length() == stringY.length() ) {
			return n_result;
		}

		if(stringX.length() > stringY.length())
			return 1;
		if(stringX.length() < stringY.length())
			return -1;	
		return 0;
	}
}
