package com.company;

public class Main {

    public static void main(String[] args) {
	    try {
	        Args arg = new Args("l,p# ,d*", args);
	        boolean logging = arg.getBoolean('l');
	        int port = arg.getInt('p');
	        String directory = arg.getString('d');
	        executeApplication(logging, port, directory);
        } catch (ArgsException e) {
	        System.out.printf("Arguments error: %s\n", e.errorMessage());
        }
    }
}
