# Tokenizing-Project
Hash Table Implementation

Large Language Models (LLMs) such as ChatGPT take text as their input and return text as their output. However, their intermediate processing is performed using numeric computations. The process by which text is turned into numbers and back again is referred to as “tokenization”. There are two major problems to solve while tokenizing:
1. How do we turn text into numbers? – this is the simple part. We read in a file containing all of the text we expect to see, and we break it up by words (using the space character). The first word we encounter is assigned number 1, the second word is assigned number 2 and so on. We usually store the words in an array, called the token dictionary, where their token is the array index. Hash tables may be used to store the dictionary as well.
2. How do we store the (number,text) pairs so that they can be retrieved quickly? – This part is harder. Given a new string of text, we need to be able to quickly find the numerical tokens without searching the whole array.

The second problem is solved via hashing as shown below:
a. Read the word character-by-character, and add the ASCII values of its characters. For instance the word “Any” has ASCII values 65 + 110 + 121 = 296
b. Use that integer as the hash key in the hashing function shown below
c. In the hash table, store the word and its index in the token dictionary
d. Resolve hashing collisions using separate chaining

Primary Hash Function 
h(k) = kk mod m where k is the key and m is the size of the hash table
