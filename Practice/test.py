days = ["sun", "mon", "tue", "wed", "thu", "fri", "sat"]
avgtemp = []
readings = []

# Input temperatures
for i in range(2):
    tempsum=0
    readings.append([])  # create a new list for each day
    for j in range(3):
        temp = float(input(f"Input temperature for {days[i]} at hour {j+1}: "))
        readings[i].append(temp)
        tempsum=tempsum+temp

    avgofday=tempsum/3
    avgtemp.append(avgofday)

# Print temperatures
for i in range(len(avgtemp)):
    print(avgtemp[i])
