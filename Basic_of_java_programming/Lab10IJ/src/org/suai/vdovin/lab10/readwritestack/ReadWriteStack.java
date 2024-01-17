package org.suai.vdovin.lab10.readwritestack;

import org.suai.vdovin.lab10.stacks.SynchroStack;

public class ReadWriteStack {
    private final SynchroStack stack;
    private final int valueThreads;

    public ReadWriteStack(int valueThreads) {
        this.stack = new SynchroStack();
        this.valueThreads = valueThreads;
    }
    public class Threads extends Thread {
        private final boolean pushOrPop;
        Threads(boolean pushOrPop) {
            this.pushOrPop = pushOrPop;
        }

        @Override
        public void run() {
            if(pushOrPop) {
                for(int i = 0; i < 1000000; i++) {
                    stack.push(i);
                }
            } else {
                for(int i = 0; i < 1000000; i++) {
                    if(stack.isEmpty()) break;
                    try {
                        stack.pop();
                    } catch (IndexOutOfBoundsException ex) {
                        break;
                    }
                }
            }
        }
    }

    public void goReadWrite() {
        boolean pushOrPop = true;
        Thread[] threads = new Thread[valueThreads];

        for(int i = 0; i < valueThreads; i++) {
            threads[i] = new Threads(pushOrPop);
            threads[i].start();
            pushOrPop = !pushOrPop;
        }

        try {
            for(Thread thread : threads) {
                thread.join();
            }
        } catch (InterruptedException ex) {
            System.out.println("Interrupted");
        }
    }

    public int getSizeStack() {
        return stack.size();
    }
}
