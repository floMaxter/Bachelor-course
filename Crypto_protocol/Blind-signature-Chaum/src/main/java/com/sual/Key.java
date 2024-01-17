package com.sual;

public class Key {
    private final long firstNumber;
    private final long module;

    public Key(long firstNumber, long module) {
        this.firstNumber = firstNumber;
        this.module = module;
    }

    public long getFirstNumber() {
        return firstNumber;
    }

    public long getModule() {
        return module;
    }

    @Override
    public String toString() {
        return "{" +
                "number=" + firstNumber +
                ", module=" + module +
                '}';
    }
}