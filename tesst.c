  strcpy(inst,TI.tab_instrus[instruction].inst);
        if (strcmp(inst, "ADD") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1] + tab_int[TI.tab_instrus[instruction].addr2];

        else if (strcmp(inst, "SUB") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1] - tab_int[TI.tab_instrus[instruction].addr2];

        else if (strcmp(inst, "MUL") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1] * tab_int[TI.tab_instrus[instruction].addr2];

        else if (strcmp(inst, "DIV") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1] / tab_int[TI.tab_instrus[instruction].addr2];
        
        else if (strcmp(inst, "AFC") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = TI.tab_instrus[instruction].addr1;

        else if (strcmp(inst, "COP") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1];

        else if (strcmp(inst, "EQU") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1] == tab_int[TI.tab_instrus[instruction].addr2];
        
        else if (strcmp(inst, "NE") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1] != tab_int[TI.tab_instrus[instruction].addr2];
            
        else if (strcmp(inst, "GT") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1] > tab_int[TI.tab_instrus[instruction].addr2];
        
        else if (strcmp(inst, "LT") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1] < tab_int[TI.tab_instrus[instruction].addr2];
            
        else if (strcmp(inst, "GE") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1] >= tab_int[TI.tab_instrus[instruction].addr2];
        
        else if (strcmp(inst, "LE") == 0) tab_int[TI.tab_instrus[instruction].addr_dest] = tab_int[TI.tab_instrus[instruction].addr1] <= tab_int[TI.tab_instrus[instruction].addr2];
        
        else if (strcmp(inst, "JMPF") == 0){
            if (!tab_int[TI.tab_instrus[instruction].addr_dest]){
                instruction = TI.tab_instrus[instruction].addr1 - 1;
                instruction--;
            }
        }

        else if (strcmp(inst, "JMP") == 0){
            instruction = TI.tab_instrus[instruction].addr_dest - 1;
            instruction--;
        }

        else if (strcmp(inst, "PRI") == 0){
            printf("%d\n", tab_int[TI.tab_instrus[instruction].addr_dest]);
        }
        instruction++;
    }
}

