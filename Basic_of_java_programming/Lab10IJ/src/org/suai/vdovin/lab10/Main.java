package org.suai.vdovin.lab10;

import org.suai.vdovin.lab10.readwritestack.ReadWriteStack;
import org.suai.vdovin.lab10.readwritestack.ReadWriteStackFast;
import org.suai.vdovin.lab10.IterativeParallelism.IterativeParallelism;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.function.Function;
import java.util.function.Predicate;

public class Main {
    public static void main(String[] args) {
        /*test1();
        System.out.println("-------------");
        test2();
        System.out.println("-------------");
        test3();*/

        try {
            testDop();
        } catch (Exception e) {
            System.out.println(e);
        }

    }

    public static void testDop() throws Exception {
        int valueOfTreads = 2;
        List<Integer> list = new ArrayList<>();
        for(int i = 0; i < 10; i++) {
            list.add(i);
        }
        list.add(1000);
        for(int i = 10; i < 20; i++) {
            list.add(i);
        }
        list.add(-10);

        Predicate<Integer> predicate = number -> number > 0;
        Function<Integer, String> function = String::valueOf;

        IterativeParallelism<Integer> iterativeParallelism = new IterativeParallelism<>();
        int min = iterativeParallelism.minimum(valueOfTreads, list, (o1, o2) -> {
            if(Objects.equals(o1, o2)) {
                return 0;
            } else if(o1 < o2) {
                return -1;
            }
            return 1;
        });

        int max = iterativeParallelism.maximum(valueOfTreads, list, (o1, o2) -> {
            if(Objects.equals(o1, o2)) {
                return 0;
            } else if(o1 < o2) {
                return -1;
            }
            return 1;
        });

        System.out.println("Max = " + max);
        System.out.println("Min = " + min);

        System.out.println("Are there only positive numbers in the list?");
        System.out.println(iterativeParallelism.all(valueOfTreads, list, predicate));

        System.out.println("Are there any elements less than zero?");
        System.out.println(iterativeParallelism.any(valueOfTreads, list, predicate));

        System.out.println("Positive elements of the sheet:");
        System.out.println(iterativeParallelism.filter(valueOfTreads, list, predicate));

        System.out.println("List in string format:");
        System.out.println(iterativeParallelism.map(valueOfTreads, list, function));

        System.out.println("After concatenation:");
        System.out.println(iterativeParallelism.join(valueOfTreads, list));
    }

    public static void test1() {
        int valueThreads = 1;
        ReadWriteStack synStack = new ReadWriteStack(valueThreads);
        ReadWriteStackFast fastStack = new ReadWriteStackFast(valueThreads);

        long time1 = System.currentTimeMillis();
        synStack.goReadWrite();
        long time2 = System.currentTimeMillis();
        System.out.println("Value Threads = " + valueThreads);
        System.out.println("Time synchronized stack = " + (time2 - time1) + " ms");

        long time3 = System.currentTimeMillis();
        fastStack.goReadWrite();
        long time4 = System.currentTimeMillis();
        System.out.println("Time fast stack = " + (time4 - time3) + " ms");
    }

    public static void test2() {
        int valueThreads = 2;
        ReadWriteStack synStack = new ReadWriteStack(valueThreads);
        ReadWriteStackFast fastStack = new ReadWriteStackFast(valueThreads);

        long time1 = System.currentTimeMillis();
        synStack.goReadWrite();
        long time2 = System.currentTimeMillis();

        System.out.println("Value Threads = " + valueThreads);
        System.out.println("Time synchronized stack = " + (time2 - time1) + " ms");

        long time3 = System.currentTimeMillis();
        fastStack.goReadWrite();
        long time4 = System.currentTimeMillis();
        System.out.println("Time fast stack = " + (time4 - time3) + " ms");
    }

    public static void test3() {
        int valueThreads = 10;
        ReadWriteStack synStack = new ReadWriteStack(valueThreads);
        ReadWriteStackFast fastStack = new ReadWriteStackFast(2);

        long time1 = System.currentTimeMillis();
        synStack.goReadWrite();
        long time2 = System.currentTimeMillis();

        System.out.println("Value Threads = " + valueThreads);
        System.out.println("Time synchronized stack = " + (time2 - time1) + " ms");

        long time3 = System.currentTimeMillis();
        fastStack.goReadWrite();
        long time4 = System.currentTimeMillis();
        System.out.println("Time fast stack = " + (time4 - time3) + " ms");
    }
}