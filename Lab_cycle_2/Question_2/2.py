'''Write a program to read a string containing numbers separated by a
space and convert it as a list of integers. Perform the following
operations on it.
1. Rotate elements in a list by 'k' position to the right
2. Convert the list into a tuple using list comprehension
3. Remove all duplicates from the tuple and convert them
into a list again.
4. Create another list by putting the results of the evaluation
of the function f(x) = x 2 – x with each element in the
final list
5. After sorting them individually, merge the two lists to
create a single sorted list.'''

def read_string():
    string=input('\n Enter the string : ')
    the_list=string.split()
    the_list=[int(ele) for ele in the_list]
    print('\n The list of strings : ',the_list)
    return the_list

def rotate_elements(the_list):
    index=int(input('\n Enter the position by which it should be rotated to the right : '))
    new_list=the_list[index:]+the_list[:index]
    print('\n The list rotated of strings : ',new_list)

def create_tuple(the_list):
    the_tuple=tuple(the_list)
    print('\n The tuple of string is : ',the_tuple)

def funtion_result(the_list):
    result_list=[f(ele) for ele in the_list]
    return removing_dupes(result_list)

def removing_dupes(the_list):
    the_set=set(the_list)
    the_list=list(the_set)
    the_list.sort()
    return the_list

def f(x):return x*x-x

count=0
while(True):
    count+=1
    if count==1:the_list=read_string()
    print('''

    0. Exit the program
    1. Enter new string
    2. Rotate elements
    3. Print the tuple
    4. Remove duplicates
    5. Results of evaluation of f(x) = x 2 – x 
    6. Merge and sort
    ''')
    choice=input('\n Enter your choice : ')
    if choice=='0':break
    elif choice=='1':the_list=read_string()
    elif choice=='2':rotate_elements(the_list)
    elif choice=='3':create_tuple(the_list)
    elif choice=='4':print('\n The list without duplicates : ',removing_dupes(the_list))
    elif choice=='5':print('\n The result list : ',funtion_result(the_list))
    elif choice=='6':print('\n The single sorted list : ',removing_dupes(the_list+funtion_result(the_list)))
    else:print('\n Wrong opt \n')
