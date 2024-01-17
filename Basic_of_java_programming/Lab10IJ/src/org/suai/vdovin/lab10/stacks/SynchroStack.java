package org.suai.vdovin.lab10.stacks;
import org.suai.vdovin.lab10.lindedlist.LinkedListMod;
import java.util.Objects;
import java.util.concurrent.atomic.AtomicInteger;

public class SynchroStack {
    private final LinkedListMod list;
    private AtomicInteger top;

    public SynchroStack() {
        top = new AtomicInteger(-1);
        list = new LinkedListMod();
    }

    public synchronized void push(int value) {
        list.add(top.incrementAndGet(), value);
    }

    public synchronized void pop() {
        if (list.isEmpty()) {
            throw new IndexOutOfBoundsException("Stack is empty");
        }
        list.remove(top.get());
        top.decrementAndGet();
    }

    public synchronized int peek() {
        return list.get(top.get());
    }

    public synchronized int size() {
        return top.get() + 1;
    }
    public synchronized boolean isEmpty() {
        return (top.get() == -1);
    }
    @Override
    public synchronized String toString() {
        return list.toString();
    }

    @Override
    public boolean equals(Object o) {
        if(!(o instanceof SynchroStack)) return false;
        if (this == o) return true;
        if (getClass() != o.getClass()) return false;
        SynchroStack that = (SynchroStack) o;
        return top == that.top && Objects.equals(list, that.list);
    }

    @Override
    public int hashCode() {
        return Objects.hash(list, top);
    }
}
