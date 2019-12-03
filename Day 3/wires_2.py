def goThroughWire(wire, crossArr):
    stepCount = 0
    for instruction in wire["wire"]:
        direction = instruction[0]
        length = int(instruction[1:])

        for _ in range(length):
            try:
                pos = wireArr[wire["row"]][wire["col"]]
                if (pos["value"] == (wire["val"] - 1) and pos["value"] != 0):  # crosspoint found
                    totalSteps = pos["steps"] + stepCount
                    crossArr.append([wire["row"], wire["col"], totalSteps])
                elif (pos["value"] == wire["val"]):  # revisiting the old position
                    pass
                else: # new position, write it down
                    wireArr[wire["row"]][wire["col"]] = {
                        "value": wire["val"], "steps": stepCount}
            except IndexError:
                print("ERR: index error: " + str(wire["row"]) + ", " + str(wire["col"]))

            if direction == "R":
                wire["col"] += 1
            elif direction == "U":
                wire["row"] += 1
            elif direction == "L":
                wire["col"] -= 1
            elif direction == "D":
                wire["row"] -= 1
            else:
                print("ERR: invalid direction")
            stepCount += 1

wires = []
with open ("input.txt", 'r') as f:  # get input from file
    for line in f:
        wires.append(line.rstrip().split(','))

firstWire = {"wire": wires[0], "row": 0, "col": 0, "val": 1} 
secondWire = {"wire": wires[1], "row": 0, "col": 0, "val": 2} 

rows = 15000
cols = 15000
# rows = 1000
# cols = 1000

wireArr = [0] * rows
for i in range(rows):
    wireArr[i] = [{"value": 0, "steps": 0}] * cols

crossPoints = []
goThroughWire(firstWire , crossPoints)
goThroughWire(secondWire, crossPoints)

if ([0, 0, 0] in crossPoints):
    crossPoints.remove([0, 0, 0])

for crossPoint in crossPoints:
    print(crossPoint)

distance = 0
if (crossPoints):
    distance = abs(crossPoints[0][0]) + abs(crossPoints[0][1])
for crossPoint in crossPoints:
    row = abs(crossPoint[0])
    col = abs(crossPoint[1])
    if (row + col < abs(distance)):
        distance = row + col
print("Final distance: " +  str(distance))

if (crossPoints):
    steps = crossPoints[0][2]
for crossPoint in crossPoints:
    newSteps = crossPoint[2]
    if (steps > newSteps):
        steps = newSteps
print("Fewest number of steps: " + str(steps))
