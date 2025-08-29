'''Design a class to store the details of a vehicle such as engine number,
model, type, mileage, vendor, registration number, and owner name.
Design another class that holds the details of several vehicles and
provide functions to
• Display the details of the collection
• Sort the collection according to mileage
• Add, Delete and Modify the entries from the collection
• Store and Load the collection as a pickle file
• Filter the result according to the attributes and export it as a
report.'''

import pickle

class Vehicle:
    def __init__(vehicle,engine_number,model,vehicle_type,mileage,vendor,registration_number,owner_name):
        vehicle.engine_number=engine_number
        vehicle.model=model
        vehicle.vehicle_type=vehicle_type
        vehicle.mileage=mileage
        vehicle.vendor=vendor
        vehicle.registration_number=registration_number
        vehicle.owner_name=owner_name

    def display(vehicle):
        print('\n---------------------------------------------------------------------')
        print('\n Engine_number : ',vehicle.engine_number,\
              '\n Model : ',vehicle.model,\
              '\n Vehicle_type : ',vehicle.vehicle_type,\
              '\n Mileaget : ',vehicle.mileage,\
              '\n Vendor : ',vehicle.vendor,\
              '\n Registration_number : ',vehicle.registration_number,\
              '\n Owner_name : ',vehicle.owner_name)
        print('\n---------------------------------------------------------------------')

    def give_engine_number(vehicle):
        return vehicle.engine_number

    def give_milage(vehicle):
        return vehicle.mileage

def sort_milage(vehicles):
    milage_list=[]
    sorted_list=[]
    for vehicle in vehicles:
        milage_list.append(vehicle.give_milage())
        milage_list=sorted(milage_list)
    for milage in milage_list:
        for vehicle in vehicles:
            if vehicle.give_milage()==milage:
                sorted_list.append(vehicle)
    for vehicle in sorted_list:
        vehicle.display()

class Vehicles:
 
    def __init__(vehicles):
        vehicles.list=[]

    def add_to_list(vehicles,vehicle):
        vehicles.list.append(vehicle)

    def give_list(vehicles):
        return vehicles.list

    def enter_data(vehicles):
        with open('vehicle_data','ab') as file:
            pickle.dump(vehicles.list,file)

    def display_data(vehicles):
        with open('vehicle_data','rb') as file:
            data=pickle.load(file)
            for vehicle in data:
                vehicle.display()

def input_details():
    engine_number=int(input('\n Enter the engine_number : '))
    model=input(' Enter the model : ')
    vehicle_type=input(' Enter the vehicle_type : ')
    mileage=float(input(' Enter the mileage : '))
    vendor=input(' Enter the vendor : ')
    registration_number=int(input(' Enter the registration_number : '))
    owner_name=input(' Enter the owner_name : ')
    
    vehicle=Vehicle(engine_number,model,vehicle_type,mileage,vendor,registration_number,owner_name)
    return vehicle

## MAIN PROGRAM

first=True

while(True):
    
    print('''
    0. Exit program
    1. Enter the details of a vehicle
    2. Output the details of a vehicle
    3. Sort the vehicles according to milage
    4. Delete the details of a vehicle
    5. Modify the details of a vehicle
    6. Store and load the data
    7. Export as a report
    ''')
    choice=input('\n Enter your choice : ')
    if first:
        vehicle=Vehicle(0,0,0,0,0,0,0)
        vehicles=Vehicles()
        first=False
    
    if choice=='0':break
    elif choice=='1':
        vehicle=input_details()
        vehicles.add_to_list(vehicle)

    elif choice=='2':
        engine_number=int(input('\n Enter the engine_number : '))
        found=False
        for vehicle in vehicles.give_list():
            if vehicle.give_engine_number()==engine_number:
                vehicle.display()
                found=True
        if not found:print('\n The vehicle does not exist')
        
    elif choice=='3':
        sort_milage(vehicles.give_list())

    elif choice=='4':
        engine_number=int(input('\n Enter the engine_number : '))
        found=False
#deleting everything and entering a new one
        old_list=vehicles.give_list()
        vehicles=Vehicles()
        for vehicle in old_list:
            if vehicle.give_engine_number()==engine_number:found=True
            else:vehicles.add_to_list(vehicle)
            
        if found:print('\n The vehicle has been deleted')
        else:print('\n The vehicle does not exist')

    elif choice=='5':
        engine_number=int(input('\n Enter the engine_number : '))
        found=False
#deleting everything and entering a new one
        old_list=vehicles.give_list()
        vehicles=Vehicles()
        for vehicle in old_list:
            if vehicle.give_engine_number()!=engine_number:
                vehicles.add_to_list(vehicle)
            else:
                found=True
                print('\n Enter the new details')
                vehicle=input_details()
                vehicles.add_to_list(vehicle)
                
        if found:print('\n The vehicle has been modified')
        else:print('\n The vehicle does not exist')

    elif choice=='6':vehicles.enter_data()

    elif choice=='7':vehicles.display_data()
        
    else:print('\n Wrong opt \n')

    
