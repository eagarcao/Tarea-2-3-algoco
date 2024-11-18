
for caso in range(2):
    fileBF = open("ResultadosBF-P"+str(caso+1)+".csv", 'r')
    fileDP = open("ResultadosDP-P"+str(caso+1)+".csv", 'r')

    fileR = open("PruebasT2-3-P"+str(caso+1)+".csv", "w")

    line1 = "Caso;Tiempo BF;Tiempo DP\n"

    fileR.write(line1)

    tiempoCasos = []

    i = 0
    acumuladoBF = 0
    acumuladoDP = 0
    fileBF.readline()
    fileDP.readline()
    while i < (85 + (15*caso)):
        j = 0
        acumuladoBF = 0
        acumuladoDP = 0
        while j < 10:
            lineDP = fileDP.readline().strip().split(";")
            lineBF = fileBF.readline().strip().split(";")
            
            acumuladoBF += int(lineBF[3])
            acumuladoDP += int(lineDP[3])
            j += 1
        fileR.write(lineBF[0] + ";" + str(acumuladoBF/10) + ";" + str(acumuladoDP/10) + "\n")
        i += 1
    fileBF.close()
    fileDP.close()
    fileR.close()
    