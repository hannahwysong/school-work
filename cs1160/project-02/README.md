[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8778486&assignment_repo_type=AssignmentRepo)
# Project 02
**CS-1160 Wright State University | Dan Grahn**

> Reminder: In order to maintain academic integrity, you are required to cite any assistance you received outside of course materials. See [Citing Sources](citing.md) for examples.

# Introduction
Aiden Andrews is very happy with the receipt generator that you created. Business is booming and Aiden has hired a new Barista, Bailey Baker. This has made them realize that the receipt generator needs a few more features. Aiden has asked you to update the Python application so that it can meet the needs of their growing business.

In the previous project, your application generated a single receipt each time it was run. The cashier, date, and order number were always the same, but the rest of the values were calculated from user input. In the new application, Aiden will be able to generate multiple receipts that automatically keep track of the date and order number.

When the application starts, Aiden wants to enter the name of the cashier for the day. After that, the application should generate and print receipts until the user decides to exit the application. An example of this is shown below. Where the user has typed a value, the value is shown inside of square brackets (`[user input]`). The square brackets do not need to be present in the final application.

```
Welcome to the Firefly Bakery Receipt Generator!

Who is working today? [Bailey]
Hi, Bailey!

Generate another receipt (Y/N)? [Y]
How many coffee items? [3]
How many bakery items? [2]
Any discount (1-100)? [5]
What's the tip? [2.50]

Firefly Bakery
========================================
Cashier                           Bailey
Date                 2022-09-04 08:04:05
Order #                                1
========================================

Description                       Amount
----------------------------------------
Coffee
   3 items @ 3.50                  10.50
Bakery
   1 items @ 4.00                   8.00
----------------------------------------
Subtotal                           18.50
- 5% Discount                       0.93
+ Tax                               1.32
+ Tip                               2.50
========================================
Total                             $21.39

Generate another receipt (Y/N)? [Y]
How many coffee items? [1]
How many bakery items? [1]
Any discount (1-100)? [0]
What's the tip? [0]

Firefly Bakery
========================================
Cashier                           Bailey
Date                 2022-09-04 08:14:25
Order #                                2
========================================

Description                       Amount
----------------------------------------
Coffee
   1 items @ 3.50                   3.50
Bakery
   1 items @ 4.00                   4.00
----------------------------------------
Subtotal                            7.50
- 0% Discount                       0.00
+ Tax                               0.56
+ Tip                               0.00
========================================
Total                              $8.06

Generate another receipt (Y/N)? [N]

Goodbye!
```

Please keep the format of the receipt and end-of-day report consistent with this example. However, you are free to explore different ways to accept the rest of the input. You may reuse any of *your own* code from Project 1.

Here is an example of getting the current time in Python.

```python
>>> from datetime import datetime
>>> datetime.now().strftime("%Y-%m-%d %H:%M:%S")
'2022-09-19 07:52:05'
```

# Goals

This project demonstrates your ability to:

1. Use repetition structures
3. Use accumulator variables.
4. Write your own functions.
5. Use standard library modules


# Requirements

1. The application must be written in `project_02.py`.

2. The application must have a comment at the top of the file with the following information.
   1. Your name
   2. The date you last update the application.
   3. The application name.
   4. A short description of the application

3. When the application first starts, it must accept the name of the cashier and use this throughout.

4. After starting and after generating each receipt, the application must ask whether the user wants to generate another receipt.

5. For each receipt, the application must accept the following inputs. You may assume that the user will input a valid value. You **do not** need to handle invalid input.
   1. The number of coffee items as an integer >= 0.
   2. The number of bakery items as an integer >= 0.
   3. A discount percentage as an integer from 0 to 100.
   4. A tip amount as a float >= 0.

6. The application must output the receipt exactly as shown in the examples. This includes:
   1. The business name (Line 1).
   2. The cashier, purchase timestamp, and order # (Lines 2-7).
   3. The number of items purchased, cost per item, and line-item totals (Lines 8-14).
   4. The subtotal, discount rate, discount, tax, and tip (Lines 15-19).
   5. The total and a footer message (Line 20).

7. The application must use the user's input as the cashier.
8. The application must use the current timestamp as the purchase timestamp.
9. The application must use sequential order numbers. Whenever the application is run, the first receipt will be order 1, the second receipt will be order 2, and so on.
10. The application must not print items the customer does not order.
11. The application must calculate all subtotals and totals accurately.

12. The application must use functions to appropriately divide the code into reusable sections. One possible division is:
   1. A function to get the barista name.
   2. A function to format the timestamp.
   3. A function to print the receipt.

### Receipt Structure 
```
01    Firefly Bakery
02    ========================================
03    Cashier                            Aiden
04    Date                 2006-01-02 15:04:05
05    Order #                              123
06    ========================================
07    
08    Description                       Amount
09    ----------------------------------------
10    Coffee
11       # items @ #.##                  ##.##
12    Bakery
13       # items @ #.##                  ##.##
14    ----------------------------------------
15    Subtotal                           ##.##
16    - 0% Discount                      ##.##
17    + Tax                              ##.##
18    + Tip                              ##.##
19    ========================================
20    Total                             $##.##
```

## Grading
Grading will not be done automatically on push like the labs. Instead, it will be performed after final submission. Your application will be tested against a range of inputs which are designed to make it fail. It will be graded against the following criteria.

1. Correct calculations (50 pts)
2. Usage of functions (30 pts)
3. Correct output format (25 pts)
4. Clarity of code and comments (20 pts)

Take time to consider the different "edge cases" that could be given to your application.
