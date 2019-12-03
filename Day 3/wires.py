def goThroughWire(wire, crossArr):
    for instruction in wire["wire"]:
        direction = instruction[0]
        length = instruction[1:]

        for i in range(int(length)):
            try:
                pos = wireArr[wire["row"]][wire["col"]]
                if (pos == wire["val"] - 1 and pos != 0):
                    crossArr.append([wire["row"], wire["col"]])
                wireArr[wire["row"]][wire["col"]] = wire["val"]
            except IndexError:
                print("Index error: " + str(wire["row"]) + ", " + str(wire["col"]))

            if direction == "R":
                wire["col"] -= 1
            elif direction == "U":
                wire["row"] -= 1
            elif direction == "L":
                wire["col"] += 1
            elif direction == "D":
                wire["row"] += 1
            else:
                print("ERR: invalid direction")

wires = []
f = open("input.txt", 'r')
for line in f:
    wires.append(line.rstrip().split(','))
f.close()

firstWire = {"wire": wires[0], "row": 0, "col": 0, "val": 1} 
secondWire = {"wire": wires[1], "row": 0, "col": 0, "val": 2} 

rows = 10000
cols = 12000
# rows = 1000
# cols = 1000

wireArr = [0] * rows
for i in range(rows):
    wireArr[i] = [0] * cols
crossPoints = []

goThroughWire(firstWire , crossPoints)
goThroughWire(secondWire, crossPoints)

if ([0, 0] in crossPoints):
    crossPoints.remove([0, 0])
print(crossPoints)

distance = 0
if (crossPoints):
    distance = abs(crossPoints[0][0]) + abs(crossPoints[0][1])
for crossPoint in crossPoints:
    row = abs(crossPoint[0])
    col = abs(crossPoint[1])

    if (row + col < abs(distance)):
        distance = row + col

print("Final distance: " +  str(distance))





