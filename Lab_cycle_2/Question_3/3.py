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
    print('                              Species  Petal area   Sepal area')
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
        temp=[]
        flowers=[]
        i=0
        for j in the_list:
            temp.append(j.split(','))
            flowers.append(list((temp[i][4],\
                                 round(float(temp[i][2])*float(temp[i][3]),3),\
                                 round(float(temp[i][0])*float(temp[i][1]),3)\
                                 )))
            i+=1
    return flowers

def dictionary_file(list_list):
    flowers_list=[]
    for the_list in list_list:
        the_dict=dict(\
                      Species=the_list[0],\
                      Petals=the_list[1],\
                      Sepals=the_list[2])
        flowers_list.append(the_dict)
    return flowers_list

def find_setosa():
    print('\n The flowers of setosa species')
    setosa_list=[]
    for flower in listing_file():
        if flower[0]=='"setosa"':
            setosa_list.append(flower)
    print('\n Species  Petal area   Sepal area\n')
    for flower in setosa_list:print(flower)

def min_petal():
    temp=listing_file()
    species=[temp[0][0],temp[1][0]]
    for flower in listing_file():
        species.append(flower[0])
    the_set=set(species)
    for i in the_set:
        print('\n Species : ',i)
        petal_list=[]
        sepal_list=[]
        for flower in listing_file():
            if flower[0]==i:
                petal_list.append(float(flower[1]))
                sepal_list.append(float(flower[2]))
        print('\n The minimum petal area : ',min(petal_list))
        print(' The maximum sepal area : ',max(sepal_list))

def sorting_area():
    check_list1=[]
    check_list2=[]
    area_list=[]
    
    for flower in listing_file():
        area_list.append([flower[0],float(flower[1])+float(flower[2])])
    
    for flower in area_list:
        check_list1.append(flower[1])
    check_list1.sort()
    
    for i in check_list1:
        for flower in area_list:
            if i==flower[1]:
                for flowers in listing_file():
                    if flowers[0]==flower[0]: 
                        check_list2.append([flowers[0],flowers[1],flowers[2]])
                        area_list.remove(flower);break
    '''
    flowers=[]
    for i in check_list2:
        for flower in listing_file():
            if i==flower[0]:
                flowers.append(flower)
                del flower;break'''
    print('\n The dictionaries : \n');[print(x) for x in dictionary_file(check_list2)]

############################################################################

count=0
while(True):
    count+=1
    #if count==1:create_file()
    print('''

    0. Exit the program
    1. Show the file
    2. Print the list of lines
    3. Print the list of dictionaries
    4. Setosa species
    5. Minimum petal area and max sepal area in each species
    6. Sorted list of dictionaries
    ''')
    choice=input('\n Enter your choice : ')
    if choice=='0':break
    elif choice=='1':read_file()
    elif choice=='2':print('\n The list of contents in file " iris.json "\n',listing_file())
    elif choice=='3':print('\n The dictionaries : \n');[print(x) for x in dictionary_file(listing_file())]
    elif choice=='4':find_setosa()
    elif choice=='5':min_petal()
    elif choice=='6':sorting_area()
    else:print('\n Wrong opt \n')
