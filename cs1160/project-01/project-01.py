"""project_01.py: Firefly Bakery Receipt Generator

Author: Hannah Wysong
Last Updated: 12/ 07/ 22
Description: This application inputs the amount Users want to buy and calculates a sales rate, discount tax, and tip. 
It then prints the output in receipt format.
"""

def print_lr(left, right):
    """Prints a line with left and right justified parts.

    Args:
        left: The part to left justify.
        right The part to right justify.
    """
    print(left, str(right).rjust(LINE_WIDTH - len(left) - 1))
# old variables
BUSINESS_NAME = 'Firefly Bakery'
BAKERY_COST = 4.00
COFFEE_COST = 3.50
TAX_RATE = 0.075
LINE_WIDTH = 40
THICK_HEADER = '=' * LINE_WIDTH
THIN_HEADER = '-' * LINE_WIDTH
print("Hi Aiden")
def reciept(): 
        qrty1=int(input('Enter Amount of Coffee Ordered: '))
        qrty2=int(input('Enter Amount of Bakery Ordered: '))
        discount1=input('Enter Discount: ')
        tip=input('Enter a Tip: ')
        disc=int(discount1)
        tip1=float(tip)
        tip2=round(tip1,2)
        allCoffee=COFFEE_COST*qrty1
        allBakery=BAKERY_COST*qrty2
        allCost=allCoffee+allBakery
        allDisc=allCost*disc/100
        discount=f'{allDisc:.2f}'
        allTax=(0.75*allCost)
        taxes=f'{allTax:.2f}'
        total=(allCost-allDisc+allTax+tip2)
        total2=f'{total:.2f}'
        print(BUSINESS_NAME)
        print(THICK_HEADER)
        print_lr('Caisher', "Aiden")
        print_lr('Date', '2005-01-02 15:04:05' )
        print_lr('Order #','123')
        print(THICK_HEADER)
        print_lr('Description','Amount')
        print(THIN_HEADER)
        print('Coffee')
        if qrty1>=0:
            print_lr(str(qrty1)+'items @ 3.50',str(allCoffee))
        if qrty1 == 0:
            print_lr('No Purchase','0')
        print('Bakery')
        if qrty2>=0:
            print_lr(str(qrty2)+'items @ 4.00',str(allBakery))
        if qrty2 == 0:
            print_lr('No Purchase','0')
        print(THIN_HEADER)
        print_lr('Subtotal',str(allCost))
        print_lr('-'+str(allDisc)+'% Discount',str(discount))
        print_lr('+ Tax',taxes)
        print_lr('+ Tip',tip2)
        print(THICK_HEADER)
        print_lr('Total',total2)
reciept()
print('Goodbye!')
