#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "../Strings/Strings.h"

// Code form Veeloxfire =====
typedef enum RegisterError {
  Reg_Ok = 0,
  Reg_InvalidName,
  Reg_InvalidPrefix
} RegisterError;

RegisterError validateRegister(char *name, const char** out_message) {
   int len = strlen(name);
   if (len < 2) {
      *out_message = "Invalid Register name";
      return Reg_InvalidName;
   }
   if (name[0] != '$' && name[0] != '#') {
      *out_message = "Invalid Register Prefix";
      return Reg_InvalidPrefix;
   }
   *out_message = "Ok";
   return Reg_Ok;
}
// Code from Veeloxfire ====

int argsLen(char **args) {
   int len = 0;
   for (;;) {
      if (strcmp(args[len], "\0") == 0)
         break;
      len += 1;
   }
   return len;
}

int isInteger(char *str) {
   char *endptr;
   strtol(str, &endptr, 10);
   return strcmp(endptr, "");
}

int checkAll3Registers(char **args, int line) {
   int errors = 0;
   for (int i = 1; i <= 3; i++) { 
      const char *result = NULL;
      RegisterError err = validateRegister(args[i], &result);
      if(err != Reg_Ok) {
         char *full_command = arrayToString(args);
         printf("Line %d - \"%s\"\n", line, full_command);
         printf(" - %dº arg - %s, %s\n", i, result, args[i]);
         errors += 1;
         free(full_command);
      }
   }
   return errors;
}

int check2Registers(char **args, int line) {
   int errors = 0;
   const char *result = NULL;

   char *reg1 = args[1];
   RegisterError err1 = validateRegister(reg1, &result);
   if(err1 != Reg_Ok) {
      char *full_command = arrayToString(args);
      printf("Line %d - \"%s\"\n", line, full_command);
      printf(" - 1º arg - %s, %s\n", result, reg1);
      free(full_command);
      errors += 1;
   }

   char *reg2 = args[2];
   RegisterError err2 = validateRegister(reg2, &result);
   if(err2 != Reg_Ok) {
      char *full_command = arrayToString(args);
      printf("Line %d - \"%s\"\n", line, full_command);
      printf(" - 2º arg - %s, %s\n", result, reg2);
      free(full_command);
      errors += 1;
   }

   return errors;
}

int check2Registers1Value(char **args, int line) {
   int errors = check2Registers(args, line);

   char *value = args[3];
   if (isInteger(value) != 0) {
      char *full_command = arrayToString(args);
      printf("Line %d - \"%s\"\n", line, full_command);
      printf(" - 3º arg - %s Invalid Integer\n", value);
      free(full_command);
      errors += 1;
   }

   return errors;
}

int check2Registers1Label(char **args, int line) {
   int errors = check2Registers(args, line);

   char *value = args[3];
   if (isInteger(value) == 0) {
      char *full_command = arrayToString(args);
      printf("Line %d - \"%s\"\n", line, full_command);
      printf(" - 3º arg - \"%s\" Invalid Label Name\n", value);
      free(full_command);
      errors += 1;
   }

   return errors;
}

void printArgsLenError(char **args, const char *op, int line, int a1, int a2) {
   char *full_command = arrayToString(args);
   printf("Line %d - \"%s\"\n", line, full_command);
   printf(" - %s gets %d args, total args = %d\n", op, a1, a2);
   free(full_command);
}

/*
 * Sintaxe functions return N if incorrect, and 0 if correct, N is "N error"
 */

// do nothing for 1 cycle 
int nop_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 0) {
      printArgsLenError(args, "nop", line,  0, len);
      return 1;
   } 
   return 0;
}

/*  Instruction ADD
 *
 *  add $t1 $t2 $t3 -> t1 = t2 + t3
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | Frist register to the instruction
 *  @param RegisterName arg2 | Second register to the instruction
 */
int add_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "add", line,  3, len);   
      return 1;
   } 

   return checkAll3Registers(args, line);
}

/*  Instruction ADDI
 *
 *  addi $t1 $t2 100 -> t1 = t2 + 100
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | Frist register to the instruction
 *  @param uint16_t v1 | Value to be add
 */
int addi_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "addi", line,  3, len);   
      return 1;
   } 

   return check2Registers1Value(args, line);
}

/*  Instruction SUB
 *
 *  sub $t1 $t2 $t3 -> t1 = t2 - t3
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | Frist register to the instruction
 *  @param RegisterName arg2 | Second register to the instruction
 */
int sub_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "sub", line,  3, len);   
      return 1;
   } 
   
   return checkAll3Registers(args, line);
}

/*  Instruction SUBI
 *
 *  subi $t1 $t2 100 -> t1 = t2 0 100
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | Frist register to the instruction
 *  @param uint16_t v1 | Value to be subtracted
 */
int subi_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "subi", line,  3, len);   
      return 1;
   } 

   return check2Registers1Value(args, line);
}

/*  Instruction MUT
 *
 *  mut $t1 $t2 $t3 -> t1 = t2 * t3
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | Frist register to the instruction
 *  @param RegisterName arg2 | Second register to the instruction
 */
int mut_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "mut", line,  3, len);   
      return 1;
   } 

   return checkAll3Registers(args, line);
}

/*  Instruction MUTI
 *
 *  muti $t1 $t2 100 -> t1 = t2 * 100
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | Value to be multipled
 *  @param uint16_t v1 | Value to be multiplier
 */
int muti_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "muti", line,  3, len);   
      return 1;
   } 

   return check2Registers1Value(args, line);
}

/*  Instruction DIV
 *
 *  div $t1 $t2 $t3 -> t1 = t2 / t3
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | Frist register to the instruction
 *  @param RegisterName arg2 | Second register to the instruction
 */
int div_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "div", line,  3, len);   
      return 1;
   } 

   return checkAll3Registers(args, line);
}

/*  Instruction DIVI
 *
 *  divi $t1 $t2 100 -> t1 = t2 / 100
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | Value to be divieded
 *  @param uint16_t v1 | Value to be divider
 */
int divi_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "divi", line,  3, len);   
      return 1;
   } 

   return check2Registers1Value(args, line);
}

/*  Instruction AND
 * 
 *  and $t1 $t2 $t3 -> t1 = t2 $ t3
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | Frist register to the instruction
 *  @param RegisterName arg2 | Second register to the instruction
 */
int and_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "and", line,  3, len);   
      return 1;
   } 
   
   return checkAll3Registers(args, line);
}

/*  Instruction OR
 * 
 *  or $t1 $t2 $t3 -> t1 = t2 | t3
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | Frist register to the instruction
 *  @param RegisterName arg2 | Second register to the instruction
 */
int or_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "or", line,  3, len);   
      return 1;
   } 

   return checkAll3Registers(args, line);
}

/*  Instruction SL (shift left)
 * 
 *  sl $t1 $t2 2 -> t1 = t2 << 2
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | The value to be shifted
 *  @param uint16_t times | Times to sift
 */
int sl_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "sl", line,  3, len);   
      return 1;
   } 
   
   return check2Registers1Value(args, line);
}

/*  Instruction SR (shift right)
 * 
 *  sr $t1 $t2 2 -> t1 = t2 >> 2
 *  @param RegisterName alvo | Register where the result will be stored
 *  @param RegisterName arg1 | The value to be shifted
 *  @param uint16_t times | Times to sift
 */
int sr_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "sr", line,  3, len);   
      return 1;
   } 

   return check2Registers1Value(args, line);
}

/*  Instruction MOV (move)
 * 
 *  mov $t1 $t2 -> t1 = t2
 *  @param RegisterName alvo | Register where the value will be moved
 *  @param RegisterName arg1 | Value to be moved
 */
int mov_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 2) {
      printArgsLenError(args, "mov", line,  2, len);   
      return 1;
   } 

   return check2Registers(args, line);
}

/*  Instruction J (jump)
 * 
 *  jump _start -> move the programmer counter to _start
 *  @param JumpPoint point | The point to be jumped
 */
int jump_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 1) {
      printArgsLenError(args, "jump", line, 1, len);   
      return 1;
   } 

   if (isInteger(args[1]) == 0) {
      char *full_command = arrayToString(args);
      printf("Line %d - \"%s\"\n", line, full_command);
      printf(" - Invalid label name '%s'\n", args[1]);
      free(full_command);
      return 1;
   }

   return 0;
}

/*  Instruction JAL (jump and link)
 * 
 *  jal _sum -> move the programmer counter to _sum, and saves the current PC on $ra
 *  @param JumpPoint point | The point to be jumped
 */
int jal_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 1) {
      printArgsLenError(args, "jal", line, 1, len);   
      return 1;
   } 

   if (isInteger(args[1]) == 0) {
      char *full_command = arrayToString(args);
      printf("Line %d - \"%s\"\n", line, full_command);
      printf(" - Invalid label name '%s'\n", args[1]);
      free(full_command);
      return 1;
   }

   return 0;
}

/*  Instruction JR (jump to register)
 * 
 *  jr $ra -> move the programmer counter to point saved on the register
 *  @param RegisterName point | The point to be jumped
 */
int jr_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 1) {
      printArgsLenError(args, "jr", line, 1, len);   
      return 1;
   } 

   const char *result = NULL;
   RegisterError err = validateRegister(args[1], &result);
   if(err != Reg_Ok) {  
      char *full_command = arrayToString(args);
      printf("Line %d - \"%s\"\n", line, full_command);
      printf(" - 1º arg - %s, %s\n", result, args[1]);
      free(full_command);
      return 1;
   }


   return 0; 
}

/*  Instruction SLT (set on less than)
 * 
 *  slt $t1 $t2 $t3 -> if (t2<t3) t1=1 else t1=0
 *  @param RegisterName alvor | Register where the result will be stored
 *  @param RegisterName arg1 | frist value on the comparison
 *  @param RegisterName arg2 | second value on the comparison
 */
int slt_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "slt", line, 3, len);   
      return 1;
   } 

   return checkAll3Registers(args, line);
}

/*  Instruction SLTI (set on less than)
 * 
 *  slt $t1 $t2 100 -> if (t2<100) t1=1 else t1=0
 *  @param RegisterName alvor | Register where the result will be stored
 *  @param RegisterName arg1 | frist value on the comparison
 *  @param uint16_t arg2 | second value on the comparison
 */
int slti_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "slti", line, 3, len);   
      return 1;
   } 

   return check2Registers1Value(args, line);
}
/*  Instruction BEQ (branch on equal)
 * 
 *  beq $t1 $t2 _sum -> if (t1==t2) jump to _sum
 *  @param RegisterName alvor | frist value on the comparison
 *  @param RegisterName arg1 | second value on the comparison
 *  @param JumpPoint arg2 | jump point
 */
int beq_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "beq", line, 3, len);   
      return 1;
   } 

   return check2Registers1Label(args, line);
}

/*  Instruction bne (branch on not equal)
 * 
 *  bne $t1 $t2 _sum -> if (t1!=t2) jump to _sum
 *  @param RegisterName alvor | frist value on the comparison
 *  @param RegisterName arg1 | second value on the comparison
 *  @param JumpPoint arg2 | jump point
 */
int bne_sintaxe(char **args, int line) { 
   int len = argsLen(args) - 1;
   if (len != 3) {
      printArgsLenError(args, "bne", line, 3, len);   
      return 1;
   } 

   return check2Registers1Label(args, line);
}

int label_sintaxe_s(char **args) {
   int s_len = strlen(args[0]);
   if (s_len == 0)
      return 1;
      
   if (args[0][s_len - 1] != ':' || s_len < 2)
      return 1;

   char *sup = getSlice(args[0], 0, s_len - 2); 
   if (isInteger(sup) == 0) {
      free(sup);
      return 1;
   }
   free(sup);

   if (argsLen(args) != 1)
      return 1; 

   return 0;
}

int label_sintaxe(char **args, int line) {
   int s_len = strlen(args[0]);
   if (args[0][s_len - 1] != ':' || s_len < 2) {
      char *full_command = arrayToString(args);
      printf("Line %d - \"%s\"\n", line, full_command);
      printf(" - Command not found\n");
      free(full_command);
      return 1;
   }

   char *sup = getSlice(args[0], 0, s_len - 2); 
   if (isInteger(sup) == 0) {
      char *full_command = arrayToString(args);
      printf("Line %d - \"%s\"\n", line, full_command);
      printf(" - \"%s\" Invalid label name\n", args[0]);
      free(full_command);
      free(sup);
      return 1;
   }
   free(sup);

   int len = argsLen(args) - 1;
   if (len != 0) {
      char *full_command = arrayToString(args);
      printf("Line %d - \"%s\"\n", line, full_command);
      printf(" - New labels gets no args, total args = %d\n", len);
      free(full_command);
      return 1;
   } 

   return 0;
}

int check_sintaxe(char **args, int line) {
   if      (strcmp(args[0], "add")  == 0) { return add_sintaxe(args, line);   } 
   else if (strcmp(args[0], "addi") == 0) { return addi_sintaxe(args, line);  } 
   else if (strcmp(args[0], "sub")  == 0) { return sub_sintaxe(args, line);   } 
   else if (strcmp(args[0], "subi") == 0) { return subi_sintaxe(args, line);  } 
   else if (strcmp(args[0], "mut")  == 0) { return mut_sintaxe(args, line);   } 
   else if (strcmp(args[0], "muti") == 0) { return muti_sintaxe(args, line);  } 
   else if (strcmp(args[0], "mov")  == 0) { return mov_sintaxe(args, line);   } 
   else if (strcmp(args[0], "div")  == 0) { return div_sintaxe(args, line);   } 
   else if (strcmp(args[0], "divi") == 0) { return divi_sintaxe(args, line);  } 
   else if (strcmp(args[0], "jump") == 0) { return jump_sintaxe(args, line);  } 
   else if (strcmp(args[0], "jal")  == 0) { return jal_sintaxe(args, line);   } 
   else if (strcmp(args[0], "jr")   == 0) { return jr_sintaxe(args, line);    } 
   else if (strcmp(args[0], "and")  == 0) { return and_sintaxe(args, line);   } 
   else if (strcmp(args[0], "or")   == 0) { return or_sintaxe(args, line);    } 
   else if (strcmp(args[0], "sl")   == 0) { return sl_sintaxe(args, line);    } 
   else if (strcmp(args[0], "sr")   == 0) { return sr_sintaxe(args, line);    } 
   else if (strcmp(args[0], "slt")  == 0) { return slt_sintaxe(args, line);   } 
   else if (strcmp(args[0], "slti") == 0) { return slti_sintaxe(args, line);  } 
   else if (strcmp(args[0], "beq")  == 0) { return beq_sintaxe(args, line);   } 
   else if (strcmp(args[0], "bne")  == 0) { return bne_sintaxe(args, line);   } 
   else if (strcmp(args[0], "nop")  == 0) { return nop_sintaxe(args, line);   } 
   else                                          { return label_sintaxe(args, line); }
}
