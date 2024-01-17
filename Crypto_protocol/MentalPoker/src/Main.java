import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> numbers = initList();

        int p;
        int c1;
        int d1;
        int c2;
        int d2;

        //Step 1
        while (true) {
            System.out.print("Enter prime number p: ");
            p = sc.nextInt();
            if (!isPrimeNumbers(p)) System.out.println("Try again!");
            else break;
        }

        while (true) {
            System.out.print("Enter c1 coprime with p: ");
            c1 = sc.nextInt();
            if (gcd(p - 1, c1) != 1) System.out.println("Try again!");
            else break;
        }

        //Step 2
        while (true) {
            System.out.print("Enter c2 coprime with p: ");
            c2 = sc.nextInt();
            if (gcd(p - 1, c2) != 1) System.out.println("Try again!");
            else break;
        }

        d1 = findD(c1, p - 1);
        d2 = findD(c2, p - 1);

        //Step 3
        List<Integer> randomCardNumbering = new ArrayList<>();
        Random random = new Random();
        for (Integer number : numbers) {
            //randomCardNumbering.add(random.nextInt(p - 1) + 1);
            System.out.print("number for " + number + ": ");
            randomCardNumbering.add(sc.nextInt());
        }
        System.out.println("randomCardNumbering");
        System.out.println(randomCardNumbering);

        //Step 4
        List<Integer> listAliceU = new ArrayList<>();
        for (Integer integer : randomCardNumbering) {
            listAliceU.add((int) (Math.pow(integer, c1) % p));
        }
        Collections.shuffle(listAliceU);
        System.out.println("Shuffle listAliceU");
        System.out.println(listAliceU);

        //Step 5
        //int indexFromBob = random.nextInt(randomCardNumbering.size() - 1) + 1;
        System.out.print("Bob chose the card: ");
        int indexFromBob = sc.nextInt();
        //int cardFromBob = randomCardNumbering.remove(indexFromBob);
        int cardFromBob = listAliceU.remove(indexFromBob);
        System.out.println("Bob chose a random card: index: " + indexFromBob + ", "
                            + "number in randomCard: " + cardFromBob);
        System.out.println("AliceV after remove");
        System.out.println(listAliceU);

        //Step 6
        List<Integer> listBobV = new ArrayList<>();
        for(Integer integer : listAliceU) {
            listBobV.add((int) (Math.pow(integer, c2) % p));
        }
        System.out.println("listBobV");
        System.out.println(listBobV);

        //Step 7
        //int indexFromAlice = random.nextInt(randomCardNumbering.size() - 1) + 1;
        System.out.print("Alice chose the card: ");
        int indexFromAlice = sc.nextInt();
        int cardFromAlice = listBobV.get(indexFromAlice);
        System.out.println("Alice chose a random card: index: " + indexFromAlice + ", "
                + "number in randomCard: " + cardFromAlice);
        int w1 = (int) (Math.pow(cardFromAlice, d1) % p);
        System.out.println("w1 = " + w1);

        //Step 8
        int z = (int) (Math.pow(w1, d2) % p);
        System.out.println("z = " + z);
    }

    public static List<Integer> initList() {
        List<Integer> res = new ArrayList<>();
        res.add(1);
        res.add(2);
        res.add(3);
        return res;
    }

    public static boolean isPrimeNumbers(int num) {
        BigInteger bigInteger = BigInteger.valueOf(num);
        return bigInteger.isProbablePrime((int) Math.log(num));
    }

    public static int gcd(int a, int b) {
        while (b != 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    public static int findD(int a, int p) {
        for (int d = 1; d < p; d++) {
            if ((a * d) % p == 1) {
                return d;
            }
        }
        return -1;
    }
}