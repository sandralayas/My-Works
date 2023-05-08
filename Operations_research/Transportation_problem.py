
rownum = int( input ("Enter the number of rows : ") )

colnum = int( input ("Enter the number of columns : ") )

grid = list()
row = list()
supply = list()
demand = list()


for i in range (rownum):
    print("Enter row "+str(i+1))
    for j in range(colnum):
        row.append( int(input ("\n")))
    grid.append( row )
    row = []

print("Enter the supply row")   
for i in range(rownum):
    supply[i] = int(input ("\n"))

print("Enter the demand row")
for i in range(colnum):
    demand[i] = int(input("\n"))

#grid = [[3, 1, 7, 4], [2, 6, 5, 9], [8, 3, 3, 2]]  # table
#supply = [300, 400, 500]  # supply
#demand = [250, 350, 400, 200]  # demand
INF = 10**rownum
n = len(grid)
m = len(grid[0])
ans = 0

def findDiff(grid):
    rowDiff = []
    colDiff = []
    for i in range(len(grid)):
        arr = grid[i][:]
        arr.sort()
        rowDiff.append(arr[1]-arr[0])
    col = 0
    while col < len(grid[0]):
        arr = []
        for i in range(len(grid)):
            arr.append(grid[i][col])
        arr.sort()
        col += 1
        colDiff.append(arr[1]-arr[0])
    return rowDiff, colDiff
 
while max(supply) != 0 or max(demand) != 0:

    row, col = findDiff(grid)

    maxi1 = max(row)

    maxi2 = max(col)
 
    if(maxi1 >= maxi2):
        for ind, val in enumerate(row):
            if(val == maxi1):

                mini1 = min(grid[ind])
                for ind2, val2 in enumerate(grid[ind]):
                    if(val2 == mini1):
                        
                        mini2 = min(supply[ind], demand[ind2])
                        ans += mini2 * mini1
                        supply[ind] -= mini2
                        demand[ind2] -= mini2

                        if(demand[ind2] == 0):
                            for r in range(n):
                                grid[r][ind2] = INF

                        else:
                            grid[ind] = [INF for i in range(m)]
                        break
                break

    else:
        for ind, val in enumerate(col):
            if(val == maxi2):

                mini1 = INF
                for j in range(n):
                    mini1 = min(mini1, grid[j][ind])
 
                for ind2 in range(n):
                    val2 = grid[ind2][ind]
                    if val2 == mini1:

                        mini2 = min(supply[ind2], demand[ind])
                        ans += mini2 * mini1

                        supply[ind2] -= mini2
                        demand[ind] -= mini2

                        if(demand[ind] == 0):
                            for r in range(n):
                                grid[r][ind] = INF

                            else:
                                grid[ind2] = [INF for i in range(m)]
                        break
                break
 
print("The basic feasible solution is ", ans)
