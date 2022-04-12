'''Read the file 'iris.json' as a text file :
1. Create a list having each line of the file as an element
2. Convert it into a list of dictionary objects.
3. Show the details of all flowers whose species is "setosa".
4. Print the minimum petal area and max sepal area in each species
5. Sort the list of dictionaries according to the total area are sepal and petal.
'''

import json

def read_file():
	print('\n The current contents in file " iris.json "\n')
	with open('_iris.json','r') as file:
		the_file=file.read()
		print(the_file)

def listing_file():
	list_list=[]
	the_file=dictionary_file()
	for dictionary in the_file:
		list_list.append([\
dictionary['species'],\
dictionary['petalLength'],\
dictionary['petalWidth'],\
dictionary['sepalLength'],\
dictionary['sepalWidth'],\
])
	return list_list

def dictionary_file():
  with open('_iris.json','r') as file:
    the_file=json.load(file)
  return the_file

def find_setosa():
	print('\n The flowers of setosa species\n')
	print('\n Species \t\t Petal length \t Petal width \t Sepal length \t Sepal width\n')
	for flower in dictionary_file():
		if flower['species']=='setosa':
			print('',end=' ')
			dictionary(flower)

def petal_sepal_list():
	petal_areas=[[flower['species'],flower['petalLength']*flower['petalWidth']]\
  for flower in dictionary_file()]
	sepal_areas=[[flower['species'],flower['sepalLength']*flower['sepalWidth']]\
  for flower in dictionary_file()]
	return petal_areas,sepal_areas

def min_petal():
	petal_areas,sepal_areas=petal_sepal_list()
	mini=min([area for species,area in petal_areas if species=='setosa'])
	maxi=max([area for species,area in petal_areas if species=='setosa'])
	print('\n Setosa')
	print('\n The minimum petal area : ',mini)
	print(' The maximum sepal area : ',maxi)

	mini = min([area for species,area in petal_areas if species=='versicolor'])
	maxi=max([area for species,area in petal_areas if species=='versicolor'])
	print('\n Versicolor')
	print('\n The minimum petal area : ',mini)
	print(' The maximum sepal area : ',maxi)

	mini = min([area for species,area in petal_areas if species=='virginica'])
	maxi=max([area for species,area in petal_areas if species=='virginica'])
	print('\n Virginica')
	print('\n The minimum petal area : ',mini)
	print(' The maximum sepal area : ',maxi)

def call_area(total_area):return total_area[1]

def sorting_area():
	petal_areas,sepal_areas=petal_sepal_list()
	total_area=[]
	for i in range(len(petal_areas)):
		total_area.append([petal_areas[i][0],petal_areas[i][1]+sepal_areas[i][1]])
	
	total_area.sort(key=call_area) 

	check_list=dictionary_file()
	print('\n Total area \tSpecies \t Petal length \t Petal width \t Sepal length \t Sepal width\n')
	for details in total_area:
		for flower in check_list:
			if flower['species']==details[0]:
				print('',round(details[1],2),'\t\t',end='')
				dictionary(flower)
				check_list.remove(flower)

def dictionary(flower):
	if len(flower['species'])>6:tab='\t'
	else:tab='\t\t'
	print(\
flower['species'],tab,\
flower['petalLength'],'\t\t',\
flower['petalWidth'],'\t\t',\
flower['sepalLength'],'\t\t',\
flower['sepalWidth'])

while(True):
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
    elif choice=='2':print('\n The list of contents in file " iris.json "\n');\
																							[print(x) for x in listing_file()]
    elif choice=='3':print('\n The dictionaries : \n');\
																							[dictionary(x) for x in dictionary_file()]
    elif choice=='4':find_setosa()
    elif choice=='5':min_petal()
    elif choice=='6':sorting_area()
    else:print('\n Wrong opt \n')

'''
def listing_file():
  with open('_iris.json','r') as file:
    the_file=file.readlines()
  return the_file
'''
