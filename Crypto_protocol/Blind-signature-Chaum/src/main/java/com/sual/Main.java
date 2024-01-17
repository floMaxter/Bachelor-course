package com.sual;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;
import java.util.Scanner;


public class Main {
    private static final Random random = new Random();

    public static void main(String[] args) {
        List<Key> bunchOfKeys = RSA();

        System.out.println("**********************************");
        System.out.println("Public key" + bunchOfKeys.get(0));
        System.out.println("Private key" + bunchOfKeys.get(1));
        System.out.println("**********************************");

        long message = setMessage();
        long r = setSalt(bunchOfKeys.get(0).getModule());

        long encryptedMessage = hideMessage(message, r, bunchOfKeys.get(0));
        System.out.println("Hided message m' = " + encryptedMessage);

//        long signedEncryptedMessage = blindDigitalSignature(encryptedMessage, bunchOfKeys.get(1));
        long replacedMessage = encryptedMessage + 1;
        System.out.println("Replaced message: " + replacedMessage);

        long signedEncryptedMessage = blindDigitalSignature(replacedMessage, bunchOfKeys.get(1));
        System.out.println("Signature s' = " + signedEncryptedMessage);

        long decipheredMessage = decipherMessage(signedEncryptedMessage, r, bunchOfKeys.get(0));
        System.out.println("Disclosed message s = " + decipheredMessage);

        if (signatureVerification(message, decipheredMessage, bunchOfKeys.get(0))) {
            System.out.println("The keys matched, the signature is valid");
        } else {
            System.out.println("The keys didn't matched, the signature is invalid");
        }
    }

    public static List<Key> RSA() {
        Scanner sc = new Scanner(System.in);
        long p;
        long q;
        while (true) {
            System.out.print("p = ");
            p = sc.nextLong();
            System.out.print("q = ");
            q = sc.nextLong();
            if (isPrimeNumber(p) && isPrimeNumber(q)) break;
            System.out.println("Вы ввели не простые числа, попробуйте еще раз");
        }

        long n = p * q;
        long fi = (p - 1) * (q - 1);
        System.out.println("n = " + n + ", fi(n) = " + fi);

        TripleForGcd tripleForGcd;
        long e;

        while (true) {
            System.out.print("e = ");
            e = sc.nextLong();

            tripleForGcd = fi > e ? extendedGcd(fi, e) : extendedGcd(e, fi);

            if (tripleForGcd.getGcd() == 1)
                break;

            System.out.println("е должно удовлетворять условиям\n 1) 1 < e < fi \n 2) (fi, e) = 1\n"
                    + "попробуйте еще раз");
        }

        long y = tripleForGcd.getY();
        while (y < 0) {
            y += fi;
        }

        System.out.println("gcd = " + tripleForGcd.getGcd() +
                            ", x = " + tripleForGcd.getX() +
                            ", y = " + tripleForGcd.getY());

        Key publicKey = new Key(e, n);
        Key privateKey = new Key(y, n);
        List<Key> bunchOfKey = new ArrayList<>();
        bunchOfKey.add(publicKey);
        bunchOfKey.add(privateKey);

        return bunchOfKey;
    }

    public static long setMessage() {
        System.out.print("Enter the message: ");
        return new Scanner(System.in).nextLong();
    }

    public static long setSalt(final long module) {
        Scanner sc = new Scanner(System.in);

        int r;
        do {
            r = random.nextInt(100);
        } while (!(extendedGcd(r, module).getGcd() == 1));
        System.out.println("Random r: " + r);

        /*long r;
        while (true) {
            System.out.print("Random r: ");
            r = sc.nextLong();

            if (extendedGcd(r, module).getGcd() == 1)
                break;

            System.out.println("Соль и модуль (" + module + ") должны быть взаимнопростыми, попробуйте еще раз.");
        }*/

        return r;
    }

    public static long hideMessage(long message, long r, Key publicKey) {
        return (message * powMod(r, publicKey)) % publicKey.getModule();
    }

    public static long blindDigitalSignature(long encryptedMessage, Key privateKey) {
        return powMod(encryptedMessage, privateKey);
    }

    public static long decipherMessage(long blindSignature, long r, Key publicKey) {
        long mod = publicKey.getModule();
        TripleForGcd tripleForGcd = r > mod ? extendedGcd(r, mod) : extendedGcd(mod, r);
        long y = tripleForGcd.getY();
        while (y < 0) {
            y += mod;
        }
        return (blindSignature * y) % publicKey.getModule();
    }

    public static boolean signatureVerification(long baseMessage, long signedMessage, Key publicKey) {
        long expectedSignedMessage = (long) Math.pow(signedMessage, publicKey.getFirstNumber()) % publicKey.getModule();

        System.out.println("Base message m = " + baseMessage);
        System.out.println("The resulting message s^e = " + expectedSignedMessage);

        return baseMessage == expectedSignedMessage;
    }

    public static boolean isPrimeNumber(long number) {
        if (number <= 1) return false;
        for (int i = 2; i < Math.sqrt(number); i++) {
            if (number % i == 0)
                return false;
        }
        return true;
    }

    public static TripleForGcd extendedGcd(long a, long b) {
        if (a == 0) return new TripleForGcd(b, 0, 1);
        if (b == 0) return new TripleForGcd(a, 1, 0);

        long x1 = 1, x2 = 0;
        long y1 = 0, y2 = 1;
        while (b != 0) {
            long quotient = a / b;
            long r = a % b;
            a = b;
            b = r;
            long tempS = x1 - x2 * quotient;
            x1 = x2;
            x2 = tempS;
            long tempR = y1 - y2 * quotient;
            y1 = y2;
            y2 = tempR;
        }
        return new TripleForGcd(a, x1, y1);
    }

    public static long powMod(long number, Key key) {
        long res = 1;
        long exp = key.getFirstNumber();
        for (int i = 0; i < exp; i++) {
            res *= number;
            res %= key.getModule();
        }
        return res;
    }
}
