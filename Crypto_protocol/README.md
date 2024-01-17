# CryptographyAlgorithm
Implementation of some cryptographic encryption algorithms.
1. Berlekamp-Massey. 
* This work presents an implementation of a shift register with linear feedback, based on which the Geffe generator is constructed. The linear complexity is computed using the Berlekamp-Massey algorithm.
2. Blind Chaum signature based on ElGamal.
* The program consists of seven independent parts (all numbers are entered in a dialogue mode).
  1. Secret key selection and obtaining the public key (ElGamal).
  2. Message selection (number) and salt selection (number).
  3. Salting the message using the salt and the public key (ElGamal).
  4. Computing the signature for the salted message using the secret key (ElGamal).
  5. Removing the salt from the signature using the salt and the public key (ElGamal).
  6. Verifying the correctness of the signature using the public key (ElGamal).
3. Kerberos.

4. Mental poker.
* Implementation of a protocol that allows playing poker remotely, ensuring a fair game. The protocol satisfies the following conditions:
    1. The player has no knowledge of any partial information about their opponent's cards.
    2. All possible outcomes are equally likely for both players.
    3. At the end of the game, the player can verify that the game was fair and no deception occurred.
4. RC4.
* RC4 is based on a pseudorandom number generation (PRNG) algorithm using a stream cipher. The main idea is to generate a key stream of bytes, which is then combined with the plaintext data using the bitwise exclusive OR (XOR) operation.
