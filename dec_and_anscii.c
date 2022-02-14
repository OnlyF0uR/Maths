#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void atoh(char* input, char* buffer) {
	for (int i = 0; i < strlen(input); i++) {
		sprintf_s(&buffer[i * 2], 3, "%02x", input[i]);
	}
}

unsigned char htoi(unsigned char hxd) {
	if (hxd <= '9') {
		return hxd - '0';
	}

	hxd = tolower(hxd);
	if (hxd == 'a') {
		return 10;
	}
	else if (hxd == 'b') {
		return 11;
	}
	else if (hxd == 'c') {
		return 12;
	}
	else if (hxd == 'd') {
		return 13;
	}
	else if (hxd == 'e') {
		return 14;
	}
	else if (hxd == 'f') {
		return 15;
	}

	return 0;
}

void htoa(char* input, char* buffer) {
	char* src = input;
	char* dst = buffer;

	while (*src != '\0') {
		const unsigned char high = htoi(*src++);
		const unsigned char low = htoi(*src++);
		*dst++ = (high << 4) | low;
	}
	
	*dst = '\0';
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Usage: %s <Output(A/D)> <Text>", argv[0]);
		return 2;
	}

	// From dec to ascii
	if (strcmp(argv[1], "a") == 0 || strcmp(argv[1], "A") == 0) {
		size_t ln = strlen(argv[2]) - 1;
		if (argv[2][ln] == '\n') {
			argv[2][ln] = '\0';
		}


		char* buffer = malloc((strlen(argv[2]) * 2 + 1) * sizeof(char));
		htoa(argv[2], buffer);

		printf("%s\n", buffer);
	}
	// From ascii to dec
	else if (strcmp(argv[1], "d") == 0 || strcmp(argv[1], "D") == 0) {
		size_t ln = strlen(argv[2]) - 1;
		if (argv[2][ln] == '\n') {
			argv[2][ln] = '\0';
		}

		char* buffer = malloc((strlen(argv[2]) * 2 + 1) * sizeof(char));
		atoh(argv[2], buffer);

		printf("%s\n", buffer);
	}
	else {
		printf("Invalid input.");
		return 2;
	}

	return 0;
}