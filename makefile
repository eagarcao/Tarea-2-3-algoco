SRCS_BF = FuerzaBruta.cpp operaciones.cpp
SRCS_DP = ProgramacionDinamica.cpp operaciones.cpp

TARGET_BF = fuerza_bruta
TARGET_DP = programacion_dinamica

all: $(TARGET_BF) $(TARGET_DP)

$(TARGET_BF): $(SRCS_BF)
	g++ -Wall -o $(TARGET_BF) $(SRCS_BF)

$(TARGET_DP): $(SRCS_DP)
	g++ -Wall -o $(TARGET_DP) $(SRCS_DP)

clean:
	rm -f $(TARGET_BF) $(TARGET_DP)