'''Read the file 'iris.json' as a text file :
1. Create a list having each line of the file as an element
2. Convert it into a list of dictionary objects.
3. Show the details of all flowers whose species is
"setosa".
4. Print the minimum petal area and max sepal area in
each species
5. Sort the list of dictionaries according to the total area
are sepal and petal.'''

def create_file():
    num=int(input('\n Enter the number of lines : '))
    lines=''
    print('                             Name  Species  Petal area   Sepal area')
    for i in range(num):
        lines+=input('\n Enter details '+str(i+1)+' : ')+'\n'
    with open('iris.json','w') as file:
        file.write(lines)
    print('\n File created')

def read_file():
    print('\n The current contents in file " iris.json "\n')
    with open('iris.json','r') as file:
        the_file=file.read()
        print(the_file)

def listing_file():
    with open('iris.json','r') as file:
        the_file=file.read()
        the_list=the_file.split('\n')
        the_list.pop()
        flowers=[]
        for i  in the_list:
            flowers.append(i.split())
    return flowers

def dictionary_file(list_list):
    flowers_list=[]
    for the_list in list_list:
        the_dict=dict(Name=the_list[0],\
                      Species=the_list[1],\
                      Petals=the_list[2],\
                      Sepals=the_list[3])
        flowers_list.append(the_dict)
    return flowers_list

def find_setosa():
    print('\n The flowers of setosa species')
    setosa_list=[]
    for flower in listing_file():
        if flower[1]=='setosa':
            setosa_list.append(flower)
    print('\n Name  Species  Petal area   Sepal area\n')
    for flower in setosa_list:print(flower)

def min_petal():
    petal_list=[]
    sepal_list=[]
    species=[]
    for flower in listing_file():
        species.append(flower[1])
    the_set=set(species)
    for i in the_set:
        print('\n Species : ',i)
        for flower in listing_file():
            if flower[1]==i:
                petal_list.append(int(flower[2]))
                sepal_list.append(int(flower[3]))
        print('\n The minimum petal area : ',min(petal_list))
        print(' The maximum sepal area : ',max(sepal_list))

def sorting_area():
    check_list1=[]
    check_list2=[]
    area_list=[]
    
    for flower in listing_file():
        area_list.append([flower[0],int(flower[2])+int(flower[3])])
    
    for flower in area_list:
        check_list1.append(int(flower[1]))
    check_list1.sort()
    
    for i in check_list1:
        for flower in area_list:
            if i==flower[1]:check_list2.append(flower[0])
    
    print()
    flowers=[]
    for i in check_list2:
        for flower in listing_file():
            if i==flower[0]:flowers.append(flower)
    print('\n The dictionaries : \n');[print(x) for x in dictionary_file(flowers)]

############################################################################

count=0
while(True):
    count+=1
    if count==1:create_file()
    print('''

    0. Exit the program
    1. Enter new file
    2. Show the file
    3. Print the list of lines
    4. Print the list of dictionaries
    5. Setosa species
    6. Minimum petal area and max sepal area in each species
    7. Sorted list of dictionaries
    ''')
    choice=input('\n Enter your choice : ')
    if choice=='0':break
    elif choice=='1':create_file()
    elif choice=='2':read_file()
    elif choice=='3':print('\n The list of contents in file " iris.json "\n',listing_file())
    elif choice=='4':print('\n The dictionaries : \n');[print(x) for x in dictionary_file(listing_file())]
    elif choice=='5':find_setosa()
    elif choice=='6':min_petal()
    elif choice=='7':sorting_area()
    else:print('\n Wrong opt \n')
