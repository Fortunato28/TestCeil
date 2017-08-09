#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


int getCipherLength(int len)
{
	int cipherLength = len;
	int shortageUpToMultiplicity = 16 - (len % 16); // Недостаток до кратности 128

	if(len % 16 != 0) // Если требуется дополнение
	{
		cipherLength += shortageUpToMultiplicity; // Увеличиваем длину последнего блока

		if(shortageUpToMultiplicity < 3) // Если требуется ещё один блок. 3 - волшебное, от фонаря
			cipherLength += 16; // То будет ещё один блок, состоящий чисто из дополнения
	}

		return cipherLength;
}

int main()
{
    int len = 79;
    int cipherLength;
    int numberOfBlocks = ceil((double)len/16); // Количество блоков для зашифрования

    cipherLength = getCipherLength(len);

    printf("%d\n", cipherLength);
    printf("%d\n", numberOfBlocks);
    printf("%d\n", 16 - (len % 16));

    return 0;
}

