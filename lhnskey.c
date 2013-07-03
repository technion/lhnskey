#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "md5.h"
#define MD5_LEN 16
#define LHNSTR "RedHook LHN 4.1 SKEY 20030101 - Kelly"
#define KEYLEN 17

void printstr(unsigned char *input, const size_t len);

int main() {

	MD5_CTX ctx;
	unsigned char result[MD5_LEN];
	char mac[20];

	printf("Enter Support Key: ");

	if( fgets(mac, sizeof(mac), stdin) == NULL)
	{
		perror("Unable to read key");
		exit(1);
	}

	if (strlen(mac) != (KEYLEN+1))
	{
		printf("Invalid key input %d\n", strlen(mac));
		exit(1);
	}
	if (mac[KEYLEN] != '\n')
	{
		printf("Invalid key input\n");
		exit(1);
	}
	mac[KEYLEN] = '\0';

	/* Root password */

	printf("Generating root password....\n");
	MD5_Init(&ctx);
	MD5_Update(&ctx, LHNSTR, strlen(LHNSTR));
	MD5_Update(&ctx, mac, KEYLEN);
	MD5_Final(result, &ctx);
	printstr(result, 5);

	/* S/Key secret */

	printf("Generating S/Key secret...\n");
	MD5_Init(&ctx);
	MD5_Update(&ctx, LHNSTR, strlen(LHNSTR));
	MD5_Final(result, &ctx);
	printstr(result, MD5_LEN);

	return 0;

}

void printstr(unsigned char *input, const size_t len) {
	int i;

	for (i=0; i<len; i++)
	{
		printf("%02x", (unsigned int) input[i]);
	}
	printf("\n");
}

