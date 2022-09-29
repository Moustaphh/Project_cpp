

SUPP=rm

EXEC=main

ARCHIVE=Repertoire.zip

SRC_DIR=src
OBJ_DIR=obj
HEAD_DIR=includes
CREATE_OBJ=mkdir $(OBJ_DIR)
SRC=$(wildcard $(SRC_DIR)/*.cpp)

OBJ=$(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp makeobjdir
	g++ -o $@ -c $<


$(EXEC):$(OBJ)
	g++ -o $(EXEC) $^


zip:
	tar -cvzf $(ARCHIVE) *.cpp *.h *.txt


clean:
	$(SUPP) -r $(OBJ_DIR)


mrproper: clean
	$(SUPP) -f $(EXEC)

makeobjdir:
	$(CREATE_OBJ)
