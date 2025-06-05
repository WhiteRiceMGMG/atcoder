#include <stdio.h>
struct Tag {
    int age;
    char name[16 + 1];
    char pref[16 + 1];
    int x;
};


void memdump(void *data, size_t data_size);

int main(void) {
    struct Tag person = {
        24,
        "Taro Yamada",
        "Hyogo",
        0xF0
    };
    memdump(&person, sizeof(person));
    return 0;
}



void memdump(void *data, size_t data_size) {
    size_t i = 0;
    size_t pad_j = 0;
    size_t byte_k = 0;
    size_t available_bytes = 0;
    char *data_head = (char *)data;
    char byte = 0x00;

    printf("+----- ADDR -----+------ MEMORY DUMP -----+------- DECODED --------+");
    for (i = 0; i < data_size; i += 8) {
        printf("\n|\e[0;33m%016lX\e[0m|", (unsigned long)(data_head + i));
        available_bytes = (i + 8) <= data_size ? 8 : (data_size % 8);
        for (byte_k = 0; byte_k < available_bytes; byte_k++) {
            byte = (*(data_head + i + byte_k)) & 0xFF;
            if (byte == 0x00) {
                printf("\e[0;36m");
            } else {
                printf("\e[0;32m");
            }
            printf("%02X\e[0m ", byte & 0xFF);
        }
        for (pad_j = 0; pad_j < (8 - available_bytes); pad_j++) {
            printf("   ");
        }

        printf("|");

        for (byte_k = 0; byte_k < available_bytes; byte_k++) {
            byte = (*(data_head + i + byte_k)) & 0xFF;
            if ((0x21 <= byte) && (byte <= 0x7E)) {
                printf("\e[0;32m %c \e[0m", byte & 0xFF);
            } else {
                if (byte == 0x00) {
                    printf("\e[0;36m . \e[0m");
                } else {
                    printf("\e[0;32m _ \e[0m");
                }
            }
        }

        for (pad_j = 0; pad_j < (8 - available_bytes); pad_j++) {
            printf("   ");
        }

        printf("|");
    }

    printf("\n+----------------+------------------------+------------------------+\n");
}
