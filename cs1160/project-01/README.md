# Project 01
**CS-1160 Wright State University | Dan Grahn**

> Reminder: In order to maintain academic integrity, you are required to cite any assistance you received outside of course materials. See [Citing Sources](citing.md) for examples.

# Introduction
Aiden Andrews runs a local coffee house and cafe named the "Firefly Bakery". After a particularly painful experience with the popular payment processing company Rectangle, Aiden has decided its time to upgrade their operation. Aiden has asked you to develop a Python application that can prepare a receipt for the customer. It needs to be accurate and attractive.

The Firefly Bakery sells coffee and bakery items. Coffee costs $3.50 and baked goods cost $4.00. The tax rate for the Firefly Bakery is 7.5%. Tax covers everything after the discount except for the tip. The receipt should be 40 characters wide and formatted exactly like the following example.

```
Firefly Bakery
========================================
Cashier                            Aiden
Date                 2006-01-02 15:04:05
Order #                                1
========================================

Description                       Amount
----------------------------------------
Coffee
   2 items @ 3.50                   7.00
Bakery
   1 items @ 4.00                   4.00
----------------------------------------
Subtotal                           11.00
- 5% Discount                       0.55
+ Tax                               0.82
+ Tip                               2.50
========================================
Total                             $13.77
```

To assist in formatting, I have included a helper function named `print_lr`. This will help print lines that have left and right justified components. Here are a few examples of how to use the function.

```python
>>> print_lr('Left', 'Right')
Left                               Right
>>> print_lr('Cashier', 'Aiden')
Cashier                            Aiden
```

# Goals

This project demonstrates your ability to:

1. Use functions with one or more arguments.
2. Work with variables of multiple types.
3. Perform basic number processing operations.
4. Output information in specific formats.
5. Use `if`, `elif`, and `else` statements to control data flow.

# Requirements

1. The application must be written in `project_01.py`.

2. The application must have a comment at the top of the file with the following information.
   1. Your name
   2. The date you last update the application.
   3. The application name.
   4. A short description of the application

3. The application must accept the following inputs. You may assume that the user will input a valid value. You **do not** need to handle invalid input.
   1. The number of coffee items as an integer >= 0.
   2. The number of bakery items as an integer >= 0.
   3. A discount percentage as an integer from 0 to 100.
   4. A tip amount as a float >= 0.

4. The application must output the receipt exactly as shown in the examples. This includes:
   1. The business name (Line 1).
   2. The cashier, purchase timestamp, and order # (Lines 2-7).
   3. The number of items purchased, cost per item, and line-item totals (Lines 8-14).
   4. The subtotal, discount rate, discount, tax, and tip (Lines 15-19).
   5. The total and a footer message (Line 20).

5. The application must use "Aiden" as the cashier.
6. The application must use "2006-01-02 15:04:05" as the purchase timestamp.
7. The application must use "123" as the order number.
8. The application must not print items the customer does not order.
   1. If no items are purchased, the receipt must state "No purchase."

9. The application must calculate all subtotals and totals accurately.

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

## Examples
### Nothing Purchased
```
Firefly Bakery
========================================
Cashier                            Aiden
Date                 2006-01-02 15:04:05
Order #                              123
========================================

Description                       Amount
----------------------------------------
No purchase.
----------------------------------------
Subtotal                            0.00
- 0% Discount                       0.00
+ Tax                               0.00
+ Tip                               0.00
========================================
Total                              $0.00
```

### One of Each
```
Firefly Bakery
========================================
Cashier                            Aiden
Date                 2006-01-02 15:04:05
Order #                              123
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
```

### Party Order
```
Firefly Bakery
========================================
Cashier                            Aiden
Date                 2006-01-02 15:04:05
Order #                              123
========================================

Description                       Amount
----------------------------------------
Coffee
   50 items @ 3.50                175.00
Bakery
   40 items @ 4.00                160.00
----------------------------------------
Subtotal                          335.00
- 10% Discount                     33.50
+ Tax                              22.61
+ Tip                              15.00
========================================
Total                            $339.11
```

## Grading
Grading will not be done automatically on push like the labs. Instead, it will be performed after final submission. Your application will be tested against a range of inputs which are designed to make it fail. It will be graded against the following criteria.

1. Correct calculations (55 pts)
2. Correct output format (35 pts)
3. Clarity of code and comments (10 pts)

Take time to consider the different "edge cases" that could be given to your application. 
