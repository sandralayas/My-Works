
# The Sudoku solver by backtracking

# THIS IS NOT IN SYNC WITH THE ALGORITHM

board=[\
[0,0,8,0,0,7,1,0,0],\
[0,0,0,8,0,0,0,4,0],\
[5,0,6,1,0,0,3,0,0],\
[0,0,3,0,0,4,0,0,9],\
[7,0,0,0,0,0,0,0,3],\
[9,0,0,7,0,0,4,0,0],\
[0,0,1,0,0,2,6,0,5],\
[0,6,0,0,0,8,0,0,0],\
[0,0,2,3,0,0,8,0,0]\
]

def vaild(board,num,index):

	length=len(board)
	
	row=index[0];column=index[1]
	
	# Row
	for each in range(length):
		if each==row:pass
		else:
			if board[row][each]==num:return False
	# Column
	for each in range(length):
		if each==column:pass
		else:
			if board[each][column]==num:return False
	# Square
	
	horizondal=row//3
	vertical=column//3
	
	for each_row in range((horizondal*3),(horizondal*3)+3):
		for each_column in range((vertical*3),(vertical*3)+3):
			if each_row==row and each_column==column:pass
			else:
				if board[each_row][each_column]==num:return False
	return True
			
def display(board):
	length=len(board)
	for each_row in range(length):
		if each_row%3==0:print(' ___________________________')
		for each_column in range(length):
			if each_column%3==0:print(' |',end=' ')
			print(board[each_row][each_column],end=' ')
			if each_column==length-1:print('\n')
	print(' ___________________________')

## Main Program
	
length=len(board)

display(board)
