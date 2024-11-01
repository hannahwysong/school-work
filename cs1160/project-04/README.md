
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9576227&assignment_repo_type=AssignmentRepo)
# Project 04
**CS-1160 Wright State University | Dan Grahn**

> Reminder: In order to maintain academic integrity, you are required to cite any assistance you received outside of course materials. See [Citing Sources](citing.md) for examples.

## Introduction
Aiden loves the receipt generator and output from Projects 1-3. Unfortunately, he's realized that he needs a few more features in order to make sure it works for the business:

1. Aiden needs to be able to change the prices, tax rate, cashier, and business name without restarting the application. Changes to any of the configuration should be saved when the application restarts.
2. Aiden must have order numbers continue where they left off after the application restarts.

You may use any of the code provided or that you wrote for Projects 1-3.

### Task 1: Changing Configuration
To be able to change the configuration and persist those changes across multiple runs of the application, the configuration must be loaded from and saved to a file. Additionally, the configuration will need to be available to multiple parts in the software.

This will require you to write a `Config` class. The class should have five attributes that are all initialized to `None`: `business_name`, `bakery_cost`, `cashier`, `coffee_cost`, and `tax_rate`. The class should have two methods `load()` and `save()`. Neither method should take any arguments. When the `load()` method is called, the class should load the attributes, except `cashier`, from `config/config.yml`. When the `save()` method is called, the class should save the attributes, except `cashier` to `config/config.yml`. You may assume `config/config.yml` exists.

`project_04.py` provides an example of how you may load and save the yaml file with `pyyaml`. To use this, you will need to install `pyyaml` by running `python -m pip install pyyaml` in the terminal. Alternatively, you may parse the file manually.

Toward the beginning of your application, you should create a `Config` object and load the attributes from the file. Instead of using the constants previously provided, the rest of the code should use the attributes of this config object to print and make calculations. Pass the object into functions or objects as arguments as needed. Don't use the config object inside a function unless is an argument or an attribute of the object.

Don't begin Task 2 until you have completed this task. 

### Task 2: Updating the Interface
The previous interface will need to be updated to allow Aiden to set configurations. Instead of asking the user whether they want to generate another receipt, the interface should prompt for a command. There are five possible commands. In the following examples, user input and variables are shown in braces `{}`.

#### `cashier`
This command sets the cashier attribute of the config object. You do not need to handle the case where the user generates a receipt before setting the cashier. The command should match this format.

```
>> cashier
Cashier [{CURRENT CASHIER}]: {USER INPUT}
Cashier has been set.
```

#### `config`
This command prompts the user to update the configuration. At the end of the command, the configuration should be saved using the `save()` method. The command should match this format. Output and accept the tax rate as a percentage out of 100.

```
>> config
Business Name [{BUSINESS NAME}]: {USER INPUT}
Bakery Cost [${PRICE}]: {USER INPUT}
Coffee Cost [${PRICE}]: {USER INPUT}
Tax Rate: [{TAX RATE}%]: {USER INPUT}
Configuration saved.
```

#### `exit`
This command exits the application. The command should match this format.

```
>> exit
Goodbye!
```

#### `help`
This command prints a help message. The command should match this format.

```
>> help
Commands:
    cashier - Update the cashier
    config  - Edit configuration
    exit    - Exit
    help    - Show this message
    r       - Generate receipt
    tips    - Print tips
```

#### `r`
This command generates a receipt. The command should match this format.

```
>> r
How many coffee items? {3}
How many bakery items? {2}
Any discount (1-100)? {5}
What's the tip? {2.50}

Firefly Bakery
========================================
Cashier                        {Cashier}
Date                 2022-09-04 08:04:05
Order #                        {Order #}
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
```

Don't begin Task 3 until you have completed this task.

### Task 3: Adding Order Number
Add a new attribute to the `Config` class named `_last_order_num`. Initalize it to `None` in the `__init__` method. Next, add a new method to the `Config` class named `next_order_number()`. This method should return the next order number to be used for a receipt.

The first time `next_order_number()` is called, it should load the order number stored in `config/last_order_num.txt` and save it to the attribute `_last_order_num`. Each time the method is called (including the first), it should update `_last_order_num` and save the updated number to `config/last_order_num.txt`.

Use `next_order_number()` to get the order number when printing the receipt and saving it to the `receipts.csv` file. Make sure that the *same* order number is used in both locations for the same receipt.


## Full Example
Here is an example of the output of each command being run during normal usage.

```
Welcome to the Firefly Bakery Receipt Generator!

>> {help}
Commands:
    cashier - Update the cashier
    config  - Edit configuration
    exit    - Exit
    help    - Show this message
    r       - Generate receipt
    tips    - Print tips

>> {cashier}
Cashier [None]: {Bailey}
Cashier has been set.

>> {r}
How many coffee items? {3}
How many bakery items? {2}
Any discount (1-100)? {5}
What's the tip? {2.50}

Firefly Bakery
========================================
Cashier                           Bailey
Date                 2022-09-04 08:04:05
Order #                        {Order #}
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

>> {exit}
Goodbye!
```

## Requirements

1. The application must be written in `project_04.py`

2. The application must have a comment at the top of the file with the following information.
   1. Your name
   2. The date you last update the application.
   3. The application name.
   4. A short description of the application

3. When the application starts, it must prompt for a command. After each command, the application must prompt for another unless the application has exited.

4. The application must perform all of the functionality described in the above tasks.

## Grading
Grading will not be done automatically on push like the labs. Instead, it will be performed after final submission. Your application will be tested against a range of inputs which are designed to make it fail. It will be graded against the following criteria.

1. Task 1 (50 pts)
2. Task 2 (50 pts)
3. Task 3 (50 pts)
4. Correct calculations, output format, and functionality from previous labs (25 pts)

Take time to consider the different "edge cases" that could be given to your application.
