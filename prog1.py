#program to print current month calendar
from datetime import datetime

def getYear():
    #return year in integer
    return int(datetime.now().year)

def checkLeap(year):
    #checks if year is leap or not
    leap = False
    if(year % 4 == 0 and year % 100 != 0):
        leap = True
        if(year % 400 == 0):
            leap = True

    return leap

def getMonth():
    #return month number and name
    months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December']
    return int(datetime.now().month), months[int(datetime.now().month)-1]

def getDays(year, month):
    #get number of days in that month
    monthDays = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    if(month == 1):
        checkleap(year)
        return 29
    
    return int(monthDays[month])

def startDay(year, month, day):
    #monthDay = getDays(year, month)
    a = (14 - month) // 12
    y = year - a
    m = month + (12 * a) - 2
    return int(( y + y//4 - y//100 + y//400 + ((31*m)/12) + day) % 7)

month, monthName = getMonth()
year = getYear()
days = getDays(year, month-1)
current = startDay(year, month, 1)

print(" -----------------" + monthName + "--------------")
print("  Sun  Mon  Tue  Wed  Thu  Fri  Sat")

for k in range(current):
    print("     ", end='')
k = current

for j in range(days):
    print("{0:5d}".format(j+1), end='')
    k+=1
    if(k > 6):
        k = 0
        print("\n")
print("")
