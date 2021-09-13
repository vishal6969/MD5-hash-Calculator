#include "md5.h"

char* md5(Blocks *blocks) {
    word *T = generateT();

    int numBlocks = blocks->numBlocks;
    word **M = blocks->words;

    // initialise MD buffer
    // (low-byte order)
    word A = 0x67452301;
    word B = 0xefcdab89;
    word C = 0x98badcfe;
    word D = 0x10325476;

    word AA, BB, CC, DD;

    for (int i = 0; i < numBlocks; i++) {
        word *X = M[i];

        AA = A;
        BB = B;
        CC = C;
        DD = D;

        // Round 1
        R1_OP(A, B, C, D, X[0], 7, T[1]);
        R1_OP(D, A, B, C, X[1], 12, T[2]);
        R1_OP(C, D, A, B, X[2], 17, T[3]);
        R1_OP(B, C, D, A, X[3], 22, T[4]);

        R1_OP(A, B, C, D, X[4], 7, T[5]);
        R1_OP(D, A, B, C, X[5], 12, T[6]);
        R1_OP(C, D, A, B, X[6], 17, T[7]);
        R1_OP(B, C, D, A, X[7], 22, T[8]);

        R1_OP(A, B, C, D, X[8], 7, T[9]);
        R1_OP(D, A, B, C, X[9], 12, T[10]);
        R1_OP(C, D, A, B, X[10], 17, T[11]);
        R1_OP(B, C, D, A, X[11], 22, T[12]);

        R1_OP(A, B, C, D, X[12], 7, T[13]);
        R1_OP(D, A, B, C, X[13], 12, T[14]);
        R1_OP(C, D, A, B, X[14], 17, T[15]);
        R1_OP(B, C, D, A, X[15], 22, T[16]);

        // Round 2
        R2_OP(A, B, C, D, X[1], 5, T[17]);
        R2_OP(D, A, B, C, X[6], 9, T[18]);
        R2_OP(C, D, A, B, X[11], 14, T[19]);
        R2_OP(B, C, D, A, X[0], 20, T[20]);

        R2_OP(A, B, C, D, X[5], 5, T[21]);
        R2_OP(D, A, B, C, X[10], 9, T[22]);
        R2_OP(C, D, A, B, X[15], 14, T[23]);
        R2_OP(B, C, D, A, X[4], 20, T[24]);

        R2_OP(A, B, C, D, X[9], 5, T[25]);
        R2_OP(D, A, B, C, X[14], 9, T[26]);
        R2_OP(C, D, A, B, X[3], 14, T[27]);
        R2_OP(B, C, D, A, X[8], 20, T[28]);

        R2_OP(A, B, C, D, X[13], 5, T[29]);
        R2_OP(D, A, B, C, X[2], 9, T[30]);
        R2_OP(C, D, A, B, X[7], 14, T[31]);
        R2_OP(B, C, D, A, X[12], 20, T[32]);

        // Round 3
        R3_OP(A, B, C, D, X[5], 4, T[33]);
        R3_OP(D, A, B, C, X[8], 11, T[34]);
        R3_OP(C, D, A, B, X[11], 16, T[35]);
        R3_OP(B, C, D, A, X[14], 23, T[36]);

        R3_OP(A, B, C, D, X[1], 4, T[37]);
        R3_OP(D, A, B, C, X[4], 11, T[38]);
        R3_OP(C, D, A, B, X[7], 16, T[39]);
        R3_OP(B, C, D, A, X[10], 23, T[40]);

        R3_OP(A, B, C, D, X[13], 4, T[41]);
        R3_OP(D, A, B, C, X[0], 11, T[42]);
        R3_OP(C, D, A, B, X[3], 16, T[43]);
        R3_OP(B, C, D, A, X[6], 23, T[44]);

        R3_OP(A, B, C, D, X[9], 4, T[45]);
        R3_OP(D, A, B, C, X[12], 11, T[46]);
        R3_OP(C, D, A, B, X[15], 16, T[47]);
        R3_OP(B, C, D, A, X[2], 23, T[48]);

        // Round 4
        R4_OP(A, B, C, D, X[0], 6, T[49]);
        R4_OP(D, A, B, C, X[7], 10, T[50]);
        R4_OP(C, D, A, B, X[14], 15, T[51]);
        R4_OP(B, C, D, A, X[5], 21, T[52]);

        R4_OP(A, B, C, D, X[12], 6, T[53]);
        R4_OP(D, A, B, C, X[3], 10, T[54]);
        R4_OP(C, D, A, B, X[10], 15, T[55]);
        R4_OP(B, C, D, A, X[1], 21, T[56]);

        R4_OP(A, B, C, D, X[8], 6, T[57]);
        R4_OP(D, A, B, C, X[15], 10, T[58]);
        R4_OP(C, D, A, B, X[6], 15, T[59]);
        R4_OP(B, C, D, A, X[13], 21, T[60]);

        R4_OP(A, B, C, D, X[4], 6, T[61]);
        R4_OP(D, A, B, C, X[11], 10, T[62]);
        R4_OP(C, D, A, B, X[2], 15, T[63]);
        R4_OP(B, C, D, A, X[9], 21, T[64]);

        // add AA, BB, CC, and DD to MD buffer
        A += AA;
        B += BB;
        C += CC;
        D += DD;
    }

    // print ABCD in low-byte order
    word state[4] = {A, B, C, D};
    word w;
    char *result = (char *)malloc(33 * sizeof(char));
    for (int i = 0; i < 4; i++) {
        w = state[i];
        
        // format string into a char array: https://stackoverflow.com/a/39495281
        sprintf(result + (i * 8),
                "%02x%02x%02x%02x",
                w & 0xff,
                (w >> 8) & 0xff,
                (w >> 16) & 0xff,
                (w >> 24) & 0xff
            );
    }
    // append null terminator
    result[32] = '\0';

    // free all dynamically allocated memory
    for (int i = 0; i < numBlocks; i++) {
        free(M[i]);
    }

    // free block memory since it's no longer needed
    free(M);
    free(blocks);

    return result;
}

// generate the 64 element array T, as per the RFC
word * generateT() {
    // use static so T can be used when out of scope
    static word T[65];

    for (int i = 1; i <= 64; i++) {
        T[i] = (word)(T_MULTIPLIER * fabs(sin(i)));
    }

    return T;
}

struct Blocks * makeBlocks(ubyte *bytes, int length) {
    int p;
    int shiftPlaces;
    word *currBlock;
    ull paddingBytes;
    ull totalBytes;
    ull totalBits;

    // copy input bytes to leave input array unchanged,
    // leaving some extra space for any amount of padding needed at the end
    ubyte buffer[length + 72];
    for (int i = 0; i < length; i++) {
        buffer[i] = bytes[i];
    }

    // compute exact number of padding bytes needed
    paddingBytes = 65 - ((length + 8) % 64 + 1);
    // total number of bytes needed for all blocks (a multiple of 64)
    // (file bytes + padding bytes + input length bytes)
    totalBytes = length + paddingBytes + 8;
    totalBits = length * 8;
    
    // start padding with a 1
    p = length;
    buffer[p++] = FIRST_PADDING_BYTE;

    // rest of the padding is 0s
    for (; p < totalBytes - 8; p++) {
        buffer[p] = 0;
    }

    // append 8 bytes describing input length (least significant byte first)
    shiftPlaces = 0;
    for (; p < totalBytes; p++) {
        buffer[p] = (totalBits >> shiftPlaces) & 0xffff;
        shiftPlaces += 8;
    }

    // compute the number of blocks needed to store all of the buffer data
    int numBlocks = totalBytes / 64;

    // allocate the memory needed for the 2D array M
    // https://stackoverflow.com/a/14088911
    word **M = (word **)malloc(numBlocks * sizeof(word *));

    for (int i = 0; i < numBlocks; i++) {
        M[i] = (int *)malloc(16 * sizeof(word));
    }

    // initialise blocks struct containing the 2D words array and number of blocks
    Blocks *blocks = (Blocks *)malloc(sizeof(Blocks));
    blocks->words = M;
    blocks->numBlocks = numBlocks;

    // now convert the array of bytes into a series of blocks,
    // each containing 16x 32 bit words (512 bits total)
    p = 0;
    for (int i = 0; i < numBlocks; i++) {
        currBlock = M[i];

        for (int j = 0; j < 16; j++) {
            // combine 4 bytes into a word (little-endian, as per the RFC)
            // and write the word to the block at the next index
            currBlock[j] = buffer[p++] | (buffer[p++] << 8) | (buffer[p++] << 16) | (buffer[p++] << 24);
        }
    }

    // return pointer to blocks
    return blocks;
}
