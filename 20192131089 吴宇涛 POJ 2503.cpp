#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	map<string, string> h;
	char a[15], b[15], s[30];

	//gets���� ���Զ�ȡ�����ַ���
	while (gets(s) && s[0] != '\0') {
		sscanf(s, "%s%s", a, b); //sscanf �ַ�����ȡ��ʽ������
		h[b] = a;
	}
	while (gets(s)) {

		//if(h.find(s)!=h.end())  ˵����map�п����ҵ���Ӧ��value
		//find�������ر�����Ԫ�صĵ�������ͨ�����������ʸ�Ԫ��
		//����Ҳ����򷵻� h.end()
		// count �������ر�����Ԫ�صĸ���
		if (h.count(s)) {
			cout << h[s] << endl;
		} else cout << "eh" << endl;
	}
	return 0;
}
