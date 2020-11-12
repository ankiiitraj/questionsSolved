# Participants may update the following function parameters
def maximumExpectedMoney(n,m,p,x,y):
    arr = []
    for i in range(0, n):
        temp = p[i]*x[i] - ((1 - p[i])*y[i])
        arr.append(temp)

    arr.sort()
    arr.reverse()
    res = 0.00
    for i in range(m):
    	if arr[i] < 0:
    		break
    	res = res + arr[i]

    return res

def main():
    # This part may require participants to fill in as well.
    noOfTradesAvailable, maximumTradesAllowed = list(map(int, input().split()))
    p = list(map(float, input().split()))
    x = list(map(float, input().split()))
    y = list(map(float, input().split()))

    # Participants may update the following function parameters
    answer = maximumExpectedMoney(noOfTradesAvailable, maximumTradesAllowed,p,x,y)
    # Do not remove below line
    print("%.2f"%answer)
    # Do not print anything after this line

# if __name__ == '__main__':
main()