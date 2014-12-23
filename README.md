Text_Compression
================

Implemented Huffman algorithm for text compression in python. Achieved text compressiblity of 60% .


Huffman Data Compression
========================

We will look at several functions that bring together an example of Huffman data compression for text files. These functions do the following.

1. Examine text to be compressed to determine the relative frequencies of individual letters.

2. Assign a binary code to each letter using shorter codes for the more frequent letters. This is the heart of the Huffman algorithm.

3. Encode normal text into its compressed form. We'll see this just as a string of '0's and '1's. This will turn out to be quite easy.

4. Recover the original text from the compressed. This will demonstrate a nice use of recursive traversal of a binary tree, but will still remain fairly simple.

Further Exploration
===================

In order to compress a text file and then later restore it, the tree must be included along with the bit stream. Modify the code to produce compressed files along with their decoding tree.

Create binary ones and zeros so that real compression actually takes place. You will need to investigate the bit operators in Python.

Can the program as it stands compress binary data as well? Test it.
