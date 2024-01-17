package org.suai.vdovin.lab10.stacks;

import org.suai.vdovin.lab10.lindedlist.LinkedListMod;

import java.util.Objects;

public class StackMod {
    private final int capacity;
    private final LinkedListMod list;
    private int top;

    StackMod(int size) {
        capacity = size;
        top = -1;
        list = new LinkedListMod();
    }

    public void push(int value) {
        if (isFull()) {
            throw new IndexOutOfBoundsException("Stack is full");
        }
        list.add(++top, value);
    }

    public int pop() {
        if (list.isEmpty()) {
            throw new IndexOutOfBoundsException("Stack is empty");
        }
        return list.remove(top--);
    }

    public int peek() {
        return list.get(top);
    }

    public int size() {
        return top + 1;
    }

    public boolean isFull() {
        return top == capacity - 1;
    }

    public boolean isEmpty() {
        return (top == -1);
    }

    @Override
    public boolean equals(Object o) {
        if(!(o instanceof StackMod)) return false;
        if (this == o) return true;
        if (getClass() != o.getClass()) return false;
        StackMod stackMod = (StackMod) o;
        return capacity == stackMod.capacity && top == stackMod.top && Objects.equals(list, stackMod.list);
    }

    @Override
    public int hashCode() {
        return Objects.hash(capacity, list, top);
    }
    @Override
    public String toString() {
        return list.toString();
    }
}
