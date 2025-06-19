#include <stdio.h>
#include <stdlib.h>
#include "sign_verify.h"

uint8_t* read_binary_file(const char* filename, size_t* size) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Move to end to determine file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    if (file_size < 0) {
        perror("Error getting file size");
        fclose(file);
        return NULL;
    }
    rewind(file);  // Go back to beginning

    // Allocate buffer
    uint8_t* buffer = (uint8_t*)malloc(file_size);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    // Read file into buffer
    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read != file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    fclose(file);
    *size = file_size;
    return buffer;
}

const uint8_t ecdsa256_public_key[65] = { 0x04, 0xd5, 0x22, 0x8f, 0xe8, 0x14, 0x0d, 0x10, 0xc1, 0xb6, 0x1a, 0x9f, 0xc8, 0xa8, 0xc1, 0xc5, 0xda, 0x1a, 0xa1, 0x35, 0xb5, 0xf2, 0x9c, 0x46, 0xaf, 0xf5, 0xe7, 0x4b, 0x63, 0xaa, 0x9b, 0xa0, 0x7b, 0xc6, 0x3c, 0x1b, 0xba, 0x72, 0x00, 0xec, 0x97, 0x82, 0x32, 0xb1, 0x78, 0xfc, 0x92, 0xc9, 0x30, 0xfd, 0xd0, 0x35, 0xa7, 0x4c, 0x69, 0x4b, 0xd7, 0x1e, 0x11, 0xa1, 0x89, 0xed, 0xc4, 0x88, 0x91 };
int main(void)
{
    char fileSignaturePath[] = "D:\\eJad_GP\\SDV-SOTA\\ECU\\ECDSA_signing\\src\\signature";
    char fileDataPath[] = "D:\\eJad_GP\\SDV-SOTA\\ECU\\ECDSA_signing\\src\\data";
    size_t sig_len;
    uint8_t *signature = read_binary_file(fileSignaturePath,&sig_len);
    size_t data_len;
    uint8_t *data= read_binary_file(fileDataPath,&data_len);
    signVerifier_init(ecdsa256_public_key, 65U);
    signVerifier_updateHash(data,data_len);
    if(signVerifier_finalizeCheckSignature(signature,sig_len) == 1U)
        printf("pass");
    else
        printf("fail");
}