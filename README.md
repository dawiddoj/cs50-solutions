# CS50x Problem Sets

This repository contains various **programs done in C** for **CS50x 2020 Course**.

## Table of Contents
- **Problem Set 0**:
    - Simple **Scratch** game named "Avoid Cars",
- **Problem Set 1**:
    - "Hello World!" in C,
    - both versions of "Mario" program:
        - less, pyramid using hashes, ex.
        ```
        $ ./mario
        Height: 8
        #
        ##
        ###
        ####
        #####
        ######
        #######
        ########
        ```
        - more, double pyramid using hashes, ex.
        ```
        $ ./mario
        Height: 8
               #  #
              ##  ##
             ###  ###
            ####  ####
           #####  #####
          ######  ######
         #######  #######
        ########  ########
        ```
    - "Cash" program:
        - program that prints the minimum number of coins with which that change can be made, ex.
        ```
        $ ./cash
        Change owed: 0.41
        4 
        ```
    - "Credit" program:
        - program prompts the user for a credit card number and then reports whether it is a valid American Express, MasterCard, or Visa card number, ex.
        ```
        $ ./credit
        Number: 4003600000000014
        VISA 
        ```
- **Problem Set 2**:
    - "Readability" program:
        - program computes the approximate grade level needed to comprehend some text using Coleman-Liau index, ex.
        ```
        $ ./readability
        Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
        Grade 3
        ```
    - "Caesar" program:
        - program encrypts messages using Caesar’s cipher, ex.
        ```
        $ ./caesar 13
        plaintext:  HELLO
        ciphertext: URYYB
        ```
- **Problem Set 3**:
    - "Plurality" program:
        - program that runs a plurality election, ex.
        ```
        $ ./plurality Alice Bob Charlie
        Number of voters: 4
        Vote: Alice
        Vote: Bob
        Vote: Charlie
        Vote: Alice
        Alice
        ```
    - "Tideman" program:
        - program that runs a [Tideman election](https://en.wikipedia.org/wiki/Ranked_pairs), ex.
        ```
        $ ./tideman Alice Bob Charlie
        Number of voters: 5
        Rank 1: Alice
        Rank 2: Charlie
        Rank 3: Bob

        Rank 1: Alice
        Rank 2: Charlie
        Rank 3: Bob

        Rank 1: Bob
        Rank 2: Charlie
        Rank 3: Alice

        Rank 1: Bob
        Rank 2: Charlie
        Rank 3: Alice

        Rank 1: Charlie
        Rank 2: Alice
        Rank 3: Bob

        Charlie
        ```
- **Problem Set 4**:
    - less version of "Filter" program:
        - program that applies filters (grayscale, sepia, reflect, blur) to BMPs, ex.
        ```
        $ ./filter -r image.bmp reflected.bmp
        ```
    - "Recovery" program:
        - program recovers JPEGs from a forensic image, ex.
        ```
        $ ./recover card.raw
        ```
