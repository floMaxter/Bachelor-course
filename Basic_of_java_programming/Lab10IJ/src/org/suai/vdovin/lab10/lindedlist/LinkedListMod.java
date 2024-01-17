package org.suai.vdovin.lab10.lindedlist;

import java.util.Objects;

public class LinkedListMod {
    private int size;
    private Node head;
    private Node tail;

    private static class Node {
        private final int element;
        private Node prev;
        private Node next;

        Node(Node prev, int value, Node next) {
            this.prev = prev;
            this.element = value;
            this.next = next;
        }
    }
    public LinkedListMod() {
        this.size = 0;
        this.head = null;
        this.tail = null;
    }

    public void add(int element) {
        if (!isEmpty()) {
            Node prev = tail;
            tail = new Node(prev, element, null);
            prev.next = tail;
        } else {
            tail = new Node(null, element, null);
            head = tail;
        }
        size++;
    }

    public void add(int index, int element) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("Invalid index");
        }
        if(!isEmpty()) {
            if(index == size) {
                add(element);
                return;
            }

            Node currNode = getNode(index);
            Node nextNode = currNode.next;

            Node newNode = new Node(currNode, element, nextNode);
            currNode.next.prev = newNode;
            currNode.next = newNode;
            size++;
        } else {
            add(element);
        }
    }

    public int get(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Invalid index");
        }
        if (index == size - 1) {
            return tail.element;
        }
        if (index == 0) {
            return head.element;
        }
        Node currNode = getNode(index);
        return currNode.element;
    }

    private Node getNode(int index) {
        Node currNode = head;
        for (int i = 0; i < index; i++) {
            currNode = currNode.next;
        }
        return currNode;
    }

    public int remove() {
        if(isEmpty()) {
            throw new IndexOutOfBoundsException("List is empty");
        }
        Node currNode = head;
        head = head.next;
        size--;
        return currNode.element;
    }

    public int remove(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Invalid index");
        }
        if(isEmpty()) {
            throw new IndexOutOfBoundsException("List is empty");
        }
        if(size == 1) {
            size--;
            int res = head.element;
            head = tail = null;
            return res;
        }
        Node currNode;
        if(index == size - 1) {
            currNode = tail;
            tail = tail.prev;
            tail.next = null;
            currNode.prev = null;
        } else if(index == 0) {
            currNode = head;
            head = head.next;
            currNode.next = null;
            head.prev = null;
        } else {
            currNode = getNode(index);
            currNode.prev.next = currNode.next;
            currNode.next.prev = currNode.prev;
            currNode.prev = null;
            currNode.next = null;
        }
        size--;
        return currNode.element;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    public void printList() {
        if(isEmpty()) {
            System.out.println("List is empty");
            return;
        }
        Node currNode = head;
        for(int i = 0; i < size; i++) {
            System.out.print(currNode.element + " ");
            currNode = currNode.next;
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        Node currNode = head;
        for(int i = 0; i < size; i++) {
            sb.append(currNode.element).append(" ");
            currNode = currNode.next;
        }
        return sb.toString();
    }
}
