# Participants may update the following function parameters
def maximumExpectedMoney(n,m,p,x,y):
    list = []
    for i in range(n):
        temp = p[i]*x[i] - ((1 - p[i])*y[i])
        list.append(temp)
    list.sort()
    list.reverse()
    return -1

def main():
    # This part may require participants to fill in as well.
    noOfTradesAvailable, maximumTradesAllowed = list(map(int, input().split()))
    p = list(map(float, input().split()))
    x = list(map(float, input().split()))
    y = list(map(float, input().split()))

    # Participants may update the following function parameters
    answer = maximumExpectedMoney(noOfTradesAvailable, maximumTradesAllowed,p,x,y)
    # Do not remove below line
    print(answer)
    # Do not print anything after this line

if __name__ == '__main__':
    main()