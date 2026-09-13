package java_mini_project;

public class Node {
    Employee data;
    Node next;
    Node prev;
    Node(Employee data) {
        this.data = data;
        next = null;
        prev = null;
    }
}