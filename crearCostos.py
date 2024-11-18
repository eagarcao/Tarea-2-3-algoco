files = ["cost_delete.txt", "cost_replace.txt", "cost_insert.txt", "cost_transpose.txt"]

costo_del = (input("del : "))
costo_ins = (input("ins : "))
costo_rep = (input("rep : "))
costo_trans = (input("trans : "))

costosMatriz = [costo_rep, costo_trans]
costosTabla = [costo_del, costo_ins]

tamaño = 26
a = 0
for filename in files:
    file = open(filename, 'w')
    if filename == "cost_delete.txt" or filename == "cost_insert.txt":
        line = ''
        for i in range(0, tamaño):
            line += costosTabla[a] + ' '   
        file.write(line)    
    else:
        for i in range(0, tamaño):
            line = ''
            for j in range(0, tamaño):
                if i == j:
                    line += '0 '
                else:
                    line += costosMatriz[a] + ' '
            file.write(line + '\n')
        a += 1
    
    file.close()
    