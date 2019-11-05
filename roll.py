import sys
import random

point_counter =[0]*7
sum_counter =[0]*19
seg_counter=[0]*2

def roll():
    random.seed()
    sum = 0
    for i in range(0,3):
        r = random.randint(1,6)
        sum += r
        point_counter[r] += 1
    if sum>=4 and sum<=10:
        seg_counter[0] +=1
    if sum>=11 and sum<=17:
        seg_counter[1] +=1
    sum_counter[sum] += 1

if __name__=="__main__":
    if len(sys.argv)<2:
        print("usage roll.py roll_count")
        exit()
    roll_c = int(sys.argv[1])
    print("will roll " + str(roll_c) + " times")
    if roll_c<1:
        exit()
    for i in range(0,roll_c):
        roll()
    for i in range(1,7):
        print("point {0}: {1} {2:.2f}%".format(i, point_counter[i], float(point_counter[i])/(roll_c*3)))
    for i in range(3,19):
        print("sum {0}: {1} {2:.2f}%".format(i, sum_counter[i], float(sum_counter[i])/roll_c))
    print("small 4-10: {0} {1:.2f}%".format(seg_counter[0], float(seg_counter[0])/roll_c))
    print("big 11-17: {0} {1:.2f}%".format(seg_counter[1], float(seg_counter[1])/roll_c))
    
