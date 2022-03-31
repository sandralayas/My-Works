'''Suppose a newly born pair of males, one male and one female, are  put in a field. males can mate
at the age of one month so that at the  end of its second month, a female has produced another pair of  males.
Suppose that our males never die and that the female always  produces one new pair every month from the second month.
Develop a program to show a table containing the number of pairs of  males in the first N months.
'''


def multiplication(pre_pairs,new_pairs):
    temp=new_pairs
    new_pairs=pre_pairs+new_pairs
    pre_pairs=temp
    return pre_pairs,new_pairs

def formatting(number):
    if number//10==0:return        '          '+str(number)
    elif number//100==0:return    '        '+str(number)
    elif number//1000==0:return    '      '+str(number)
    elif number//10000==0:return    '    '+str(number)
    elif number//100000==0:return  '    '+str(number)
    else:return str(number)

months=int(input(' Enter the number of months  : '))
print('\n Months                    |  Pairs\n')

pre_pairs=1
new_pairs=1

for i in range(1,months+1):
    
    print(' Month ',formatting(i),'     |  ',formatting(pre_pairs))
    pre_pairs,new_pairs=multiplication(pre_pairs,new_pairs)


    




    
