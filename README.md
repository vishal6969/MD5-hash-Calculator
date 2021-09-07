# What is Hashing?
In simple words, hashing means converting a simple text,  string or message into some encoded message which is:
1. Unique for every unique text or string.
2. of fixed length, irrespective of input string length.
3. not reversible which means the original message cannot be traced back from a hash value.
4. same for a particular text or string, irrespective of how many times it is calculated.

#### Names of some hashing algorithms
* MD4
* MD5
* SHA-256
* SHA-512

# Why? and How? of Hashing
To understand why we need hashing is quite simple. In today's online world, our data is open to the internet and so it invites a lot of trouble from people who try to harm you by stealing your data, mainly your personal details and passwords. To avoid such disasters, one efficient is to avoid storing the actual data and instead store some encryption or hash value of the original data.

#### Some applications of hashing
* Password Matching
* Data Storage
* Checking message integrity
* Error correcting
* Ciphers

### How is hashing done?
The fundamental concept of hashing is to take a text or string as an input and produce some encoded messasge which can be a result of some processing and mathematical operations and calculations. The length of output is always same for any length of input. Different hashing algorithms may utilise different processing and operations on the input to produce some output. Some operations that might be performed by hashing algorithms on the input string are:
* Dividing input into data packets or groups.
* Add padding to the input.
* Pre-processing.
* Scramble and shuffle input bits.
* Combine data packets to produce output.

# Purpose of this project
The project implements very famous MD5 algorithm. MD5 was designed by *Ronald Rivest.* The soul purpose of this project is to implement the MD5 algorithm in C language.

The program takes a string as an input, applies all the processing and calculation on the input and produces an output which is also called the message digest. So the final output of the program is a message digest.

The program utilises only basic C functions like input/output and totally avoids any use of any inbuilt functions other than that.

# MD5 Algorithm Design

## Terminology and Notation

   In this document a "word" is a 32-bit quantity and a "byte" is an
   eight-bit quantity. A sequence of bits can be interpreted in a
   natural manner as a sequence of bytes, where each consecutive group
   of eight bits is interpreted as a byte with the high-order (most
   significant) bit of each byte listed first. Similarly, a sequence of
   bytes can be interpreted as a sequence of 32-bit words, where each
   consecutive group of four bytes is interpreted as a word with the
   low-order (least significant) byte given first.

   Let x_i denote "x sub i". If the subscript is an expression, we
   surround it in braces, as in x_{i+1}. Similarly, we use ^ for
   superscripts (exponentiation), so that x^i denotes x to the i-th
   power.

   Let the symbol "+" denote addition of words (i.e., modulo-2^32
   addition). Let X <<< s denote the 32-bit value obtained by circularly
   shifting (rotating) X left by s bit positions. Let not(X) denote the
   bit-wise complement of X, and let X v Y denote the bit-wise OR of X
   and Y. Let X xor Y denote the bit-wise XOR of X and Y, and let XY
   denote the bit-wise AND of X and Y.


## MD5 Algorithm Description

   We begin by supposing that we have a b-bit message as input, and that
   we wish to find its message digest. Here b is an arbitrary
   nonnegative integer; b may be zero, it need not be a multiple of
   eight, and it may be arbitrarily large. We imagine the bits of the
   message written down as follows:

          m_0 m_1 ... m_{b-1}

   The following five steps are performed to compute the message digest
   of the message.

### Append Padding Bits

   The message is "padded" (extended) so that its length (in bits) is
   congruent to 448, modulo 512. That is, the message is extended so
   that it is just 64 bits shy of being a multiple of 512 bits long.
   Padding is always performed, even if the length of the message is
   already congruent to 448, modulo 512.

   Padding is performed as follows: a single "1" bit is appended to the
   message, and then "0" bits are appended so that the length in bits of
   the padded message becomes congruent to 448, modulo 512. In all, at
   least one bit and at most 512 bits are appended.

### Append Length

   A 64-bit representation of b (the length of the message before the
   padding bits were added) is appended to the result of the previous
   step. In the unlikely event that b is greater than 2^64, then only
   the low-order 64 bits of b are used. (These bits are appended as two
   32-bit words and appended low-order word first in accordance with the
   previous conventions.)

   At this point the resulting message (after padding with bits and with
   b) has a length that is an exact multiple of 512 bits. Equivalently,
   this message has a length that is an exact multiple of 16 (32-bit)
   words. Let M[0 ... N-1] denote the words of the resulting message,
   where N is a multiple of 16.

### Initialize MD Buffer

   A four-word buffer (A,B,C,D) is used to compute the message digest.
   Here each of A, B, C, D is a 32-bit register. These registers are
   initialized to the following values in hexadecimal, low-order bytes
   first):

          word A: 01 23 45 67
          word B: 89 ab cd ef
          word C: fe dc ba 98
          word D: 76 54 32 10

### Process Message in 16-Word Blocks

   We first define four auxiliary functions that each take as input
   three 32-bit words and produce as output one 32-bit word.

          F(X,Y,Z) = XY v not(X) Z
          G(X,Y,Z) = XZ v Y not(Z)
          H(X,Y,Z) = X xor Y xor Z
          I(X,Y,Z) = Y xor (X v not(Z))

   In each bit position F acts as a conditional: if X then Y else Z.
   The function F could have been defined using + instead of v since XY
   and not(X)Z will never have 1's in the same bit position.) It is
   interesting to note that if the bits of X, Y, and Z are independent
   and unbiased, the each bit of F(X,Y,Z) will be independent and
   unbiased.

   The functions G, H, and I are similar to the function F, in that they
   act in "bitwise parallel" to produce their output from the bits of X,
   Y, and Z, in such a manner that if the corresponding bits of X, Y,
   and Z are independent and unbiased, then each bit of G(X,Y,Z),
   H(X,Y,Z), and I(X,Y,Z) will be independent and unbiased. Note that
   the function H is the bit-wise "xor" or "parity" function of its
   inputs.

   This step uses a 64-element table T[1 ... 64] constructed from the
   sine function. Let T[i] denote the i-th element of the table, which
   is equal to the integer part of 4294967296 times abs(sin(i)), where i
   is in radians. The elements of the table are given in the appendix.

   Do the following:

   /* Process each 16-word block. */
   For i = 0 to N/16-1 do

     /* Copy block i into X. */
     For j = 0 to 15 do
       Set X[j] to M[i*16+j].
     end /* of loop on j */

     /* Save A as AA, B as BB, C as CC, and D as DD. */
     AA = A
     BB = B
     CC = C
     DD = D

     /* Round 1. */
     /* Let [abcd k s i] denote the operation
          a = b + ((a + F(b,c,d) + X[k] + T[i]) <<< s). */
     /* Do the following 16 operations. */
     [ABCD  0  7  1]  [DABC  1 12  2]  [CDAB  2 17  3]  [BCDA  3 22  4]
     [ABCD  4  7  5]  [DABC  5 12  6]  [CDAB  6 17  7]  [BCDA  7 22  8]
     [ABCD  8  7  9]  [DABC  9 12 10]  [CDAB 10 17 11]  [BCDA 11 22 12]
     [ABCD 12  7 13]  [DABC 13 12 14]  [CDAB 14 17 15]  [BCDA 15 22 16]

     /* Round 2. */
     /* Let [abcd k s i] denote the operation
          a = b + ((a + G(b,c,d) + X[k] + T[i]) <<< s). */
     /* Do the following 16 operations. */
     [ABCD  1  5 17]  [DABC  6  9 18]  [CDAB 11 14 19]  [BCDA  0 20 20]
     [ABCD  5  5 21]  [DABC 10  9 22]  [CDAB 15 14 23]  [BCDA  4 20 24]
     [ABCD  9  5 25]  [DABC 14  9 26]  [CDAB  3 14 27]  [BCDA  8 20 28]
     [ABCD 13  5 29]  [DABC  2  9 30]  [CDAB  7 14 31]  [BCDA 12 20 32]

     /* Round 3. */
     /* Let [abcd k s t] denote the operation
          a = b + ((a + H(b,c,d) + X[k] + T[i]) <<< s). */
     /* Do the following 16 operations. */
     [ABCD  5  4 33]  [DABC  8 11 34]  [CDAB 11 16 35]  [BCDA 14 23 36]
     [ABCD  1  4 37]  [DABC  4 11 38]  [CDAB  7 16 39]  [BCDA 10 23 40]
     [ABCD 13  4 41]  [DABC  0 11 42]  [CDAB  3 16 43]  [BCDA  6 23 44]
     [ABCD  9  4 45]  [DABC 12 11 46]  [CDAB 15 16 47]  [BCDA  2 23 48]

     /* Round 4. */
     /* Let [abcd k s t] denote the operation
          a = b + ((a + I(b,c,d) + X[k] + T[i]) <<< s). */
     /* Do the following 16 operations. */
     [ABCD  0  6 49]  [DABC  7 10 50]  [CDAB 14 15 51]  [BCDA  5 21 52]
     [ABCD 12  6 53]  [DABC  3 10 54]  [CDAB 10 15 55]  [BCDA  1 21 56]
     [ABCD  8  6 57]  [DABC 15 10 58]  [CDAB  6 15 59]  [BCDA 13 21 60]
     [ABCD  4  6 61]  [DABC 11 10 62]  [CDAB  2 15 63]  [BCDA  9 21 64]

     /* Then perform the following additions. (That is increment each
        of the four registers by the value it had before this block
        was started.) */
     A = A + AA
     B = B + BB
     C = C + CC
     D = D + DD

   end /* of loop on i */


### Output

   The message digest produced as output is A, B, C, D. That is, we
   begin with the low-order byte of A, and end with the high-order byte
   of D.

*Reference~* https://datatracker.ietf.org/doc/html/rfc1321
