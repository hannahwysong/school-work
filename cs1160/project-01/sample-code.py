from pathlib import Path

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
order = 0 
cashier=input("Who is working today?: ")
print("Hi "+ cashier)
class Receipt:
    def __init__(self, cashier):
        self.cashier = cashier 
        self.order = order
        self.bakery_count = None
        self.coffee_count = None
        self.bakery_subtotal = None
        self.coffee_subtotal = None
        self.discount = None
        self.tip = None
        self.discount_total = None 
        self.tax = None
        self.tax_total = None
        self.total = None
        self.cash = None
        self.cash_total = None
   
    def calculate(self):
        self.bakery_subtotal = self.bakery_count * BAKERY_COST
        self.coffee_subtotal = self.coffee_count * COFFEE_COST
        self.total = self.bakery_subtotal + self.coffee_subtotal 
        self.discount_total = (self.total * self.discount)/100
        self.tax_total = self.total * TAX_RATE
        self.tax = f'{float(self.tax_total):.2f}'
        self.cash = (self.total + self.tax_total + self.tip) - self.discount_total
        self.cash_total = f'{float(self.cash):.2f}'
        self.discount_total = f'{float(self.discount_total):.2f}'

    def print(self):
        print(BUSINESS_NAME)
        print(THICK_HEADER)
        print_lr('Cashier:', self.cashier)
        from datetime import datetime
        print_lr('Date',datetime.now().strftime("%Y-%ym-%d %H:%M:%S"))
        print_lr('Order #',self.order + 1 )
        print(THICK_HEADER)
        print_lr('Description','Amount')
        print(THIN_HEADER)
        print("Coffee")
        print_lr(str(self.coffee_count) + ' items @ 3.50', self.coffee_subtotal)
        print('Bakery')
        print_lr(str(self.bakery_count) + ' items @ 4.00', self.bakery_subtotal)
        print(THIN_HEADER)
        print('Subtotal')
        print_lr('- '+str(self.discount)+'% Discount',self.discount_total )
        print_lr('+ Tax',str(self.tax))
        print_lr('+ Tip', str(self.tip))
        print(THICK_HEADER)
        print_lr('Total','$'+ str(self.cash_total))

    def save_csv(self):
        if not Path('receipts.csv').exists():
            print('Open and add the header.')
        
        with open('receipts.csv', 'a') as f:
            f.write(str(order) + ',')
            from datetime import datetime
            f.write(datetime.now().strftime("%Y-%ym-%d %H:%M:%S") + ',')
            f.write(self.cashier + ',')
            f.write(f'{self.bakery_subtotal:.2f},')
            f.write(f'{self.coffee_subtotal:.2f},')
            f.write(self.discount_total+',')
            f.write(f'{float(self.tax_total):.2f},')
            f.write(str(self.tax) + ',')
            f.write(str(self.cash_total))
            f.write('\n')
   
while True:
    another = input('Print another reciept? (y/n): ')
    if another != 'y': break
    rec = Receipt(cashier)
    rec.bakery_count = int(input('Bakery Items: '))
    rec.coffee_count = int(input('Coffee Items: '))
    rec.discount = int(input('Enter Discount: '))
    rec.tip = int(input('Enter a Tip: '))
    rec.calculate()
    rec.print()
    rec.save_csv()
print('Goodbye!')
