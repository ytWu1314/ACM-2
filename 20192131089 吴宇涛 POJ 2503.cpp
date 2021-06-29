#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;
int main() {
	map<string, string> h;
	char a[15], b[15], s[30];

	//gets函数 可以读取整行字符串
	while (gets(s) && s[0] != '\0') {
		sscanf(s, "%s%s", a, b); //sscanf 字符串读取格式化输入
		h[b] = a;
	}
	while (gets(s)) {

		//if(h.find(s)!=h.end())  说明在map中可以找到对应的value
		//find函数返回被查找元素的迭代器，通过迭代器访问该元素
		//如果找不到则返回 h.end()
		// count 函数返回被查找元素的个数
		if (h.count(s)) {
			cout << h[s] << endl;
		} else cout << "eh" << endl;
	}
	return 0;
}
