package com.sual;

public class TripleForGcd {
    private final long gcd;
    private final long x;
    private final long y;

    public TripleForGcd(long gcd, long x, long y) {
        this.gcd = gcd;
        this.x = x;
        this.y = y;
    }

    public long getGcd() {
        return gcd;
    }

    public long getX() {
        return x;
    }

    public long getY() {
        return y;
    }

    @Override
    public String toString() {
        return "TripleForGcd{" +
                "gcd=" + gcd +
                ", u=" + x +
                ", v=" + y +
                '}';
    }
}
