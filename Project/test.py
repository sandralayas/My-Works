import csv

temp_board=[]
with open('game_stats.csv') as file:
    reader=csv.reader(file)
    for i in (reader):
        if i!=[]:
            temp_board.append(i)
for q in range(9):
    for w in range(9):   
        board[q][w]=int(temp_board[q][w])      