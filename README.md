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

