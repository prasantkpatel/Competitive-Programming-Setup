def coverage(input1, input2):
    input2.sort()
    ans = 0
    last = -1

    for i in range(0, input1):
        if(last >= input2[i][1]):
            continue
        ans += (input2[i][1] - max(last, input2[i][0]))
        last = input2[i][1]

    print(ans)
    return ans

coverage(2, [[5, 10], [8, 12]])