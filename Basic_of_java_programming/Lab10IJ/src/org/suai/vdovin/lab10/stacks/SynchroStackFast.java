package org.suai.vdovin.lab10.stacks;

import org.suai.vdovin.lab10.lindedlist.LinkedListMod;

import java.util.Objects;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReadWriteLock;
import java.util.concurrent.locks.ReentrantReadWriteLock;

public class SynchroStackFast extends Thread {
    private final LinkedListMod list;
    private AtomicInteger top;

    private final ReadWriteLock lock = new ReentrantReadWriteLock();
    private final Lock readLock = lock.readLock(); //немодифицирующий метод
    private final Lock writeLock = lock.writeLock(); //модифицирующий

    public SynchroStackFast() {
        top = new AtomicInteger(-1);
        list = new LinkedListMod();
    }

    public void push(int value) {
        writeLock.lock();
        try {
            list.add(top.incrementAndGet(), value);
        } finally {
            writeLock.unlock();
        }
    }

    public void pop() {
        writeLock.lock();
        try {
            if (list.isEmpty()) {
                throw new IndexOutOfBoundsException("Stack is empty");
            }
            list.remove(top.get());
            top.decrementAndGet();
        } finally {
            writeLock.unlock();
        }
    }

    public int peek() {
        readLock.lock();
        try {
            return list.get(top.get());
        } finally {
            readLock.unlock();
        }
    }

    public int size() {
        readLock.lock();
        try {
            return top.get() + 1;
        } finally {
            readLock.unlock();
        }
    }

    public boolean isEmpty() {
        readLock.lock();
        try {
            return (top.get() == -1);
        } finally {
            readLock.unlock();
        }
    }

    @Override
    public boolean equals(Object o) {
        readLock.lock();
        try {
            if (!(o instanceof SynchroStackFast)) return false;
            if (this == o) return true;
            if (getClass() != o.getClass()) return false;
            SynchroStackFast that = (SynchroStackFast) o;
            return top == that.top &&
                    Objects.equals(list, that.list) && Objects.equals(lock, that.lock) &&
                    Objects.equals(readLock, that.readLock) && Objects.equals(writeLock, that.writeLock);
        } finally {
            readLock.unlock();
        }
    }

    @Override
    public int hashCode() {
        readLock.lock();
        try {
            return Objects.hash(list, top, lock, readLock, writeLock);
        } finally {
            readLock.unlock();
        }
    }

    @Override
    public String toString() {
        readLock.lock();
        try {
            return list.toString();
        } finally {
            readLock.unlock();
        }
    }
}