package com.company;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.io.*;


public class AddressBookGUI extends JFrame {
    private JPanel panelMain;
    private static AddressEntry a3;
    Scanner input = new Scanner(System.in);
    private JButton display;
    private JButton add;
    private JButton remove;
    private static AddressEntry a;
    private JLabel label1;
    private JComboBox addresses;
    private static AddressBook ad = null;
    private JScrollPane scroll;

    //i had to copy and paste from geeksforgeeks
    public static void appendStrToFile(String fileName,
                                       String str)
    {
        try {

            // Open given file in append mode.
            BufferedWriter out = new BufferedWriter(
                    new FileWriter(fileName, true));
            out.write(str);
            out.close();
        }
        catch (IOException e) {
            System.out.println("exception occoured" + e);
        }
    }

    public AddressBookGUI(String title) {
        super(title);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setContentPane(panelMain);
        this.pack();
        display.addActionListener(new ActionListener() {
            private Object FileUtils;

            @Override
            public void actionPerformed(ActionEvent e) {

                try {
                    File f = new File("filename.txt");
                    Scanner myReader = new Scanner(f);
                    ad = new AddressBook();
                    ArrayList<String> a5 = new ArrayList<>();
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        a5.add(data);
                    }
                    myReader.close();
                    for (int j = 0; j < a5.size()/8; j++) {//iterating through a5
                        a3 = new AddressEntry(a5.get(0+(8*j)), a5.get(1+(8*j)), a5.get(2+(8*j)), a5.get(3+(8*j)), a5.get(4+(8*j)), Integer.parseInt(a5.get(5+(8*j))), a5.get(6+(8*j)), a5.get(7+(8*j)));
                        ad.add(a3);
                    }
                    //a3 = null;


                }
                catch (FileNotFoundException z) {
                    System.out.println("An error occured.");
                    z.printStackTrace();
                }
 //               System.out.println(ad.getClass());
 //               System.out.println(ad.length());
//                label1.setText((("<html>" + (AddressEntry)ad.getFirstName() + " " + a3.getLastName() + "<br>" + a3.getStreet() + "<br>" + a3.getCity() + ", " + a3.getState() + " " + a3.getZip() + "<br>" + a3.getEmail() + "<br>" + a3.getPhone() + "</html>").toString()));
//                label1.setText((("<html>" + ad.addressEntryList.get(0).toString() + "<br>"+ad.addressEntryList.get(1).toString() + "</html>" )));
//                label1.setText((("<html>" + ad.addressEntryList.get(1).toString() + "</html>")));
                Collections.sort(ad.addressEntryList, new LastNameComparator());
                String displayText="<html>";
            for (int i = 0; i < ad.addressEntryList.size(); i++) {


                displayText+=ad.addressEntryList.get(i).getFirstName()+" "
                             + ad.addressEntryList.get(i).getLastName() + "<br>"
                             + ad.addressEntryList.get(i).getStreet() + "<br>" +
                        ad.addressEntryList.get(i).getCity() + " " +
                        ad.addressEntryList.get(i).getState() + " " +
                        ad.addressEntryList.get(i).getZip() + "<br>" +
                        ad.addressEntryList.get(i).getEmail() + "<br>" +
                        ad.addressEntryList.get(i).getPhone() + "<br>" + "<br>";
//                label1.setText((("<html>" + ad.addressEntryList.get(i).getFirstName() + "<br>"+ "</html>")));
            }
                displayText+="</html>";
                label1.setText(displayText);
            }

        });

        add.addActionListener(new ActionListener() {
            @Override

            public void actionPerformed(ActionEvent e) {
                try {
                    File f = new File("filename.txt");
                    Scanner myReader = new Scanner(f);
                    ad = new AddressBook();
                    ArrayList<String> a5 = new ArrayList<>();
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        a5.add(data);
                    }
                    myReader.close();
                    for (int j = 0; j < a5.size()/8; j++) {//iterating through a5
                        a3 = new AddressEntry(a5.get(0+(8*j)), a5.get(1+(8*j)), a5.get(2+(8*j)), a5.get(3+(8*j)), a5.get(4+(8*j)), Integer.parseInt(a5.get(5+(8*j))), a5.get(6+(8*j)), a5.get(7+(8*j)));
                        ad.add(a3);
                    }
                }
                catch (FileNotFoundException z) {
                    System.out.println("An error occured.");
                    z.printStackTrace();
                }
                String firstName = JOptionPane.showInputDialog("Enter First name: ", null);
                String lastName = JOptionPane.showInputDialog("Enter Last name: ", null);
                String street = JOptionPane.showInputDialog("Enter Street name: ", null);
                String city = JOptionPane.showInputDialog("Enter city name: ", null);
                String state = JOptionPane.showInputDialog("Enter state initials: ", null);
                String zip = JOptionPane.showInputDialog("Enter zip code: ", null);
                String phone = JOptionPane.showInputDialog("Enter phone number: ", null);
                String email = JOptionPane.showInputDialog("Enter email: ", null);
                AddressEntry added = new AddressEntry(firstName, lastName, street, city, state, Integer.parseInt(zip), phone, email);
                ad.addressEntryList.add(added);
            }
        });

        addresses.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    File f = new File("filename.txt");
                    Scanner myReader = new Scanner(f);
                    ad = new AddressBook();
                    ArrayList<String> a5 = new ArrayList<>();
                    while (myReader.hasNextLine()) {
                        String data = myReader.nextLine();
                        a5.add(data);
                    }
                    myReader.close();
                    for (int j = 0; j < a5.size()/8; j++) {//iterating through a5
                        a3 = new AddressEntry(a5.get(0+(8*j)), a5.get(1+(8*j)), a5.get(2+(8*j)), a5.get(3+(8*j)), a5.get(4+(8*j)), Integer.parseInt(a5.get(5+(8*j))), a5.get(6+(8*j)), a5.get(7+(8*j)));
                        ad.add(a3);
                    }
                }
                catch (FileNotFoundException z) {
                    System.out.println("An error occured.");
                    z.printStackTrace();
                }
                //AddressEntry[] listofaddresses = ad.addressEntryList.toArray(new AddressEntry[0]);

                addresses = new JComboBox(ad.addressEntryList.toArray());

            }

        });
        remove.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String lastName = JOptionPane.showInputDialog("Enter Last name: ", null);
                Object addressToDelete = addresses.getSelectedItem();
            }
        });

            }




    public static void main(String[] args) {

            JFrame frame = new AddressBookGUI("AddressBookApplication");
            frame.setVisible(true);

        }
    }


