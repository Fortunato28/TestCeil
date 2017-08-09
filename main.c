#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


int getCipherLength(int len)
{
	int cipherLength = len;
	int shortageUpToMultiplicity = 16 - (len % 16); // ���������� �� ��������� 128

	if(len % 16 != 0) // ���� ��������� ����������
	{
		cipherLength += shortageUpToMultiplicity; // ����������� ����� ���������� �����

		if(shortageUpToMultiplicity < 3) // ���� ��������� ��� ���� ����. 3 - ���������, �� ������
			cipherLength += 16; // �� ����� ��� ���� ����, ��������� ����� �� ����������
	}

		return cipherLength;
}

int main()
{
    int len = 79;
    int cipherLength;
    int numberOfBlocks = ceil((double)len/16); // ���������� ������ ��� ������������

    cipherLength = getCipherLength(len);

    printf("%d\n", cipherLength);
    printf("%d\n", numberOfBlocks);
    printf("%d\n", 16 - (len % 16));

    return 0;
}

