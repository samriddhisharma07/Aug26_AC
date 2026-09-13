package java_mini_project;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {

    static Scanner sc = new Scanner(System.in);
    static Employee[] emp = new Employee[100];
    static int count = 0;
    static int current = -1;

    public static void main(String[] args) {
        int choice;

        do {
            System.out.println("\n===== MAIN MENU =====");
            System.out.println("1. Add an Employee");
            System.out.println("2. Display");
            System.out.println("3. Sort");
            System.out.println("4. Save to File");
            System.out.println("5. Load from File");
            System.out.println("6. Exit");
            System.out.print("Enter your choice : ");
            choice = sc.nextInt();

            if (choice == 1) {
                addMenu();
            } else if (choice == 2) {
                displayMenu();
            } else if (choice == 3) {
                sortMenu();
            } else if (choice == 4) {
                saveToFile();
            } else if (choice == 5) {
                loadFromFile();
            } else if (choice == 6) {
                System.out.println("Exiting... Bye!");
            } else {
                System.out.println("Invalid choice, try again.");
            }

        } while (choice != 6);
    }

    static void addMenu() {
        int choice;
        do {
            System.out.println("\n--- ADD EMPLOYEE MENU ---");
            System.out.println("1. Manager");
            System.out.println("2. Engineer");
            System.out.println("3. Sales Person");
            System.out.println("4. Exit to Main Menu");
            System.out.print("Enter your choice : ");
            choice = sc.nextInt();
            sc.nextLine();

            if (choice == 1) {
                System.out.print("Enter name : ");
                String name = sc.nextLine();
                System.out.print("Enter address : ");
                String address = sc.nextLine();
                System.out.print("Enter age : ");
                int age = sc.nextInt();
                sc.nextLine();
                System.out.print("Enter gender : ");
                String gender = sc.nextLine();
                System.out.print("Enter basic salary : ");
                double salary = sc.nextDouble();
                System.out.print("Enter HRA : ");
                double hra = sc.nextDouble();
                sc.nextLine();

                Manager m = new Manager();
                m.setData(name, address, age, gender, salary);
                m.hra = hra;
                emp[count] = m;
                count = count + 1;
                current = count - 1;
                System.out.println("Manager added.");

            } else if (choice == 2) {
                System.out.print("Enter name : ");
                String name = sc.nextLine();
                System.out.print("Enter address : ");
                String address = sc.nextLine();
                System.out.print("Enter age : ");
                int age = sc.nextInt();
                sc.nextLine();
                System.out.print("Enter gender : ");
                String gender = sc.nextLine();
                System.out.print("Enter basic salary : ");
                double salary = sc.nextDouble();
                System.out.print("Enter technical allowance : ");
                double allowance = sc.nextDouble();
                sc.nextLine();

                Engineer e = new Engineer();
                e.setData(name, address, age, gender, salary);
                e.technicalAllowance = allowance;
                emp[count] = e;
                count = count + 1;
                current = count - 1;
                System.out.println("Engineer added.");

            } else if (choice == 3) {
                System.out.print("Enter name : ");
                String name = sc.nextLine();
                System.out.print("Enter address : ");
                String address = sc.nextLine();
                System.out.print("Enter age : ");
                int age = sc.nextInt();
                sc.nextLine();
                System.out.print("Enter gender : ");
                String gender = sc.nextLine();
                System.out.print("Enter basic salary : ");
                double salary = sc.nextDouble();
                System.out.print("Enter commission : ");
                double commission = sc.nextDouble();
                sc.nextLine();

                SalesPerson s = new SalesPerson();
                s.setData(name, address, age, gender, salary);
                s.commission = commission;
                emp[count] = s;
                count = count + 1;
                current = count - 1;
                System.out.println("Sales Person added.");

            } else if (choice == 4) {
                System.out.println("Returning to main menu...");
            } else {
                System.out.println("Invalid choice, try again.");
            }

        } while (choice != 4);
    }

    static void displayMenu() {
        int choice;
        do {
            System.out.println("\n--- DISPLAY MENU ---");
            System.out.println("1. All Employees");
            System.out.println("2. First Employee");
            System.out.println("3. Next Employee");
            System.out.println("4. Previous Employee");
            System.out.println("5. Last Employee");
            System.out.println("6. Exit to Main Menu");
            System.out.print("Enter your choice : ");
            choice = sc.nextInt();

            if (count == 0) {
                System.out.println("No employees found.");
            } else if (choice == 1) {
                for (int i = 0; i < count; i++) {
                    emp[i].display();
                }

            } else if (choice == 2) {
                current = 0;
                emp[current].display();

            } else if (choice == 3) {
                if (current < count - 1) {
                    current = current + 1;
                    emp[current].display();
                } else {
                    System.out.println("Already at last employee.");
                }

            } else if (choice == 4) {
                if (current > 0) {
                    current = current - 1;
                    emp[current].display();
                } else {
                    System.out.println("Already at first employee.");
                }

            } else if (choice == 5) {
                current = count - 1;
                emp[current].display();

            } else if (choice == 6) {
                System.out.println("Returning to main menu...");
            } else {
                System.out.println("Invalid choice, try again.");
            }

        } while (choice != 6);
    }

    static void sortMenu() {
        int choice;
        do {
            System.out.println("\n--- SORT MENU ---");
            System.out.println("1. Sort by Name - Ascending");
            System.out.println("2. Sort by Name - Descending");
            System.out.println("3. Exit to Main Menu");
            System.out.print("Enter your choice : ");
            choice = sc.nextInt();

            if (choice == 1) {
                sortAscending();
                System.out.println("Sorted ascending.");
            } else if (choice == 2) {
                sortDescending();
                System.out.println("Sorted descending.");
            } else if (choice == 3) {
                System.out.println("Returning to main menu...");
            } else {
                System.out.println("Invalid choice, try again.");
            }

        } while (choice != 3);
    }

    static void sortAscending() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - 1 - i; j++) {
                if (emp[j].name.compareToIgnoreCase(emp[j + 1].name) > 0) {
                    Employee temp = emp[j];
                    emp[j] = emp[j + 1];
                    emp[j + 1] = temp;
                }
            }
        }
        current = 0;
    }

    static void sortDescending() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - 1 - i; j++) {
                if (emp[j].name.compareToIgnoreCase(emp[j + 1].name) < 0) {
                    Employee temp = emp[j];
                    emp[j] = emp[j + 1];
                    emp[j + 1] = temp;
                }
            }
        }
        current = 0;
    }

    static void saveToFile() {
        try {
            BufferedWriter writer = new BufferedWriter(new FileWriter("employees.txt"));
            for (int i = 0; i < count; i++) {
                writer.write(emp[i].toFileLine());
                writer.newLine();
            }
            writer.close();
            System.out.println("Saved to employees.txt successfully.");
        } catch (IOException e) {
            System.out.println("Error while saving: " + e.getMessage());
        }
    }

    static void loadFromFile() {
        try {
            BufferedReader reader = new BufferedReader(new FileReader("employees.txt"));
            count = 0;
            current = -1;

            String line = reader.readLine();
            while (line != null) {
                String[] parts = line.split(",");
                String type = parts[0];
                String name = parts[1];
                String address = parts[2];
                int age = Integer.parseInt(parts[3]);
                String gender = parts[4];
                double salary = Double.parseDouble(parts[5]);
                double extra = Double.parseDouble(parts[6]);

                if (type.equals("MANAGER")) {
                    Manager m = new Manager();
                    m.setData(name, address, age, gender, salary);
                    m.hra = extra;
                    emp[count] = m;
                    count = count + 1;
                } else if (type.equals("ENGINEER")) {
                    Engineer e = new Engineer();
                    e.setData(name, address, age, gender, salary);
                    e.technicalAllowance = extra;
                    emp[count] = e;
                    count = count + 1;
                } else if (type.equals("SALESPERSON")) {
                    SalesPerson s = new SalesPerson();
                    s.setData(name, address, age, gender, salary);
                    s.commission = extra;
                    emp[count] = s;
                    count = count + 1;
                }

                line = reader.readLine();
            }

            reader.close();
            if (count > 0) {
                current = 0;
            }
            System.out.println("Loaded from employees.txt successfully.");
        } catch (IOException e) {
            System.out.println("Error while loading: " + e.getMessage());
        }
    }
}