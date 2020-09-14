import java.util.*;
import java.io.*;

class FooBar {
    private int n;
    private boolean isFoo = true;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            synchronized (this) {
                if (isFoo == false) {
                    wait();
                }
                printFoo.run();
                isFoo = false;
                notify();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            synchronized (this) {
                if (isFoo == true) {
                    wait();
                }
                printBar.run();
                isFoo = true;
                notify();
            }
        }
    }
}

public class PrintFooBarAlternately {
    public static void main(String args[]) {

    }
}