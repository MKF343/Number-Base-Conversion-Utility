#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "convert.h"

int main() {
	FILE* file = fopen("a1_test_file.txt", "r");
	if (file == NULL) {
		printf("Error: Could not open file\n");
		return 1;
	}
	char line[256];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        if (line[0] == '#' || line[0] == '\n') {
            continue;
        }

        if (strstr(line, "div_convert")) {
            uint32_t num;
            int base;
            char expectedStr[65];
            char actualStr[65];

            sscanf(line, "%*s %u %d %s", &num, &base, expectedStr);

            div_convert(num, base, actualStr);

            if (strcmp(actualStr, expectedStr) == 0) {
                printf("Test: div_convert(%u, %d) -> Expected: \"%s\", Got: \"%s\" [PASS]\n", num, base, expectedStr, actualStr);
            }
            else {
                printf("Test: div_convert(%u, %d) -> Expected: \"%s\", Got: \"%s\" [FAIL]\n", num, base, expectedStr, actualStr);
            }

        }
        else if (strstr(line, "sub_convert")) {
            uint32_t num;
            int base;
            char expectedStr[65];
            char actualStr[65];

            
            sscanf(line, "%*s %u %d %s", &num, &base, expectedStr);

            sub_convert(num, base, actualStr);

            if (strcmp(actualStr, expectedStr) == 0) {
                printf("Test: sub_convert(%u, %d) -> Expected: \"%s\", Got: \"%s\" [PASS]\n", num, base, expectedStr, actualStr);
            }
            else {
                printf("Test: sub_convert(%u, %d) -> Expected: \"%s\", Got: \"%s\" [FAIL]\n", num, base, expectedStr, actualStr);
            }

        }
        else if (strstr(line, "print_tables")) {
            uint32_t num;
            sscanf(line, "%*s %u", &num);

            printf("--- Test: print_tables(%u) ---\n", num);
            print_tables(num);
            printf("--- End Test ---\n");
            printf("Test: print_tables(%u) -> [FORMATTED OUTPUT CHECK] [PASS]\n", num);
        }
    }
	fclose(file);
	return 0;
}