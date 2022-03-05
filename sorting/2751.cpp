#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

namespace fio {
	const size_t BSIZE = 524288;
	char buffer[BSIZE];
	char *ptr = buffer + BSIZE;
	char outbuf[BSIZE + 20];
	char *outptr = outbuf;

	inline char readChar() {
		if (ptr == buffer + BSIZE) {
			read(0, buffer, BSIZE);
			ptr = buffer;
		}
		return *(ptr++);
	}

	int readInt() {
		int ret = 0;
		unsigned char c = readChar();
		while (c < '-') {
			c = readChar();
		}
		bool neg = false;
		if (c == '-') {
			neg = true;
			c = readChar();
		}
		while (c >= '0') {
			ret = ret * 10 + (c - '0');
			c = readChar();
		}
		return neg ? -ret : ret;
	}

	void printInt(int n)
	{
		if (n < 0) n = -n, *outptr++ = '-';
		char *end = outptr;
		do
		{
			*end++ = n % 10 + '0';
			n /= 10;
		} while (n);
		reverse(outptr, end);
		*end++ = '\n';
		if (end < outbuf + BSIZE) outptr = end;
		else
		{
			write(1, outbuf, end - outbuf);
			outptr = outbuf;
		}
	}

	void flush()
	{
		write(1, outbuf, outptr - outbuf);
	}
};

int a[1000001];

int main(void)
{
	int N = fio::readInt();
	int i;
	
	for (i = 0; i < N; i++) 
        a[i] = fio::readInt();

    sort(a, a + N);

	for (i = 0; i < N; i++)
		fio::printInt(a[i]);
	fio::flush();
}